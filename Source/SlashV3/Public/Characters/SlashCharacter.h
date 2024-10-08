
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

// forward declarations
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class USkeletalMeshComponent;
class AItem;



UCLASS()
class SLASHV3_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ASlashCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:	// InputActions pointers, (They HAVE TO BE SET IN BLUEPRINT)

	UPROPERTY(EditAnywhere, Category = Input) 
	UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = Input) 
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input) 
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input) 
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input) 
	UInputAction* EKeyAction;


protected:	// Components, (They HAVE TO BE SET IN BLUEPRINT)

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair) 
	UGroomComponent* HairGroom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair) 
	UGroomComponent* EyebrowsGroom;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Hair) 
	USkeletalMeshComponent* HairMesh;

	virtual void BeginPlay() override;


protected:	// Callback functions for input-actions 

	void Move(const FInputActionValue& Value); // HAS TO BE SET IN BLUEPRINT

	void Look(const FInputActionValue& Value); // HAS TO BE SET IN BLUEPRINT

	void EKeyPressed(); 

private:		

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;


public:		// Getters and setters

	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
