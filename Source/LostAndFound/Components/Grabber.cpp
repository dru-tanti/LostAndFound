// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "LostAndFound/Actors/MagicBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay() {
	Super::BeginPlay();
	InitInput();
	InitPhysics();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(!PhysicsHandle) return; // Null Check
	// The code that makes the object actually move around.
	if (PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(this->GetComponentLocation());
	}
}

void UGrabber::Interact() {
	if(!PhysicsHandle) return; // Null Check
	if(PhysicsHandle->GrabbedComponent) { // If an object is being held.
		UE_LOG(LogTemp, Warning, TEXT("Releasing"));
		PhysicsHandle->GrabbedComponent->GetOwner()->SetActorEnableCollision(true);
		PhysicsHandle->ReleaseComponent();
	} else { // If no object is currently held.
		UE_LOG(LogTemp, Warning, TEXT("Grabbing"));

		// Fire Raycast and get hit details.
		FHitResult Hit = GetFirstPhysicsBody();
		AActor* HitActor = Hit.GetActor();
		UPrimitiveComponent* GrabComponent = Hit.GetComponent();

		if (HitActor && GrabComponent) {
			UE_LOG(LogTemp, Warning, TEXT("Line Trace has Hit: %s"), *(HitActor->GetName()));
			// If the HitActor is the Magic Box, spawn an item, and replace the details with the newly spawned item.
			if(HitActor->IsA(AMagicBox::StaticClass())) {
				UE_LOG(LogTemp, Warning, TEXT("Magiiiic"));
				AMagicBox* MagicBox = Cast<AMagicBox>(HitActor);
				HitActor = Cast<AActor>(MagicBox->SpawnItem());
				GrabComponent = Cast<UPrimitiveComponent>(HitActor->GetRootComponent());
			}
			if (!HitActor || !GrabComponent) return;
			
			// Grab the Hit Object.
			PhysicsHandle->GrabComponentAtLocation(
				GrabComponent,
				NAME_None,
				HitActor->GetActorLocation()
			);

			// Disable collision to avoid and funny business.
			PhysicsHandle->GrabbedComponent->GetOwner()->SetActorEnableCollision(false);
		}
	}
}

void UGrabber::InitInput() {
	// Retrieving the Input component.
	Input = GetOwner()->FindComponentByClass<UInputComponent>();
	if (!Input) return; // Null Check
	Input->BindAction("Interact", IE_Pressed, this, &UGrabber::Interact);
}

void UGrabber::InitPhysics() {
	// Retrieving the Physics Handle Component.
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle) { // Avoiding Null Pointer Error.
		UE_LOG(LogTemp, Error, TEXT("No Physics Handle Present in Object %s"), *GetOwner()->GetName());
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Physics Handle Present in Object %s"), *GetOwner()->GetName());
	}
}

FHitResult UGrabber::GetFirstPhysicsBody() const {
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetPlayerWorldPosition(),
		GetRaycastEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);

	return Hit;
}

FVector UGrabber::GetPlayerWorldPosition() const {
	return GetOwner()->GetActorLocation();
}

FVector UGrabber::GetRaycastEnd() const {
	FVector PLocation;
	FRotator PRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PLocation, OUT PRotation); // Gets the players viewport
	return PLocation + PRotation.Vector() * Reach;
}
