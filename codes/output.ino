void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  
//  pinMode(LED_BUILTIN,OUTPUT);
}

long int conv_int(int arr[])
{
  long int sum;
  sum = arr[0]*128+arr[1]*64+arr[2]*32;
  //Serial.println(sum);
  sum = sum +arr[3]*16 +arr[4]*8+arr[5]*4+arr[6]*2+arr[7]*1;
 //  Serial.println(sum);
  return sum;
}




long int  conv_fra(int arr[])
{
//  long int temp = 800000000
  long int  sum ;
  sum = arr[0]*150000000 + arr[1]*125000000 + arr[2]*112500000 + arr[3]*106250000;
  //Serial.println(sum);
  //Serial.println(arr[5]*1015625000);
  sum = sum + arr[4]*103125000 + arr[5]*101562500 +arr[6]*100781250 + arr[7]*100390625;
  //Serial.println(sum);
  
  return sum;
  
}

void fun(long int sum,int arr[])
{
  for(int i=0;i<8;i++)
  {
    arr[7-i]= sum%10;
    sum =sum /10;
  }
}


int arr[8];
int arr1[8];
int k =0;
int temp1=0;
int i1=0,j1=0;
int x =3,count =0,flag=0,count1=0;
int n= 3;
long int dec,fra;

//

void loop()
{
  long int dec_arr[n+1][n+1];
  long int fra_arr[n+1][n+1][8];
  
  int i =0,j =0, x=3,temp1 =0;
//  digitalWrite(LED_BUILTIN,HIGH);
  if(count<(2*n*n))
  {
    if(digitalRead(12)>0)
    {
      k=1;
//      digitalWrite(LED_BUILTIN,LOW);
    }
    if(k==1)
    {

//      Serial.print("entered the output with count and count1:");
//      Serial.print(" ");
//      Serial.println(count);
//      Serial.print(" ");
//      Serial.println(count1);       
      digitalWrite(11,HIGH); 
//      delay(2000); 
      delay(100);
      if(digitalRead(13))
      {

        delay(100);
         while(i<8)
         {
            arr[i]= digitalRead(x);
//            Serial.print(x);
//            Serial.print("  ");
//            Serial.println(arr[i]);
          //  delay(100);
            x =x+1;
            i= i+1;
         }
        if(count%2==0)
        {
            dec = conv_int(arr);
//            Serial.println(dec);
//            Serial.println("#####");
//            Serial.print(dec);
//            Serial.print("                           ");
           
              dec_arr[i1][j1]=dec;
//               Serial.println(dec_arr[i1][j1]);
            
        }
        else if(count%2==1)
        {
           
            fra = conv_fra(arr);
            fun(fra,arr1);
            for(int index =0;index<8;index++)
            {            
                fra_arr[i1][j1][index] = arr1[index];
            }
            
//            Serial.println(fra);
            flag = 1;
        }
        if(flag==1)
        {
            Serial.print("C");
            Serial.print(i1);
            Serial.print(j1);
            Serial.print(" ");
            Serial.print(dec);
            Serial.print(".");
            while(j<8)
            {
              Serial.print(arr1[j]);
              j= j+1;
            }
          
            Serial.println();


//             Serial.print("                           ");
//             Serial.print(i1);
//             Serial.print(j1);
//             Serial.print("  ");
//             Serial.print(dec_arr[i1][j1]);
//                  Serial.print(".");
//                  for(int index =0;index<8;index++)
//                  {
//                  Serial.print(fra_arr[i1][j1][index]); 
//                  }
//                  Serial.println();

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

            

                  
            flag = 0;
        }
        count = count+1;
        if(count == (2*n*n))
        {
              Serial.println();
              Serial.println();
              Serial.println("final multilpication Matrix formed :");
              for(int l=0;l<n;l++)
              {
                for(int m=0;m<n;m++)
                {
                  Serial.print(dec_arr[l][m]);
                  Serial.print(".");
                  for(int index =0;index<8;index++)
                  {
                  Serial.print(fra_arr[l][m][index]); 
                  }
                  Serial.print("   ");
                }
                Serial.println();
              }
              Serial.println();
              Serial.println();
        }
      } 
      digitalWrite(11,LOW);
      delay(100);
    }
  }

}
