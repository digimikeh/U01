// Fill out your copyright notice in the Description page of Project Settings.

#include "Jugador.h"
#include "Components/SpotLightComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/AudioComponent.h"


// Sets default values
AJugador::AJugador()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	this->SetActorLabel("Jugador");

	//Creacion e inicializacion de componentes
	myLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	myCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	myAudioCH = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioCH"));

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	myLight->SetupAttachment(GetMesh());
	myCamera->SetupAttachment(GetMesh());
	myAudioCH->SetupAttachment(myLight);

	//Ajuste de posicion y rotacion
	myLight->SetRelativeLocation(FVector(20.0f, 0.0f, 30.0f));
	myCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 30.0f));
	myCamera->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	myAudioCH->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	


}

// Called when the game starts or when spawned
void AJugador::BeginPlay()
{
	Super::BeginPlay();

	if (iniciaLinternaEncendida){
		myLight->SetVisibility(true);
	} else {
		myLight->SetVisibility(false);
	}
	
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
	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AJugador::setActionON);
	PlayerInputComponent->BindAction("Action", IE_Released, this, &AJugador::setActionOFF);

}

void AJugador::moveHorizontal(float a){
	if (Controller && a)
		AddMovementInput(GetActorRightVector(), a);

	
}

void AJugador::moveVertical(float a){
	if (Controller && a)
		AddMovementInput(GetActorForwardVector(), a);
}

void AJugador::toggleLight(){

	myAudioCH->SetSound(myClips[0]);
	myAudioCH->Play();

	if (LinternaCargada){
		myLight->SetVisibility(!isLightOn());		//Al ser Toggle (intercambio), ajusta la visibilidad al contrario de como se halla actualmente
	}												//por eso el signo !
}

bool AJugador::isLightOn() const{
	return myLight->IsVisible();
}

void AJugador::setActionON(){
	ActionKeyPressed = true;
}

void AJugador::setActionOFF(){
	ActionKeyPressed = false;
}


