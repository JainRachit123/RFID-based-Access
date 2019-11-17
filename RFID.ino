char input[12];
char tag[] = "0200107DF49B";
int count = 0;
boolean flag = 0;
int t=0;
void setup()
{
  pinMode(11,OUTPUT); 
  Serial.begin(9600); // START SERIAL AT BAUD RATE OF 9600 BITS/SEC
}
void loop()
{
  if(Serial.available()) // CHECK FOR AVAILABILITY OF SERIAL DATA
  { 
    count = 0; // Reset the counter to zero
    while(Serial.available() && count < 12) 
    {
      input[count] = Serial.read(); // Read 1 Byte of data and store it in the input[] variable
      count++; // increment counter 
      delay(5);
    }
    Serial.println(input);
    if(count == 12)
    {
      count =0;
      flag = 1;
      while(count<12 && flag !=0) 
      {
        if(tag[count]==input[count])
        {
        t++;
        break;
        }
        else
        {
        flag= 1;
        break;
        }
      }
    }
    if(t == 1)
          digitalWrite(11,HIGH);
    else if(t == 2)
    {
          digitalWrite(11,LOW);
          t=0;
    }
  }
}
