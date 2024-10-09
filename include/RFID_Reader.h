#ifndef RFID_READER_H
#define RFID_READER_H

#include <SPI.h>
#include <MFRC522.h>

// Definições dos pinos
#define SS_PIN 5
#define RST_PIN 2

#define MAX_BYTE 7




void RFIDReader_Init();
String RFIDReader_ReadCardID();

#endif
