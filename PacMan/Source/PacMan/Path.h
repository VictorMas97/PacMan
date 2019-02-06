#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Path.generated.h"

UCLASS()
class PACMAN_API APath : public AActor
{
	GENERATED_BODY()
	
public:	

	APath();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void GetDirection(FVector currentDirction); //EDIT

	UPROPERTY(EditDefaultsOnly, Category = Collectible)
	UBoxComponent* collider;	
};
