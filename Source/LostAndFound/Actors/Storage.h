// Andrew Tanti

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "Storage.generated.h"

class AItems;
class UStorageSpace;

UCLASS()
class LOSTANDFOUND_API AStorage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStorage();
	bool CanStoreItem(AActor* ItemToStore);
	UStorageSpace* GetValidStorageSpace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
