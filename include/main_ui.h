#ifndef MAIN_UI_H
#define MAIN_UI_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/button.hpp>

namespace godot {

class MainUI : public Control {
    GDCLASS(MainUI, Control)

private:
    Label *enemy_hp_lbl = nullptr;
    Label *player_hp_lbl = nullptr;
    Label *player_block_lbl = nullptr;
    Label *player_energy_lbl = nullptr;
    Label *status_lbl = nullptr;
    Button *end_turn_btn = nullptr;

    int player_hp = 30;
    int player_block = 0;
    int player_energy = 3;
    int enemy_hp = 20;

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