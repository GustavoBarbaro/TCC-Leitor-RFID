#ifndef BOTOES_H
#define BOTOES_H


#define bt_r 25   // botão direita
#define bt_l 13   // botão esquerda
#define bt_e 26   // botão enter
#define bt_b 33   // botão voltar

#define led_red 3 //Led vermelho
#define led_blue 1 //Led azul

extern int menu_num, sub_menu;


void configurar_botoes();
void ler_botoes();

#endif