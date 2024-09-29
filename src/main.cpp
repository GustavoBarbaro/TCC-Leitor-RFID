#include <Arduino.h>
#include "botoes.h"
#include "menu.h"  // menu.h já declara extern lcd e a função de inicialização do display

#include <SPI.h>

void setup() {
    inicializar_display();  // Agora inicializa o LCD através da função modularizada
    configurar_botoes();
}

void loop() {

    ler_botoes();

    switch (menu_num) {
        case 1: Ler_Usuario(); break;
        case 2: Cadastrar_Produto(); break;
        case 3: Baixa_Produto(); break;
        case 4: Reset(); break;
    }
}