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

String busca_id(String tag, int escolha){

    if (WiFi.status() == WL_CONNECTED){
        HTTPClient http;

        if (escolha == 1){ //produto
            http.begin("http://192.168.1.124:8000/api/produto/buscar/");

        } else if (escolha == 2){ //usuario
            http.begin("http://192.168.1.124:8000/api/usuario/buscar/");
        }
        

        http.addHeader("Content-Type", "application/json");      // Cabeçalho da requisição

        // Corpo da requisição com a tag RFID

        String requestBody = "{\"tag_rfid\":\"" + tag + "\"}";

        int httpResponseCode = http.POST(requestBody);

        if (httpResponseCode > 0){
            String response = http.getString(); // Resposta do servidor
            // Serial.println(httpResponseCode);
            // Serial.println(response);
            http.end();
            return extractNumber(response);
        }
        else{
            // Serial.print("Erro na requisição: ");
            // Serial.println(httpResponseCode);
            http.end();
            return "Erro na requisicao";
        }
    } else {
        return "Nao conectado ao WIFI";
    }

}


String extractNumber(String jsonString) {
    //Esse codigo eh util para extrair toda a resposta do http

    // Localiza a posição do ":" e da "}"
    int startIndex = jsonString.indexOf(":") + 2; // +2 para pular o ":" e o espaço
    int endIndex = jsonString.indexOf("}");

    // Extrai a parte numérica da string
    String number = jsonString.substring(startIndex, endIndex);

    return number;
}
