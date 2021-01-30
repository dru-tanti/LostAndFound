// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Request.h"
#include "LostAndFound/Actors/MagicBox.h"
#include "Kismet/GameplayStatics.h"
#define OUT

void AGameManager::BeginPlay()  {
   Super::BeginPlay();
   SetupLevel(0);
}

void AGameManager::GameStart()  {
}

void AGameManager::GameOver(bool PlayerWon)  {
   
}

void AGameManager::SetupLevel(int8 Level)  {
   CurrentLevel = Level;
   LMaxItems = LevelSettings[Level].MaxItems;
   LMaxGuarenteedRequests = LevelSettings[Level].MaxGuarenteedRequests;
}

void AGameManager::UpdateScore(int32 AddedScore)  {
   Score += AddedScore;
}

bool AGameManager::IsItemMaxNumberExceeded() {
   TArray<AActor*> SpawnItems;
   UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItems::StaticClass(), OUT SpawnItems);
   UE_LOG(LogTemp, Warning, TEXT("Number of Items in World: %i"), SpawnItems.Num()+1);
   if(SpawnItems.Num()+1 > LMaxItems) return true;
   else return false;
}