// Default Message.


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"
#include "Kismet/KismetSystemLibrary.h"

AAuraEnemy::AAuraEnemy()
{
	// Init the Highlight yellow when mouse cursor hovered
	GetMesh()->SetCustomDepthStencilValue(GCustom_Depth_Yellow);
	Weapon->SetCustomDepthStencilValue(GCustom_Depth_Yellow);
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// Init AbilitySys
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystem");
	AbilitySystemComponent->SetIsReplicated(true);
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
