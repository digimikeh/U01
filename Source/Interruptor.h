// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interruptor.generated.h"

UCLASS()
class X01_API AInterruptor : public AActor
{
	GENERATED_BODY()

	//Componentes
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * myBaseInterruptor;
	
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * myInterruptor;

	UPROPERTY(EditAnywhere)
	class UAudioComponent * myAudioCH;

	//UPROPERTY(EditAnywhere)
	//class AActor * targetPointLight;		//Luz a la cual se desea acceder para encenderla o apagarla
	//class UPointLightComponent * targetPointLightComponent;

	//UPROPERTY(EditAnywhere)
	//class USoundWave * myClips[2];

	//UPROPERTY(EditAnywhere)
	//bool IniciaActivado;


	//Posiciones de interruptor
	//On
	//FVector interruptorLoc_ON;
	//FVector interruptorLoc_OFF;

	//Esta el interruptor encendido?
	//bool isOn;


	//Metodos o funciones

	//void setInterruptorLocation(const FVector _loc);



	
public:	
	// Sets default values for this actor's properties
	AInterruptor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//void ToggleActivar();


};
