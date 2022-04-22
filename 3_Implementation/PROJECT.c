#include <LiquidCrystal.h>
#include<stdio.h>
#include<string.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
int ir1=7;
int ir2=6;
int ir2time=0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int inhh=0;int inmm=0;int inss=0;
int outhh=0;int outmm=0;int outss=0;
int temp=0;
#include <Wire.h>
#include "Sodaq_DS3231.h"
char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
DateTime dt(2022, 3, 25, 15, 57, 0, 5);
void setup () 
{
  pinMode(ir1,INPUT);pinMode(ir2,INPUT);
  lcd.begin(16, 2);
  lcd.clear();lcd.print("CAR PARKING");
  lcd.setCursor(0,1);lcd.print("BILLING SYSTEWM....");
    Serial.begin(115200);
    Wire.begin();
    rtc.begin();
    //rtc.setDateTime(dt); //Adjust date-time as defined 'dt' above 
    
}

void loop () 
{
    DateTime now = rtc.now(); //get the current date-time
    lcd.clear();
    lcd.print(now.year(), DEC);lcd.print('/');
    lcd.print(now.month(), DEC);lcd.print('/');
    lcd.print(now.date(), DEC);lcd.print(' ');
    lcd.setCursor(5,1);
    lcd.print(now.hour(), DEC);lcd.print(':');
    lcd.print(now.minute(), DEC);lcd.print(':');
    lcd.print(now.second(), DEC);delay(1000);
   
while(Serial.available())
{
String data=Serial.readString();
lcd.clear();lcd.print(data);delay(1000);
if((data[0]=='I')||(data[1]=='I')||(data[2]=='I')||(data[3]=='I'))
{
  temp=1;delay(1000);
}
if((data[0]=='O')||(data[1]=='O')||(data[2]=='O')||(data[3]=='O'))
{
  temp=2;delay(1000);
}
if(temp==1)
{
  temp=9;
 lcd.clear();lcd.print("VALID QR CODE");delay(1000);
 inhh=now.hour();inmm=now.minute();inss=now.second();
 lcd.setCursor(0,1);lcd.print("INTIME:");lcd.print(inhh);lcd.print(":");lcd.print(inmm);lcd.print(":");lcd.print(inss);delay(1000); 
}
else if(temp==2)
{
  temp=9;
 lcd.clear();lcd.print("VALID QR CODE");delay(1000);
 outhh=now.hour();outmm=now.minute();outss=now.second();
 lcd.setCursor(0,1);lcd.print("OUTTIME:");lcd.print(outhh);lcd.print(":");lcd.print(outmm);lcd.print(":");lcd.print(outss);delay(1000);delay(1000); 
lcd.clear();        lcd.print("IN ");lcd.print(inhh);lcd.print(":");lcd.print(inmm);lcd.print(":");lcd.print(inss);delay(1000);
lcd.setCursor(0,1);lcd.print("OUT ");lcd.print(outhh);lcd.print(":");lcd.print(outmm);lcd.print(":");lcd.print(outss);delay(5000);  
lcd.clear();lcd.print("BILLING (HH/MM) ");lcd.print(outmm-inmm);lcd.print(":");lcd.print(outmm-inmm);delay(5000);
int mm=outmm-inmm;
int hh=outhh-inhh;
lcd.clear();lcd.print("DURA(HH/MM) ");lcd.print(hh);lcd.print(":");lcd.print(mm);delay(1000);
lcd.setCursor(0,1);lcd.print("Amount:");
float amount=((hh*1)+(mm*0.5));lcd.print(amount);lcd.print("/Rs");delay(10000);temp=0;
}
}



int ir1val=digitalRead(ir1);delay(10);
int ir2val=digitalRead(ir2);delay(10);
if(ir1val==LOW){lcd.clear();lcd.print("S1:BUSY");  }
if(ir1val==HIGH){lcd.clear();lcd.print("S1:FREE");  }
if(temp==1)
{
lcd.setCursor(0,1);lcd.print("S1:BOOKED");  delay(1000); 
}
if(ir2val==LOW){lcd.print(" S2:BUSY");ir2time=ir2time+1;delay(1000);lcd.setCursor(0,1);lcd.print("S2 BILL  ");lcd.print(ir2time*0.5);delay(1000);  }
if(ir2val==HIGH){lcd.print(" S2:FREE"); ir2time=0;}delay(2000);


}
