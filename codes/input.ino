void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  Serial.println("Enter the matrix A values");
  Serial.print("A00 : ");
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  
}
char rx_byte = 0;
String rx_str_dec = "";
String rx_str_fra = "";
int arr[4];
int arr1[4];
int flag =1;
int count =0;
long int dec;
long int fra;
double temp=0;
char matrix = 'A';
int i1=0,j1=0;

//dimensions of the matrix 
int n= 3; 

int no_of_elem;
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
  // put your main code here, to run repeatedly:
  if(no_of_elem<(2*n*n))
  {
     long int dec_arr[n+1][n+1];
    long int fra_arr[n+1][n+1];
  if(Serial.available())
  {
    rx_byte = Serial.read();
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
        else if(rx_byte =='\n')
        {
            dec = rx_str_dec.toInt();
            fra = rx_str_fra.toInt();
            temp = pow(10,count);
            fraction_conv((double)fra,arr1,temp);
            dec_conv(dec,arr);
            dec_arr[i1][j1]=dec;
            fra_arr[i1][j1] = fra;
            
            Serial.print(dec);
            Serial.print(".");
            Serial.print(fra);
            Serial.print(" ");
            Serial.print("In binary:");
            Serial.print(arr[0]);
            Serial.print(arr[1]);
            Serial.print(arr[2]);
            Serial.print(arr[3]);
            
            Serial.print(arr1[0]);
            Serial.print(arr1[1]);
            Serial.print(arr1[2]);
            Serial.print(arr1[3]);
            Serial.println();
            
            digitalWrite(3,arr[0]);
            digitalWrite(4,arr[1]);
            digitalWrite(5,arr[2]);
            digitalWrite(6,arr[3]);


            digitalWrite(7,arr1[0]);
            digitalWrite(8,arr1[1]);
            digitalWrite(9,arr1[2]); 
            digitalWrite(10,arr1[3]);
            delay(100);
            digitalWrite(11,1);
            delay(1000); 
            digitalWrite(11,0);
            delay(100);
            
          rx_str_dec = "";                // clear the string for reuse
          rx_str_fra = "";
          flag  = 1;
          temp = 0;
          count=0;
          no_of_elem = no_of_elem+1;
          if( no_of_elem == n*n)
            {
              
              Serial.println();
              Serial.println();
              Serial.println("Matrix A values formed from the inputs");
              for(int l=0;l<n;l++)
              {
                for(int m=0;m<n;m++)
                {
                  Serial.print(dec_arr[l][m]);
                  Serial.print(".");
                  Serial.print(fra_arr[l][m]);
                  Serial.print("  "); 
                }
                Serial.println();
              }
              
              matrix = 'B';
              Serial.println();
              Serial.println();
              Serial.println("Enter matrix B values");
            }
            
          j1 = j1+1;
            if(j1== n)
            {
              j1=0;
              i1 = i1+1;
              if(i1==n)
              {
                i1=0;
              }
            }
          if(no_of_elem<(2*n*n))
          {
            
            Serial.print(matrix);
            Serial.print(i1);
            Serial.print(j1);
            Serial.print(" : ");
          }
          if(no_of_elem == (2*n*n))
          {
            
            Serial.println();
              Serial.println();
              Serial.println("Matrix B values formed from the inputs");
              for(int l=0;l<n;l++)
              {
                for(int m=0;m<n;m++)
                {
                  Serial.print(dec_arr[l][m]);
                  Serial.print(".");
                  Serial.print(fra_arr[l][m]); 
                  Serial.print("  ");
                }
                Serial.println();
              }
              Serial.println();
              Serial.println();
              Serial.print("please change to output port and check matrix multiplication values");
           
          }
        }
        else if(rx_byte == '.')
        {
            flag = 0;
        }
  }
}
}

