# iot-arduino-ina219-oled1306

![](doc/ina219-oled1306.jpg)

- BV : bus voltage
- SV : shunt resistor voltage
- LV : load voltage
- C : current

## connections

- arduino can be powered using 9V connected to Vin
- from arduino 3.3v supply power to oled1306 and ina219
- oled sck and ina scl to arduino scl ( A5 )
- oled and ina sda to arduino sda ( A4 )

## note

INA219 can read voltage when load circuit ground is common with ina gnd else you'll get almost 0 V value on bus and load voltage.