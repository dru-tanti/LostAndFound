// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.h"
#include "MagicBox.generated.h"

USTRUCT(BlueprintType)
struct FItemTemplate {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) UStaticMesh* TemplateMesh;
	UPROPERTY(EditAnywhere) TEnumAsByte<Type> ItemType;
};

UCLASS()
class LOSTANDFOUND_API AMagicBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicBox();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	void SpawnItem();
	UPROPERTY(EditAnywhere, meta = (TitleProperty = "ItemType")) TArray<FItemTemplate> Templates;
};
