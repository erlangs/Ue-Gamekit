// BSD 3-Clause License Copyright (c) 2022, Pierre Delaunay All rights reserved.

#include "Gamekit/Abilities/GKCastPointAnimNotify.h"
#include "Gamekit/Abilities/GKAbilitySystemGlobals.h"

// Unreal Engine
#include "AbilitySystemBlueprintLibrary.h"



void UGKCastPointAnimNotify::Notify(class USkeletalMeshComponent *MeshComp, class UAnimSequenceBase *Animation, const FAnimNotifyEventReference& EventReference)
{
    UAnimNotify::Notify(MeshComp, Animation, EventReference);

    // Send Game play event
    AActor *Owner = MeshComp->GetOwner();

    // this prevent the editor from printing scary error message
    // when the animation is played in the editor
    // ASC is not populated in the animation editor
    if (::IsValid(Owner) && UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Owner)) {
        // How can I populate the TargetData here
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(Owner, CastPointEventTag, FGameplayEventData());
    }
}


UGKAbilitySystemGlobals* Get() {
    UAbilitySystemGlobals* ASG = &UAbilitySystemGlobals::Get();
    return Cast<UGKAbilitySystemGlobals>(ASG);
}
 

FGameplayTag GetDefaultAnimTag() {

    auto ASG = Get();
    if (ASG){
        return ASG->AnimationCastPointTag;
    }

    return FGameplayTag::EmptyTag;
}

FGameplayTag UGKCastPointAnimNotify::GetCastPointEventTag() {

    static FGameplayTag DefaultTag = GetDefaultAnimTag();

    if (CastPointEventTag == FGameplayTag::EmptyTag){
        return DefaultTag;
    }

    return CastPointEventTag;
}