#ifndef WIFILIB_H
#define WIFILIB_H

#include <Arduino.h>
#include "WiFi.h"
#include <HTTPClient.h>

#include "wifiLib.h"
#include "senha.h"

void wifi_Init();

void busca_id(String tag, int escolha);


#endif