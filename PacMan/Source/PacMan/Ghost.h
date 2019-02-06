#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Ghost.generated.h"

UCLASS()
class PACMAN_API AGhost : public AActor
{
	GENERATED_BODY()
	
public:	

	AGhost();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void ChangeDirection(FVector direction);

	enum ghostState
	{
		CHASING,
		FLEEING,
		DEAD
	};

	void ChangePhase(ghostState newState);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* staticMesh;

	UPROPERTY(EditDefaultsOnly)
		USphereComponent* collider;

	UPROPERTY(EditAnywhere)
		float speed;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* normalMaterial;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* scaredMaterial;

	FVector movement;
	FVector base;
	ghostState currentState;
};

