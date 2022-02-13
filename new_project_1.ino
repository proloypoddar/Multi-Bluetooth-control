#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int a=4;
char txt;
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup()
{
  dht.begin();
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  lcd.begin();
  lcd.print("  HEY, WELCOME");
  lcd.setCursor(0,1);
  lcd.print("-----PROLOY-----");
  delay(7000);
}
void loop(){
  if(Serial.available()!=0){
    txt=Serial.read();
  }
  if (txt=='1'){
    digitalWrite(a,HIGH);
  }
  if(txt=='0'){
    digitalWrite(a,LOW);
  }
  if (txt=='3')
  {
     digitalWrite(a, HIGH);  
  delay(1000);                    
  digitalWrite(a, LOW);    
  delay(1000); 
    }
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Humidity :");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temperature:");
  lcd.print(t);
  lcd.print("°C");
  delay(1000);
}
