// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "SlashV3/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	/*
	
	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt);

	float AvgFloat = Avg<float>(4.345f, 6.6f);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 4.345 and 6.6: %f"), AvgFloat);

	FVector AvgVector = Avg<FVector>(FVector(1.0f, 5.f, 7.f), FVector(2.f, 15.f, 27.f));
	UE_LOG(LogTemp, Warning, TEXT("Avg of (1.0f, 5.f, 7.f) and (2.f, 15.f, 27.f): %s"), *AvgVector.ToString());
	
	*/
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movement rate in units of cm/frame
	//float MovementRate = 50.f;
	//float RotationRate = 45.f;

	//Movement rate * DeltaTime = (cm/frame) * (frame/s) = (cm/s)
	//AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	//AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));

	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	/*
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);
	*/
}

