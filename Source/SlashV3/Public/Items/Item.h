// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class USkeletalMeshComponent;

UCLASS()
class SLASHV3_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters", meta = (ToolTip = "Controls the maximum length of the wave"))
	float Amplitude = 0.25f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters", meta = (ToolTip = "Controls the speed of the wave"))
	float TimeConstant = 5.f;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* SK_Mesh;

	template<typename T>
	T Avg(T First, T Second);

	UFUNCTION()
	virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
									  int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime = 0.f;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second)/2;
}
