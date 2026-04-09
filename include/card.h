#ifndef CARD_H
#define CARD_H

class Card {
private:
    int damage;
    int block;
    int energy_cost;

    bool selected;
    


public:
    Card(int dmg, int blck, int cost);
    ~Card() = default;

    int get_damage();
    int get_block();
    int get_energy_cost();
    bool get_selected();
};
#endif
