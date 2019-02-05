#include "PacManCharacter.h"
#include "Components/InputComponent.h"

// Sets default values
APacManCharacter::APacManCharacter()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->OnComponentBeginOverlap.AddDynamic(this, &APacManCharacter::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APacManCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APacManCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (movementDirection != FVector::ZeroVector)
	{
		AddActorLocalOffset(movementDirection);
	}
}

// Called to bind functionality to input
void APacManCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APacManCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APacManCharacter::MoveRight);
}

void APacManCharacter::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("aa"));
}

void APacManCharacter::MoveForward(float value)
{

}

void APacManCharacter::MoveRight(float value)
{
	movementDirection.X = value;
}
