#ifndef CARD_H
#define CARD_H

enum Pile {
    Draw,
    Discard,
    Exhaust,
    Hand
};

class Card {
private:
    int damage;
    int block;
    int energy_cost;
    bool selected;
    enum Pile which_pile;

public:
    Card(int dmg, int blck, int cost, bool selected, Pile which_pile);
    ~Card() = default;

    int get_damage() const;
    int get_block() const;
    int get_energy_cost() const;
    bool get_selected() const;
    enum Pile get_which_pile() const;

    void set_selected(bool value);
    void set_pile(enum Pile pile);
};
#endif
