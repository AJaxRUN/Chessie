/*                     ------Input Pattern Code-------
    
    Command format looks like ---- action:motor:direction:steps:;
    hyphen (-) for any value represents empty
    
    {
      action: m - move, i - move to origin, e - engage magnet, d - disengage magnet, p - parallel motion
      motor: 1 - x_motor, 2 - y_motor
      direction: 1 - one way, 0 - otherway
    }

*/

uint8_t limitSwitch1 = A0;
uint8_t limitSwitch2 = D0;

// motor x
uint8_t x_motor[4] = {D4,D3,D2,D1}

// motor y
uint8_t y_motor[4] = {D8,D7,D6,D5}

String Action;
uint8_t Motor[4];
int Direction, Steps;

const uint16_t _delay = 1; /* delay in between two steps. minimum delay more the rotational speed */
const uint16_t stepper_resolution = 5;

void setup()
{
  pinMode(limitSwitch1, INPUT); /* set four wires as output */
  pinMode(limitSwitch2, INPUT);

  pinMode(wire1, OUTPUT);
  pinMode(wire2, OUTPUT);
  pinMode(wire3, OUTPUT); /* set four wires as output */
  pinMode(wire4, OUTPUT);
  pinMode(wire5, OUTPUT);
  pinMode(wire6, OUTPUT);
  pinMode(wire7, OUTPUT); /* set four wires as output */
  pinMode(wire8, OUTPUT);

  Serial.begin(115200);
}


void loop()
{
  while (!Serial.available());

  String controlCommand = Serial.readStringUntil(';');
  

  setCommandToExecute(controlCommand);
 
  // if (controlCommand.equals("init"))
  // {
  //   moveToOrigin();
  // }

  // int wayToRotate = controlCommand.toInt();
  // if (wayToRotate == 1)
  // {
  //   moveOneWay();
  // }
  // else if (wayToRotate == 0)
  // {
  //   moveOtherWay();
  // }
  // Serial.println(wayToRotate);
}
