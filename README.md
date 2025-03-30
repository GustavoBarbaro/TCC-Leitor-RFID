[![OS - Windows](https://img.shields.io/badge/OS-Windows-blue?logo=windows&logoColor=white)](https://www.microsoft.com/ "Go to Microsoft homepage") [![GitHub Repo](https://img.shields.io/badge/GustavoBarbaro-TCC__Leitor__RFID-blue?style=flat&logo=github)](https://github.com/GustavoBarbaro/TCC-Leitor-RFID) [![License](https://img.shields.io/badge/License-MIT-yellow)](#license) [![Made with Python](https://img.shields.io/badge/Python-=3.12.3-blue?logo=python&logoColor=white)](https://python.org "Go to Python homepage") ![GitHub last commit](https://img.shields.io/github/last-commit/GustavoBarbaro/Sistema_Controle_Estoques_Django)

# Sistema de Controle de Estoque com Django


Este projeto é um Sistema de Controle de Estoque desenvolvido em Django e um ESP32 com interface responsiva em Bootstrap e suporte a leitura de RFID. Ele permite registrar movimentações de produtos (entradas e saídas), armazenando as informações em um banco de dados relacional.

Este repositório contém o código fonte do hardware, com o ESP32 e o leitor RFID

Para o código fonte da WEB Django com o banco de dados confira este repositório:


[![GitHub Repo](https://img.shields.io/badge/GustavoBarbaro-Sistema__Controle__Estoques__Django-blue?style=flat&logo=github)](https://github.com/GustavoBarbaro/Sistema_Controle_Estoques_Django)




---



# Tecnologias Utilizadas

### Backend
* ![Django](https://img.shields.io/badge/Django-092E20?style=for-the-badge&logo=django&logoColor=green)

### Frontend
* ![bootstrap](https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white)
* ![HTML](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
* ![CSS](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white
)

### Banco de Dados
* ![SQL_Lite](https://img.shields.io/badge/Sqlite-003B57?style=for-the-badge&logo=sqlite&logoColor=white)

### Hardware
* ![ESP](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
* 	![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

---

# Bibliotecas utilizadas


* ```miguelbalboa/MFRC522@^1.4.11``` Comunicação com o leitor RFID
* ```marcoschwartz/LiquidCrystal_I2C@^1.1.4``` Comunicação com Display LCD
* ```bblanchon/ArduinoJson@^7.2.0``` Manipulação JSON
* ```HTTPClient@1.2``` Envio de requisições HTTP


---

# Screenshots

<img src='https://github.com/user-attachments/assets/78c697ab-733d-44e6-a1cb-7781176dfdf2' width='700px' height='500px'>

![Homecomlogin](https://github.com/user-attachments/assets/00b9c2e1-201b-4c5b-8ddf-31642bf224ad)

![Log das Movimentacoes Menor](https://github.com/user-attachments/assets/0ebe9fda-f07e-479b-b3e4-14c9aded9e4a)

![Estoque Atual Menor](https://github.com/user-attachments/assets/2c6a9285-ce6e-4741-b18a-bcc75e4379e5)


# Funcionalidades

✅ Leitura de tags RFID em tempo real

✅ Envio de dados para um servidor via HTTP

✅ Conexão WiFi com ESP32

✅ Compatível com o framework Arduino

✅Cadastro de produto e usuários

✅Registro de entradas e saídas de produtos

✅Monitoramento de movimentações em tempo real com **WebSockets**

✅Integração com Leitor RFID por meio de *wi-fi* para leitura automática

✅Controle de usuários e permissões

---

# Componentes Utilizados

* ESP32 - DOIT DevKit V1
* Display LCD I2C
* Sensor RFID MFRC522
* Botão Push Button (4X)
* Conversor de nível lógico 4
* LEDs (2x)
* Resistores 100 Ohms (2x)
* Fios diversos
* Protoboard


---

# Diagrama Esquemático

![Esquematico V2](https://github.com/user-attachments/assets/33c05727-884f-4e78-b71e-eaf14b0e3e9a)


---

# Pinagem ESP32

| ESP32 (placa) | Atribuição via código | Destino | Componente |
|---|---|---|---|
| D23 | MOSI | MOSI | Sensor RFID |
| D19 | MISO | MISO | Sensor RFID |
| D18 | SCK | SCK | Sensor RFID |
| D5 | SS | SDA | Sensor RFID |
| D2 | GPIO | RST | Sensor RFID |
| D22 | SCL | SCL | Display LCD |
| D21 | SDA | SDA | Display LCD |
| TX0 | GPIO 1 | LV1 (LED Verde) | Conversor de Nível Lógico |
| RX0 | GPIO 3 | LV2 (LED Vermelho) | Conversor de Nível Lógico |
| D13 | GPIO 13 | BT1 | Botões |
| D33 | GPIO 33 | BT2 | Botões |
| D26 | GPIO 26 | BT3 | Botões |
| D25 | GPIO 25 | BT4 | Botões |

---

# Instalação

1️⃣ Clonar o repositório:

```bash
git clone https://github.com/GustavoBarbaro/TCC-Leitor-RFID.git
cd TCC-Leitor-RFID
```

2️⃣ Abra o Visual Studio Code

3️⃣ Instalar o PlatformIO como extenção do VSCode

4️⃣ Abrir o projeto pelo PlatformIO

Isso fará que a extensão PlatformIO que transforma o VSCode em uma IDE para embarcados instale as dependências automaticamente do arquivo ```platformio.ini```

5️⃣ Subir o código para o ESP32





---

# Banco de dados

<img src='https://github.com/user-attachments/assets/4a160b63-0d6c-4335-8273-fb8fb22fce53' width='800px' height='600px'>



---

# Demonstração

[YouTube](https://youtu.be/2zCVcu27XJM)

---

# Trabalho de Conclusão de Curso

[TCC - Gustavo-Comprimido.pdf](https://github.com/user-attachments/files/19526330/TCC.-.Gustavo-Comprimido.pdf)

---

# Palavras-chave


Django; Bootstrap; RFID; Banco de Dados; WebSockets; Backend Python; Fullstack Development; API REST; ESP32; RFID; IoT; HTTP; HTTP Requests; Arduino Framework; Automação; PlatformIO

