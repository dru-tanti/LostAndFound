// Andrew Tanti

#pragma once

#include "CoreMinimal.h"
#include "LostAndFound/GameModes/GameManager.h"
#include "GameFramework/Actor.h"
#include "Delivery.generated.h"

class AItems;
class UBoxComponent;

UCLASS()
class LOSTANDFOUND_API ADelivery : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelivery();
	bool DepositItem(AActor* DepositedItem);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* BaseMesh;
};
