#ifndef MENU_H
#define MENU_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;  // Declaração de lcd

extern int menu_num, sub_menu;
extern int erro_Usuario;

extern String tagLida, idProduto, idUsuario, movimentacao;

#define menu_max 4  // Número máximo de menus existentes

void inicializar_display();  // Função de inicialização do display
void Ler_Usuario();
void Cadastrar_Produto();
void Baixa_Produto();
void Reset();

#endif
