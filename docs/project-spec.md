# 2D turn-based card battler
- Should be a playable combat prototype

### Core Game Idea
The player fights one enemy in a turn-based battle

Each turn:
- the player draws cards
- the player has a limited amount of energy
- the player can play cards from their hand
- cards do simple things like attack or block
- the player ends their turn
- the enemy performs a simple action
- battle continues until one side reaches 0hp

### Core Mechanics

#### Player
- has block
- has hp
- has energy each turn
- has a deck
- draws a hand of cards

#### Enemy
- has hp
- performs one simple attack each turn
- later can have intent display, but not required for sprint 1

#### Cards
- Attack: deal damage
- Block: gain block
- optional: Buff or heal

#### Turn Structure
- Start player turn
- reset energy
- draw cards
- player plays cards
- player presses end turn
- enemy attacks
- new turn starts

### Visual Style
2D UI-Heavy game

- a central battlefield
- player info
- enemy info
- a visible hand of cards
- an End Turn Button
- readable text, numbers, and layout

### Technical Scope

#### Engine / Tools
- Godot
- GDScript, C++
- nvim for code
- Godot editor for scenes, UI, and running the game

 
