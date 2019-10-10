int incomingByte = 0; // for incoming serial data
  int programm=0;
  int numberofDatabytes=0;
  int changeFlag=1;
  int defaultFlag=0;

enum{
     RESERVED = 0,
     RAIN,
     RANDOM,
     PYRAMID,
     STROBO,
     AUFAB,
     LINKSRECHTS,
     SCHLANGE,
     AUDIO,
     MATRIX
};

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  
}

void loop() 
{
  // send data only when you receive data:
  if (Serial&&changeFlag) 
  {
      switch(programm)
      {
        case RESERVED:
        {
           Serial.print("RESERVED\n");
          break;
        }
        case RAIN:
        {
           Serial.print("RAIN\n");
          break;
        }
        case RANDOM:
        {
           Serial.print("RANDOM\n");
          break;
        }
        case PYRAMID:
        {
          Serial.print("PYRAMID\n");
          break;
        }
        case STROBO:
        {
          Serial.print("STROBO\n");
          break;
        }
        case AUFAB:
        {
          Serial.print("AUFAB\n");
          break;
        }
        case LINKSRECHTS:
        {
          Serial.print("LINKSRECHTS\n");
          break;
        }
        case SCHLANGE:
        {
          Serial.print("SCHLANGE\n");
          break;
        }
        case AUDIO:
        {
          Serial.print("AUDIO\n");
          break;
        }
        case MATRIX:
        {
          Serial.print("MATRIX\n");
          break;
        }
        default:
        {
          Serial.print(programm,HEX);
          Serial.print(" is not a code for an implemented function\n");
          defaultFlag=1;
        }
        
      }
      
       if((numberofDatabytes!=0)&&defaultFlag==0)
          {
            Serial.print("With ");
            Serial.print(numberofDatabytes ,DEC);
            Serial.print(" Databyte(s)\n");
          }
      changeFlag=0;
      defaultFlag=0;
  }
}    

void serialEvent() 
 {
  incomingByte = Serial.read();
  programm= incomingByte&0x0F;
  numberofDatabytes=(incomingByte&0xF0)>>4;
  changeFlag=1;
/*  for (int i=0; i<numberofDatabytes;i++) 
  {
    
  }*/
}
  /*  // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: 0x");
    Serial.println(incomingByte, HEX);
   */
    
