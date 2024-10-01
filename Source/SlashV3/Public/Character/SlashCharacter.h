// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SlashCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class USkeletalMeshComponent;

UCLASS()
class SLASHV3_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void MoveForward(float Value);

	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputAction* LookAction;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair)
	UGroomComponent* HairGroom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair)
	UGroomComponent* EyebrowsGroom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair)
	USkeletalMeshComponent* HairMesh;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

private:	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
};
