#include <Wire.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_INA219.h>

#include <Arduino.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/Picopixel.h>
#include <Fonts/FreeMono9pt7b.h>

#ifndef SSD1306_128_64
#error "set display on Adafruit_SSD1306.h"
#endif

#define OLED_RESET 4
Adafruit_SSD1306 dsp(OLED_RESET);

Adafruit_INA219 ina219;

void setup()
{
    Serial.begin(115200);
    Serial.println("SAMPLE");

    dsp.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    dsp.clearDisplay();    
    dsp.setFont(&FreeMono9pt7b);
    dsp.setTextSize(1);
    dsp.setTextColor(WHITE);
    //dsp.setRotation(3);

    ina219.begin();
    dsp.setCursor(0, 12);
    dsp.print("INA Initialized");
    dsp.display();
}

char buf[80];

void loop()
{
    dsp.clearDisplay();

    float shuntvoltage = 0;
    float busvoltage = 0;
    float current_mA = 0;
    float loadvoltage = 0;

    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    loadvoltage = busvoltage + (shuntvoltage / 1000);

    // Serial.print("Bus Voltage:   ");
    // Serial.print(busvoltage);
    // Serial.println(" V");
    // Serial.print("Shunt Voltage: ");
    // Serial.print(shuntvoltage);
    // Serial.println(" mV");
    // Serial.print("Load Voltage:  ");
    // Serial.print(loadvoltage);
    // Serial.println(" V");
    // Serial.print("Current:       ");
    // Serial.print(current_mA);
    // Serial.println(" mA");
    // Serial.println("");

    auto str = String("BV ") + String(busvoltage) + String(" V");
    dsp.setCursor(0, 12);
    dsp.print(str.c_str());

    str = String("SV ") + String(shuntvoltage) + String(" mV");
    dsp.setCursor(0, 12 * 2);
    dsp.print(str.c_str());

    str = String("LV ") + String(loadvoltage) + String(" V");
    dsp.setCursor(0, 12 * 3);
    dsp.print(str.c_str());

    str = String("C  ") + String(current_mA) + String(" mA");
    dsp.setCursor(0, 12 * 4);
    dsp.print(str.c_str());

    dsp.display();
}
