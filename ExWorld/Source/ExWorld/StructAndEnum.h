// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "StructAndEnum.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLD_API UStructAndEnum : public UObject
{
	GENERATED_BODY()
};

UENUM(BlueprintType)
enum class FObjectType: uint8
{
	NONE,
    PAWN,
    DESTRUCTIBLE,
    WORLD_STATIC
};

USTRUCT(BlueprintType)
struct FObjectTypeData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FObjectType objectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<AActor> ActorRef;
};
