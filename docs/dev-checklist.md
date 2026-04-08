TL;DR:
Exact build order, shortest version

If you want the absolute no-nonsense order:

Make main.tscn
Add labels + End Turn button
Attach main.gd
Make button change label text
Add player/enemy stats
Show stats in labels
Make End Turn cause enemy attack
Add win/lose checks
Make card data
Make starter deck
Show hand as buttons
Make Strike work
Make Defend work
Make energy decrease
Make full turn loop work
Clean up bugs

# Phase 0 — project setup

Goal: get a project that opens and runs.

Create the project folder
Create these folders:
scenes/
scripts/
assets/art/
assets/audio/
ui/
Create these files:
scenes/main.tscn
scripts/main.gd
scripts/game_manager.gd
scripts/player.gd
scripts/enemy.gd
scripts/card.gd
Make main.tscn your main scene
Run the project once to confirm it launches

Done when:

Godot opens the project
pressing run opens your scene without errors


# Phase 1 — make the screen exist

Goal: make a visible combat screen before writing logic.

In main.tscn, create a very rough layout with:

title/status label
player HP label
player block label
player energy label
enemy HP label
hand area
End Turn button

Do not worry about it looking good yet.

A simple layout is enough:

enemy info near the top
status label in the middle/top
player info lower down
hand area at bottom
End Turn button on the side

Done when:

you can run the scene
you can see labels and a button on screen

# Phase 2 — get one script talking to the UI

Goal: prove scripts are connected properly.

Attach main.gd to the root node of main.tscn.

In main.gd:

change one label’s text when the scene starts
connect the End Turn button
when the button is pressed, change the status label text

You are not making game logic yet.
You are just proving:

script attached correctly
node paths work
button signal works

Done when:

the label changes on startup
clicking the button changes something visible

# Phase 3 — make player and enemy data

Goal: create the basic stats.

In player.gd:

hp
block
energy

Suggested starting values:

hp = 30
block = 0
energy = 3

In enemy.gd:

hp
attack_damage

Suggested starting values:

hp = 20
attack_damage = 6

In main.gd or game_manager.gd:

create one player
create one enemy
update the labels from those values

Done when:

UI shows the correct starting HP, block, and energy
enemy HP is shown too

# Phase 4 — make the turn state

Goal: create the turn loop skeleton.

In game_manager.gd, add:

whose turn it is
a function to start player turn
a function to end player turn
a function for enemy turn

For now:

start player turn sets energy to 3
end player turn changes status label
enemy turn subtracts damage from player
then player turn starts again

Do not worry about cards yet.

Also add damage handling properly:

block absorbs damage first
leftover damage reduces HP
player block should not last forever unless you want that later

A simple first version:

player block resets to 0 at start of enemy turn or after damage is taken

Done when:

pressing End Turn causes enemy attack
player HP changes correctly
next player turn starts

# Phase 5 — win/lose conditions

Goal: make the fight end properly.

Add checks:

if enemy HP <= 0, show “You Win”
if player HP <= 0, show “You Lose”
stop further turns after battle ends

Do this now before cards, because it makes everything safer later.

Done when:

you can manually force hp to 0 and see the correct result

# Phase 6 — create the card data model

Goal: represent a card cleanly.

In card.gd, make a simple card structure with:

name
cost
card_type
value

Example:

Strike: cost 1, type attack, value 6
Defend: cost 1, type block, value 5

Do not make visual card scenes yet unless you really want to.
At first, cards can just be buttons with text.

Done when:

you can create a Strike card and a Defend card in code

# Phase 7 — make a starter deck and hand

Goal: get cards onto the screen.

Create a very small deck:

5 Strikes
5 Defends

At start of player turn:

clear current hand
draw 5 cards from the deck
show them in the hand area

Simplest version:

each card is a button
button text shows name + cost

Example button text:

Strike (1)
Defend (1)

Done when:

5 playable-looking card buttons appear in the hand area each turn

# Phase 8 — make cards actually work

Goal: clicking a card does the effect.

When a card button is clicked:

check battle is active
check it is player turn
check player has enough energy
reduce energy
apply effect
remove card from hand
update labels

Effects:

Strike → enemy HP goes down
Defend → player block goes up

Done when:

Strike lowers enemy HP
Defend raises player block
energy goes down
clicked card disappears

# Phase 9 — connect cards to the turn loop

Goal: make the whole combat loop playable.

Now combine everything:

player turn starts
hand appears
player plays some cards
player presses End Turn
enemy attacks
next player turn begins
repeat until win/lose

Done when:

you can complete a full fight without manual editing

# Phase 10 — clean up the basics

Goal: make it usable, not pretty.

Do these quick improvements:

status label says whose turn it is
hand clears properly between turns
labels always refresh after actions
disabled card play if not enough energy
disable End Turn after battle ends
avoid duplicate button connections / weird repeats

Done when:

gameplay feels stable
no obvious breakage in one full fight

# Recommended file responsibility
main.gd

Keep this light.

Use it for:

references to UI nodes
calling setup
maybe passing node refs into the manager

Do not stuff all game logic in here if you can help it.

game_manager.gd

This is the brain.

Use it for:

turn flow
battle state
drawing cards
card play handling
win/lose checks
player.gd

Use it for:

hp
block
energy
taking damage
gaining block
resetting for turn
enemy.gd

Use it for:

hp
attack damage
taking damage
basic attack action
card.gd

Use it for:

card properties
maybe a helper function or type info


