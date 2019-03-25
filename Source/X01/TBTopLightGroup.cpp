// Fill out your copyright notice in the Description page of Project Settings.

#include "TBTopLightGroup.h"
#include "GameFramework/Actor.h"

//Constructor
ATBTopLightGroup::ATBTopLightGroup(){

    OnActorBeginOverlap.AddDynamic(this, &ATBTopLightGroup::OnBeginOverlap);
    OnActorEndOverlap.AddDynamic(this, &ATBTopLightGroup::OnEndOverlap);

}

void ATBTopLightGroup::OnBeginOverlap(AActor * OverlappedActor, AActor * OtherActor){


}

void ATBTopLightGroup::OnEndOverlap(AActor * OverlappedActor, AActor * OtherActor){

}