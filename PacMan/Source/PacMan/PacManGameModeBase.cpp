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

void APacManGameModeBase::SetGhostsState(AGhost::ghostState _state)
{
	UE_LOG(LogTemp, Warning, TEXT("hola"));

	for (int i = 0; i < ghosts.Num(); i++)
		if (_state != AGhost::ghostState::DEAD)
			ghosts[i]->ChangePhase(_state);
		
}
