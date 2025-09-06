// Default Message.


#include "Character/AuraEnemy.h"

#include "Kismet/KismetSystemLibrary.h"

void AAuraEnemy::HighlightActor()
{
	bIsHighlighted = true;
}

void AAuraEnemy::UnHighlightActor()
{
	bIsHighlighted = false;
}
