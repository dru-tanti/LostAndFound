// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Request.h"
#include "LostAndFound/Actors/MagicBox.h"
#include "LostAndFound/Actors/Items.h"
#include "Kismet/GameplayStatics.h"

#define OUT

void AGameManager::BeginPlay()  {
   Super::BeginPlay();
   SetupLevel(0);
}

void AGameManager::GameOver(bool PlayerWon)  {
   if(PlayerWon) {
      UE_LOG(LogTemp, Error, TEXT("Congratulations, You won!"));
   }
}

void AGameManager::SetupLevel(int8 Level)  {
   CurrentLevel = Level;
   LMaxItems = LevelSettings[Level].MaxItems;
   LMaxRequests = LevelSettings[Level].MaxRequests;   
   LMaxScore = LevelSettings[Level].MaxScore;

   for (size_t i = 0; i < LMaxRequests; i++) {
      GenerateRequest(); 
   }  
   
}

void AGameManager::UpdateScore(int32 AddedScore)  {
   Score += AddedScore;
}

bool AGameManager::IsItemMaxNumberExceeded() {
   TArray<AActor*> SpawnItems;
   UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItems::StaticClass(), OUT SpawnItems);
   if(SpawnItems.Num()+1 > LMaxItems) return true;
   else return false;
}

void AGameManager::GenerateRequest() {
   URequest* NewRequest = NewObject<URequest>();
   if(NewRequest) {
      NewRequest->SetRequest(static_cast<Type>(FMath::RandRange(0,2)), static_cast<Colour>(FMath::RandRange(0,2)), rand()%2*10);
      UE_LOG(LogTemp, Warning, TEXT("%s"), *NewRequest->GetRequestText());
      ActiveRequests.Add(NewRequest);
   }
}

bool AGameManager::CheckDelivery(AItems* DepositedItem) {
   if(!DepositedItem) return false; // NULL Check.
   UE_LOG(LogTemp, Warning, TEXT("Total Requests Request: %i"), ActiveRequests.Num());
   for (size_t i = 0; i < ActiveRequests.Num(); i++) {
      UE_LOG(LogTemp, Warning, TEXT("Checking Request: %s [%i]"), *ActiveRequests[i]->GetName(), i);
      if(!ActiveRequests[i]) continue; // NULL Check.
      if(ActiveRequests[i]->IsRequestCorrect(DepositedItem->ItemType, DepositedItem->ItemColour)) {
         UpdateScore(ActiveRequests[i]->Score);
         if(CurrentScore >= LMaxScore) {
            ActiveRequests.Empty();
            GameOver(true);
            return true;
         }
         // Remove the reference for the request.
         ActiveRequests.RemoveAt(i);
         ++LCompletedRequests;
         // If we have not exceeded maximum requests, generate a new one and insert at the current element.
         if(LCompletedRequests + ActiveRequests.Num() < LMaxRequests) {
            URequest* NewRequest = NewObject<URequest>();
            if(NewRequest) {
               NewRequest->SetRequest(static_cast<Type>(FMath::RandRange(0,2)), static_cast<Colour>(FMath::RandRange(0,2)), rand()%2*10);
               ActiveRequests.Insert(NewRequest, i);
               return true;
            }
            return false;
         } else {
            return false;
         }
      }
   }
   return false;
}