#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"
#include "player.h"
#include "enemy.h"

class Deck {
private:
    int num;
    std::vector<Card> cards;

public:
    Deck();
    ~Deck() = default;

    int get_num();
    const std::vector<Card> get_cards() const;
    std::vector<Card>& get_mut_cards();

    void remove_card(size_t index);
    void add_card(const Card& card);
    void play_card(Player& player, Enemy& enemy);
};
#endif
