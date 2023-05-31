/*
  Julio 
  Sensor de temperatura e umidade com lcd

  */ 
// ===============================================================================
// --- Biblioteca Auxiliar ---
#include <dht.h>   //biblioteca do sensor de umidade e temperatura
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // biblioteca modulo i2c

// ===============================================================================
// --- Mapeamento de Hardware ---
#define    dht_pin    5   //pino de sinal do dht11 ligado no digital 5


// ===============================================================================
// --- Declaração de Objetos ---
dht   my_dht;   //objeto para o sensor
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

// ===============================================================================
// --- Variáveis Globais ---
int    temperatura = 0x00,   //armazena a temperatura em inteiro
       umidade     = 0x00;   //armazena a umidade em inteiro


// ===============================================================================
// --- Configurações Iniciais ---
void setup() 
{
   lcd.begin(16,2);   //Inicia do Display


} //end setup


// ===============================================================================
// --- Loop Infinito ---
void loop() 
{
   my_dht.read11(dht_pin); // faz a leitura do sensor 

   temperatura = my_dht.temperature; // utiliza o comando especifico de controle da temperatura"TEMPERETURE"
   umidade     = my_dht.humidity;    // utiliza o comando especifico de controle de umidade"HU<IDITY"


lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("TEMPAERATURA");
  lcd.setCursor(13,0);
  lcd.print(temperatura);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Umidade");
  lcd.setCursor(12,1);
  lcd.print(umidade);
  lcd.print("%");
  delay(1000);


 


} //end loop





















