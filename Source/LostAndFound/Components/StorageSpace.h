// Andrew Tanti

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "StorageSpace.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOSTANDFOUND_API UStorageSpace : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStorageSpace();
	UPROPERTY(VisibleAnywhere) bool Available = true;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
