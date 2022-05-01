// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "StructAndEnum.h"
#include "GameFramework/Actor.h"
#include "ObjectTypeDistributor.generated.h"

UCLASS()
class EXWORLD_API AObjectTypeDistributor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectTypeDistributor();

	UPROPERTY(EditAnywhere)
		UDataTable* ObjectTypeDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FObjectTypeData> ObjectDatas;

	UFUNCTION(BlueprintCallable)
	void LoadObjectTypes();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
