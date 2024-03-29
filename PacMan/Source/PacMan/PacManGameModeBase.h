// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Ghost.h"
#include "PacManGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacManGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	void SetGhostsState(AGhost::ghostState _state);
	
	TArray <AGhost*> ghosts;
};
