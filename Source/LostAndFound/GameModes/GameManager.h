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
	UPROPERTY(EditAnywhere, Category = "Level Settings") bool Paint = false;
	UPROPERTY(EditAnywhere, Category = "Level Settings") bool Scissors = false;
	UPROPERTY(EditAnywhere, Category = "Level Settings") bool Printer = false;

};

UCLASS()
class LOSTANDFOUND_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()

private:
	int32 Score = 0;
	UPROPERTY(EditAnywhere, Category = "Level Settings", meta = (AllowPrivateAccess = "true")) TArray<FLevelSettings> LevelSettings;

public:
	void UpdateScore(int32 AddedScore);
	bool IsItemMaxNumberExceeded();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 CurrentLevel = 0;
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LMaxItems = 0;
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LMaxGuarenteedRequests = 0;

	AMagicBox* MagicBoxRef;

	virtual void BeginPlay() override;
	void SetupLevel(int8 Level);
	void GameStart(); 
	void GameOver(bool PlayerWon);
};


