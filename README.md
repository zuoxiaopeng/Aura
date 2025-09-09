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

  
  
