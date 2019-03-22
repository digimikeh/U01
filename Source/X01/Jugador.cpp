// Fill out your copyright notice in the Description page of Project Settings.

#include "Jugador.h"
#include "Components/SpotLightComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AJugador::AJugador()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Creacion e inicializacion de componentes
	myLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	myCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	//Ajuste de posicion y rotacion
	myLight->SetRelativeLocation(FVector(20.0f, 0.0f, 30.0f));
	myCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	myCamera->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));


}

// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Horizontal", this, &AJugador::moveHorizontal);
	PlayerInputComponent->BindAxis("Vertical", this, &AJugador::moveVertical);

	PlayerInputComponent->BindAction("ToggleLight", IE_Pressed, this, &AJugador::toggleLight);
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AJugador::SetAction);

}

void AJugador::moveHorizontal(float a){
	if (Controller && a)
		AddMovementInput(GetActorForwardVector(), a);
	
}

void AJugador::moveVertical(float a){
	if (Controller && a)
		AddMovementInput(GetActorForwardVector(), a);
}

void AJugador::toggleLight(){
	myLight->SetVisibility(!isLightOn());		//Al ser Toggle (intercambio), ajusta la visibilidad al contrario de como se halla actualmente
												//por eso el signo !
}

bool AJugador::isLightOn() const{
	return myLight->IsVisible();
}

void AJugador::SetAction(){
	//Aqui van las acciones que debe hacer el jugador cuando interactua con un objeto
}


