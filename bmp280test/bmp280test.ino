/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMEP280 Breakout 
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required 
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/


// Libraries to Include
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

//Definitions
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10


Adafruit_BMP280 bme; // I2C
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

 
void setup() {
  Serial.begin(9600);
  //Check for sensor
  //Serial.println(F("BMP280 test"));
  
  if (!bme.begin()) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}

// Start continuos loop 
void loop() {
    //Get Temp Data
    //Serial.print("Temperature = ");
    //Serial.print(bme.readTemperature());
    //Serial.println(" *C");
    //Get Pressure Data
    //Serial.print("Pressure = ");
    Serial.print(bme.readPressure());
    //Serial.println(" Pa");
    //Get Altitude Data
    //Serial.print("Approx altitude = ");
    //Serial.print(bme.readAltitude(1013.25)); // this should be adjusted to your local forcase
    //Serial.println(" m");
    //Print to serial
    Serial.println();
    delay(30000);
}
