// Fill out your copyright notice in the Description page of Project Settings.

#include "PacManGameModeBase.h"
#include "Runtime/Engine/Public/EngineUtils.h"

void APacManGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlayGameMode"));

	for (TActorIterator<AGhost> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ghosts.Add(*ActorItr);
		UE_LOG(LogTemp, Warning, TEXT("ghost %s"), *ActorItr->GetName());
	}

}

void APacManGameModeBase::ScareGhosts()
{
	UE_LOG(LogTemp, Warning, TEXT("hola"));

	for (int i = 0; i < ghosts.Num(); i++) {
		ghosts[i]->ChangePhase(AGhost::ghostState::FLEEING);
	}

	// delay 5s

	/*for (int i = 0; i < ghosts.Num(); i++) {
		ghosts[i]->ChangePhase(AGhost::ghostState::CHASING);
	}*/


}
