// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.h"
#include "MagicBox.generated.h"

class UBoxComponent;
class AGameManager;

// Defines what Blueprint will be spawned for which ItemType.
USTRUCT(BlueprintType)
struct FItemTemplate {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TSubclassOf<AItems> TemplateItem;
	UPROPERTY(EditAnywhere) TEnumAsByte<Type> ItemType;
};

UCLASS()
class LOSTANDFOUND_API AMagicBox : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicBox();
	AItems* SpawnItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	AGameManager* GameManagerRef;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) USceneComponent* ItemSpawnPoint;
	UPROPERTY(EditAnywhere, Category = "Templates", meta=(TitleProperty = "ItemType")) TArray<FItemTemplate> Templates;
};
