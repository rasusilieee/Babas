#include <SoftwareSerial.h>
#include <Servo.h>

//SERVOS
Servo BASE;
Servo ART_1;
Servo ART_2;
Servo GANCHO;

//BLUETOOTH
SoftwareSerial bluetooth(5, 6); // RX, TX

//SERVOS Y POSICIONES INICIALES
int BASE_PWRD=9;
int P_BASE =90;

int ART_1_PWRD=10;
int P_ART_1=50;

int ART_2_PWRD=11;
int P_ART_2=140;

int GANCHO_PWRD=12;
int P_GANCHO=75;

int vel=10;

char val;
String estado;

void setup() {
  BASE.attach(BASE_PWRD);
  ART_1.attach(ART_1_PWRD);
  ART_2.attach(ART_2_PWRD);
  GANCHO.attach(GANCHO_PWRD);

  BASE.write(P_BASE);
  delay(100);
  ART_1.write(P_ART_1);
  delay(100);
  ART_2.write(P_ART_2);
  delay(100);
  GANCHO.write(P_GANCHO);
  delay(100);
  
  Serial.begin(9600);
  bluetooth.begin(9600);
}

//Metodos SERVOS
 void BASE_SERVO(){
    pinMode(BASE_PWRD,HIGH);
    delay(100);
    while(bluetooth.available())
    {
      char c = bluetooth.read();
      estado += c;
      Serial.print(estado);
    }
    if (estado.length() > 0)
    {
      int a = estado.toInt();
      if(a>P_BASE)
      {
        for(int i=P_BASE;i<a;i++)
        {
          BASE.write(i);
          delay(25);
        }
      }
      else
      {
        for(int i=P_BASE;i>a;i--)
        {
          BASE.write(i);
          delay(25);
        }
      }
      P_BASE=a;
      estado = "";
    }
  }
  void ART1_SERVO(){
    pinMode(ART_1_PWRD,HIGH);
    delay(100);
    while(bluetooth.available())
    {
      char c = bluetooth.read();
      estado += c;
      Serial.print(estado);
    }
       if (estado.length() > 0)
    {
      int a = estado.toInt();
      if(a>P_ART_1)
      {
        for(int i=P_ART_1;i<a;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
      else
      {
        for(int i=P_ART_1;i>a;i--)
        {
          ART_1.write(i);
          delay(25);
        }
      }
      
      P_ART_1=a;
      estado = "";
    }
  }
  void ART2_SERVO(){
    pinMode(ART_2_PWRD,HIGH);
    delay(100);
    while(bluetooth.available())
    {
      char c = bluetooth.read();
      estado += c;
      Serial.print(estado);
    }
    if (estado.length() > 0)
    {
      int a = estado.toInt();
      if(a>P_ART_2)
      {
        for(int i=P_ART_2;i<a;i++)
        {
          ART_2.write(i);
          delay(25);
        }
      }
      else
      {
        for(int i=P_ART_2;i>a;i--)
        {
          ART_2.write(i);
          delay(25);
        }
      }
      
      P_ART_2=a;
      estado = "";
    }
  }
  void GANCHO_SERVO(){
    pinMode(GANCHO_PWRD,HIGH);
    delay(100);
    
    while(bluetooth.available())
    {
      char c = bluetooth.read();
      estado += c;
      Serial.print(estado);
    }
    if (estado.length() > 0)
    {
      int a = estado.toInt();
      if(a>P_GANCHO)
      {
        for(int i=P_GANCHO;i<a;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
      else
      {
        for(int i=P_GANCHO;i>a;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      
      P_GANCHO=a;
      estado = "";
    }
  }

//METODO SALUDO
  void Saludo_1()
  {
    /*Servo BASE;
    Servo ART_1;
    Servo ART_2;
    Servo GANCHO;
    P_BASE
    P_ART_1
    P_ART_2
    P_GANCHO*/
    Serial.println("Posiciones Iniciales------------------------------");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("--------------------------------------------------");
    
    if(90>P_BASE)
      {
        for(int i=P_BASE;i<90;i++)
        {
          BASE.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_BASE;i>90;i--)
        {
          BASE .write(i);
          delay(25);
        }
      }
    P_BASE=90; //Nueva Posición
    
    if(70>P_ART_1)
      {
        for(int i=P_ART_1;i<70;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>70;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=70; //Nueva Posición
     
     if(100>P_ART_2)
      {
        for(int i=P_ART_2;i<100;i++)
        {
          ART_2.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_2;i>100;i--)
        {
          ART_2 .write(i);
          delay(25);
        }
      }
     P_ART_2=100; //Nueva Posición
      
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
    Serial.println("PARTE 1");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 1 -> LISTO--------------------------------------------------");
    Serial.println("");

     //PARTE 2
     if(12>P_ART_1)
      {
        for(int i=P_ART_1;i<12;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>12;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=12; //Nueva Posición
      
     if(15>P_ART_2)
      {
        for(int i=P_ART_2;i<15;i++)
        {
          ART_2.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_2;i>15;i--)
        {
          ART_2 .write(i);
          delay(25);
        }
      }
     P_ART_2=15; //Nueva Posición
      
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
    Serial.println("PARTE 2");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 2 -> LISTO--------------------------------------------------");
    Serial.println("");

     //Parte 3
     if(50>P_ART_1)
      {
        for(int i=P_ART_1;i<50;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>50;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
      if(140>P_ART_2)
      {
        for(int i=P_ART_2;i<140;i++)
        {
          ART_2.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_2;i>140;i--)
        {
          ART_2 .write(i);
          delay(25);
        }
      }
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
             
    Serial.println("PARTE 3");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 3 -> LISTO--------------------------------------------------");
    Serial.println("");

     
  }

  void Saludo_2()
  {
    //Parte 4
     if(40>P_BASE)
      {
        for(int i=P_BASE;i<40;i++)
        {
          BASE.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_BASE;i>40;i--)
        {
          BASE .write(i);
          delay(25);
        }
      }
    P_BASE=40; //Nueva Posición
    
    for(int i=0;i<3;i++)
    {
          if(75>P_ART_1)
      {
        for(int i=P_ART_1;i<75;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>75;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=75; //Nueva Posición

     if(50>P_ART_1)
      {
        for(int i=P_ART_1;i<50;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>50;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=50; //Nueva Posición
    }
     
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
     
    Serial.println("PARTE 4");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 4 -> LISTO--------------------------------------------------");
    Serial.println("");

    //Parte 5
     if(90>P_BASE)
      {
        for(int i=P_BASE;i<90;i++)
        {
          BASE.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_BASE;i>90;i--)
        {
          BASE .write(i);
          delay(25);
        }
      }
    P_BASE=90; //Nueva Posición
    
    for(int i=0;i<3;i++)
    {
          if(75>P_ART_1)
      {
        for(int i=P_ART_1;i<75;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>75;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=75; //Nueva Posición

     if(50>P_ART_1)
      {
        for(int i=P_ART_1;i<50;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>50;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=50; //Nueva Posición
    }
     
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
     
    Serial.println("PARTE 5");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 5 -> LISTO--------------------------------------------------");
    Serial.println("");

    //Parte 6
     if(140>P_BASE)
      {
        for(int i=P_BASE;i<140;i++)
        {
          BASE.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_BASE;i>140;i--)
        {
          BASE .write(i);
          delay(25);
        }
      }
    P_BASE=140; //Nueva Posición
    
    for(int i=0;i<3;i++)
    {
          if(75>P_ART_1)
      {
        for(int i=P_ART_1;i<75;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>75;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=75; //Nueva Posición

     if(50>P_ART_1)
      {
        for(int i=P_ART_1;i<50;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>50;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
     P_ART_1=50; //Nueva Posición
    }
     
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
     
    Serial.println("PARTE 6");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 6 -> LISTO--------------------------------------------------");
    Serial.println("");

    //Parte 7
    if(90>P_BASE)
      {
        for(int i=P_BASE;i<90;i++)
        {
          BASE.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_BASE;i>90;i--)
        {
          BASE .write(i);
          delay(25);
        }
      }
    P_BASE=90; //Nueva Posición
     if(50>P_ART_1)
      {
        for(int i=P_ART_1;i<50;i++)
        {
          ART_1.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_1;i>50;i--)
        {
          ART_1 .write(i);
          delay(25);
        }
      }
      if(140>P_ART_2)
      {
        for(int i=P_ART_2;i<140;i++)
        {
          ART_2.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_ART_2;i>140;i--)
        {
          ART_2 .write(i);
          delay(25);
        }
      }
     for(int i=0;i<3;i++)
     {
      if(120>P_GANCHO)
      {
        for(int i=P_GANCHO;i<120;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>120;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=120;
      
      if(80>P_GANCHO)
      {
        for(int i=P_GANCHO;i<80;i++)
        {
          GANCHO.write(i);
          delay(25);
        }
      }
     else
      {
        for(int i=P_GANCHO;i>80;i--)
        {
          GANCHO .write(i);
          delay(25);
        }
      }
      P_GANCHO=80;
     }
             
    Serial.println("PARTE 7");
    Serial.println("Posición Servo Base: ");
    Serial.println(P_BASE);
    Serial.println("Posición Servo ART_1: ");
    Serial.println(P_ART_1);
    Serial.println("Posición Servo ART_2: ");
    Serial.println(P_ART_2);
    Serial.println("Posición Servo Gancho: ");
    Serial.println(P_GANCHO);
    Serial.println("PARTE 7 -> LISTO--------------------------------------------------");
    Serial.println("");    
  }

void loop() {
  delay(250);
  if (bluetooth.available()) {
    val = bluetooth.read();

    if(val == 'B')
    {
      Serial.println("SERVO: ");
      Serial.print(val);
      Serial.println();
      BASE_SERVO();
      delay(100);
      
      
    }
    if(val == 'A')
    {
      Serial.println("SERVO: ");
      Serial.print(val);
      Serial.println();
      ART1_SERVO();
      delay(100);
      
    }
    if(val == 'C')
    {
      Serial.println("SERVO: ");
      Serial.print(val);
      Serial.println();
      ART2_SERVO();
      delay(100);
    }
    if(val == 'G')
    {
      Serial.println("SERVO: ");
      Serial.print(val);
      Serial.println();
      GANCHO_SERVO();
      delay(100);
    }
    if(val == 'S')
    {
      Saludo_1();
      delay(100);
    }
    if(val == 'D')
    {
      Saludo_2();
      delay(100);
    }
    //Serial.write(bluetooth.read());
  }

  //  bluetooth.write(Serial.read());
  
}
