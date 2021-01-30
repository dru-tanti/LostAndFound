// Andrew Tanti

#pragma once

#include "CoreMinimal.h"
#include "LostAndFound/Actors/Items.h"

class LOSTANDFOUND_API Request {
	
public:
	Request();
	Request(Colour IColour);
	Request(Type IType);
	Request(Colour IColour, Type IType);
	~Request();

	UPROPERTY(VisibleAnywhere) float Score;
	UPROPERTY(VisibleAnywhere) float ActiveTime;
	UPROPERTY(VisibleAnywhere) float QualityMultiplier; // Multiplier per quality of item
	UPROPERTY(VisibleAnywhere) float TimeMultiplier; // Multiplier for how quickly you complete the request
	// UPROPERTY(VisibleAnywhere) Pattern RPattern;
	UPROPERTY(VisibleAnywhere) Colour RColour;
	UPROPERTY(VisibleAnywhere) Type RType;

};
