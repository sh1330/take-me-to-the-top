#include "player.h"

Player::Player()
    : player_hp(30),
    player_block(0),
    player_energy(3),
    player_max_hp(30),
    player_max_energy(3),
    is_turn(true){
}

//getters
int Player::get_hp() {
    return player_hp;
}

int Player::get_block() {
    return player_block;
}

int Player::get_energy() {
    return player_energy;
}

int Player::get_max_hp() {
    return player_max_hp;
}

int Player::get_max_energy() {
    return player_max_energy;
}

bool Player::get_is_turn() {
    return is_turn;
}

//setters
void Player::reset_energy() {
    player_energy = player_max_energy;
}

void Player::gain_block(int amount) {
    player_block += amount;
}

void Player::gain_energy(int amount) {
    player_max_energy += amount;
}

void Player::gain_max_hp(int amount) {
    player_max_hp += amount;
}

void Player::gain_hp(int amount) {
    player_hp += amount;
}

void Player::lose_hp(int amount) {
    player_hp -= amount;
}


