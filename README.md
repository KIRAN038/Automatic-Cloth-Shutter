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
}The Automatic Cloth Dryer is an innovative solution designed to efficiently dry clothes with minimal human intervention. This system incorporates sensors, a heating element, and a motorized mechanism to ensure optimal drying while reducing energy consumption. The dryer detects moisture levels in the fabric and adjusts the drying time accordingly, enhancing efficiency and preventing over-drying.

Key features include automatic temperature control, timer settings, and energy-efficient operation. Some models may also integrate IoT capabilities for remote monitoring and control. By automating the drying process, this system offers convenience, energy savings, and reduced dependency on weather conditions, making it a sustainable and user-friendly solution for households and commercial use.# Automatic-Cloth-Shutter


