/* Arduino Tutorial: Learn how to use an LCD 16x2 screen

   More info: http://www.ardumotive.com/how-to-use-an-lcd-dislpay-en.html  
   
   https://www.instructables.com/id/How-to-use-an-LCD-displays-Arduino-Tutorial/
   
   */



//Include LCD library

#include <LiquidCrystal.h>

int a;

// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {

  
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 

  lcd.begin(20, 4);

  // Print a message to the LCD.
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Webwork");
  lcd.setCursor(4, 1);
  lcd.print("Batteritester");
  lcd.setCursor(4, 2);
  lcd.print("v1.0");

  delay(3000);
  lcd.clear();
}

void loop() {
  
Main();
}

void Main() {
 
 float _voltage = MeasureVoltage();
 
 WriteToLCD(_voltage);
  
}


void WriteToLCD(float _voltage) {

  lcd.setCursor(4, 1);
  lcd.print("Spenningen er: ");
  lcd.setCursor(4, 2);
  lcd.print(_voltage);
  lcd.setCursor(10, 2);
  lcd.print("volt");
  //delay(1000);
  
  //lcd.clear();
  
  
}

float MeasureVoltage() {
    // + -> sensor = 47 kohm
    // sensor -> - = 1000 kohm  
    
  
  //int sensorValue = analogRead(A1);
 
  //float voltage = sensorValue * (22.27 * 4.97 / 1023.0);
  //Serial.println(voltage);
  
  //regner gjennomsnittet av NUM_SAMPLES målinger
  int NUM_SAMPLES = 100;
  int sum = 0;
  unsigned char sample_count = 0;
  float voltage = 0.0;
  
  while (sample_count < NUM_SAMPLES) {
    sum += analogRead(A1);
    sample_count++;
    delay(10);
  }
  
    // 4.97V er målt referance spenning
    voltage = ((float)sum / (float)NUM_SAMPLES * 4.97) / 1024.0;
    voltage = voltage * 22.27;
    sample_count = 0;
    sum = 0;
  
  if (voltage < 5) voltage = 0;
  return voltage;
}
