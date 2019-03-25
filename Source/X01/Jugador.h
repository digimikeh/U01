// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Jugador.generated.h"

UCLASS()
class X01_API AJugador : public ACharacter
{
	GENERATED_BODY()

	//Componentes
	class USpotLightComponent * myLight;
	class UCameraComponent * myCamera;
	class UAudioComponent * myAudioCH;

	UPROPERTY(EditAnywhere)
	class USoundWave * myClips[1];

	UPROPERTY(EditAnywhere)
	bool iniciaLinternaEncendida;		//Se ajusta desde el panel Details, cuando comienza el juego, la linterna comienza encendida?

	void moveHorizontal(float a);
	void moveVertical(float a);
	void toggleLight();
	void setActionON();
	void setActionOFF();


	bool isLightOn() const;

public:
	// Sets default values for this character's properties
	AJugador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetAction();

	UPROPERTY(EditAnywhere)
	bool LinternaCargada;

	//Esta propiedad sirve para saber si el jugador ha presionado el boton accion, se lee desde otra clase
	bool ActionKeyPressed;

};
