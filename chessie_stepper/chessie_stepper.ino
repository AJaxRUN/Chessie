uint8_t wire1 = D3;
uint8_t wire2 = D2;
uint8_t wire3 = D1;
uint8_t wire4 = D0;

const uint16_t _delay = 4; /* delay in between two steps. minimum delay more the rotational speed */

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
  Serial.begin(115200);
}

void controlOneWay() {
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

void controlOtherWay() {
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
}

void loop() {
  while (!Serial.available());
  String temp =  Serial.readString();
  Serial.println(temp);
  int wayToRotate = temp.toInt();
  Serial.flush();
  if(wayToRotate == 1) {
    
    controlOneWay();
  }
  else if(wayToRotate == 2){
    controlOtherWay();
  }
}
