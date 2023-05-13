#define x A0
#define y A1

int x_val;
int y_val;

int x_valinit;
int y_valinit;

void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  Serial.begin(9600);
  x_valinit = analogRead(x);
  y_valinit = analogRead(y);
}

void loop() 
{
  x_val = analogRead(x);
  y_val = analogRead(y);

  int x_axis = x_val - x_valinit;
  int y_axis = y_val - y_valinit;

  if(x_axis >= 40)
  {
    Serial.println("F");
  }
  else if(x_axis <= -40)
  {
    Serial.println("B");
  }
  else if(y_axis >= 40)
  {
    Serial.println("L");
  }
  else if(y_axis <= -40)
  {
    Serial.println("R");
  }
  else
  {
    Serial.println("S");
  }
  delay(200);
}