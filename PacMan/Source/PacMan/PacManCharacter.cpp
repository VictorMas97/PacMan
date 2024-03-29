#include "PacManCharacter.h"
#include "Components/InputComponent.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Collectible.h"
#include "PacManGameModeBase.h"
#include "Upgrade.h"
#include "Ghost.h"

APacManCharacter::APacManCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->OnComponentBeginOverlap.AddDynamic(this, &APacManCharacter::OnOverlapBegin);

	speed = 2;
	lifes = 3;
}

void APacManCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Get number of collectibles
	for (TActorIterator<ACollectible> CollectibleItr(GetWorld()); CollectibleItr; ++CollectibleItr)
		collectiblesToEat++;

	base = GetActorLocation();
}

void APacManCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move();
}

void APacManCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APacManCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APacManCharacter::MoveRight);
}

void APacManCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Collision"));

	if (OtherActor->IsA(ACollectible::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Collectible picked up"));

		ScoreUp(Cast<ACollectible>(OtherActor)->points);
		OtherActor->Destroy();

		if (OtherActor->IsA(AUpgrade::StaticClass()))
			Upgrade(Cast<AUpgrade>(OtherActor)->duration);
		
		if (--collectiblesToEat == 0)
		{
			// Level won
			UE_LOG(LogTemp, Warning, TEXT("Won the level"));
		}
	}
	else if (OtherActor->IsA(AGhost::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Ghost collided"));
		if (isUpgraded)
		{
			UE_LOG(LogTemp, Warning, TEXT("A ghost has been killed"));
			OtherActor->Destroy();
			// TP back to his base
			// Kill
			// + 200 points for the first, 400 for the second etc.. (in succession)
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Ghost killed you, -1 life"));
			SetActorLocation(base);
			// TP back to my base
			// - 1 life
			if (--lifes == 0)
			{
				// Death
				UE_LOG(LogTemp, Warning, TEXT("You died"));
			}
		}
	}
}

void APacManCharacter::Move()
{
	if (!inputDirection.IsZero())
		movementDirection = inputDirection;

	if (movementDirection.X != 0)
		movementDirection.Y = 0;
	else if (movementDirection.Y != 0)
		movementDirection.X = 0;

	AddActorLocalOffset(movementDirection * speed);
}

void APacManCharacter::ScoreUp(int _score)
{
	score += _score;
	UE_LOG(LogTemp, Warning, TEXT("Score is now %i ( + %i )"), score, _score);
	// Update HUD
}

void APacManCharacter::Upgrade(float _duration)
{
	UE_LOG(LogTemp, Warning, TEXT("Upgraded!"));
	isUpgraded = true;
	((APacManGameModeBase*)GetWorld()->GetAuthGameMode())->SetGhostsState(AGhost::ghostState::FLEEING);

	GetWorld()->GetTimerManager().SetTimer(upgradeTimer, this, &APacManCharacter::StopUpgrade, _duration);
}

void APacManCharacter::StopUpgrade()
{
	isUpgraded = false;
	((APacManGameModeBase*)GetWorld()->GetAuthGameMode())->SetGhostsState(AGhost::ghostState::CHASING);
}

void APacManCharacter::MoveForward(float value)
{
	inputDirection.X = value;
}

void APacManCharacter::MoveRight(float value)
{
	inputDirection.Y = value;
}