// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "TopLightGroup.generated.h"

UCLASS()
class X01_API ATopLightGroup : public AActor
{
	GENERATED_BODY()


	class USceneComponent * myRoot;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * baseInterruptor;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent * interruptor;

	UPROPERTY(EditAnywhere)
	class UPointLightComponent * luz;

	class UAudioComponent * audioCH;

	UPROPERTY(EditAnywhere)
	class USoundWave * myClips[1];

	FVector interruptorLoc_ON;
	FVector interruptorLoc_OFF;

	bool isLightON() const;

	UPROPERTY(EditAnywhere)
	bool iniciaLuzEncendida;



	
public:	
	// Sets default values for this actor's properties
	ATopLightGroup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Activa el interruptor ON / OFF
	void ToggleLight();

	UFUNCTION()
	void OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor);
	
	UFUNCTION()
	void OnOverlapEnd(AActor * OverlappedActor, AActor * OtherActor);



};
