#include "enemy.h"

Enemy::Enemy()
    : enemy_hp(50),
    enemy_block(0),
    enemy_max_hp(50) {

    }

//getters
int Enemy::get_hp() {return enemy_hp;}
int Enemy::get_block() {return enemy_block;}
int Enemy::get_max_hp() {return enemy_max_hp;}

//setters
void Enemy::gain_block(int amount) {
    enemy_block += amount;
}

void Enemy::gain_max_hp(int amount) {
    enemy_max_hp += amount;
}

void Enemy::gain_hp(int amount) {
    enemy_hp += amount;
}

void Enemy::lose_hp(int amount) {
    if (enemy_block > 0) {
            amount -= enemy_block;
    }
    if (amount < 0) {
        amount = 0;
    }
    enemy_hp -= amount;
}
 

