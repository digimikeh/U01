// Fill out your copyright notice in the Description page of Project Settings.

#include "TBTopLightGroup.h"
#include "TopLightGroup.h"
#include "Jugador.h"
#include "GameFramework/Actor.h"

//Constructor
ATBTopLightGroup::ATBTopLightGroup(){

    OnActorBeginOverlap.AddDynamic(this, &ATBTopLightGroup::OnBeginOverlap);
    OnActorEndOverlap.AddDynamic(this, &ATBTopLightGroup::OnEndOverlap);

}

void ATBTopLightGroup::OnBeginOverlap(AActor * OverlappedActor, AActor * OtherActor){

    AJugador * jugador = Cast<AJugador>(OtherActor);

    if (jugador != nullptr && OtherActor != this){

        if (jugador->ActionKeyPressed){
            topLightGroup->ToggleLight();
        }

    }    

}

void ATBTopLightGroup::OnEndOverlap(AActor * OverlappedActor, AActor * OtherActor){
    
}