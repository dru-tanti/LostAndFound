// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UENUM(BlueprintType)
enum Type {
	Shirt    UMETA(DisplayName="Shirt"),
	Shoe     UMETA(DisplayName="Shoe"),
	Jeans    UMETA(DisplayName="Jeans"),
};

UENUM(BlueprintType)
enum Colour {
	Red     	UMETA(DisplayName="Red"),
	Blue     UMETA(DisplayName="Blue"),
	Green    UMETA(DisplayName="Green"),
};

UENUM(BlueprintType)
enum Pattern {
	Spotted	UMETA(DisplayName="Spotted"),
	Striped  UMETA(DisplayName="Striped"),
	Plain    UMETA(DisplayName="Plain"),
};

class UParticleSystem;

UCLASS()
class LOSTANDFOUND_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ItemDetails, meta = (AllowPrivateAccess = "true")) TEnumAsByte<Type> ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ItemDetails, meta = (AllowPrivateAccess = "true")) TEnumAsByte<Colour> ItemColour;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ItemDetails, meta = (AllowPrivateAccess = "true")) TEnumAsByte<Pattern> ItemPattern;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true")) UStaticMeshComponent* ItemMesh;
};
