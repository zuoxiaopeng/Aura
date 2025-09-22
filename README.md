#  GAS Study Note
## Day One
### Character and Player Controller
- Create the **AuraCharacterBase** class and create the **AuraCharacter** and **AuraEnemy** based on it
- Create the **AuraPlayerController** class and add **MoveInput** feature
  >Create InputMappingContext named **AuraContext** and InputAction named **MoveAction**.
  
<img width="1888" height="854" alt="image" src="https://github.com/user-attachments/assets/a5ad05ba-350f-4167-be38-ae047fe03e79" />
<p align="center">Init Third-person top-down Controll Setting in BeginPlay</p>

<img width="1270" height="637" alt="image" src="https://github.com/user-attachments/assets/736b279d-7771-47c7-9ba5-ad60e382ee06" />
<p align="center">Move Function</p>

## Day Two
### Create GameMode and Interaction
- Create **AuraGameModeBase** and set it as default
- Create **EnemyInterface** and **IEnemyInterface**
  >AuraEnemy inherit from IEnemyInterface to highlight enemy when cursor hovered it.\
  >Expend PlayerContrroler to use mouse cursor detect Actor and Highlight the Actor.
  
<img width="1318" height="1172" alt="image" src="https://github.com/user-attachments/assets/740b083d-718b-4194-bd9b-f98eba779e17" />
<p align="center">CursorTrace Function</p>

<img width="1710" height="389" alt="image" src="https://github.com/user-attachments/assets/38f1f807-af8a-47e4-a25a-148d0d4e7244" />
<p align="center">Use EnemyInterface Custom Highlight Function Flexible</p>

## Day Three
### AbilitySystemComponent, AttributeSet and PlayerState
- Create **AuraAbilitySystemComponent** and  **AuraAttributeSet**
  >Add AbilitySystem and AttributeSet parameter in AuraCharacterBase.
- Create **AuraPlayerState**
  >Init the parameters directly in AuraEnemy cause we don't need to keep the date when enemy destructed.\
  >AuraPlayerState and AuraCharacterBase will use the AbilitySystemInterface to manage date.
<img width="2560" height="1440" alt="gas structure" src="https://github.com/user-attachments/assets/fbcb211f-2d2b-45ff-8b83-39925b577856" />
<p align="center">GAS Structure</p>

## Day Four
### Init Ability Actor Info and Attributes Adding Process
- Init AuraCharacter's Ability Actor Info in PossessedBy for Server and OnRep_PlayerState for Client
  >PossessedBy build a controll relationship between the Pawn and Conttroller at the Server.\
  >OnRep_PlayerState is called when Replication happen.\
  >the Owner Actor is AuraPlayer State, the Avatar Actor is itself(AuraCharacter).
- Init AuraEnemy's Ability Actor Info in BeginPlay directly, the both of Owner and Avatar is itself
- Build a Attributes Adding Process
  >StepOne: Create a variable as the Attribute.\
  >StepTwo: Create a OnRep function for the Attribute.\
  >StepThree：Register the Attribute in GetLifetimeReplicatedProps.

<img width="2319" height="1380" alt="Init Ability Actor Info" src="https://github.com/user-attachments/assets/db758ae0-9051-4264-a7c1-21c155d7531b" />
<p align="center"> Init Ability Actor Info in different case</p>

## Day Five
### AttributeSet Macros and EffectActor
- Use AttributeSet Macro to add game-specific functions
- Create a EffectActor and overlap call back function
  >Create a HealthPotion based on it
<img width="1628" height="394" alt="image" src="https://github.com/user-attachments/assets/5e3ee582-d9a1-4842-9de6-dcb5b6e4e838" />
<p align="center">AttributeSet Macros</p>
<img width="1288" height="770" alt="image" src="https://github.com/user-attachments/assets/6508df16-1a8d-4d6b-b2f9-9c67516b1738" />
<p align="center">Use ShowDebug AbilitySystem to Check Attributes</p>

## Day Six
### Create UserWidget, WidgetController and HUD classes\
- Globe Progress Bar
  >Create a Globe Progress Bar based on UseWidget to derive the Health Globe and Mana Globe.
- HUD
 >Create a OverlayWidget based on UseWidget to and init in AuraHUD cpp class set AuraHUD class as HUD class in GameMode

 ## Day Seven
 ### Wiget Controller
 - Widget Controller monitor game data chages and broadcast the changes
  >Based it to Create a AuraWidgetController class and init Overlay in AuraHUD class
<img width="1710" height="602" alt="image" src="https://github.com/user-attachments/assets/feda177e-8eee-4a4c-b12e-a364908802f2" />
<p align="center">InitOverlay Function whitch be called by OnRep_PlayerState in AuraCharacter</p>

## Day Eight
### Delegate
- Using Delegate to Broadcast the Attribute Changes for HUD
  >Declare Delegate -> Declare Delagate varible -> Broadcast Init Values when HUD init -> Bind the Attribute to the Callback Fuction -> When the Attirbute has Changed Broadcast to HUD
<img width="5605" height="3165" alt="deepseek_mermaid_20250913_a07a18" src="https://github.com/user-attachments/assets/dc0dd352-06cf-4c7c-9d58-6d04f35f0a27" />
<p align="center">Full Delegate Workflow</p>

## Day Nine
# Aura Effect Actor
- Get TargetActor's AbilitySystemComponent and make a outgoingspec than apply effect to TargetActor
<img width="1986" height="930" alt="image" src="https://github.com/user-attachments/assets/e261b47e-7a45-4df4-b8b9-a021dacbdec3" />
<p align="center">ApplyEffectToTarget Function</p>





  
