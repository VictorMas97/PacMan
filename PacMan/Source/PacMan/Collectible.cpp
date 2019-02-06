#include "Collectible.h"

ACollectible::ACollectible()
{
	PrimaryActorTick.bCanEverTick = false;

	collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	collectibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	collectibleMesh->AttachTo(collider);
	RootComponent = collider;
}

