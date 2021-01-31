// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

USTRUCT(BlueprintType)
struct FLevelSettings {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxItems = 30;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxRequests = 5;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxActiveRequests = 5;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxGuarenteedRequests;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxItemTypes;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxVariants;
	UPROPERTY(EditAnywhere, Category = "Level Settings") int8 MaxScore;
	UPROPERTY(EditAnywhere, Category = "Level Settings") bool Paint = false;
	UPROPERTY(EditAnywhere, Category = "Level Settings") bool Scissors = false;
	UPROPERTY(EditAnywhere, Category = "Level Settings") bool Printer = false;

};

class AItems;
class AMagicBox;
class URequest;

UCLASS()
class LOSTANDFOUND_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()

private:
	int32 Score = 0;
	UPROPERTY(EditAnywhere, Category = "Level Settings", meta = (AllowPrivateAccess = "true")) TArray<FLevelSettings> LevelSettings;

	// Current Level Settings.
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LMaxItems = 0;
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LMaxRequests = 0;
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LMaxScore = 0;
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LMaxActiveRequests = 0;
	UPROPERTY(VisibleAnywhere, Category = "Level Settings") int8 LCompletedRequests = 0;

	// Game State Tracking.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true")) int32 CurrentLevel = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true")) float CurrentScore = 0.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true")) float TimeRemaining = 8.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State", meta = (AllowPrivateAccess = "true")) TArray<URequest*> ActiveRequests;

public:
	void UpdateScore(int32 AddedScore);
	bool IsItemMaxNumberExceeded();
	void GenerateRequest();
	bool CheckDelivery(AItems* DepositedItem);
	// TArray<Request> ActiveRequests;

protected:

	AMagicBox* MagicBoxRef;

	virtual void BeginPlay() override;
	void SetupLevel(int8 Level);
	void GameOver(bool PlayerWon);
};


