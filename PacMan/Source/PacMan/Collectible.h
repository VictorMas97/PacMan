#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Collectible.generated.h"

UCLASS()
class PACMAN_API ACollectible : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACollectible();

	UPROPERTY(EditDefaultsOnly, Category = Collectible)
		USphereComponent* collider;

	UPROPERTY(EditDefaultsOnly, Category = Collectible)
		UStaticMeshComponent* collectibleMesh;

	UPROPERTY(EditAnywhere, Category = Collectible)
		int points;
};
