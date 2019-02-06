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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* staticMesh;

	UPROPERTY(EditDefaultsOnly)
		USphereComponent* collider;

	UPROPERTY(EditAnywhere)
		float speed;

	FVector movement;


};
