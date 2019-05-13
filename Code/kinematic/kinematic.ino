#include <Servo.h>
#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

//Definição do tamanhos do braço
#define a1 39.45
#define a2 42.4
#define a3 9.11
#define a4 43.05
#define a5 86 
//#define a5 76 

Servo servoPonta;
Servo servoBase;
Servo servoMeio;

double LastPosX;
double LastPosY;
double LastPosZ;

double t1, t2, t3;



void Inversa(double x, double y, double z) {

  
  double w = sqrt((x * x) + (y * y));

  double wlinha = sqrt( pow((a1 - a3 - z), 2) + pow((w - a2), 2) );

  double alpha, b, gama;

  if ( (a1 - a3 - z) != 0)
  {
    alpha = atan( (w - a2) / (a1 - a3 - z) );
  }
  else
  {
    alpha = asin( (w - a2) / (wlinha) );
  }

  if ( (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha ) > 1  || (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha ) < -1)
  {
    int parteInteira = (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha );

    double pontoFlutuante = (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha ) - parteInteira;
    b = acos( pontoFlutuante );
  }
  else {
    b = acos( (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha ) );

  }
  if ( (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) > 1 || (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) < -1)
  {
    int parteInteira = (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5);

    double pontoFlutuante = (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) - parteInteira;
    gama = acos( pontoFlutuante );

  }

  else {
    gama = acos( (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) );
  }


  t1 = atan2(y, x);

  t2 = HALF_PI - b - alpha;

  t3 = PI - gama;

  Serial.println("Angulo em radiano");
  Serial.println(t1);
  Serial.println(t2);
  Serial.println(t3);

  t1 = t1 * 180 / PI;
  t2 = t2 * 180 / PI;
  t3 = t3 * 180 / PI;

  Serial.println("Angulo em graus");
  Serial.println(t1);
  Serial.println(t2);
  Serial.println(t3);
 Serial.println("===================================================");  
  
}

void DesiredPosition2(double x, double y, double z){
    Inversa(LastPosX,LastPosY,LastPosZ);

    double t1Ant = t1;
    double t2Ant= t2;
    double t3Ant=t3;
    
    Inversa(x,y,z);

    double DesiredT1 = t1;
    double DesiredT2 = t2;
    double DesiredT3 = t3;    

    Serial.print("Angulo1 Atual: ");
    Serial.print(t1Ant);
    Serial.print("   |   ");
    Serial.print("Angulo1 Desejado: ");
    Serial.println(DesiredT1);

    Serial.print("Angulo2 Atual: ");
    Serial.print(t2Ant);
    Serial.print("   |   ");
    Serial.print("Angulo2 Desejado: ");
    Serial.println(DesiredT2);

    Serial.print("Angulo2 Atual: ");
    Serial.print(t3Ant);
    Serial.print("   |   ");
    Serial.print("Angulo3 Desejado: ");
    Serial.println(DesiredT3);

    double deltaT1 = (t1 - t1Ant)/30;
    double deltaT2 = (t2 - t2Ant)/30;
    double deltaT3 = (t3 - t3Ant)/30;
    Serial.println("DESIRED NEW");
    int i;
    for(i=0;i<=30;i++){

      Serial.print("t1:  ");
      Serial.print((t1Ant+deltaT1*i)+90);
      Serial.print("    |   ");
      Serial.print("t2:  ");
      Serial.print((t2Ant+deltaT2*i)+90);
      Serial.print("    |   ");
      Serial.print("t3:  ");
      Serial.print((t3Ant+deltaT3*i)+90);
      Serial.println("");
      servoPonta.write((t3Ant+deltaT3*i)+90);
 
      servoBase.write((t1Ant+deltaT1*i)+90);
      servoMeio.write((t2Ant+deltaT2*i)+90); 
      
      delay(50);
    }
    
    i--;
    Serial.println("DESIRED done:");
    Serial.println(int(t1Ant+deltaT1*i)+90);
    Serial.println(int(t2Ant+deltaT2*i)+90);
    Serial.println(int(t3Ant+deltaT3*i)+90);
    Serial.println("---------------------------");

    LastPosX = x;
    LastPosY = y;
    LastPosZ = z;
}

