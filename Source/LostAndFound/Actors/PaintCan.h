// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items.h"
#include "GameFramework/Actor.h"
#include "PaintCan.generated.h"

UCLASS()
class LOSTANDFOUND_API APaintCan : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintCan();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=ItemDetails, meta = (AllowPrivateAccess = "true")) TEnumAsByte<Colour> ItemColour;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
