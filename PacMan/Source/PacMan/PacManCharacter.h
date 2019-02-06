#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "PacManCharacter.generated.h"

UCLASS()
class PACMAN_API APacManCharacter : public APawn
{
	GENERATED_BODY()

public:

	APacManCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Move();
	void Upgrade(float _duration);
	void StopUpgrade();
	void ScoreUp(int _score);
	void MoveForward(float value);
	void MoveRight(float value);

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent * mesh;

	UPROPERTY(EditAnywhere)
	float speed;

	FTimerHandle upgradeTimer;
	FVector inputDirection;
	FVector movementDirection;
	bool isUpgraded;
	int score;
	int collectiblesToEat;
	int lifes;
	FVector base;
};