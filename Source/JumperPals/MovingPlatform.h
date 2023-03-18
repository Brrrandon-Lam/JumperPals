// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class JUMPERPALS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

	// Creates a target location that we can modify in the editor on a widget.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locations", Meta = (MakeEditWidget = true))
	FVector TargetLocation;

protected:
	
private:
	UPROPERTY(EditAnywhere)
	float MovementSpeed;

	FVector StartLocation;

};
