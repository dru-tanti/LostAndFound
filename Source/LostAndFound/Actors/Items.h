// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UENUM(BlueprintType)
enum Type {
	Shirt    	UMETA(DisplayName="Shirt"),
	Shoe     	UMETA(DisplayName="Shoe"),
	Jeans   		UMETA(DisplayName="Jeans"),
	AnyType		UMETA(DisplayName="Any"),
};

UENUM(BlueprintType)
enum Variant {
	Large    	UMETA(DisplayName="Large"),
	Medium     	UMETA(DisplayName="Medium"),
	Small     	UMETA(DisplayName="Small"),
	AnyVarient  UMETA(DisplayName="Any"),
};

UENUM(BlueprintType)
enum Colour {
	Red     		UMETA(DisplayName="Red"),
	Blue     	UMETA(DisplayName="Blue"),
	Green    	UMETA(DisplayName="Green"),
	AnyColour	UMETA(DisplayName="Any"),
};

UENUM(BlueprintType)
enum Pattern {
	Spotted		UMETA(DisplayName="Spotted"),
	Striped  	UMETA(DisplayName="Striped"),
	Plain    	UMETA(DisplayName="Plain"),
	AnyPattern	UMETA(DisplayName="Any"),
};

class UBoxComponent;
class UParticleSystem;
class UMaterialInstanceDynamic;
class UPhysicsConstraintComponent;
class UStorageSpace;

UCLASS()
class LOSTANDFOUND_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

	void SetMaterialColour();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details") TEnumAsByte<Type> ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details") TEnumAsByte<Colour> ItemColour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details") TEnumAsByte<Pattern> ItemPattern;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components") UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, Category = "Storage") UStorageSpace* StorageSpace;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
