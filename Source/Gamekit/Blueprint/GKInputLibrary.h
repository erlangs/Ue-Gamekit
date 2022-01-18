// BSD 3-Clause License Copyright (c) 2019, Pierre Delaunay All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputActionValue.h"

#include "GKInputLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GAMEKIT_API UGKInputLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    UFUNCTION(BlueprintPure, Category = "Input")
    static FInputActionValue MakeBooleanAction(bool value);

    UFUNCTION(BlueprintPure, Category = "Input")
    static FInputActionValue MakeAxis1DAction(float value);

    UFUNCTION(BlueprintPure, Category = "Input")
    static FInputActionValue MakeAxis2DAction(FVector2D value);

    UFUNCTION(BlueprintPure, Category = "Input")
    static FInputActionValue MakeAxis3DAction(FVector value);

    UFUNCTION(BlueprintPure, Category = "Input|EdgePan")
    static bool IsEdgePanning(FVector2D MouseXYViewport, FVector4 Margins);

    UFUNCTION(BlueprintPure, Category = "Input|EdgePan")
    static FVector2D EdgePanDirection(FVector2D MouseXYViewport);
};
