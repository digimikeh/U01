// Fill out your copyright notice in the Description page of Project Settings.

#include "TopLightGroup.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/AudioComponent.h"
#include "Jugador.h"


// Sets default values
ATopLightGroup::ATopLightGroup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	myRoot = CreateDefaultSubobject<USceneComponent>(TEXT("GroupRoot"));
	baseInterruptor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Interruptor"));
	interruptor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Interruptor"));
	luz = CreateDefaultSubobject<UPointLightComponent>(TEXT("Luz"));
	audioCH = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioCH"));

	RootComponent = myRoot;
	baseInterruptor->SetupAttachment(myRoot);
	interruptor->SetupAttachment(baseInterruptor);
	luz->SetupAttachment(myRoot);
	audioCH->SetupAttachment(baseInterruptor);

	//Posiciones de interruptor ON y OFF
	interruptorLoc_ON = FVector(0.f, 0.f, 0.f);
	interruptorLoc_OFF = FVector(0.f, 0.f, -30.f);

	//Overlapping
	OnActorBeginOverlap.AddDynamic(this, &ATopLightGroup::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATopLightGroup::OnOverlapEnd);


}


// Called when the game starts or when spawned
void ATopLightGroup::BeginPlay()
{
	Super::BeginPlay();

	//Verifica si inicia con luz encendida o apagada
	if (iniciaLuzEncendida){
		interruptor->SetRelativeLocation(interruptorLoc_ON);
		luz->SetVisibility(true);

	} else {
		interruptor->SetRelativeLocation(interruptorLoc_OFF);
		luz->SetVisibility(false);
	}

	
}

// Called every frame
void ATopLightGroup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATopLightGroup::ToggleLight(){

	audioCH->SetSound(myClips[0]);
	audioCH->Play();
	luz->SetVisibility(!isLightON());

	if (isLightON())
		interruptor->SetRelativeLocation(interruptorLoc_OFF);
	else 
		interruptor->SetRelativeLocation(interruptorLoc_ON);

}

//Overlapping
void ATopLightGroup::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor){

	AJugador * jugador = Cast<AJugador>(OtherActor);

	if (jugador && (jugador->GetActorLabel() == "Jugador")){

			GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, "Dentro del trigger de luz");

			if (jugador->ActionKeyPressed){

				//Accionar el interruptor
				ToggleLight();

			}
	}


	delete jugador;
	

}

void ATopLightGroup::OnOverlapEnd(AActor * OverlapedActor, AActor * OtherActor){


}


//Metodos privados
bool ATopLightGroup::isLightON() const {
	return luz->IsVisible();
}



