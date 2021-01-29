// Andrew Tanti

#include "Delivery.h"
#include "LostAndFound/Actors/Items.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADelivery::ADelivery() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseMesh;
	
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADelivery::BeginPlay() {
	Super::BeginPlay();
	
}

void ADelivery::DepositItem(AActor* DepositedItem)  {
	UE_LOG(LogTemp, Warning, TEXT("%s Deposited in Delivery Box"), *DepositedItem->GetName());
	DepositedItem->Destroy();
}


