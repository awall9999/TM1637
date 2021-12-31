int Clock = 7; // Clock Pin Display
int Data = 8; // Data Pin Display
const byte Seg[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; // Define Segment Numbers 0-9, 
const byte CubeUp = 0x63, CubeDown = 0x5c, LetterC=0x39, LetterL=0x38, LetterN=0x54; // Define Special Segment Caracters

void start()
{
  digitalWrite(Clock,HIGH);//send start signal to TM1637
  digitalWrite(Data,HIGH);
  microsecond();

  digitalWrite(Data,LOW);
  digitalWrite(Clock,LOW);
  microsecond();
}
void stop()
{
  digitalWrite(Clock,LOW);
  digitalWrite(Data,LOW);
  microsecond();

  digitalWrite(Clock,HIGH);
  digitalWrite(Data,HIGH);
  microsecond();
}

void microsecond() // 45 microsecond delay 
{
long int slowdown = micros();
  do {
    
  } while ((unsigned long)(micros() - slowdown) < 45); 
}


void shiftOut(byte val)
{
      

      for (int i = 0; i < 8; i++)  
            {
            
            digitalWrite(Data, !!(val & (1 << i)));
                              
            microsecond();
            digitalWrite(Clock, HIGH);
            microsecond();
            digitalWrite(Clock, LOW);
            microsecond();            
           }
      
          digitalWrite(Clock, HIGH);
          microsecond();
          digitalWrite(Clock, LOW);
      
}
void DispOut(byte val0,byte val1,byte val2,byte val3,byte dp,byte br) // number 1-4, Double Point, Brightness
{
  

 start();
 shiftOut(0x40);
 stop();
 
 start();
 shiftOut(0xC0);
 
 shiftOut(val0);
 
 if (dp==1) shiftOut(val1=val1+0x80);
 else shiftOut(val1);
 
 shiftOut(val2);
 shiftOut(val3);
 
 start();
 shiftOut(br);
 stop();
 
}









void setup() {
 pinMode(Clock,OUTPUT);
 pinMode(Data,OUTPUT);


}

void loop() {

  
  for (int a = 0; a < 10; a++)  {
  DispOut(Seg[a],Seg[a],Seg[a],Seg[a],0,0x8f);
  delay(250);
  }
}
