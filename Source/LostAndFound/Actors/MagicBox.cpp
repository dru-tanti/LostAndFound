// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicBox.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMagicBox::AMagicBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseMesh;
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComp->SetupAttachment(RootComponent);

	ItemSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Item Spawn Point"));
	ItemSpawnPoint->SetupAttachment(BaseMesh);
}

// Called when the game starts or when spawned
void AMagicBox::BeginPlay() {
	Super::BeginPlay();
	GenerateList(30);
}

// Called every frame
void AMagicBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMagicBox::GenerateList(int8 MaxItems) {
	ItemList[MaxItems];
	RemainingItems = MaxItems;
	// for (size_t i = 0; i < MaxItems; i++) {
	// 	ItemList[i] = new FItemList(Shirt, Red, Plain);
	// }
}

AItems* AMagicBox::SpawnItem() {
	// ItemList[rand() % RemainingItems];
	ItemToSpawn = new FItemList();

	// NOTE: TESTING!
	ItemToSpawn->EItemType = Type(rand()%2);
	ItemToSpawn->EItemColour = Colour(rand()%3);
	ItemToSpawn->EItemPattern = Plain;
	//--------------------------------------------
	UE_LOG(LogTemp, Warning, TEXT("Spawning Item"));
	for(FItemTemplate Template : Templates) {
		if(Template.ItemType == ItemToSpawn->EItemType) {
			UE_LOG(LogTemp, Warning, TEXT("Item found!"));
			FVector SpawnLocation = this->GetActorLocation();
			FRotator SpawnRotation = this->GetActorRotation();
			AItems* TempItem = GetWorld()->SpawnActorDeferred<AItems>(Template.TemplateItem, FTransform(SpawnLocation));
			TempItem->ItemColour = ItemToSpawn->EItemColour;
			TempItem->ItemPattern = ItemToSpawn->EItemPattern;
			UGameplayStatics::FinishSpawningActor(TempItem, FTransform(SpawnLocation));
			return TempItem;
		} else {
			continue;	
		}
	}
	UE_LOG(LogTemp, Error, TEXT("No item found!!"));
	return nullptr;
}