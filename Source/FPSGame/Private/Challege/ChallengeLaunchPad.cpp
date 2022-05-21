// Fill out your copyright notice in the Description page of Project Settings.


#include "Challege/ChallengeLaunchPad.h"
#include "Components/BoxComponent.h"
#include "Gameframework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChallengeLaunchPad::AChallengeLaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Declare Box Component
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComp->SetCollisionProfileName(TEXT("Trigger"));
	BoxComp->SetupAttachment(RootComponent);

	// declare overlap events for outer
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AChallengeLaunchPad::OnOverlapBegin);

	LaunchStrength = 1500;
	LaunchPitchAngle = 35.f;

}

// Called when the game starts or when spawned
void AChallengeLaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

void AChallengeLaunchPad::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch += LaunchPitchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;

	if (OtherComp && OtherComp->IsSimulatingPhysics()) {
		OtherComp->AddImpulse(LaunchVelocity, NAME_None, true);

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, OtherComp->GetName());

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActivateLaunchPadEffect, GetActorLocation());
	}
	else {
		ACharacter* Other = Cast<ACharacter>(OtherActor);

		if (Other) {
			Other->LaunchCharacter(LaunchVelocity, true, true);
		}

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ActivateLaunchPadEffect, GetActorLocation());
	}
}

// Called every frame
void AChallengeLaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

