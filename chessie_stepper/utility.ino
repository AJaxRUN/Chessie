void sequence(bool a, bool b, bool c, bool d, uint8_t motor[4] = Motor)
{ /* four step sequence to stepper motor */
  digitalWrite(motor[0], a);
  digitalWrite(motor[1], b);
  digitalWrite(motor[2], c);
  digitalWrite(motor[3], d);
  delay(_delay);
}

void justMove()
{
  if (Direction == 1)
  {
    moveOneWay();
  }
  else
  {
    moveOtherWay();
  }
}

void moveToOrigin()
{

  if (Motor[0] == x_motor[0])
  {
    while (analogRead(limitSwitch1) == 0)
    {
      justMove();
    }
  }
  else
  {
    while (digitalRead(limitSwitch1) == LOW)
    {
      justMove();
    }
  }
}

void moveOneWay()
{
  for (int i = 0; i < Steps * stepper_resolution; i++)
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

void moveOtherWay()
{
  for (int j = 0; j < Steps * stepper_resolution; j++)
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

void setCommandToExecute(String controlCommand)
{
  String commands[4], temp;
  int arrayLoc = 0;

  for (int i = 0; i < controlCommand.length(); i++)
  {
    if (controlCommand.charAt(i) != ':')
    {
      temp += controlCommand.charAt(i);
    }
    else if (controlCommand.charAt(i) == ':')
    {
      commands[arrayLoc] = temp;
      temp = "";
      arrayLoc++;
    }
  }

  Action = commands[0];
  Direction = commands[2].toInt();
  Steps = commands[3].toInt();

  if (commands[1].toInt() == 1)
  {
    Motor = x_motor;
  }
  else if (commands[1].toInt() == 2)
  {
    Motor = y_motor;
  }
}