#include "RFID_Reader.h"


MFRC522 rfid(SS_PIN, RST_PIN); // Inicializa o MFRC522 com os pinos definidos
byte nuidPICC[MAX_BYTE]; // Armazena o UID do cartão
unsigned long cardID = 0; // Armazena o ID do cartão

void RFIDReader_Init() {
    SPI.begin(); // Inicia o barramento SPI
    rfid.PCD_Init(); // Inicializa o MFRC522
}

unsigned long RFIDReader_ReadCardID() {
    // Verifica se há um novo cartão presente
    if (!rfid.PICC_IsNewCardPresent()) {
        return 0; // Retorna 0 se não houver cartão
    }

    // Lê o cartão
    if (!rfid.PICC_ReadCardSerial()) {
        return 0; // Retorna 0 se não conseguir ler
    }

    // Constrói o ID do cartão
    cardID = 0;
    for (byte i = 0; i < rfid.uid.size; i++) {
        cardID = (cardID << 8) | rfid.uid.uidByte[i]; // Concatena os bytes do UID
    }

    // Para o cartão e interrompe a criptografia
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    return cardID; // Retorna o ID do cartão
}
