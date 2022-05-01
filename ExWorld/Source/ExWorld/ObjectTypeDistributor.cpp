// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity.h"
#include "ExWorldCharacter.h"
#include "ObjectTypeDistributor.h"

// Sets default values
AObjectTypeDistributor::AObjectTypeDistributor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AObjectTypeDistributor::LoadObjectTypes()
{
	if (ObjectTypeDataTable == nullptr) return;

	if (ObjectDatas.IsValidIndex(0))
		ObjectDatas.Empty();

	for (auto it : ObjectTypeDataTable->GetRowMap())
	{
		FObjectTypeData* missionData = reinterpret_cast<FObjectTypeData*>(it.Value);
		ObjectDatas.Add(*missionData);
	}
	for (auto& i : ObjectDatas)
	{
		switch (i.objectType)
		{
		case FObjectType::PAWN:

			AExWorldCharacter* characterPawn = Cast<AExWorldCharacter>(i.ActorRef.LoadSynchronous());
			//characterPawn->objectType = i.objectType;
			UE_LOG(LogTemp, Warning, TEXT("PAWNS IS: %s"), *i.ActorRef->GetName());
			break;

		default:
			AEntity* TempActor = Cast<AEntity>(i.ActorRef.LoadSynchronous());
			TempActor->objectType = i.objectType;
			UE_LOG(LogTemp, Warning, TEXT("NAME IS: %s"), *i.ActorRef->GetName());
			break;
		}
	}
}

// if (ObjectDatas.IsValidIndex(0))
// {
// 	switch (ObjectDatas[0].objectType)
// 	{
// 		
// 	case FObjectType::WORLD_STATIC:
// 		{
// 			AEntity* TempActor = Cast<AEntity>(ObjectDatas[0].ActorRef.LoadSynchronous());
// 			UE_LOG(LogTemp, Warning, TEXT("NAME IS: %s"), *ObjectDatas[0].ActorRef->GetName());
// 			TempActor->objectType=ObjectDatas[0].objectType;
// 			break;
// 		}
// 	case FObjectType::NONE: break;
// 	case FObjectType::PAWN: break;
// 	case FObjectType::DESTRUCTIBLE: break;
// 	default: ;
// 	}
// }


// Called when the game starts or when spawned
void AObjectTypeDistributor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObjectTypeDistributor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
