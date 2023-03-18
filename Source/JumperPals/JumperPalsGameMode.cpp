// Copyright Epic Games, Inc. All Rights Reserved.

#include "JumperPalsGameMode.h"
#include "JumperPalsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJumperPalsGameMode::AJumperPalsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
