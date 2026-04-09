#include "card.h"

Card::Card(int dmg, int blck, int cost) 
    : damage(dmg),
    block(blck),
    energy_cost(cost){
        
    }

int Card::get_damage() {return damage;}
int Card::get_block() {return block;}
int Card::get_energy_cost() {return energy_cost;}
