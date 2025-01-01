#include "BluetoothSerial.h"

// Definições dos pinos dos motores
#define IN1_A 25
#define IN2_A 26
#define IN1_B 32
#define IN2_B 33





BluetoothSerial SerialBT;
char ch;

void setup() {

  Serial.begin(115200);
  SerialBT.begin("ATOM");  // Nome do dispositivo Bluetooth
  Serial.println("O dispositivo foi iniciado, agora você pode controlar!");

  // Configuração dos pinos dos motores como OUTPUT
  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);
  pinMode(IN1_B, OUTPUT);
  pinMode(IN2_B, OUTPUT);

  
}



void loop() {
  
  // Controle via Bluetooth
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
    ch = SerialBT.read();
    switch (ch) {
      case 'f':  // Frente
        andarFrente();
        break;
      case 'b':  // Trás
        andarTras();
        break;
      case 'l':  // Esquerda
        virarEsquerda();
        break;
      case 'r':  // Direita
        virarDireita();
        break;
      case 's':  // Parar
        parar();
        break;
      case 'p':  // Provocar
        provocar();
        break;
    }
  }
}

// Função para andar para frente
void andarFrente() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, HIGH);
  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
}

// Função para andar para trás
void andarTras() {
  digitalWrite(IN1_A, HIGH);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);
}

void andarTrasInfra() {
  digitalWrite(IN1_A, HIGH);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, HIGH);
}

// Função para virar à esquerda
void virarEsquerda() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, HIGH);
  digitalWrite(IN2_B, LOW);
}

// Função para virar à direita
void virarDireita() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, HIGH);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, LOW);
}

// Função para parar
void parar() {
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, LOW);
  digitalWrite(IN2_B, LOW);
}

// Função para provocar
void provocar() {
  digitalWrite(IN1_B, HIGH);
  delay(1000);
  digitalWrite(IN1_B, LOW);

  digitalWrite(IN2_A, HIGH);
  delay(2000);
  digitalWrite(IN2_A, LOW);

  digitalWrite(IN2_A, HIGH);
  digitalWrite(IN1_B, HIGH);
  delay(1000);
  digitalWrite(IN2_A, LOW);
  digitalWrite(IN1_B, LOW);

  digitalWrite(IN1_A, HIGH);
  digitalWrite(IN2_B, HIGH);
  delay(2000);
  digitalWrite(IN1_A, LOW);
  digitalWrite(IN2_B, LOW);
}
