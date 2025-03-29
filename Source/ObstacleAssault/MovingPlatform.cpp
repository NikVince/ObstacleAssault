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

	UE_LOG(LogTemp, Display, TEXT("This moving platform is moving: %f"), DistanceToTravel);

	UE_LOG(LogTemp, Display, TEXT("The Start Location is: %s"), *StartLocation.ToString());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

	
}


void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);
	float DistanceTravelled = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceTravelled > DistanceToTravel)
	{
		FString PlatformName = GetName();
		float OverShoot = DistanceTravelled - DistanceToTravel;
		UE_LOG(LogTemp, Display, TEXT("The OverShoot of Platform %s is: %f"), *PlatformName, OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * DistanceToTravel;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

// function to rotate platform without real implementation, but only logging for prototyping
void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Rotating Platform"));
}
