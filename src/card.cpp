#include "card.h"

Card::Card(int dmg, int blck, int cost, bool selected, Pile which_pile) 
    : damage(dmg),
    block(blck),
    energy_cost(cost),
    selected(false),
    which_pile(Draw){
        
    }

int Card::get_damage() const {return damage;}
int Card::get_block() const {return block;}
int Card::get_energy_cost() const {return energy_cost;}
bool Card::get_selected() const {return selected;}
Pile Card::get_which_pile() const {return which_pile;}


void Card::set_selected(bool value) {
    selected = value;
}

void Card::set_pile(enum Pile pile) {
    which_pile = pile;
}


