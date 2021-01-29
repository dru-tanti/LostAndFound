// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

class AMagicBox;

USTRUCT(BlueprintType)
struct FLevelSettings {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxItems = 30;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxGuarenteedRequests;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxItemTypes;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxVariants;
};

UCLASS()
class LOSTANDFOUND_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Level Settings", meta = (AllowPrivateAccess = "true")) TArray<FLevelSettings> LevelSettings;

public:

protected:
	int8 CurrentLevel = 0;
	AMagicBox* MagicBoxRef;
	virtual void BeginPlay() override;
	void GameStart(); 
	void GameOver(bool PlayerWon);
};


