#include <Servo.h>
#include <SoftwareSerial.h>

const int IN1 = 12;
const int IN2 = 11;
const int IN3 = 2;
const int IN4 = 9;
int BTTx = 7;//7
int BTRx = 6;//6
int val[7] = {0, 70, 90, 100, 0, 65, 30};
int maxi[7] = {0, 180, 110, 180, 180, 130, 50};
int mini[7] = {0, 0, 0, 0, 0, 0, 0};
int nr = 5;

SoftwareSerial BT(7, 6);

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
void setup()
{

  Serial.begin(9600);
  BT.begin(9600);
  Serial.setTimeout(0);
  BT.setTimeout(0);
  myservo1.attach(3);
  myservo2.attach(4);
  myservo3.attach(5);
  myservo4.attach(8);
  myservo5.attach(10);
  myservo6.attach(13);

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  myservo1.write(val[1]);
  myservo2.write(val[2]);
  myservo3.write(val[3]);
  myservo4.write(val[4]);
  myservo5.write(val[5]);
  myservo6.write(val[6]);


}
void Fata() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}
void Spate() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stanga() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void Dreapta() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop()
{

  if (BT.available())
  {
    String value = BT.readString();
    value.trim(); // SCOATE SPATIILE LIBERE

    if (value != NULL && value != " " && value != '\n' ) {

      if ( value == "W")
        Fata();
      else if (value == "A")
        Stanga();
      else if (value == "S")
        Spate();
      else if (value == "D")
        Dreapta();
      else if (value == "X")
        Stop();
      else if (value == "F")
      {
        if (val[1] - nr > mini[1])
        {
          val[1] -= nr;
          myservo1.write(val[1]);
          
        }
      }
      else if (value == "T")
      {
        if (val[1] - nr < maxi[1])
        {
          val[1] += nr;
          myservo1.write(val[1]);
          
        }

      }
     else if (value == "G")
      {
        if (val[2] - nr > mini[2])
        {
          val[2] -= nr;
          myservo2.write(val[2]);
        }

      }
      else if (value == "Y")
      {
        if (val[2] - nr < maxi[2])
        {
          val[2] += nr;
          myservo2.write(val[2]);

        }
      }
      else if (value == "H")
      {
        if (val[3] - nr > mini[3])
        {
          val[3] -= nr;
          myservo3.write(val[3]);
        }
      }
      else if (value == "U")
      {
        if (val[3] - nr < maxi[3])
        {
          val[3] += nr;
          myservo3.write(val[3]);

        }
      }
      else if (value == "J")
      {
        if (val[4] - nr > mini[4])
        {
          val[4] -= nr;
          myservo4.write(val[4]);
        }

      }
      else if (value == "I")
      {
        if (val[4] - nr < maxi[4])
        {
          val[4] += nr;
          myservo4.write(val[4]);

        }
      }
      else if (value == "K")
      {
        if (val[5] - nr > mini[5])
        {
          val[5] -= nr;
          myservo5.write(val[5]);
        }

      }
      else if (value == "O")
      {
        if (val[5] - nr < maxi[5])
        {
          val[5] += nr;
          myservo5.write(val[5]);

        }
      }
      else if (value == "L")
      {
        if (val[6] - nr > mini[6])
        {
          val[6] -= nr;
          myservo6.write(val[6]);
        }

      }
      else if (value == "P")
      {
        if (val[6] - nr < maxi[6])
        {
          val[6] += nr;
          myservo6.write(val[6]);

        }
      }


      /*
          de la primul motor la ultimul (de jos in sus) ---
          1. F --- scade  ;;; T --- creste
          2. G --- scade  ;;; Y --- creste
          3. H --- scade  ;;; U --- creste
          4. J --- scade  ;;; I --- creste
          5. K --- scade  ;;; O --- creste
          6. L --- scade  ;;; P --- creste

      */



    }
  }
}