void write_Paulo()
{
//P


    DesiredPosition2(60,0,-70);
    delay(300);
    DesiredPosition2(60,15,-70);
    delay(300);
    DesiredPosition2(80,15,-70);
    delay(300);
    DesiredPosition2(80,0,-70);

    //=========================//
    DesiredPosition2(90,0,-50);
    delay(500);
    DesiredPosition2(90,0,-70);
   //=========================//
   
      //A
  
    DesiredPosition2(60,0,-70);
    delay(300);
    DesiredPosition2(60,15,-70);
    delay(300);
    DesiredPosition2(90,15,-70);
    delay(300);

    DesiredPosition2(90,0,-50);
    delay(300);

    DesiredPosition2(75,0,-50);
    delay(300);
    DesiredPosition2(75,-1,-70);
    delay(300);
    DesiredPosition2(75,20,-70);


    //=========================//
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
   //=========================//

    // U
   
    DesiredPosition2(100,20,-70);
    delay(500);
    
    DesiredPosition2(100,0,-50);
    delay(500);

    DesiredPosition2(100,0,-70);
    delay(500);
    
    DesiredPosition2(60,0,-70);
    delay(500);
    
    DesiredPosition2(100,20,-50);
    delay(500);

    DesiredPosition2(100,20,-70);
    delay(500);

    DesiredPosition2(60,16,-70);
    delay(500);

    //=========================//
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
   //=========================//

    //L
    DesiredPosition2(60,0,-70);
    delay(500);
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
    DesiredPosition2(100,20,-70);
    delay(500);

    //=========================//
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
   //=========================//

     // O
    DesiredPosition2(100,20,-70);
    delay(500);
    DesiredPosition2(60,17,-70);
    delay(500);
    DesiredPosition2(60,0,-70);   
    delay(500);
    DesiredPosition2(100,0,-70);   
    delay(500);

    //=========================//
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
   //=========================//

     // C
    DesiredPosition2(60,0,-70);
    delay(500);
    DesiredPosition2(60,20,-70);
    delay(500);
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
    DesiredPosition2(100,20,-70);   
    delay(500);

    //=========================//
    DesiredPosition2(80,0,-30);
    delay(500);
   //=========================//

}

void write_Raul()
{
   // R
    DesiredPosition2(60,0,-70);
    delay(300);
    DesiredPosition2(60,15,-70);
    delay(300);
    DesiredPosition2(80,15,-70);
    delay(300);
    DesiredPosition2(80,0,-70);
    
    DesiredPosition2(80,15,-70);
    delay(500);
    DesiredPosition2(100,15,-70);
    delay(500);

     //=========================//
    DesiredPosition2(90,0,-50);
    delay(500);
    DesiredPosition2(90,0,-70);
   //=========================//
   
      //A
  
    DesiredPosition2(60,0,-70);
    delay(300);
    DesiredPosition2(60,15,-70);
    delay(300);
    DesiredPosition2(90,15,-70);
    delay(300);

    DesiredPosition2(90,0,-50);
    delay(300);

    DesiredPosition2(75,0,-50);
    delay(300);
    DesiredPosition2(75,-1,-70);
    delay(300);
    DesiredPosition2(75,20,-70);


    //=========================//
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
   //=========================//

    // U
   
    DesiredPosition2(100,20,-70);
    delay(500);
    
    DesiredPosition2(100,0,-50);
    delay(500);

    DesiredPosition2(100,0,-70);
    delay(500);
    
    DesiredPosition2(60,0,-70);
    delay(500);
    
    DesiredPosition2(100,20,-50);
    delay(500);

    DesiredPosition2(100,20,-70);
    delay(500);

    DesiredPosition2(60,16,-70);
    delay(500);

    //=========================//
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
   //=========================//

    //L
    DesiredPosition2(60,0,-70);
    delay(500);
    DesiredPosition2(100,0,-50);
    delay(500);
    DesiredPosition2(100,0,-70);
    delay(500);
    DesiredPosition2(100,20,-70);
    delay(500);
}


void setup() {
  // put your setup code here, to run once:
  servoPonta.attach(3); // ponta
  servoBase.attach(5);// base
  servoMeio.attach(6);  //meio

  Serial.begin(9600);
  Serial.println("=====================================================================================");

    delay(1000); 
    LastPosX = 100;
    LastPosY = 0;
    LastPosZ = -70;
}
int cont = 0;

