// Default Message.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interaction/EnemyInterface.h"
#include "AuraPlayerController.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

private:
	// Input Mapping Context
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	// Movement Input Action
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	// Cursor Check
	IEnemyInterface* LastActor = nullptr;
	IEnemyInterface* ThisActor = nullptr;

private:
	// Movement
	void Move(const FInputActionValue& InputActionValue);
	// Cursor Check
	void CursorTrace();
};
