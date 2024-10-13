#include "RFID_Reader.h"


MFRC522 rfid(SS_PIN, RST_PIN); // Inicializa o MFRC522 com os pinos definidos
byte nuidPICC[MAX_BYTE]; // Armazena o UID do cartão
unsigned long cardID = 0; // Armazena o ID do cartão

void RFIDReader_Init() {
    SPI.begin(); // Inicia o barramento SPI
    rfid.PCD_Init(); // Inicializa o MFRC522
}

String RFIDReader_ReadCardID() {

    // Verifica se há um novo cartão presente
    /* if (!rfid.PICC_IsNewCardPresent()) {
        return ""; // Retorna string vazia se não houver cartão
    } */

    while (!rfid.PICC_IsNewCardPresent()) {
        delay(100);  // Evita loop excessivo e economiza CPU
    }

    // Lê o cartão
    if (!rfid.PICC_ReadCardSerial()) {
        return ""; // Retorna string vazia se não conseguir ler
    }

    // Constrói o ID do cartão como uma string hexadecimal
    String cardID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        if (rfid.uid.uidByte[i] < 0x10) {
            cardID += "0"; // Adiciona zero à esquerda se necessário
        }
        cardID += String(rfid.uid.uidByte[i], HEX); // Concatena os bytes em hexadecimal
    }

    // Para o cartão e interrompe a criptografia
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    return cardID; // Retorna o ID do cartão em hexadecimal
}