void loop() {
  // put your main code here, to run repeatedly:

  if(cont == 0){
  servoMeio.write(90);
  servoPonta.write(90);
  servoBase.write(90);
  delay(2000);



  write_Raul();
   //write_Paulo();

/*
   //P

    DesiredPosition2(60,0,-70);
    delay(300);
    DesiredPosition2(60,20,-70);
    delay(300);
    DesiredPosition2(75,20,-70);
    delay(300);
    DesiredPosition2(75,0,-70);


//===============================//

    DesiredPosition2(90,0,-30);
    delay(500);
    DesiredPosition2(60,0,-70);

//===============================//
/*
    // L
    //LastPosX = 60;
    //LastPosY = 0;
    //LastPosZ = -70;
    
     DesiredPosition2(90,20,-70);
    delay(500);
    DesiredPosition2(60,20,-70);
    delay(500);
*/
/*
 
  //A
  
    DesiredPosition2(90,0,-70);
    delay(300);
    DesiredPosition2(90,20,-70);
    delay(300);
    DesiredPosition2(60,20,-70);
    delay(300);

    DesiredPosition2(75,0,-50);
    delay(300);
        DesiredPosition2(75,0,-70);
    delay(300);
    DesiredPosition2(75,20,-70);

 */
 

  /**
   * 
   * tentando T
    LastPosX = 60;
    LastPosY = -20;
    LastPosZ = -70;
    DesiredPosition2(60,20,-70);
    delay(500);
    
    servoMeio.write(90);
    servoPonta.write(90);
    servoBase.write(90);

    LastPosX = 100;
    LastPosY = 0;
    LastPosZ = -70;
    DesiredPosition2(60,0,70);
    delay(500);

   * 
   * 
   *

   */
   
   
   
   /*
      tentando E

      LastPosX = 60;
      LastPosY = 20;
      LastPosZ = -70;
      
      DesiredPosition2(60,0,-70);
      delay(500);
      DesiredPosition2(100,20,-70);
      delay(500);
      DesiredPosition2(100,0,-70);
      delay(500);

      servoMeio.write(90);
      servoPonta.write(90);
      servoBase.write(90);
      LastPosX = 80;
      LastPosY = 0;
      LastPosZ = -70;
      DesiredPosition2(80,20,-70);
      delay(500);   
   
   */

  /*
  //tendando a PORRA DO N
      LastPosX = 60;
      LastPosY = 20;
      LastPosZ = -70;

     DesiredPosition2(100,20,-70);
     delay(500);
     DesiredPosition2(60,0,-70);
     delay(500);
     DesiredPosition2(100,0,-70);
     delay(500);

  */
  
  


  /**
   * I
   * 
   
    DesiredPosition2(60,0,-70);
    delay(500);
   * 
   * /  
   * 
    */
   /*


/*
 * R
    LastPosX = 100;
    LastPosY = 0;
    LastPosZ = -70;
  

    DesiredPosition2(60,0,-70);
    delay(500);
    DesiredPosition2(60,20,-70);
    delay(500);
    DesiredPosition2(80,20,-70);
    delay(500);
    DesiredPosition2(80,0,-70);
    delay(500);
    DesiredPosition2(80,20,-70);
        delay(500);
    DesiredPosition2(100,20,-70);
*/
/*
 * 


/*
 * v
    LastPosX = 60;
    LastPosY = 0;
    LastPosZ = -70;
    
     DesiredPosition2(100,0,-70);
    delay(500);
    DesiredPosition2(100,20,-70);
    delay(500);
    DesiredPosition2(60,20,-70);
    delay(500);
*/



/*
 * U
     LastPosX = 60;
    LastPosY = 0;
    LastPosZ = -70;
    
     DesiredPosition2(100,0,-70);
    delay(500);
    DesiredPosition2(100,23,-70);
    delay(500);

          servoMeio.write(90);
  servoPonta.write(90);
  servoBase.write(90);

    LastPosX = 100;
    LastPosY = 20;
    LastPosZ = -70;

    DesiredPosition2(65,20,-70);
  */
    /*
     * O
     DesiredPosition2(60,0,-70);
    delay(500);
    DesiredPosition2(60,15,-70);
    delay(500);
    DesiredPosition2(100,15,-70);   
    delay(500);
    DesiredPosition2(100,0,-70);

          */

/*

              LastPosX = 100;
    LastPosY = 20;
    LastPosZ = -70;
         Inversa(100,20,-70);

         
      servoMeio.write(t2);
  servoPonta.write(t3);
  servoBase.write(t1);
         
         DesiredPosition2(100,0,-70);
    delay(500);
    DesiredPosition2(60,0,-70);
    delay(500);
        DesiredPosition2(60,20,-70);
        */
    cont = 1;
  }

}
