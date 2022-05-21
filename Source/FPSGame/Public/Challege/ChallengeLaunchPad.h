// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChallengeLaunchPad.generated.h"

class UBoxComponent;

UCLASS()
class FPSGAME_API AChallengeLaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChallengeLaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* BoxComp;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
		float LaunchStrength;

	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
		float LaunchPitchAngle;

	UPROPERTY(EditDefaultsOnly, Category = "LaunchPad")
		UParticleSystem* ActivateLaunchPadEffect;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
