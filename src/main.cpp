#include <Arduino.h>
#include "INA3221_IXGL.h"

INA3221_IXGL Sensor_INA3221;


// the three channels of the INA3221 named for SunAirPlus Solar Power Controller channels (www.switchdoc.com)
#define CHANNEL_01 1
#define CHANNEL_02 2
#define CHANNEL_03 3

void setup(void) 
{
    
  Serial.begin(9600);
  Serial.println("INA3221_IXGL Class Test");
  
  Serial.println("Measuring voltage and current with Sensor_INA3221");
  Sensor_INA3221.Mtd_begin();

  Serial.print("Manufactures ID=0x");
  int MID;
  MID = Sensor_INA3221.Mtd_getManufID();
  Serial.println(MID,HEX);
}

void loop(void) 
{
  
  Serial.println("------------------------------");

  float shuntvoltage1 = 0;
  float busvoltage1 = 0;
  float current_mA1 = 0;
  float loadvoltage1 = 0;

  busvoltage1 = Sensor_INA3221.Mtd_getBusVoltage_V(CHANNEL_01);
  shuntvoltage1 = Sensor_INA3221.Mtd_getShuntVoltage_mV(CHANNEL_01);
  current_mA1 = -Sensor_INA3221.Mtd_getCurrent_mA(CHANNEL_01);  // minus is to get the "sense" right.   - means the battery is charging, + that it is discharging
  loadvoltage1 = busvoltage1 + (shuntvoltage1 / 1000);
  
  Serial.print("LIPO_Battery Bus Voltage:   "); Serial.print(busvoltage1); Serial.println(" V");
  Serial.print("LIPO_Battery Shunt Voltage: "); Serial.print(shuntvoltage1); Serial.println(" mV");
  Serial.print("LIPO_Battery Load Voltage:  "); Serial.print(loadvoltage1); Serial.println(" V");
  Serial.print("LIPO_Battery Current 1:       "); Serial.print(current_mA1); Serial.println(" mA");
  Serial.println("");

  float shuntvoltage2 = 0;
  float busvoltage2 = 0;
  float current_mA2 = 0;
  float loadvoltage2 = 0;

  busvoltage2 = Sensor_INA3221.Mtd_getBusVoltage_V(CHANNEL_02);
  shuntvoltage2 = Sensor_INA3221.Mtd_getShuntVoltage_mV(CHANNEL_02);
  current_mA2 = -Sensor_INA3221.Mtd_getCurrent_mA(CHANNEL_02);
  loadvoltage2 = busvoltage2 + (shuntvoltage2 / 1000);
  
  Serial.print("Solar Cell Bus Voltage 2:   "); Serial.print(busvoltage2); Serial.println(" V");
  Serial.print("Solar Cell Shunt Voltage 2: "); Serial.print(shuntvoltage2); Serial.println(" mV");
  Serial.print("Solar Cell Load Voltage 2:  "); Serial.print(loadvoltage2); Serial.println(" V");
  Serial.print("Solar Cell Current 2:       "); Serial.print(current_mA2); Serial.println(" mA");
  Serial.println("");

  float shuntvoltage3 = 0;
  float busvoltage3 = 0;
  float current_mA3 = 0;
  float loadvoltage3 = 0;

  busvoltage3 = Sensor_INA3221.Mtd_getBusVoltage_V(CHANNEL_03);
  shuntvoltage3 = Sensor_INA3221.Mtd_getShuntVoltage_mV(CHANNEL_03);
  current_mA3 = Sensor_INA3221.Mtd_getCurrent_mA(CHANNEL_03);
  loadvoltage3 = busvoltage3 - (shuntvoltage3 / 1000);
  
  Serial.print("Output Bus Voltage 3:   "); Serial.print(busvoltage3, 4); Serial.println(" V");
  Serial.print("Output Shunt Voltage 3: "); Serial.print(shuntvoltage3, 4); Serial.println(" mV");
  Serial.print("Output Load Voltage 3:  "); Serial.print(loadvoltage3, 4); Serial.println(" V");
  Serial.print("Output Current 3:       "); Serial.print(current_mA3, 4); Serial.println(" mA");
  Serial.println("");

  delay(4000);
}