#include "deck.h"
#include "player.h"
#include "enemy.h"
#include "card.h"

Deck::Deck() 
    : num(0),
    cards({}){
}

int Deck::get_num() {return num;}
const std::vector<Card> Deck::get_cards() const {return cards;}

std::vector<Card>& Deck::get_mut_cards() {
    return cards;
}

void Deck::remove_card(size_t index) {
    cards.erase(cards.begin() + index);
}

void Deck::move_to_discard(size_t index) {
    cards[index].set_pile(Discard);
}


void Deck::add_card(const Card& card) {
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

            move_to_discard(i);
            return;
        }
    }
}

void Deck::put_5_draw_cards_in_hand() {
    int card_count = 0;
    if (count_draw_cards() < 5) {
        refill_draw_cards();
    }

    for (Card &card : cards) {
        if (card.get_which_pile() == Draw) {
            card.set_pile(Hand);
            card_count += 1;
            if (card_count == 5) {
                return;
            }
        }
    }
}

int Deck::count_draw_cards() {
    int count = 0;
    for (Card & card : cards) {
        if (card.get_which_pile() == Draw) {
            count += 1;   
        }
    }
    return count;
}

void Deck::refill_draw_cards(){ 
    for (Card &card : cards) {
        if (card.get_which_pile() == Discard) {
            card.set_pile(Draw);
        }
    }
}


