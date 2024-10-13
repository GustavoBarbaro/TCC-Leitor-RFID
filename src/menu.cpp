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

int erro_Usuario = 0;

String tagLida = "", idProduto = "", idUsuario = "", movimentacao = "";


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


            //delay(900);
            tagLida = "";
            tagLida = RFIDReader_ReadCardID();

            // wifi consultar tag
            idUsuario = busca_id(tagLida, 2);

            //preciso ver se ele achou o usuario ou não
            if (idUsuario == "\"Usuario nao encontrado\""){
                lcd.setCursor(0, 0);
                lcd.print("Usuario         ");
                lcd.setCursor(0, 1);
                lcd.print("Desconhecido !  ");
                erro_Usuario = 0;
            } else if (idUsuario == "\"Formato JSON invalido\"" || idUsuario == "\"Campo tag_rfid nao fornecido\""){
                lcd.setCursor(0, 0);
                lcd.print("Erro na leitura!");
                lcd.setCursor(0, 1);
                lcd.print("                ");
                erro_Usuario = 0;
            }else {
                lcd.setCursor(0, 0);
                lcd.print("Usuario lido com");
                lcd.setCursor(0, 1);
                lcd.print("Sucesso !       ");
                erro_Usuario = 1;
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
            
            Baixa_ou_Cadastra("Cadastrar");

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
            
            Baixa_ou_Cadastra("Baixa");

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


void Baixa_ou_Cadastra (String tipo){

    if(erro_Usuario == 0){
        lcd.setCursor(0, 0);
        lcd.print("Leia Usuario    ");
        lcd.setCursor(0, 1);
        lcd.print("Primeiro !      ");
        delay(3000);
        sub_menu -=1;

    } else {
        lcd.setCursor(0, 0);
        lcd.print("Aguardando      ");
        lcd.setCursor(0, 1);
        lcd.print("      leitura...");

        //ler a tag
        //delay para dar tempo da pessoa posicionar o leitor
        //delay(900);
        tagLida = "";
        tagLida = RFIDReader_ReadCardID();

        
        // wifi consultar tag
        idProduto = busca_id(tagLida, 1);

        
        //preciso ver se ele achou o produto ou não
        if (idProduto == "\"Produto nao encontrado\""){
            lcd.setCursor(0, 0);
            lcd.print("Produto         ");
            lcd.setCursor(0, 1);
            lcd.print("Desconhecido !  ");
        } else if (idProduto == "\"Formato JSON invalido\"" || idProduto == "\"Campo tag_rfid nao fornecido\""){
            lcd.setCursor(0, 0);
            lcd.print("Erro na leitura!");
            lcd.setCursor(0, 1);
            lcd.print("                ");

        }else {
            //achou o ID do produto e do usuario, pode cadastrar ou dar baixa

            if (tipo == "Cadastrar"){
                movimentacao = cria_movimentacao (idUsuario, idProduto, "Entrada"); //esse entrada e saida sao os que vao na API

            } else if (tipo == "Baixa"){
                movimentacao = cria_movimentacao (idUsuario, idProduto, "Saida");
            }

            //Analisar as respostas
            if (movimentacao == "\"O Produto ja esta no estoque\""){
                lcd.setCursor(0, 0);
                lcd.print("Produto no      ");
                lcd.setCursor(0, 1);
                lcd.print("Estoque         ");

            } else if (movimentacao == "\"O Produto nao esta no estoque\"") {
                lcd.setCursor(0, 0);
                lcd.print("Produto fora do ");
                lcd.setCursor(0, 1);
                lcd.print("Estoque         ");
                    

            } else if (movimentacao == "\"Movimentacao criada com sucesso\"") {
                lcd.setCursor(0, 0);

                if (tipo == "Cadastrar"){
                    lcd.print("Cadastrado com  ");

                } else if (tipo == "Baixa"){
                    lcd.print("Retirado com    ");
                }
                lcd.setCursor(0, 1);
                lcd.print("Sucesso !       ");
            }
        }

        delay(3000);

        sub_menu -=1;
    }
}