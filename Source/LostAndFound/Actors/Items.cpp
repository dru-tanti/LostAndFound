// Fill out your copyright notice in the Description page of Project Settings.

#include "Items.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "LostAndFound/Components/StorageSpace.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AItems::AItems() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseMesh;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItems::BeginPlay() {
	Super::BeginPlay();
 	SetMaterialColour();
}

void AItems::SetMaterialColour()  {
	FLinearColor MatColour;
	switch(ItemColour) {
		case Red: 
			MatColour = {1.f, 0.f, 0.f};
			break;
		case Green: 
			MatColour = {0.f, 1.f, 0.f};
			break;
		case Blue: 
			MatColour = {0.f, 0.f, 1.f};
			break;
		default: 
			MatColour = {1.f, 1.f, 1.f};
			break;
	}

	if (BaseMesh->GetMaterial(0)->IsA(UMaterialInstanceDynamic::StaticClass())) {
		UE_LOG(LogTemp, Warning, TEXT("test planes material is already a UMaterialInstanceDynamic"));
	} else {
		UMaterialInstanceDynamic* Material = UMaterialInstanceDynamic::Create(BaseMesh->GetMaterial(0), this);
		BaseMesh->SetMaterial(0, Material);
		Material->SetVectorParameterValue(FName(TEXT("DiffuseColor")), MatColour);
	}

}