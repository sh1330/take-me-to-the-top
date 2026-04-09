#include "card.h"

Card::Card(int dmg, int blck, int cost) 
    : damage(dmg),
    block(blck),
    energy_cost(cost),
    selected(false){
        
    }

int Card::get_damage() const {return damage;}
int Card::get_block() const {return block;}
int Card::get_energy_cost() const {return energy_cost;}
bool Card::get_selected() const {return selected;}
