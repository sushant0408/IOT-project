#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
TMRpcm tmrpcm;
//Constants:
const int flexPin = A0; //pin A0 to read analog input
const int flexPin1=A1;
const int flexPin2=A2;
const int flexPin3=A3;
//Variables:
int value,value1,value2,value3; //save analog value
void setup() {
tmrpcm.speakerPin=8;
Serial.begin(9600);       //Begin serial communication
lcd.begin(16, 2); 
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);
}
void loop() 
{
 value = analogRead(flexPin); //Read and save analog value from flex sensor
 value1=analogRead(flexPin1);
 value2=analogRead(flexPin2);
 value3=analogRead(flexPin3);
  Serial.println(value);               //Print value
  Serial.println(value1);
  Serial.println(value2);
  Serial.println(value3);
  delay(1000);                          //Small delay 
  if(value<425 && value1>425 && value2>425 && value3>425){  
    lcd.setCursor(0, 0);
    lcd.print("HELLO");
    tmrpcm.play("Hello.wav");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2>425 && value3>425)
  {
    //digitalWrite(1,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("THIS IS");
    tmrpcm.play("ThisIs.wav");
    delay(1000);
  }
  else if(value>425 && value1>425 && value2<425 && value3>425)
  {
    //digitalWrite(2,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("HandTalk");
    tmrpcm.play("HandTalk.wav");
    delay(1000);
  }
  else if(value>425 && value1>425 && value2>425 && value3<425)
  {
    //digitalWrite(2,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("AYS.wav");
    lcd.print("AT YOUR SERVICE");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2>425 && value3>425)
  {
    //digitalWrite(3,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("IAm.wav");
    lcd.print("I AM");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2<425 && value3>425)
  { 
    //digitalWrite(3,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("AI.wav");
    lcd.print("AN INTERPRETER");
    delay(1000);
  }
  else if(value>425 && value1>425 && value2<425 && value3<425)
  { 
    //digitalWrite(4,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("WC.wav");
    lcd.print("WHICH CONVERTS");
    delay(1000);
  }
  else if(value<425 && value1>425 && value2<425 && value3>425)
  { 
    //digitalWrite(4,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("HG.wav");
    lcd.print("HAND GESTURES");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2>425 && value3<425)
  { 
    //digitalWrite(5,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("TTAV.wav");
    lcd.print("TO TEXT AND VOICE");
    delay(1000);
  }
  else if(value<425 && value1>425 && value2>425 && value3<425)
  { 
    //digitalWrite(5,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("Sushant.wav");
    lcd.print("SUSHANT");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2<425 && value3>425)
  { 
    //digitalWrite(6,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("Shefin.wav");
    lcd.print("SHEFIN");
    delay(1000);
  }
  else if(value>425 && value1<425 && value2<425 && value3<425)
  { 
    //digitalWrite(6,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("Akshay.wav");
    lcd.print("AKSHAY");
    delay(1000);
  }
  else if(value<425 && value1<425 && value2>425 && value3<425)
  { 
    //digitalWrite(7,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("SO.wav");
    lcd.print("SIGNING OFF");
    delay(1000);
  }
  
   else if(value<425 && value1>425 && value2<425 && value3<425)
  { 
    //digitalWrite(8,HIGH);
    lcd.setCursor(0, 0);
    tmrpcm.play("ThankYou.wav");
    lcd.print("FUCK OFF");
    delay(1000);
  }
  lcd.clear();
}
