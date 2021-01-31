// Andrew Tanti

#pragma once

#include "CoreMinimal.h"
#include "LostAndFound/Actors/Items.h"
#include "Request.generated.h"

UCLASS()
class LOSTANDFOUND_API URequest : public UObject {
	GENERATED_BODY()
public:
	URequest();
	void SetRequest(TEnumAsByte<Type> IType, TEnumAsByte<Colour> IColour, float BaseScore);
	FString GetRequestText();
	bool IsRequestCorrect(TEnumAsByte<Type> IType, TEnumAsByte<Colour> IColour);
	UPROPERTY(VisibleAnywhere) float Score = 10.f;
	UPROPERTY(VisibleAnywhere) float ActiveTime = 1.f;
	UPROPERTY(VisibleAnywhere) float QualityMultiplier = 1.5f; // Multiplier per quality of item
	UPROPERTY(VisibleAnywhere) float TimeMultiplier = 1.5f; // Multiplier for how quickly you complete the request
	// UPROPERTY(VisibleAnywhere) TEnumAsByte<Colour> RPattern;
	UPROPERTY(VisibleAnywhere) TEnumAsByte<Colour> RColour;
	UPROPERTY(VisibleAnywhere) TEnumAsByte<Type> RType;

};
