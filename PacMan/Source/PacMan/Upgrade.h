#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.h"
#include "Upgrade.generated.h"

UCLASS()
class PACMAN_API AUpgrade : public ACollectible
{
	GENERATED_BODY()
	
public:	

	AUpgrade() : ACollectible() {}

	UPROPERTY(EditAnywhere, Category = Upgrade)
		float duration;
};
