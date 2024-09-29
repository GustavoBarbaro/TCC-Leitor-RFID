#include <Arduino.h>
#include "botoes.h"
#include "menu.h"



void configurar_botoes() {
    pinMode(bt_r, INPUT_PULLUP);
    pinMode(bt_l, INPUT_PULLUP);
    pinMode(bt_e, INPUT_PULLUP);
    pinMode(bt_b, INPUT_PULLUP);
}

void ler_botoes() {
    if (!digitalRead(bt_r) && sub_menu == 1) {
        delay(150);
        if (menu_num <= menu_max) menu_num += 1;
    }
    if (!digitalRead(bt_l) && sub_menu == 1) {
        delay(150);
        if (menu_num > 0) menu_num -= 1;
    }
    if (!digitalRead(bt_e)) {
        delay(150);
        if (sub_menu <= 2) sub_menu += 1;
    }
    if (!digitalRead(bt_b)) {
        delay(150);
        if (sub_menu > 0) sub_menu -= 1;
    }
}
