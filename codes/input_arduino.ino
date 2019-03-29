void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number:");
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
}

char rx_byte = 0;
String rx_str_dec = "";
String rx_str_fra = "";
boolean not_number = false;
double result;
long int dec;
long int fra;
int flag = 1;
int arr[4];
int arr1[4];
int dec_bytes;
int count =0;
int count1 =0;
double fraction,temp;
int x=2,y=6;

void dec_conv(int a,int arr[])
{
//  Serial.println("entered fraction");
  int i=0;
  while(i<4)
  {
   arr[3-i]=a%2;
   a = a/2;
   i++;
  }
}
void fraction_conv(double a,int arr[],double temp)
{
//  Serial.println("entered fraction");
  int i=0;
  double x = temp/2;
    while(i<4)
    {
    
      if(x<=a)
      {
        
        a=a-x;
        arr[i]=1;
      }
      else
      {
        arr[i]=0;
      }
      i++;
      x=x/2;
    }
}

void loop() {
    if(count1<9)
    {
      if (Serial.available() > 0)
     {    // is a character available?
        rx_byte = Serial.read();       // get the character
        
        if ((rx_byte >= '0') && (rx_byte <= '9'))
        {
//           Serial.println(rx_byte);
          if(flag ==1)
          {
            rx_str_dec += rx_byte;
          }
          else if(flag==0)
          {
            rx_str_fra += rx_byte;
            count++;
          }
        }
        else if(rx_byte == '\n')
        {
          // end of string
          if (not_number)
          {
            Serial.println("Not a number");
          }
          else
          {
            dec = rx_str_dec.toInt();
            fra = rx_str_fra.toInt();
    
            temp = pow(10,count);
            dec_conv(dec,arr);
            fraction_conv((double)fra,arr1,temp);
            for(int i=0;i<4;i++)
            {
              
              Serial.println(arr[i]);
              digitalWrite(x,arr[i]);
              x=x+1;
             }
    
              Serial.println("fraction bits");
              for(int i=0;i<4;i++)
              {
                Serial.println(arr1[i]);
                digitalWrite(y,arr1[i]);
               y=y+1;
              }  
            }
        
             not_number = false;         // reset flag
              rx_str_dec = "";                // clear the string for reuse
              rx_str_fra = "";
              flag  = 1;
              count=0;
              count1=count1+1;
              x=2;
              y=6;
              Serial.println("Enter the Number:");
        } 
         else if(rx_byte == '.')
        {
            flag = 0;
        }
      else {
        // non-number character received
        not_number = true;    // flag a non-number
      }
    }
//    
  } // end: if (Serial.available() > 0)

    
}
  


