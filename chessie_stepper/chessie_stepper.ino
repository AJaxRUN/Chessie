uint8_t wire1 = D3;
uint8_t wire2 = D2;
uint8_t wire3 = D1;
uint8_t wire4 = D0;

const uint16_t _delay = 5; /* delay in between two steps. minimum delay more the rotational speed */

void sequence(bool a, bool b, bool c, bool d){  /* four step sequence to stepper motor */
  digitalWrite(wire1, a);
  digitalWrite(wire2, b);
  digitalWrite(wire3, c);
  digitalWrite(wire4, d);
  delay(_delay);
}

void setup() {
  pinMode(wire1, OUTPUT); /* set four wires as output */
  pinMode(wire2, OUTPUT);
  pinMode(wire3, OUTPUT);
  pinMode(wire4, OUTPUT);
  Serial.begin(19200);
}

void oneWay() {
  for(int i = 0; i<600; i++)
  {
    sequence(HIGH, LOW, LOW, LOW);
    sequence(HIGH, HIGH, LOW, LOW);
    sequence(LOW, HIGH, LOW, LOW);
    sequence(LOW, HIGH, HIGH, LOW);
    sequence(LOW, LOW, HIGH, LOW);
    sequence(LOW, LOW, HIGH, HIGH);
    sequence(LOW, LOW, LOW, HIGH);
    sequence(HIGH, LOW, LOW, HIGH);
  }
  sequence(HIGH, LOW, LOW, LOW);
}

void loop() {
  /* Rotation in one direction */
  Serial.println("One Way!");
  
  delay(3000);
  /* Rotation in opposite direction */
  Serial.println("The other Way!");
  for(int j = 0; j<600; j++)
  {
    sequence(LOW, LOW, LOW, HIGH);
    sequence(LOW, LOW, HIGH, HIGH);
    sequence(LOW, LOW, HIGH, LOW);
    sequence(LOW, HIGH, HIGH, LOW);
    sequence(LOW, HIGH, LOW, LOW);
    sequence(HIGH, HIGH, LOW, LOW);
    sequence(HIGH, LOW, LOW, LOW);
    sequence(HIGH, LOW, LOW, HIGH);
  }
  sequence(LOW, LOW, LOW, HIGH);
  delay(3000);
}
