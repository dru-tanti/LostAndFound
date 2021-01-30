// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOSTANDFOUND_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Interact();
	void Release();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	UPROPERTY(EditAnywhere) float Reach = 100.f;
	UPROPERTY() UInputComponent* Input = nullptr;
	void InitInput();
	void InitPhysics();

	UPROPERTY() UPhysicsHandleComponent* PhysicsHandle;
	FHitResult GetFirstPhysicsBody() const;
	FHitResult GetFirstDynamicBody() const;
	FHitResult GetFirstStaticBody() const;
	FVector GetRaycastEnd() const;
};
