#ifndef MAIN_UI_H
#define MAIN_UI_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/button.hpp>

#include "player.h"
#include "enemy.h"
#include "card.h"
#include "deck.h"

namespace godot {

class MainUI : public Control {
    GDCLASS(MainUI, Control)

private:
    Label *enemy_hp_lbl = nullptr;
    Label *player_hp_lbl = nullptr;
    Label *player_block_lbl = nullptr;
    Label *player_energy_lbl = nullptr;
    Label *status_lbl = nullptr;
    Label *enemy_block_lbl = nullptr;
    Button *end_turn_btn = nullptr;

    Player player;
    Enemy enemy;

protected:
    static void _bind_methods();

public:
    MainUI();
    ~MainUI();

    void _ready();
    void update_labels();
    void _on_end_turn_pressed();
};

} // namespace godot

#endif
