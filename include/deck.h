#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck {
private:
    int num;
    std::vector<Card> cards;

public:
    Deck();
    ~Deck();

    int get_num();
    std::vector<Card> get_cards();

    void remove_card(size_t index);
    void add_card(Card& card);
    void play_card(Player& player, Enemy& enemy);
};
#endif