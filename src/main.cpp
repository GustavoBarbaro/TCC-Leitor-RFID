#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

#define   bt_r   25   //botão direita
#define   bt_l   13   //botão esquerda
#define   bt_e   26   //botão enter
#define   bt_b   33   //botão voltar

#define   menu_max   4                  //número máximo de menus existentes
// LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidCrystal_I2C lcd(0x27,20,4);

void ler_botoes();

void Ler_Usuario();
void Cadastrar_Produto();
void Baixa_Produto();
void Reset();


int menu_num = 1, sub_menu = 1, submenu1 = 1;


void setup() {
  // put your setup code here, to run once:
  lcd.init();

  pinMode(bt_r, INPUT_PULLUP);
  pinMode(bt_l, INPUT_PULLUP);
  pinMode(bt_e, INPUT_PULLUP);
  pinMode(bt_b, INPUT_PULLUP);

  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:


  ler_botoes();

  switch(menu_num){
    case 1: Ler_Usuario(); break;
    case 2: Cadastrar_Produto(); break;
    case 3: Baixa_Produto(); break;
    case 4: Reset(); break;
  }

}



void ler_botoes()
{
   if(!digitalRead(bt_r) && sub_menu == 1){
      delay(150);
      if(menu_num <= menu_max) menu_num += 1;
    
   } //end bt_r

   if(!digitalRead(bt_l) && sub_menu == 1){
      delay(150);
      if(menu_num > 0) menu_num -= 1;
    
   } //end bt_l

   if(!digitalRead(bt_e)){
      delay(150);
      if(sub_menu <= 2) sub_menu += 1;
    
   } //end bt_e

   if(!digitalRead(bt_b)){
      delay(150);
      if(sub_menu > 0) sub_menu -= 1;
    
   } //end bt_b
   
  
} //end keyboard

void Ler_Usuario(){
  switch(sub_menu){
    case 1:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Ler Usuario  >");
      lcd.setCursor(0,1);
      lcd.print("                ");
      break;
      
    case 2:
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Aguardando      ");
      lcd.setCursor(0,1);
      lcd.print("      leitura...");
      break;
  }
}

void Cadastrar_Produto(){
  switch(sub_menu){
    case 1:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("< Cadastrar     ");
      lcd.setCursor(0,1);
      lcd.print("    Produto    >");
      break;
      
    case 2:
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Aguardando      ");
      lcd.setCursor(0,1);
      lcd.print("      leitura...");
      break;
  }
}


void Baixa_Produto(){
  switch(sub_menu){
    case 1:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("< Baixa         ");
      lcd.setCursor(0,1);
      lcd.print("    Produto    >");
      break;
      
    case 2:
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Aguardando      ");
      lcd.setCursor(0,1);
      lcd.print("      leitura...");
      break;
  }
}

void Reset(){
  switch(sub_menu){
    case 1:
      //lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("<     Reset     ");
      lcd.setCursor(0,1);
      lcd.print("                ");
      break;
      
    case 2:
      //lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Aguardando      ");
      lcd.setCursor(0,1);
      lcd.print("      leitura...");
      break;
  }
}







