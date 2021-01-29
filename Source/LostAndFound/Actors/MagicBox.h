// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.h"
#include "MagicBox.generated.h"

class UBoxComponent;

USTRUCT(BlueprintType)
struct FItemTemplate {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) TSubclassOf<AItems> TemplateItem;
	UPROPERTY(EditAnywhere) TEnumAsByte<Type> ItemType;
};

USTRUCT(BlueprintType)
struct FItemList {
	GENERATED_BODY()

public:
	// FItemList(TEnumAsByte<Type> ItemType, TEnumAsByte<Colour> ItemColour, TEnumAsByte<Pattern> ItemPattern);
	UPROPERTY(EditAnywhere) TEnumAsByte<Type> EItemType;
	UPROPERTY(EditAnywhere) TEnumAsByte<Colour> EItemColour;
	UPROPERTY(EditAnywhere) TEnumAsByte<Pattern> EItemPattern;
};

UCLASS()
class LOSTANDFOUND_API AMagicBox : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicBox();
	AItems* SpawnItem();
	void GenerateList(int8 MaxItems);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) USceneComponent* ItemSpawnPoint;
	int8 RemainingItems;
	FItemList* ItemToSpawn;
	UPROPERTY(EditAnywhere, Category = "Generated Item List", meta=(TitleProperty = "ItemType")) TArray<FItemList> ItemList;
	UPROPERTY(EditAnywhere, Category = "Templates", meta=(TitleProperty = "ItemType")) TArray<FItemTemplate> Templates;
};
