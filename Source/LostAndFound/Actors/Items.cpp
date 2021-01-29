// Fill out your copyright notice in the Description page of Project Settings.

#include "Items.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AItems::AItems() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseMesh;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItems::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
