int PWMA=5;
int PWMB=6;
int INA=4;
int INB=7;


void setup()
{
  Serial.begin(9600);
  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(INA,OUTPUT);
  pinMode(INB,OUTPUT);  
}
void forward()
{
  digitalWrite(INA,HIGH);
  digitalWrite(INB,HIGH);
  analogWrite(PWMA,500);
  analogWrite(PWMB,500);
  
}
void back()
{
  digitalWrite(INA,LOW);
  digitalWrite(INB,LOW);
  analogWrite(PWMA,500);
  analogWrite(PWMB,500);
  
}
void tleft()
{
  digitalWrite(INA,LOW);
  digitalWrite(INB,HIGH);
  analogWrite(PWMA,200);
  analogWrite(PWMB,200);
  
}
void tright()
{
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  analogWrite(PWMA,200);
  analogWrite(PWMB,200);
}
void left()
{
  digitalWrite(INA,LOW);
  digitalWrite(INB,HIGH);
  analogWrite(PWMA,200);
  analogWrite(PWMB,200);
  delay(400);
  off();

  
}
void right()
{
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  analogWrite(PWMA,200);
  analogWrite(PWMB,200);
  delay(400);
  off();
  
  
  
}
void off()
{
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  
}
void loop()
{
  while(Serial.available())
   {
     char c=Serial.read();
      switch(c)
      {
        case 'g':
        {
         forward();
         break;
        }
        case 'l':
        {
          tleft();
          break;
        }
        case 'r':
        {
          tright();
          break;
        }
        case 'b':
        {
          back();
          break;
        }
        case 't':
        {
          off();
          break;
        }
        case 'e':
        {
          left();
          break;
        }
        case 'i':
        {
          right();
          break;
        }
      }
         
        
   }
}

