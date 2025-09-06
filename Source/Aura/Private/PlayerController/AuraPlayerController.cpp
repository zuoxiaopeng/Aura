// Default Message.


#include "PlayerController/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	// Config Enhanced Input Subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	// Show off Mouse And set Mouse's Style
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	// Use Keyboard and Mouse at Same Time, no lock mouse, no hide mouse
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	// detect Visible Actor
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/*
	 * A. LastActor is NULL and ThisActor is NULL
	 *		-Do Nothing
	 * B. LastActor is Valid and ThisActor is NULL
	 *		-UnHighlight LastActor
	 * C. Both Actor is Valid, and aren't the Same Actor
	 *		-Highlight ThisActor and UnHighlight LastActor
	 * D. LastActor is NULL and ThisActor is Valid
	 *		-Highlight ThisActor
	 * E Both Actor is Valid, and are the Same Actor
	 *		-Do nothing
	 */
	if (LastActor && ThisActor != LastActor)
	{
		LastActor->UnHighlightActor();
	}
	if (ThisActor && LastActor != ThisActor)
	{
		ThisActor->HighlightActor();
	}
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// Decide Direction by Camera Yaw Rotation
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}


