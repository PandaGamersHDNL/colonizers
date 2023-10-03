// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "GameFramework/Actor.h"
#include "MapManager.generated.h"

UCLASS()
class COLONIZERS_API AMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapManager();
	UPROPERTY(EditDefaultsOnly)
	int MapRadius = 3;

	UPROPERTY(EditDefaultsOnly)
	float TileRadius = 100.f;

	UPROPERTY(EditDefaultsOnly)
	float TileTriangleHeight = 86.6f ;
	UPROPERTY(EditDefaultsOnly)
	float StreetWidth = 20.f;

	UPROPERTY(EditDefaultsOnly)
	float CityHeight = 17.3f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TMap<int, TArray<AActor*>> t;

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetActorsAtIndex(int index);
	UFUNCTION(BlueprintCallable)
		void AddActorToList(int index, AActor* newActor);

	UFUNCTION(BlueprintCallable)
	FVector GetStart(int radius);
		
	/*
	UFUNCTION(BlueprintCallable)
	void MapGen();
	UFUNCTION(BlueprintCallable)
	void TileGen();
	*/

	UFUNCTION(BlueprintCallable)
	bool IsEdge(FVector tileLocation);

	float getXoffset(int offset);
};
