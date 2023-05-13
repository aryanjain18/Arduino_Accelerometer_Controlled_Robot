#define led 13

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char val = Serial.read();
    if(val == 'F' )
    {
      digitalWrite(led, HIGH);
      Serial.println("F");
      carForward();
    }
    else if(val == 'L' )
    {
      digitalWrite(led, HIGH);
      Serial.println("L");
      carLeft();
    }
    else if(val == 'B' )
    {
      digitalWrite(led, HIGH);
      Serial.println("B");
      carBackward();
    }
    else if(val == 'R' )
    {
      digitalWrite(led, HIGH);
      Serial.println("R");
      carRight();
    }
    else if(val == 'S')
    {
      digitalWrite(led, LOW);
      Serial.println("S");
      carStop();
    }
  }
}

//Motor movement functions
void carForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
