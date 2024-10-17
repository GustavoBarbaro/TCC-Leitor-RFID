#ifndef WIFILIB_H
#define WIFILIB_H

#include <Arduino.h>
#include "WiFi.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "wifiLib.h"
#include "senha.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;  // Declaração de lcd

void wifi_Init();

String busca_id(String tag, int escolha);

String cria_movimentacao (String idUsuario, String idProduto, String tipo);

String checa_status (String idProduto);

String extractNumber(String jsonString);

String getCurrent_Date ();


#endif