// Fill out your copyright notice in the Description page of Project Settings.


#include "MapManager.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<AActor*> AMapManager::GetActorsAtIndex(int index)
{
	auto find = t.Find(index);
	if (!find) {
		find = new TArray<AActor*>();
	}
	return *find;
}

void AMapManager::AddActorToList(int index, AActor* newActor)
{
	auto actorsatindex = t.Find(index);
	if (actorsatindex) {
		actorsatindex->Add(newActor);
	}
	else {
		actorsatindex = new TArray<AActor*>();
		t.Add(index, *actorsatindex);
	}
}

