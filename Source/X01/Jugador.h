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
	UPROPERTY(EditAnywhere)
	class USpotLightComponent * myLight;
	UPROPERTY(EditAnywhere)
	class UCameraComponent * myCamera;

	void moveHorizontal(float a);
	void moveVertical(float a);
	void toggleLight();

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

};
