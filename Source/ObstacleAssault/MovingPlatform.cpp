// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move Platform Forward
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add Vector to that location
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
		// Set new location
	SetActorLocation(CurrentLocation);
	// Send Platform back if gone to far
		// Check how far it has gone
	float DistanceTravelled = FVector::Dist(StartLocation, CurrentLocation);
		// Reverse direction if gone to far
	if (DistanceTravelled > DistanceToTravel)
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * DistanceToTravel;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

