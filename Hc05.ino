char command;
String string;
boolean ledon = false;
#define led 13
void setup()
{
Serial.begin(9600);
pinMode(led, OUTPUT);
}
void loop()
{
if (Serial.available() > 0)
{string = "";}
while(Serial.available() > 0)
{
  Serial.println("in while loop");
  command = ((byte)Serial.read());
if(command == ':')
{
break;
}
else
{
string += command;
}
delay(1);
}
if(string == "TO")
{
  Serial.println("in here");
ledOn();
ledon = true;
}
if(string =="TF")
{
ledOff();
ledon = false;
Serial.println(string); //debug
}
if ((string.toInt()>=0)&&(string.toInt()<=255))
{
if (ledon==true)
{
analogWrite(led, string.toInt());
Serial.println(string); //debug
delay(10);
}
}
}
void ledOn()
{
analogWrite(led, 255);
delay(10);
}
void ledOff()
{
analogWrite(led, 0);
delay(10);
}