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

    int get_damage() const;
    int get_block() const;
    int get_energy_cost() const;
    bool get_selected() const;
};
#endif
