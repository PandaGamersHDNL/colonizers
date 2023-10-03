// Fill out your copyright notice in the Description page of Project Settings.


#include "MapManager.h"
#include <Kismet/KismetMathLibrary.h>
//#include <MathUtil.h>

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

FVector AMapManager::GetStart(int radius)
{
	auto actorLoc = GetActorLocation();
	auto ret = FVector(0,0, actorLoc.Z);
	
	ret.X = getXoffset(radius) * -1;
	ret.X += actorLoc.X;

	
	ret.Y = (TileTriangleHeight + (StreetWidth / 2))* radius * -1;
	ret.Y += actorLoc.Y;

	return ret;
}

bool AMapManager::IsEdge(FVector tileLocation)
{
	
	//make tile location relative
	FVector actorLoc = GetActorLocation();
	tileLocation.X -= actorLoc.X;
	tileLocation.Y -= actorLoc.Y;

	//absolute values
	
	tileLocation.X = UKismetMathLibrary::Abs(tileLocation.X);
	tileLocation.Y = UKismetMathLibrary::Abs(tileLocation.Y);

	
	//TOP or BOTTOM
	if (UKismetMathLibrary::Round( getXoffset(MapRadius)) == UKismetMathLibrary::Round(tileLocation.X)) {
		return true;
	} 

	int xOffset = tileLocation.X/ getXoffset(1);

	//TODO one of these 2 can be made into a helper function
	auto yCoordOffset = xOffset * ((StreetWidth / 2) + TileTriangleHeight);
	//bottom row y coord for most right y
	auto bottomYcoord = ((TileTriangleHeight * 2) + StreetWidth) * MapRadius;

	//check
	auto x = UKismetMathLibrary::Round(bottomYcoord - yCoordOffset);
	auto y = UKismetMathLibrary::Round(tileLocation.Y);
	auto res = x == y;
		return res;
}

//gets the offset created by the x coordinate, we say 0 0 is the center of the map
float AMapManager::getXoffset(int offset)
{
	return ((TileRadius * 1.5f) + CityHeight) *offset;
}

