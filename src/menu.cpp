#include <Arduino.h>
#include "menu.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RFID_Reader.h"
#include "wifiLib.h"

// Inicializa o objeto lcd
LiquidCrystal_I2C lcd(0x27, 20, 4);  

int menu_num = 1;
int sub_menu = 1;

String tagLida = "", idProduto = "", idUsuario = "";


void inicializar_display() {
    lcd.init();  // Inicializa o LCD
    lcd.backlight();  // Ativa a luz de fundo
}

void Ler_Usuario() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("  Ler Usuario  >");
            lcd.setCursor(0, 1);
            lcd.print("                ");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");




            delay(900);
            tagLida = "";
            tagLida = RFIDReader_ReadCardID();

            
            // wifi consultar tag
            idUsuario = busca_id(tagLida, 2);

            Serial.println(idUsuario);

            //preciso ver se ele achou o usuario ou não
            if (idUsuario == "\"Usuario nao encontrado\""){
                lcd.setCursor(0, 0);
                lcd.print("Usuario         ");
                lcd.setCursor(0, 1);
                lcd.print("Desconhecido !  ");
            } else if (idUsuario == "\"Formato JSON invalido\"" || idUsuario == "\"Campo tag_rfid nao fornecido\""){
                lcd.setCursor(0, 0);
                lcd.print("Erro na leitura!");
                lcd.setCursor(0, 1);
                lcd.print("                ");
            }else {
                lcd.setCursor(0, 0);
                lcd.print("Usuario lido com");
                lcd.setCursor(0, 1);
                lcd.print("Sucesso !       ");
            }







            
            delay(3000);



            sub_menu -=1;
            break;
    }
}

void Cadastrar_Produto() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("< Cadastrar     ");
            lcd.setCursor(0, 1);
            lcd.print("    Produto    >");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");

            //ler a tag
            //delay para dar tempo da pessoa posicionar o leitor
            delay(900);
            tagLida = "";
            tagLida = RFIDReader_ReadCardID();

            
            // wifi consultar tag
            idProduto = busca_id(tagLida, 1);

            






            sub_menu -=1;
            break;
    }
}

void Baixa_Produto() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("< Baixa         ");
            lcd.setCursor(0, 1);
            lcd.print("    Produto    >");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");
            break;
    }
}

void Reset() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("<     Reset     ");
            lcd.setCursor(0, 1);
            lcd.print("                ");
            break;
        case 2:
            lcd.setCursor(0, 0);
            lcd.print("Aguardando      ");
            lcd.setCursor(0, 1);
            lcd.print("      leitura...");
            break;
    }
}