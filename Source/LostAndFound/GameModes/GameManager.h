// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

class AMagicBox;
UCLASS()
class LOSTANDFOUND_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()


private:
	UPROPERTY(EditAnywhere, Category = "Spawn Parameters", meta = (AllowPrivateAccess = "true")) int8 MaxItems = 30;
	UPROPERTY(EditAnywhere, Category = "Spawn Parameters", meta = (AllowPrivateAccess = "true")) int8 MaxItemTypes;
	UPROPERTY(EditAnywhere, Category = "Spawn Parameters", meta = (AllowPrivateAccess = "true")) int8 MaxVariants;

public:
	void ActorDied(AActor* DeadActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop") int32 StartDelay = 3;

	AMagicBox* MagicBoxRef;
	virtual void BeginPlay() override;
	void GameStart(); 
	void GameOver(bool PlayerWon);
};
