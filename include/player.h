
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int player_hp;
    int player_block;
    int player_energy;
    int player_max_hp;

public:
    Player();
    ~Player();

    int get_hp();
    int get_block();
    int get_energy();

    void reset_energy();
    void gain_block(int amount);
    void gain_energy();
    void gain_max_hp(int amount);
    void gain_hp(int amount);
};
#endif
