#include "menu.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o objeto lcd
LiquidCrystal_I2C lcd(0x27, 20, 4);  

int menu_num = 1;
int sub_menu = 1;

void inicializar_display() {
    lcd.init();  // Inicializa o LCD
    lcd.backlight();  // Ativa a luz de fundo
}

void Ler_Usuario() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("  Ler Usuario  >");
            lcd.setCursor(0, 1);
            lcd.print("                ");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");
            break;
    }
}

void Cadastrar_Produto() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("< Cadastrar     ");
            lcd.setCursor(0, 1);
            lcd.print("    Produto    >");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");
            break;
    }
}

void Baixa_Produto() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("< Baixa         ");
            lcd.setCursor(0, 1);
            lcd.print("    Produto    >");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");
            break;
    }
}

void Reset() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("<     Reset     ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");
            break;
    }
}