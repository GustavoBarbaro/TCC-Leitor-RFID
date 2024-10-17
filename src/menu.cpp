#include <Arduino.h>
#include "botoes.h"
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
                digitalWrite(led_red, HIGH);
                erro_Usuario = 0;
            } else if (idUsuario == "\"Formato JSON invalido\"" || idUsuario == "\"Campo tag_rfid nao fornecido\""){
                lcd.setCursor(0, 0);
                lcd.print("Erro na leitura!");
                lcd.setCursor(0, 1);
                lcd.print("                ");
                digitalWrite(led_red, HIGH);
                erro_Usuario = 0;
            }else {
                lcd.setCursor(0, 0);
                lcd.print("Usuario lido com");
                lcd.setCursor(0, 1);
                lcd.print("Sucesso !       ");
                erro_Usuario = 1;
                digitalWrite(led_green, HIGH);
            }

            delay(3000);
            digitalWrite(led_red, LOW);
            digitalWrite(led_green, LOW);

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
            
            Baixa_Cadastra_Status("Cadastrar");

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
            
            Baixa_Cadastra_Status("Baixa");

            break;
    }
}

//talvez colocar um consultar estado ?
void Reset() {
    switch(sub_menu) {
        case 1:
            lcd.setCursor(0, 0);
            lcd.print("< Checa         ");
            lcd.setCursor(0, 1);
            lcd.print("    Status      ");
            break;
        case 2:

            Baixa_Cadastra_Status("Status");
            
            break;
    }
}


void Baixa_Cadastra_Status (String tipo){

    if(erro_Usuario == 0){
        lcd.setCursor(0, 0);
        lcd.print("Leia Usuario    ");
        lcd.setCursor(0, 1);
        lcd.print("Primeiro !      ");
        digitalWrite(led_red, HIGH);
        delay(3000);
        sub_menu -=1;

    } else {
        lcd.setCursor(0, 0);
        lcd.print("Aguardando      ");
        lcd.setCursor(0, 1);
        lcd.print("      leitura...");

        //ler a tag
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
            digitalWrite(led_red, HIGH);
        } else if (idProduto == "\"Formato JSON invalido\"" || idProduto == "\"Campo tag_rfid nao fornecido\""){
            lcd.setCursor(0, 0);
            lcd.print("Erro na leitura!");
            lcd.setCursor(0, 1);
            lcd.print("                ");
            digitalWrite(led_red, HIGH);

        }else {
            //achou o ID do produto e do usuario, pode cadastrar ou dar baixa ou checar status

            if (tipo == "Cadastrar"){
                movimentacao = cria_movimentacao (idUsuario, idProduto, "Entrada"); //esse entrada e saida sao os que vao na API

            } else if (tipo == "Baixa"){
                movimentacao = cria_movimentacao (idUsuario, idProduto, "Saida");
            } else if (tipo == "Status"){
                movimentacao = checa_status (idProduto);
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

                if (tipo == "Cadastrar"){//esse cadastrar eu mando na funcao
                    lcd.print("Cadastrado com  ");

                } else if (tipo == "Baixa"){
                    lcd.print("Retirado com    ");
                }
                lcd.setCursor(0, 1);
                lcd.print("Sucesso !       ");
                digitalWrite(led_green, HIGH);
            }
        }

        delay(3000);

        sub_menu -=1;
    }
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
}