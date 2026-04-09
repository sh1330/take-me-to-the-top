
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int player_hp;
    int player_block;
    int player_energy;
    int player_max_hp;
    int player_max_energy;

public:
    Player();
    ~Player() = default;

    int get_hp();
    int get_block();
    int get_energy();
    int get_max_hp();
    int get_max_energy();

    void reset_energy();
    void gain_block(int amount);
    void gain_energy(int amount);
    void gain_max_hp(int amount);
    void gain_hp(int amount);
    void lose_hp(int amount);
};
#endif
