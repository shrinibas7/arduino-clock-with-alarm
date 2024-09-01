#include <Wire.h>
#include<EEPROM.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
#include<Servo.h>
 Servo myServo;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
RTC_DS1307 RTC;
int BELL = 13;
int motor=A3;
int light=0;
#include <Keypad.h>
const byte ROWS = 4; /* four rows */
const byte COLS = 3; /* four columns */
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {12, 10, 9, 8}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {A0, A1, A2}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int HOUR,MINUT,SECOND;
unsigned char CSec=3;
unsigned char Read_Detail( char str[])
{
  unsigned char d,i;
  unsigned char x[3];
  lcd.clear();
  lcd.print(str);
  lcd.setCursor(0,1);
  for(i=0;i<2;)
  {
    char customKey = customKeypad.getKey();
  
  if(customKey)
  {
  lcd.write(customKey);
  x[i]=customKey;
  i++;
  }
  }
  x[i]='\0';
  while('#' != customKeypad.getKey());
  d=atoi(x);//ASCII2BCD(x[0],x[1]);
  return d; 
}

void EEPROM_Save(unsigned char addr,unsigned char h,unsigned char m)
{
  lcd.clear();
  lcd.print(addr,DEC);
  EEPROM.write(2*addr,h);
  EEPROM.write(2*addr+1,m);
  delay(2000);
}
void EEPROM_Read(unsigned char addr)
{
    unsigned char hr,mn;
    
    hr = EEPROM.read(2*addr);        /* starts w/last address stored in register pointer */
    mn = EEPROM.read(2*addr+1);
   
    if(hr==HOUR&&MINUT==mn&&SECOND<=CSec)
    {
      if((addr==1))
      {
      digitalWrite(BELL,HIGH);
     // digitalWrite(light,LOW);
      delay(1000);
       myServo.write(90);
       delay (1000);
       digitalWrite(motor,HIGH);  
      lcd.clear();
      lcd.print("Alarming...1: ");
      Serial.println("Ringing...: ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
       Serial.println("bell and its addrsss");
        Serial.println(addr);
    
     
       delay(10000);
        digitalWrite(BELL,LOW);
        digitalWrite(motor,LOW);
        delay (1000);
          myServo.write(0);
     Serial.println("1 time ring");
      delay(1000);
     
     // delay(7000);
      lcd.clear();
    }
     if((addr==2))
      {
      digitalWrite(BELL,HIGH);
     // digitalWrite(light,LOW);
      delay(1000);
       myServo.write(90);
       delay (1000);
       digitalWrite(motor,HIGH);  
      lcd.clear();
      lcd.print("Alarming...2: ");
      Serial.println("Ringing...: ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
       Serial.println("bell and its addrsss");
        Serial.println(addr);
    
     
       delay(10000);
        digitalWrite(BELL,LOW);
        digitalWrite(motor,LOW);
        delay (1000);
          myServo.write(0);
     Serial.println("1 time ring");
      delay(1000);
     
     // delay(7000);
      lcd.clear();
    }
     if((addr==3))
      {
      digitalWrite(BELL,HIGH);
    //  digitalWrite(light,LOW);
      delay(1000);
       myServo.write(90);
         delay(700);
          myServo.write(0);
      lcd.clear();
      lcd.print("Ringing...: ");
      Serial.println("Ringing...: ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
       Serial.println("bell and its addrsss");
        Serial.println(addr);
      delay(500);
      digitalWrite(BELL,LOW);
      Serial.println("1 time ring");
      delay(600);
      digitalWrite(BELL,HIGH);
     delay(1000);
      digitalWrite(BELL,LOW);
      Serial.println("2 time ring");
      delay(600);
      digitalWrite(BELL,HIGH);
     delay(1000);
      digitalWrite(BELL,LOW);
      Serial.println("3 time ring");
      delay(600);
      
      lcd.clear();
    }
     if((addr==4))
      {
      digitalWrite(BELL,HIGH);
     // digitalWrite(light,LOW);
      delay(1000);
       myServo.write(90);
         delay(700);
          myServo.write(0);
      lcd.clear();
      lcd.print("Ringing...: ");
      Serial.println("Ringing...: ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
       Serial.println("bell and its addrsss");
        Serial.println(addr);
      delay(500);
      digitalWrite(BELL,LOW);
      Serial.println("1 time ring");
      delay(600);
      digitalWrite(BELL,HIGH);
     delay(1000);
      digitalWrite(BELL,LOW);
      Serial.println("2 time ring");
      delay(600);
      digitalWrite(BELL,HIGH);
     delay(1000);
      digitalWrite(BELL,LOW);
      Serial.println("3 time ring");
      delay(600);
      digitalWrite(BELL,HIGH);
     delay(1000);
      digitalWrite(BELL,LOW);
      delay(600);
          Serial.println("4 time ring");
     // delay(7000);
      lcd.clear();
    } 
      if(addr==5)
      {
      Serial.println("Pump ON...: ");
      lcd.print(addr,DEC);//lcdof(addr);
      
          digitalWrite(motor,HIGH);
       //motorState=1;
         
        //  EEPROM.update(28, motorState);
      Serial.println("motor off 19 35");
      lcd.clear();
      lcd.print("Motor ON ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
      delay(6000);
      lcd.clear();//here also
       lcd.print("Motor OFF");
        delay(2000);
        digitalWrite(motor,LOW);  
        
        }
       
    if(addr==6)
      {
        digitalWrite(light,HIGH);
       //motorState=0;
      Serial.println("Ringing...: ");
      lcd.print(addr,DEC);//lcdof(addr);
         
         // EEPROM.update(28, motorState);
       Serial.println("motor on 19 36");
      lcd.clear();
      lcd.print("light ON ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
      delay(1000);
      lcd.clear();//here cld clear function is there it shall be clear
      delay(3000);
        
        }
          if(addr==7)
      {
        digitalWrite(light,LOW);
      // motorState=0;
      Serial.println("Ringing...: ");
      lcd.print(addr,DEC);//lcdof(addr);
         
         // EEPROM.update(28, motorState);
       Serial.println("motor on 19 36");
      lcd.clear();
      lcd.print("Light OFF ");
      lcd.print(addr,DEC);//lcdof(addr);
      lcd.setCursor(8,1);
      lcd.print(hr,DEC);//lcdof(hr);
      lcd.write(':');
      lcd.print(mn,DEC);//lcdof(mn);
      delay(1000);
      lcd.clear();//here cld clear function is there it shall be clear
      delay(3000);
        
        }    
      
    }
   // else
    //  digitalWrite(BELL,LOW);
     // digitalWrite(light,LOW);
}

void SchoolAlarm_test()
{
  EEPROM_Read(0X01);
  EEPROM_Read(0X02);
  EEPROM_Read(0X03);
  EEPROM_Read(0X04);
  EEPROM_Read(0X05);
  EEPROM_Read(0X06);
  EEPROM_Read(0X07);
  EEPROM_Read(0X08);
  EEPROM_Read(0X09);
  EEPROM_Read(0X10);
  EEPROM_Read(0X11);
  EEPROM_Read(0X12);
  EEPROM_Read(0X13);
  EEPROM_Read(0X14);
  EEPROM_Read(0X15);
  EEPROM_Read(0X16);
  EEPROM_Read(0X17);
  EEPROM_Read(0X18);
  EEPROM_Read(0X19);
  EEPROM_Read(0X20);
  EEPROM_Read(0X21);
  EEPROM_Read(0X22);
  EEPROM_Read(0X23);
  EEPROM_Read(0X24);
  EEPROM_Read(0X25);
  EEPROM_Read(0X26);
  EEPROM_Read(0X27); 
 EEPROM_Read(0X28);
  EEPROM_Read(0X29); 
EEPROM_Read(0X30);
  EEPROM_Read(0X31);
EEPROM_Read(0X32);
  EEPROM_Read(0X33);

}

void Initialize(void)
{
unsigned char yr, m, dt, dy, hr, mn, sec;
  yr=Read_Detail("Enter Year:");
  m=Read_Detail("Enter Month:");
  dt=Read_Detail("Enter Date:");
  //dy=Read_Detail("Enter Day:");
  hr=Read_Detail("Enter Hour:");
  mn=Read_Detail("EnterMinutes:");
  sec=Read_Detail("EnterSeconds:");
  RTC.adjust(DateTime(yr,m,dt,hr,mn,sec));
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
 // checkmotorState(); 
  pinMode(BELL,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(light,OUTPUT);
    digitalWrite(light,LOW);
    digitalWrite(BELL,LOW);
  digitalWrite(motor, LOW);
  Wire.begin();
  RTC.begin();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
   lcd.print("   Alarm and  ");
   lcd.setCursor(0,1);
   lcd.print("  Digital Clock  ");
   Serial.println("Reminder System  ");
    delay(2000);
     myServo.attach(11);
     delay(1000);
     myServo.write(0);
  if(!RTC.isrunning())
 {
 //RTC.adjust(DateTime(__DATE__,__TIME__));
 }

  lcd.clear();
}

void loop() {
 // digitalWrite(motor,LOW);
  // put your main code here, to run repeatedly:
  char ch,h,m,choice;
  char customKey = customKeypad.getKey();

  if (customKey){
        if(customKey=='*')
      {
        
        while(1)
        {
        ch=Read_Detail("Enter Option:");
        if(ch==0X00)
        {
          Initialize();
          lcd.clear();
          lcd.print("Clock Updated..!!");
          delay(2000);
          break;
        }
        else if(ch==28)
        {
          CSec=Read_Detail("Enter SEC:");
          break;          
        }
        else if(ch==29)
        {
           for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
     Serial.println("eprom erased");
           }
          break;          
        }

        
        else
        {
          h=Read_Detail("Enter Hour:");
          m=Read_Detail("Enter Min:");
          EEPROM_Save(ch,h,m);          
          break;
        }
        
      }
  }
  }
  DateTime now = RTC.now();
  lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Time:");
 lcd.setCursor(6,0);
 lcd.print(HOUR=now.hour(),DEC); 
 lcd.print(":");
 lcd.print(MINUT=now.minute(),DEC);
 lcd.print(":");
 lcd.print(SECOND=now.second(),DEC);
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(now.day(),DEC);
 lcd.print("/");
 lcd.print(now.month(),DEC);
 lcd.print("/");
 lcd.print(now.year(),DEC);
 delay(200);
 SchoolAlarm_test();




}
