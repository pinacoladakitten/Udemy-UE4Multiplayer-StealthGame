// Fill out your copyright notice in the Description page of Project Settings.


#include "Challege/ChallengeBlackHole.h"

// Sets default values
AChallengeBlackHole::AChallengeBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Declare Outer Sphere
	SphereCompOuter = CreateDefaultSubobject<USphereComponent>(TEXT("Outer Sphere"));
	SphereCompOuter->SetCollisionProfileName(TEXT("Trigger"));
	SphereCompOuter->SetupAttachment(RootComponent);

	// declare overlap events for outer
	SphereCompOuter->OnComponentBeginOverlap.AddDynamic(this, &AChallengeBlackHole::OnOverlapBegin);
	SphereCompOuter->OnComponentEndOverlap.AddDynamic(this, &AChallengeBlackHole::OnOverlapEnd);


	//Declare Inner Sphere
	SphereCompInner = CreateDefaultSubobject<USphereComponent>(TEXT("Inner Sphere"));
	SphereCompInner->SetCollisionProfileName(TEXT("Trigger"));
	SphereCompInner->SetupAttachment(RootComponent);

	// declare overlap events for inner
	SphereCompInner->OnComponentBeginOverlap.AddDynamic(this, &AChallengeBlackHole::OnOverlapBegin);
	SphereCompInner->OnComponentEndOverlap.AddDynamic(this, &AChallengeBlackHole::OnOverlapEnd);


}

// Called when the game starts or when spawned
void AChallengeBlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

void AChallengeBlackHole::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this) {
		AffectedActors.Add(OtherActor);
	}
}

void AChallengeBlackHole::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != this) {
		AffectedActors.Remove(OtherActor);
	}
}

// Called every frame
void AChallengeBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto& actor : AffectedActors) {
		actor->
	}

}

