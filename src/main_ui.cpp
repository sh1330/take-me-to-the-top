#include "main_ui.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/h_box_container.hpp>

using namespace godot;

void MainUI::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_end_turn_pressed"), &MainUI::_on_end_turn_pressed);
    ClassDB::bind_method(D_METHOD("update_labels"), &MainUI::update_labels);
}

MainUI::MainUI() {
}

MainUI::~MainUI() {
}

void MainUI::_ready() {
    enemy_hp_lbl = get_node<Label>("EnemyHpLabel");
    enemy_block_lbl = get_node<Label>("EnemyBlockLabel");
    player_hp_lbl = get_node<Label>("PlayerHpLabel");
    player_block_lbl = get_node<Label>("PlayerBlockLabel");
    player_energy_lbl = get_node<Label>("PlayerEnergyLabel");
    status_lbl = get_node<Label>("StatusLabel");
    end_turn_btn = get_node<Button>("EndTurnButton");

    if (!enemy_hp_lbl || !player_hp_lbl || !player_block_lbl ||
        !player_energy_lbl || !status_lbl || !end_turn_btn || !enemy_block_lbl) {
        UtilityFunctions::printerr("MainUI: one or more UI nodes were not found.");
        return;
    }

    end_turn_btn->connect("pressed", Callable(this, "_on_end_turn_pressed"));

    update_labels();
    status_lbl->set_text("Player turn");

    deck.add_card(Card(6, 0, 1));
    deck.add_card(Card(0, 5, 1));
    deck.add_card(Card(10, 0, 2));
    update_card_display();
}

void MainUI::update_labels() {
    if (!enemy_hp_lbl || !player_hp_lbl || !player_block_lbl ||
        !player_energy_lbl || !status_lbl) {
        return;
    }

    enemy_hp_lbl->set_text(String::num_int64(enemy.get_hp()) + "/" + String::num_int64(enemy.get_max_hp()) + " <3");
    player_hp_lbl->set_text(String::num_int64(player.get_hp()) + "/" + String::num_int64(player.get_max_hp()) + " <3");
    player_block_lbl->set_text(String::num_int64(player.get_block()) + " Block");
    player_energy_lbl->set_text(String::num_int64(player.get_energy()) + " Energy");
    enemy_block_lbl->set_text(String::num_int64(enemy.get_block()) + " Block");
}

void MainUI::_on_end_turn_pressed() {
    status_lbl->set_text("Enemy turn");

    int incoming_damage = 6;

    player.lose_hp(incoming_damage);
    player.reset_energy();
    update_labels();

    if (player.get_hp() <= 0) {
        status_lbl->set_text("You Lose");
        end_turn_btn->set_disabled(true);
        return;
    }

    status_lbl->set_text("Player turn");
}

void MainUI::_on_card_pressed(size_t index) {
    //create the mutable cards vector
    std::vector<Card>& cards = deck.get_mut_cards();
    //check if its a valid index
    if ((index < 0) || (index > cards.size())) {
        UtilityFunctions::printerr("Invalid index");
        return;
    }
    // unselect everything else first 
    for (size_t i = 0; i < cards.size(); i++) {
        cards[i].set_selected(false);
    }
    //select the card
    cards[index].set_selected(true);
    //do the stuff
    deck.play_card(player, enemy);
    update_labels();
    update_card_display();
}

void MainUI::update_card_display() {
    HBoxContainer *card_container = get_node<HBoxContainer>("CardContainer");
    if (!card_container) {
        UtilityFunctions::printerr("CardContainer not found.");
        return;
    }

    // remove old card UI
    Array children = card_container->get_children();
    for (int i = 0; i < children.size(); i++) {
        Node *child = Object::cast_to<Node>(children[i]);
        if (child) {
            child->queue_free();
        }
    }

    // add one UI element per card
    const std::vector<Card> &cards = deck.get_cards();

    for (const Card &card : cards) {
        Button *card_button = memnew(Button);

        String text = "DMG: " + String::num_int64(card.get_damage()) +
                      "\nBLK: " + String::num_int64(card.get_block()) +
                      "\nCOST: " + String::num_int64(card.get_energy_cost());

        card_button->set_text(text);
        card_container->add_child(card_button);
    }
}
