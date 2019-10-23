 // for incoming serial data
  int programm=0;
  int numberofDatabytes=0;
  int changeFlag=1;
  int defaultFlag=0;
  byte Data[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int Byteorder=0;

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
           printData();
          break;
        }
        case RAIN:
        {
           Serial.print("RAIN\n");
           printData();
          break;
        }
        case RANDOM:
        {
           Serial.print("RANDOM\n");
           printData();
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
          printData();
          break;
        }
        case SCHLANGE:
        {
          Serial.print("SCHLANGE\n");
          printData();
          break;
        }
        case AUDIO:
        {
          Serial.print("AUDIO\n");
          printData();
          break;
        }
        case MATRIX:
        {
          Serial.print("MATRIX\n");
          printData();
          break;
        }
        default:
        {
          Serial.print(programm,HEX);
          Serial.print(" is not a code for an implemented function\n");
          defaultFlag=1;
        }
        
      }
  //@TODO entfernen bei Einbindung
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
    int Detection; //Byte to detect which programm that is choosen and how many databytes are expected
       Detection= Serial.read();
       programm=Detection&0x0F;
       changeFlag=1;
       numberofDatabytes=(Detection>>4);
       Serial.readBytes(Data,numberofDatabytes);
 }

void printData()
{
  for(int i=0;i<numberofDatabytes;i++)
  {
   Serial.print(Data[i],HEX); 
   Serial.print("\n"); 
  }
}
 
    
