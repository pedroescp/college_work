#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
int pino005 = 6;
int pino010 = 5;
int pino025 = 4;
int pino050 = 3;
int pino1 = 2;
int leitura005 = 1;
int leitura010 = 1 ;
int leitura025 =1 ;
int leitura050=1;
int leitura1=1;
int endereco = 10;
float total;
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup()
{
  pinMode(pino1, INPUT);
  pinMode(pino050, INPUT);
  pinMode(pino025, INPUT);
  pinMode(pino010, INPUT);
  pinMode(pino005, INPUT);
  Serial.begin(9600);
  EEPROM.get(endereco, total);
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print(F("R$ "));
}
 
void loop()
{

  leitura1   = digitalRead(pino1);
  leitura050   = digitalRead(pino050);
  leitura025   = digitalRead(pino025);
  leitura010   = digitalRead(pino010);
  leitura005   = digitalRead(pino005);
  
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  Serial.println(EEPROM.read(endereco));

  lcd.print("R$ " + (String)total);
 
  if (leitura1 != 1)
  {
    lcd.setCursor(0,0);
    total = total + 1.00f;
    EEPROM.put(endereco, total);

    Serial.print("\nAdicionado R$ 1,00, Total: ");
    Serial.print(total);
  lcd.print("R$ " + (String)total);
    delay(500);
  }
  if (leitura050 != 1)
  {
  lcd.setCursor(0,0);
    total = total + 0.50f;
    EEPROM.put(endereco, total);
 
    Serial.println("Adicionado R$ 0,50, Total: ");
    Serial.print(total);
  lcd.print("R$ " + (String)total);
    delay(500);
  }
  if (leitura025 != 1)
  {
  lcd.setCursor(0,0);
    total = total + 0.25f;
    EEPROM.put(endereco, total);
 
    Serial.println("Adicionado R$ 0,25, Total: ");
    Serial.print(total);
  lcd.print("R$ " + (String)total);
    delay(500);
  }
  if (leitura010 != 1)
  {
  lcd.setCursor(0,0);
    total = total + 0.10f;
    EEPROM.put(endereco, total);
   
    Serial.println("Adicionado R$ 0,10, Total: ");
    Serial.print(total);
  lcd.print("R$ " + (String)total);
    delay(500);
  }
  if (leitura005 != 1)
  {
  lcd.setCursor(0,0);
    total = total + 0.05f;
    EEPROM.put(endereco, total);
   
    Serial.println("Adicionado R$ 0,05, Total: ");
    Serial.print(total);
  lcd.print("R$ " + (String)total);
    delay(500);
  }
  lcd.setBacklight(LOW);
}
 
 
