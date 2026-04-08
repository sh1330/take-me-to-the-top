#include "main_ui.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

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
    player_hp_lbl = get_node<Label>("PlayerHpLabel");
    player_block_lbl = get_node<Label>("PlayerBlockLabel");
    player_energy_lbl = get_node<Label>("PlayerEnergyLabel");
    status_lbl = get_node<Label>("StatusLabel");
    end_turn_btn = get_node<Button>("EndTurnButton");

    if (!enemy_hp_lbl || !player_hp_lbl || !player_block_lbl ||
        !player_energy_lbl || !status_lbl || !end_turn_btn) {
        UtilityFunctions::printerr("MainUI: one or more UI nodes were not found.");
        return;
    }

    end_turn_btn->connect("pressed", Callable(this, "_on_end_turn_pressed"));

    update_labels();
    status_lbl->set_text("Player turn");
}

void MainUI::update_labels() {
    if (!enemy_hp_lbl || !player_hp_lbl || !player_block_lbl ||
        !player_energy_lbl || !status_lbl) {
        return;
    }

    enemy_hp_lbl->set_text("Enemy HP: " + String::num_int64(enemy_hp));
    player_hp_lbl->set_text("Player HP: " + String::num_int64(player_hp));
    player_block_lbl->set_text("Block: " + String::num_int64(player_block));
    player_energy_lbl->set_text("Energy: " + String::num_int64(player_energy));
}

void MainUI::_on_end_turn_pressed() {
    status_lbl->set_text("Enemy turn");

    int incoming_damage = 6;

    if (player_block >= incoming_damage) {
        player_block -= incoming_damage;
    } else {
        int damage_left = incoming_damage - player_block;
        player_block = 0;
        player_hp -= damage_left;
    }

    player_energy = 3;

    update_labels();

    if (player_hp <= 0) {
        status_lbl->set_text("You Lose");
        end_turn_btn->set_disabled(true);
        return;
    }

    status_lbl->set_text("Player turn");
}
