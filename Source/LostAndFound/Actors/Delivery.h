// Andrew Tanti

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delivery.generated.h"

class AItems;
class AGameManager;
class UBoxComponent;

UCLASS()
class LOSTANDFOUND_API ADelivery : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's propertiesEngine\Build\BatchFiles\Build.bat LostAndFoundEditor Win64 Development D:\Projects\Lost-and-Found\LostAndFound.uproject -waitmutex
	ADelivery();
	bool DepositItem(AActor* DepositedItem);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	AGameManager* GameManagerRef;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* BaseMesh;
};
