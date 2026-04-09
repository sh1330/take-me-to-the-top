#include "deck.h"
#include "player.h"
#include "enemy.h"

Deck::Deck() 
    : num(0),
    cards({}){
}

int Deck::get_num() {return num;}
const std::vector<Card> Deck::get_cards() const {return cards;}

void Deck::remove_card(size_t index) {
    cards.erase(cards.begin() + index);
}
void Deck::add_card(Card& card) {
    cards.push_back(card);
}

void Deck::play_card(Player& player, Enemy& enemy) {
    for (size_t i = 0; i < cards.size(); i++) {
        if (cards[i].get_selected() == true) {
            if (player.get_is_turn() == true) {
                enemy.lose_hp(cards[i].get_damage());
                player.gain_block(cards[i].get_block());
                player.lose_energy(cards[i].get_energy_cost());
            } else {
                player.lose_hp(cards[i].get_damage());
                enemy.gain_block(cards[i].get_block());
            }

            remove_card(i);
            return;
        }
    }
}
