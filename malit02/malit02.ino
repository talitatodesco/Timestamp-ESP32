//TIMESTAMP: ACIONAMENTO LED POR TEMPO

//Bibliotecas
#include <NTPClient.h>  // Biblioteca do NTP.
#include <WiFi.h>       // Biblioteca do WiFi.

//Conexão com wifi
const char* ssid = "***************";
const char* password = "********";

// --------------Configuração de relógio online -------------------
const char* ntpServer1 = "c.st1.ntp.br"; //Endereço 1
const char* ntpServer2 = "pool.ntp.org";//Endereço 1
const long gmtOffset_sec = 0; 
const int daylightOffset_sec = -3600*3;


struct tm timeinfo;


#define led 2

void printLocalTime() {

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Não foi possivel obter o tempo");
    return;
  } //Caso não consiga buscar o horario
  Serial.println(&timeinfo, "%H:%M");  //Saida horario monitor serial

  delay(1000);
}


void setup() {
  Serial.begin(115200);


  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2); //Configuração Time

  pinMode(led, OUTPUT);  //Define o pino como saída
  //digitalWrite(led, LOW);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  
  Serial.println(" WIFI CONECTADO!");
  delay(1000);
}

void loop() {
  
  if (timeinfo.tm_hour == 19 && timeinfo.tm_min == 47) { 
    digitalWrite(led, HIGH);  
   }
   if (timeinfo.tm_hour == 19 && timeinfo.tm_min == 50) 
   { 
     digitalWrite(led, LOW); 
   }

  delay(1000);
  printLocalTime();
}