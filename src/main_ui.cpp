#include "main_ui.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/h_box_container.hpp>

using namespace godot;

void MainUI::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_end_turn_pressed"), &MainUI::_on_end_turn_pressed);
    ClassDB::bind_method(D_METHOD("update_labels"), &MainUI::update_labels);
    ClassDB::bind_method(D_METHOD("_on_card_pressed", "index"), &MainUI::_on_card_pressed);
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

    deck.add_card(Card(6, 0, 1, false, Draw));
    deck.add_card(Card(0, 5, 1, false, Draw));
    deck.add_card(Card(6, 0, 1, false, Draw));
    deck.add_card(Card(0, 5, 1, false, Draw));
    deck.add_card(Card(10, 0, 2, false, Draw));
    deck.add_card(Card(10, 0, 2, false, Draw));

    deck.put_5_draw_cards_in_hand();
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
    deck.put_5_draw_cards_in_hand();
    update_card_display();
}

void MainUI::_on_card_pressed(int index) {
    std::vector<Card>& cards = deck.get_mut_cards();

    if (index < 0 || index >= (int)cards.size()) {
        UtilityFunctions::printerr("Invalid index");
        return;
    }

    for (size_t i = 0; i < cards.size(); i++) {
        cards[i].set_selected(false);
    }

    cards[index].set_selected(true);

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

    Array children = card_container->get_children();
    for (int i = 0; i < children.size(); i++) {
        Node *child = Object::cast_to<Node>(children[i]);
        if (child) {
            child->queue_free();
        }
    }

    const std::vector<Card> &cards = deck.get_cards();

    for (size_t i = 0; i < cards.size(); i++) {
        if (cards[i].get_which_pile() == Hand) {
            Button *card_button = memnew(Button);

            String text = "DMG: " + String::num_int64(cards[i].get_damage()) +
                          "\nBLK: " + String::num_int64(cards[i].get_block()) +
                          "\nCOST: " + String::num_int64(cards[i].get_energy_cost());

            card_button->set_text(text);

            Callable pressed_callable = Callable(this, "_on_card_pressed").bind((int)i);
            card_button->connect("pressed", pressed_callable);

            card_container->add_child(card_button);
        }
    }
}
