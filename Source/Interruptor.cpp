// Fill out your copyright notice in the Description page of Project Settings.

#include "Interruptor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AInterruptor::AInterruptor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	myBaseInterruptor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseInterruptor"));
	myInterruptor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Interruptor"));
	myAudioCH = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioCH"));

	//PointLight no se crea aqui porque no es parte del interruptor, se crea en el mapa y se asigna en el panel de Details
	//targetPointLightComponent = targetPointLight->FindComponentByClass<UPointLightComponent>();

	RootComponent = myBaseInterruptor;
	myInterruptor->SetupAttachment(RootComponent);
	myAudioCH->SetupAttachment(RootComponent);

	myBaseInterruptor->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	//Valores de posicion de interruptor on y off
	//interruptorLoc_ON = FVector(0.f, 0.f, 0.f);
	//interruptorLoc_OFF = FVector(0.f, 0.f, -20.f);
	

}

void AInterruptor::setInterruptorLocation(FVector _loc){
	myInterruptor->SetRelativeLocation(_loc);
}


// Called when the game starts or when spawned
void AInterruptor::BeginPlay()
{
	Super::BeginPlay();

	if (IniciaActivado){
		myInterruptor->SetRelativeLocation(interruptorLoc_ON);
		//targetPointLightComponent->SetVisibility(true);
		//isOn = true;
	} else {
		myInterruptor->SetRelativeLocation(interruptorLoc_OFF);
		//targetPointLightComponent->SetVisibility(false);
		//isOn = false;
	}
	
}

// Called every frame
void AInterruptor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Esta funcion es publica, se activa cuando el jugador está frente al interruptor.
void AInterruptor::ToggleActivar(){

	myAudioCH->SetSound(myClips[0]);
	myAudioCH->Play();
/*
	if (isOn){
		myInterruptor->SetRelativeLocation(interruptorLoc_OFF);
		//targetPointLightComponent->SetVisibility(false);
	} else {
		myInterruptor->SetRelativeLocation(interruptorLoc_ON);
		//targetPointLightComponent->SetVisibility(true);
	}
	
	isOn = !isOn;
	*/

}

