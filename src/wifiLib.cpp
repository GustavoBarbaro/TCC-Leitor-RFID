#include <Arduino.h>

#include "WiFi.h"
#include <HTTPClient.h>

#include "wifiLib.h"
#include "senha.h"

void wifi_Init(){

    WiFi.begin(ssid, password);

    delay(5000);

    while (WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.println("Conectando...");
    }

    Serial.println("Conectado ao WiFi");
}

void busca_idProduto(){

    if (WiFi.status() == WL_CONNECTED){
        HTTPClient http;

        // http.begin("http://192.168.1.124:8000/api/produto/buscar/"); // Substitua pelo IP correto da máquina
        http.begin("http://127.0.0.1:8000/api/produto/buscar/"); // Substitua pelo IP correto da máquina
        http.addHeader("Content-Type", "application/json");      // Cabeçalho da requisição

        // Corpo da requisição com a tag RFID

        String requestBody = "{\"tag_rfid\":\"123\"}";

        int httpResponseCode = http.POST(requestBody);

        if (httpResponseCode > 0){
            String response = http.getString(); // Resposta do servidor
            Serial.println(httpResponseCode);
            Serial.println(response);
        }
        else{
            Serial.print("Erro na requisição: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    }

    delay(10000); // Aguarda 10 segundos antes de enviar nova requisição
}
