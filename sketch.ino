// proses include library 
#include "DHTesp.h"

// deklarasi variable
// set pin yang digunakan
#define DHTPIN 15

// deklarasi object sensor
// set tipe DHT dan pin yang digunakan
DHTesp dht;
const int pinLED = 23;
void setup() {
  // put your setup code here, to run once:
  // inisiasi interface serial
  // deklarasi interface serial
  Serial.begin(115200);

  Serial.println(" Akuisisi sensor DHT22 via ESP32");

  pinMode(pinLED, OUTPUT);

  // inisiasi sensor DHT
  dht.setup(DHTPIN, DHTesp::DHT22);
}

void loop() {
  // deklarasi objek untuk menampung data 
  // temperatur dan kelembapan dari DHT22
  TempAndHumidity data = dht.getTempAndHumidity();

  // ekstrak data temperature
  float temp = data.temperature;
  // ekstrak data humidity
  float hum = data.humidity;

  // menampilkan data di serial
  Serial.println("Suhu: " + String(temp, 2) + "°C");
  if(temp > 40){
    Serial.println("WARNING: " );
    digitalWrite(pinLED, HIGH);
    delay(500);

  }else{
  Serial.println("NORMAL: " );

    digitalWrite(pinLED, HIGH);
    delay(500);

  }
  Serial.println("Kelembaban: " + String(hum, 1) + "%");
  Serial.println("---");

  // waktu jeda sampling data
  // minimal 2 detik
  delay(5000);
  
}