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
#define a5 17.15


Servo servoPonta;
Servo servoBase;
Servo servoMeio;

float t11, t22, t33;


double X, Y, Z;
double t1, t2, t3;


void PositionChecker(double x, double y, double z) {

  if (x < 55) x = 55;
}

void Inversa(double x, double y, double z) {

  //PositionChecker(x, y, z);

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

//    Serial.println("Ponto flutuante");
//    Serial.println(pontoFlutuante);

    b = acos( pontoFlutuante );

//    Serial.println("cos");
//    Serial.println(b);

  }
  else {
    b = acos( (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha ) );
//    Serial.println("cos");
//    Serial.println(b);
  }



  if ( (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) > 1 || (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) < -1)
  {
    int parteInteira = (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5);

    double pontoFlutuante = (pow(a4, 2) + pow(wlinha, 2) - pow(a5, 2) ) / ( 2 * a4 * wlinha ) - parteInteira;

    Serial.println("parteInteira");
    Serial.println(parteInteira);

        Serial.println("ponroFlutuante");
    Serial.println(pontoFlutuante);

    gama = acos( pontoFlutuante );

//    Serial.println("cos");
//    Serial.println(gama);

  }

  else {
    gama = acos( (pow(a4, 2) + pow(a5, 2) - pow(wlinha, 2) ) / (2 * a4 * a5) );

//    Serial.println("cos");
//    Serial.println(gama);
  }



  //double gama = acos( (pow(a4,2)+pow(a5,2)-pow(wlinha,2) ) / (2*a4*a5) );



//  Serial.println("w");
//  Serial.println(w);
//
//  Serial.println("w'");
//  Serial.println(wlinha);
//
//  Serial.println("alpha");
//  Serial.println(alpha);
//
//  Serial.println("beta");
//  Serial.println(b);
//
//  Serial.println("gama");
//  Serial.println(gama);

  t1 = atan2(y, x);

  t2 = HALF_PI - b - alpha;

  t3 = PI - gama;

  if(t1>PI) t1 = PI;
  else if (t1<0) t1 = 0;

    if(t2>PI) t2 = PI;
  else if (t2<0) t2 = 0;

    if(t3>PI) t3 = PI;
  else if (t3<0) t3 = 0;


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

//  t11 = map(t1, -90, 90, 0, 180);
//  t22 = map(t2, -90, 90, 0, 180);
//  t33 = map(t3, -90, 90, 0, 180);

//  Serial.println("Angulo mapeados");
//  Serial.println(t11);
//  Serial.println(t22);
//  Serial.println(t33);

  if (t11 > 180)  t11 = 178;
  else if (t11 < 0)  t11 = 0;

  if (t22 > 180)  t22 = 178;
  else if (t22 < 0)  t22 = 0;

  if (t33 > 180)  t33 = 178;
  else if (t33 < 0)  t33 = 0;

  
//  Serial.println("Angulo mapeados apos as limitações");
//  Serial.println(t11);
//  Serial.println(t22);
//  Serial.println(t33);

  servoPonta.write(t11);
  servoBase.write(t22);
  servoMeio.write(t33);
}

void Direta(double teta1, double teta2, double teta3) {

  X = (cos(t11) * (861 * cos(t22 + t33) + 848 * cos(t22) + 789)) / 20;
  Y = (sin(t11) * (861 * cos(t22 + t33) + 848 * cos(t22) + 789)) / 20;
  Z = 343 / 20 - (212 * sin(t22)) / 5 - (861 * sin(t22 + t33)) / 20;

}

//pino 7 teta1
//ppino 5 teta2
//pino 3 teta3
void setup() {
  // put your setup code here, to run once:
  servoPonta.attach(3); // ponta
  servoBase.attach(5);// base
  servoMeio.attach(6);  //meio
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("=====================================================================================");
  //  t1=map(0, -90, 90, 0, 180);
  //  t2=map(0, -90, 90, 0, 180);
  //  t3=map(0, -90, 90, 0, 180);
  //servoPonta.write(146.00);
  //servoMeio.write(142.00);
  //servoBase.write(108);
  //Inversa(60, 0, -20);
}
int cont = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(13,HIGH);
  delay(500);

  //digitalWrite(13,LOW);
  delay(500);
  if (cont == 0) {
    delay(1000);
    Inversa(60, 0, -20);
    delay(1000);
    Inversa(90, 0, -20);
    delay(1000);
    Inversa(90, 20, -20);
    delay(1000);
    Inversa(70, 20, -20);
    delay(1000);
    Inversa(70, 0, -20);
    cont++;
    //m1.write(t1*180/PI);
    //m2.write(t2*180/PI);
    // m3.write(t3*180/PI);
  }
}
