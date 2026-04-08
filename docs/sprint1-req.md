# Sprint 1 Requirements
Sprint 1 is about making the smallest playable combat prototype

### Sprint 1 Goals
- launch the project
- enter one combat scene
- see player and enemy HP
- see cards in hand
- play at least one attack card
- play at least one block card
- end the turn
- let the enemy attack
- win or lose the battle

### Sprint 1 required features
##### Main Combat Scene
- player area
- enemy area
- hand area
- energy display
- End Turn button
- battle message or status label

#### Player Stats
- HP
- block
- energy

#### Enemy Stats
- HP
- one simple attack value

#### Card system
Minimum card types
- Strike: Deal 6 damage
- Defend: Gain 5 block

#### Hand system
At the start of a turn the player draws:
- 5 cards
Ideally:
- hand is cleared at the end of turn
- used cards leave the hand
- cards are drawn from a deck list

#### Turn system
- player turn start
- energy resets to 3
- draw 5 cards
- card play reduces energy if card has cost
- End Turn button
- enemy turn
- next player turn

#### Card Playing
When a card is clicked
- If enough energy, apply its effect
- remove it from hand
- update UI

#### Enemy turn
When player ends turn:
- enemy attacks once
- player block reduces damage first
- remaining damage hits player HP
- then a new turn starts

#### Win/Lose Condition
Battle ends when:
- enemy HP \<= 0 -> player wins
- player HP \<= 0 -> enemy wins


### Sprint 1 deliverables
By the end of sprint 1, this project will include

##### Scenes
- scenes/main.tscn

##### Scripts
- scripts/main.gd
- scripts/game_manager.gd
- scripts/player.gd
- scripts/enemy.gd
- scripts/card.gd

##### Working Gameplay
- one battle
- one enemy
- two card types
- turn loop
- win/lose state
