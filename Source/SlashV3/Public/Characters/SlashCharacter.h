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
	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input) // HAS TO BE SET IN BLUEPRINT
	UInputAction* JumpAction;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair) // HAS TO BE SET IN BLUEPRINT
	UGroomComponent* HairGroom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair) // HAS TO BE SET IN BLUEPRINT
	UGroomComponent* EyebrowsGroom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair) // HAS TO BE SET IN BLUEPRINT
	USkeletalMeshComponent* HairMesh;

	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value); // HAS TO BE SET IN BLUEPRINT
	void Look(const FInputActionValue& Value); // HAS TO BE SET IN BLUEPRINT

private:	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
};
