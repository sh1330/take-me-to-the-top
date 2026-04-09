#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    int enemy_hp;
    int enemy_block;
    int enemy_max_hp;

public:
    Enemy();
    ~Enemy() = default;

    int get_hp();
    int get_block();
    int get_max_hp();

    void gain_block(int amount);
    void gain_max_hp(int amount);
    void gain_hp(int amount);
    void lose_hp(int amount);
};
#endif
