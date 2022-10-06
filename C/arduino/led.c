void lightPin(int pin_num, float freq, int base)
{

  float initialDelay = ((float)base)*freq;
  float postDelay = ((float)base)*(1-freq);
  delay(initialDelay);
  digitalWrite(pin_num, HIGH);
  delay(postDelay);
  digitalWrite(pin_num, LOW);
}
void debugLog(char* f_string, char* str_arr, int str_size)
{
  char str_buffer[str_size];
  //char f_copy[strlen(f_string)+1];
  char t_copy[] = "HI %s MAN %s DUDE";
  Serial.println("INITIAL..............");
  
  char *token=strtok(t_copy," "); //Not return a string literal
  Serial.println((unsigned int)&token);
  char msg_str[100];
  strcpy(msg_str,"");
  while( token != NULL)
  {
    if(strcmp(token,"%s") == 0)
    {
      Serial.println("FOUND");
      Serial.println(token);
      //strcat(msg_str,)
    }
    else
    {
      strcat(msg_str,token);
    }
    token = strtok(NULL, " ");
  }
  //char* m_copy  = malloc(strlen(f_string)+1);
  //strcpy(m_copy,f_string);
  //Serial.println();
  f_string[0]='a';
  char* test = "THIS IS A LITERAL";
  test[0]='Z';
  Serial.println(test);
  Serial.println(f_string);
  //Serial.println();
  //Serial.println(m_copy);
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