#define rain A0
int rain_sense;

#define mois A1
int mois_sense;

#define motor1 4
#define motor2 5
#define fan 6
int i=1;

void setup()
{
  Serial.begin(9600);
  pinMode(rain,INPUT);
  pinMode(mois,INPUT);
  pinMode(motor1,OUTPUT);pinMode(motor2,OUTPUT);
  pinMode(fan,OUTPUT);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  digitalWrite(fan,LOW);
}
void loop()
{
  rain_sense=analogRead(rain);
  rain_sense=map(rain_sense,1023,0,0,100);
  mois_sense=analogRead(mois);
  mois_sense=map(mois_sense,1023,0,0,100);
  

  Serial.print("RAIN : ");Serial.println(rain_sense);
  Serial.print("MOIS : ");Serial.println(mois_sense);

  if(rain_sense>=50 && i==1)
  {
    Serial.println("DOOR CLOSED");
    i=0;
    door_close();
  }
  else if(rain_sense<50 && i==0)
  {
    Serial.println("DOOR OPEN");
    i=1;
    door_open();
  }

  if(mois_sense>=30 && rain_sense>=50)
    {
      Serial.println("FAN ON");
      digitalWrite(fan,HIGH);
    }
    else
    {
      Serial.println("FAN OFF");
      digitalWrite(fan,LOW);
    }
  delay(1000);
}
void door_open()
{
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,LOW);
  delay(800);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  delay(200);
}
void door_close()
{
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);
  delay(800);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  delay(200);
}
