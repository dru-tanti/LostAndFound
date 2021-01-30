// Andrew Tanti

#include "Storage.h"
#include "LostAndFound/Components/StorageSpace.h"
#include "LostAndFound/Actors/Items.h"

// Sets default values
AStorage::AStorage() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AStorage::BeginPlay() {
	Super::BeginPlay();
}

UStorageSpace* AStorage::GetValidStorageSpace()  {
	UE_LOG(LogTemp, Warning, TEXT("Checking for valid storage space"));
	TArray<UStorageSpace*> ComponentsOut;
   GetComponents<UStorageSpace>(ComponentsOut);
	UE_LOG(LogTemp, Warning, TEXT("%i storage spaces found"), ComponentsOut.Num());

	for (int32 i = 0; i < ComponentsOut.Num(); i++) {
		UE_LOG(LogTemp, Warning, TEXT("Component: %s"), *ComponentsOut[i]->GetName()); 
	}
 
   for(UStorageSpace* StorageComponent : ComponentsOut) {
		UE_LOG(LogTemp, Warning, TEXT("Checking a storage space"));
		if(StorageComponent && StorageComponent->Available) {
			return StorageComponent;
		}
   }
	return nullptr;
}

bool AStorage::CanStoreItem(AActor* ItemToStore) {
	UStorageSpace* ValidStorage = GetValidStorageSpace();
	if(!ItemToStore || !ValidStorage) return false;
	UE_LOG(LogTemp, Warning, TEXT("Found a storage space!"));
	ItemToStore->SetActorLocation(ValidStorage->GetComponentLocation());
	ItemToStore->SetActorRotation(FRotator(0.f, 0.f, 0.f));
	AItems* CastItemToStore = Cast<AItems>(ItemToStore);
	if(CastItemToStore) {
		CastItemToStore->StorageSpace = ValidStorage;
		Cast<UPrimitiveComponent>(CastItemToStore->GetRootComponent())->SetSimulatePhysics(false);
	}
	ValidStorage->Available = false;
	return true;
}
