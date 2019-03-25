// Fill out your copyright notice in the Description page of Project Settings.
//Trigger Box que interactua con ATopLightGroup


#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TBTopLightGroup.generated.h"

/**
 * 
 */
UCLASS()
class X01_API ATBTopLightGroup : public ATriggerBox
{
	GENERATED_BODY()

public:

	ATBTopLightGroup();

	void OnBeginOverlap(class AActor * OverlappedActor, class AActor * OtherActor);
	void OnEndOverlap(class AActor * OverlappedActor, class AActor * OtherActor);


	
};
