void lightPin(int pin_num, float freq, int base)
{

  float initialDelay = ((float)base)*freq;
  float postDelay = ((float)base)*(1-freq);
  delay(initialDelay);
  digitalWrite(pin_num, HIGH);
  delay(postDelay);
  digitalWrite(pin_num, LOW);
}


void setup() 
{
  Serial.begin(9600 );
    // put your setup code here, to run once:
  Serial.println();
  pinMode(13,OUTPUT);
}

void loop() 
{
    // put your main code here, to run repeatedly:
  lightPin(13,.5,650);
}