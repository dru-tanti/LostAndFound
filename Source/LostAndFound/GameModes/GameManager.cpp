// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "LostAndFound/Actors/MagicBox.h"
#include "Kismet/GameplayStatics.h"
#define OUT

void AGameManager::GameStart()  {
   MagicBoxRef = Cast<AMagicBox>(UGameplayStatics::GetActorOfClass(GetWorld(), AMagicBox::StaticClass()));
   MagicBoxRef->GenerateList(MaxItems);
}

void AGameManager::GameOver(bool PlayerWon)  {
   
}

void AGameManager::BeginPlay()  {
   Super::BeginPlay();
}

void AGameManager::ActorDied(AActor* DeadActor)  {
   
}
