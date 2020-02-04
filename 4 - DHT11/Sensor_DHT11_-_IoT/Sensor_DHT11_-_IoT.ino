//... Livro IoT na Prática - PROGRAMA 4 - Monitoramento do sensor DHT11 ...//

#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN A1
DHT SENSOR_DHT11(DHTPIN, DHTTYPE);

//............. BLOCO 1 - NOMEAR PINOS USADOS NO PROJETO .............//

float umidade_ar = 0;
float temperatura = 0;

int LED1 = 6;         
int LED2 = 7;         
int LED3 = 8;         
int LED4 = 9;        
int LED5 = 10;       
int LED6 = 11;   
                    
//............. BLOCO 2 - CONFIGURAR PINOS USADOS NO PROJETO .............//
void setup() 
{
  SENSOR_DHT11.begin();
  pinMode(LED1, OUTPUT);          // Configura o GPIO 25 do ESP32 como saída
  pinMode(LED2, OUTPUT);          // Configura o GPIO 26 do ESP32 como saída
  pinMode(LED3, OUTPUT);          // Configura o GPIO 27 do ESP32 como saída
  pinMode(LED4, OUTPUT);          // Configura o GPIO 14 do ESP32 como saída
  pinMode(LED5, OUTPUT);          // Configura o GPIO 12 do ESP32 como saída
  pinMode(LED6, OUTPUT);          // Configura o GPIO 13 do ESP32 como saída
  Serial.begin(9600);
}
//......... BLOCO 3 - REPETIÇÃO DAS TAREFAS USADAS NO PROJETO ...........//
void loop() 
{
  umidade_ar = SENSOR_DHT11.readHumidity();     // requisita medição de umidade do sensor DHT11
  temperatura = SENSOR_DHT11.readTemperature(); // requisita medição de temperatura do sensor DHT11
  
  // Neste teste, é possível detectar se existiu algum erro de medição de temperatura ou umidade
  // Se algum erro aconteceu, o comando return faz com que todo o código abaixo seja desprezado
  // e volta ao início do loop()
  if (isnan(umidade_ar) || isnan(temperatura)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(umidade_ar);
  Serial.print("%  Temperature: ");
  Serial.print(temperatura);
  Serial.println("°C ");

  if(temperatura < 5)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
  }
  else if(temperatura > 5 && temperatura < 10)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
  }
  else if(temperatura > 10 && temperatura < 20)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
  }
  else if(temperatura > 20 && temperatura < 30)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
  }
  else if(temperatura > 30 && temperatura < 35)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,HIGH);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
  }
  else if(temperatura > 35 && temperatura < 45)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,HIGH);
    digitalWrite(LED5,HIGH);
    digitalWrite(LED6,LOW);
  }
  else if(temperatura > 45)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,HIGH);
    digitalWrite(LED5,HIGH);
    digitalWrite(LED6,HIGH);
  }
  delay(2000);   
  
}
 
