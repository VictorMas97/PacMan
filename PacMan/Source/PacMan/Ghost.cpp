#include "Ghost.h"

AGhost::AGhost()
{
	PrimaryActorTick.bCanEverTick = true;

	collider =			CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	staticMesh =		CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	staticMesh->AttachTo(collider);
	RootComponent = collider;

	movement = FVector{ 0,1,0 };
	speed = 1;
}

void AGhost::BeginPlay()
{
	Super::BeginPlay();
}

void AGhost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(movement * speed);
}

void AGhost::ChangeDirection(FVector direction)
{
	movement = direction;

}

void AGhost::ChangePhase(ghostState newState)
{
	currentState = newState;

	switch (newState)
	{
	case AGhost::CHASING:
		staticMesh->SetMaterial(0, normalMaterial);

		break;
	case AGhost::FLEEING:
		staticMesh->SetMaterial(0, scaredMaterial);  
		movement = -movement;
		break;
	case AGhost::DEAD:
		// base
		break;
	default:

		break;
	}
}

