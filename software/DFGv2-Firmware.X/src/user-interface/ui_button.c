#include "user-interface/ui_button.h"

void ui_button_set_state(struct ui_button_t *button, enum button_state state)
{
    button->prev_state = button->state;
    button->state = state;
}
