#include <Arduino.h>

#include "WiFi.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "wifiLib.h"
#include "senha.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuração do servidor NTP e fuso horário
const char* ntpServer = "pool.ntp.org";  // Servidor NTP público
const long  gmtOffset_sec = -10800;      // Offset GMT-3 (Horário de Brasília)
const int   daylightOffset_sec = 3600;   // Horário de verão (se aplicável)


void wifi_Init(){

    WiFi.begin(ssid, password);

    delay(5000);

    while (WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.println("Conectando...");
    }

    //configurando Relogio
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    Serial.println("Conectado ao WiFi");

    lcd.setCursor(0, 0);
    lcd.print("Conectado ao    ");
    lcd.setCursor(0, 1);
    lcd.print("WIFI !          ");
    delay(2000);
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

String cria_movimentacao (String idUsuario, String idProduto, String tipo){


    // Criação do buffer para armazenar o JSON
    JsonDocument doc;

    doc["produto_id"] = idProduto;
    doc["usuario_id"] = idUsuario;
    doc["data"] = getCurrent_Date();
    doc["tipo"] = tipo;

    // Serializando o objeto para uma string JSON
    String jsonBuffer;

    serializeJson(doc, jsonBuffer);

    //agora falta enviar a requisicao http

    if (WiFi.status() == WL_CONNECTED){
        HTTPClient http;

        http.begin("http://192.168.1.124:8000/api/movimentacao/");
        

        http.addHeader("Content-Type", "application/json");      // Cabeçalho da requisição

        int httpResponseCode = http.POST(jsonBuffer);

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


    return "";
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


String getCurrent_Date (){

    // Estrutura para armazenar a data e hora
    struct tm timeinfo;

    // Verifica se o tempo foi obtido com sucesso
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Erro ao obter o tempo.");
        return String("Erro");
    }

    // Formata a data como "YYYY-MM-DD"
    char dataFormatada[11];  // YYYY-MM-DD + '\0'
    strftime(dataFormatada, sizeof(dataFormatada), "%Y-%m-%d", &timeinfo);

    return String(dataFormatada);

}