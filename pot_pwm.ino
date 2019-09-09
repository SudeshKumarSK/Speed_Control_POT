#include<LiquidCrystal.h>

//note enable pin numbers and lcd 12 is changed to 14 
LiquidCrystal lcd(14,11,5,4,1,2);
const int l1=12;
const int l2=13;
const int r1=3;
const int r2=15;

int pot;

const int potpin = 26;

void Forward(int p) //Forward Movement
{
  analogWrite(l1,p);
  analogWrite(l2,0);
  analogWrite(r1,p);
  analogWrite(r2,0);
}
void Stop()
{
  analogWrite(l1,0);
  analogWrite(l2,0);
  analogWrite(r1,0);
  analogWrite(r2,0);
}
void Reverse(int p)  //Backward Movement
{
  analogWrite(l1,0);
  analogWrite(l2,p);
  analogWrite(r1,0);
  analogWrite(r2,p);
}
void Right(int p)    //Right Movement
{
  analogWrite(l1,0);
  analogWrite(l2,p);
  analogWrite(r1,p);
  analogWrite(r2,0);
}
void Left(int p) //Left Movement
{
  analogWrite(l1,p);
  analogWrite(l2,0);
  analogWrite(r1,0);
  analogWrite(r2,p);
}

void setup()
{
  Serial.begin(9600);
  
  //Setting up output pins
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  
  //Setting up input pins
  pinMode(potpin, INPUT);
  
  //Initializing LCD
  lcd.begin(16,2);
  lcd.print("Welcome Aboard");
  delay(1000);
}

void loop()
{
  lcd.clear();
  delay(50); 
  while(!Serial.available())
  {
    lcd.clear();
    lcd.print("No data available");
    analogWrite(3,0);
    analogWrite(12,0);
    analogWrite(13,0);
    analogWrite(15,0);

    delay(50);
  }
  
char c = Serial.read();

Serial.println(c);
lcd.print(c);

pot = analogRead(potpin);

if(c=='A')
{
  Left(pot/4);
  lcd.print("Turning Left");
  lcd.setCursor(0, 1);
  lcd.print(pot);
  delay(50);
  lcd.setCursor(0, 0);
}
if(c=='D')
{
  Right(pot/4);
  lcd.print("Turning Right");
  lcd.setCursor(0, 1);
  lcd.print(pot);
  delay(50);
  lcd.setCursor(0, 0);
 }

if(c=='W')
{
  Forward(pot/4);
  lcd.print("Moving Forward");
  lcd.setCursor(0, 1);
  lcd.print(pot);
  delay(50);
  lcd.setCursor(0, 0);
}
if(c=='S')
{
  Reverse(pot/4);
  lcd.print("Moving Backwards");
  lcd.setCursor(0, 1);
  lcd.print(pot);
  delay(50);
  lcd.setCursor(0, 0);
}
}
