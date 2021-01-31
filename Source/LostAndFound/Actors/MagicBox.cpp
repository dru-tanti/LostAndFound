// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicBox.h"
#include "LostAndFound/GameModes/GameManager.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMagicBox::AMagicBox() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
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
	GameManagerRef = Cast<AGameManager>(UGameplayStatics::GetGameMode(GetWorld()));
}

AItems* AMagicBox::SpawnItem() {
	UE_LOG(LogTemp, Warning, TEXT("Spawning Item"));

	if(!GameManagerRef) return nullptr;
	if(GameManagerRef->IsItemMaxNumberExceeded()) return nullptr;

	// Setting the object type.
	TEnumAsByte<Type> SpawnItemType = Type(rand()%3);

	// Looking through the templates to find the matching bluepring.
	for(FItemTemplate Template : Templates) {
		if(Template.ItemType == SpawnItemType) {
			UE_LOG(LogTemp, Warning, TEXT("Item found!"));
			FVector SpawnLocation = this->GetActorLocation();
			// Create the spawned obeject and set the necissary parameters.
			AItems* TempItem = GetWorld()->SpawnActorDeferred<AItems>(Template.TemplateItem, FTransform(SpawnLocation));
			TempItem->ItemColour = Colour(rand()%3);
			TempItem->ItemPattern = Pattern(rand()%3);
			UGameplayStatics::FinishSpawningActor(TempItem, FTransform(SpawnLocation));
			return TempItem;
		} else {
			continue;	
		}
	}
	UE_LOG(LogTemp, Error, TEXT("No item found!!"));
	return nullptr;
}