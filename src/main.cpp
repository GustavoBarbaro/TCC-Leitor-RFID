#include <Arduino.h>
#include "botoes.h"
#include "menu.h"  // menu.h já declara extern lcd e a função de inicialização do display
#include "RFID_Reader.h" //já declara a biblioteca e inicia o rfid
#include "wifiLib.h"

void setup() {

    Serial.begin(9600);

    inicializar_display();
    configurar_botoes();

    RFIDReader_Init();
    wifi_Init();
}

void loop() {


    /* String cardID = RFIDReader_ReadCardID(); // Lê o ID do cartão e armazena na variável

    // Verifica se algum cartão foi lido
    if (cardID != "") {
        Serial.print("Card UID: ");
        Serial.println(cardID); // Exibe o ID do cartão no monitor serial
    } */


    ler_botoes();

    switch (menu_num) {
        case 1: Ler_Usuario(); break;
        case 2: Cadastrar_Produto(); break;
        case 3: Baixa_Produto(); break;
        case 4: Reset(); break;
    }
}