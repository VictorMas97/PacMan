#include "Path.h"
#include "Ghost.h"

APath::APath() //TO DO
{
	PrimaryActorTick.bCanEverTick = false;

	collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = collider;

	collider->OnComponentBeginOverlap.AddDynamic(this, &APath::OnOverlapBegin);
}

void APath::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->IsA(AGhost::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Ghost crossed here"));
		// Turn after some seconds so it turns in the middle and not after just entering the collider or think of something else	
	}
}

void APath::GetDirection(FVector currentDirction) //TO DO
{

}