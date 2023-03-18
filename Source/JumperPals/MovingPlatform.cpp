// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
void AMovingPlatform::BeginPlay() 
{
	Super::BeginPlay();
	// Cannot be called on a client.
	if (HasAuthority()) {
		// Set whether this actor replicates to the client
		SetReplicates(true);
		// Set whether actor movement replicates to the client
		SetReplicateMovement(true);
	}
	// Set the start location of the actor.
	StartLocation = GetActorLocation();
	// Get and transform our target location to global space.
	TargetLocation = GetTransform().TransformPosition(TargetLocation);
}
AMovingPlatform::AMovingPlatform()
{
	MovementSpeed = 5.0f;
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority()) {
		// Get the actor's location and the target's location transformed into global space.
		FVector ActorLocation = GetActorLocation();
		// If the distance from start to current is greater than dist from start to target, we have passed the target.
		if (FVector::DistSquared(StartLocation, ActorLocation) >= FVector::DistSquared(StartLocation, TargetLocation)) {
			// Swap the start and target location
			FVector temp = TargetLocation;
			TargetLocation = StartLocation;
			StartLocation = temp;
		}
		// Get the unit direction vector from A to B
		FVector UnitDirectionVector = (TargetLocation - StartLocation).GetSafeNormal();
		// Update Actor Location in the direction of the unit direction vector using MS and delta time
		ActorLocation += UnitDirectionVector * MovementSpeed * DeltaTime;
		SetActorLocation(ActorLocation);
	}
}
