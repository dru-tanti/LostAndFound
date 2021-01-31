// Andrew Tanti

#include "Request.h"

URequest::URequest() {

}

void URequest::SetRequest(TEnumAsByte<Type> IType=AnyType, TEnumAsByte<Colour> IColour=AnyColour, float BaseScore = 10.f) {
   RType = IType;
   RColour = IColour;
   Score = BaseScore;
}

FString URequest::GetRequestText() {
   FString RequestText = "I want : ";
   FString TypeText;
   FString ColourText;

   switch(RType) {
      case Shirt:
         TypeText = "Shirt ";
         break;
      case Shoe:
         TypeText = "Shoes ";
         break;
      case Jeans:
         TypeText = "Jeans ";
         break;
      case AnyType:
         TypeText = "Something ";
         break;
   }

   switch(RColour) {
      case Red:
         ColourText = "Red ";
         break;
      case Green:
         ColourText = "Green ";
         break;
      case Blue:
         ColourText = "Blue ";
         break;
      case AnyColour:
         ColourText = "";
         break;
   }

   // switch(RPattern) {
   //    case Striped:
   //       FString PatternText = " Striped ";
   //       break;
   //    case Spotted:
   //       FString PatternText = " Spotted ";
   //       break;
   //    case Plain:
   //       FString PatternText = " Plain ";
   //       break;
   //    case AnyType:
   //       FString PatternText = "";
   //       break;
   // }
   return RequestText.Append(ColourText.Append(TypeText));
}

bool URequest::IsRequestCorrect(TEnumAsByte<Type> IType, TEnumAsByte<Colour> IColour) {
   return (IType == RType && IColour == RColour) ? true : false;
}

