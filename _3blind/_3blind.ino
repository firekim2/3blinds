int irSense[3];
int led[3];
int is_on[3];
int distances[3];
int trigger[3];

void setup()
{
  Serial.begin(9600);
  irSense[0] = A0;
  irSense[1] = A1;
  irSense[2] = A2;
  led[0] = 8;
  led[1] = 9;
  led[2] = 10;
  is_on[0] = 0;
  is_on[1] = 0;
  is_on[2] = 0;
  trigger[0] = 200;
  trigger[1] = 200;
  trigger[2] = 250;
  delay(30);
  int i = 0;
  while (i < 3)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);  
    i++;
  }
}

void loop()
{ 
  irRead();
  swtch();
  delay(82.5);
}

void swtch()
{
 int i = 0;
 while (i < 3)
 {
  if (is_on[i] == 0)
  {
    if (distances[i] > trigger[i] - 30 && distances[i] < trigger[i] + 30)
    {
     is_on[i] = 1;
     Serial.print("led");
     Serial.print(i);
     Serial.println(" turn on.");
     digitalWrite(led[i], HIGH);
     delay(16.5*300);
    }
  }
  else
  {
    if (distances[i] < trigger[i] - 50 || distances[i] > trigger[i] + 50)
    {
      is_on[i] = 0;
      Serial.print("led");
      Serial.print(i);
      Serial.println(" turn off.");
      digitalWrite(led[i], LOW);
      delay(16.5*50);
    }
  }
  Serial.print(i);
  Serial.print(" : ");
  Serial.print(distances[i]);
  Serial.print(" , ");
  i++;
 }
 Serial.println();
}


void irRead()
{
  int averaging[3];
  int minimum[3];
  int maximum[3];
  int i = 0;
  int distance;
  while (i < 3)
  {
    distance = analogRead(irSense[i]);
    averaging[i] = distance;
    minimum[i] = distance;
    maximum[i] = distance;
    i++;
  }
  delay(16.5);
  for (int j=0; j<9; j++)
  {
    i = 0;
    while (i < 3)
    {
      distance = analogRead(irSense[i]);
      averaging[i] = averaging[i] + distance;
      if (distance < minimum[i])
        minimum[i] = distance;
      else if (distance > maximum[i])
        maximum[i] = distance;
      i++;
    }
    delay(16.5);
  }
  
  i = 0;
  while(i < 3)
  {
    averaging[i] -= (minimum[i] + maximum[i]);
    distance = averaging[i] / 8;
    if(distance >= 280 && distance <= 512)
      distances[i] = 28250 / (distance - 229.5);
    else
      distances[i] = 0;
    i++;
  }
}
int irSense[3];
int led[3];
int is_on[3];
int distances[3];
int trigger[3];

void setup()
{
  Serial.begin(9600);
  irSense[0] = A0;
  irSense[1] = A1;
  irSense[2] = A2;
  led[0] = 8;
  led[1] = 9;
  led[2] = 10;
  is_on[0] = 0;
  is_on[1] = 0;
  is_on[2] = 0;
  trigger[0] = 200;
  trigger[1] = 200;
  trigger[2] = 250;
  delay(30);
  int i = 0;
  while (i < 3)
  {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);  
    i++;
  }
}

void loop()
{ 
  irRead();
  swtch();
  delay(82.5);
}

void swtch()
{
 int i = 0;
 while (i < 3)
 {
  if (is_on[i] == 0)
  {
    if (distances[i] > trigger[i] - 30 && distances[i] < trigger[i] + 30)
    {
     is_on[i] = 1;
     Serial.print("led");
     Serial.print(i);
     Serial.println(" turn on.");
     digitalWrite(led[i], HIGH);
     delay(16.5*300);
    }
  }
  else
  {
    if (distances[i] < trigger[i] - 50 || distances[i] > trigger[i] + 50)
    {
      is_on[i] = 0;
      Serial.print("led");
      Serial.print(i);
      Serial.println(" turn off.");
      digitalWrite(led[i], LOW);
      delay(16.5*50);
    }
  }
  Serial.print(i);
  Serial.print(" : ");
  Serial.print(distances[i]);
  Serial.print(" , ");
  i++;
 }
 Serial.println();
}


void irRead()
{
  int averaging[3];
  int minimum[3];
  int maximum[3];
  int i = 0;
  int distance;
  while (i < 3)
  {
    distance = analogRead(irSense[i]);
    averaging[i] = distance;
    minimum[i] = distance;
    maximum[i] = distance;
    i++;
  }
  delay(16.5);
  for (int j=0; j<9; j++)
  {
    i = 0;
    while (i < 3)
    {
      distance = analogRead(irSense[i]);
      averaging[i] = averaging[i] + distance;
      if (distance < minimum[i])
        minimum[i] = distance;
      else if (distance > maximum[i])
        maximum[i] = distance;
      i++;
    }
    delay(16.5);
  }
  
  i = 0;
  while(i < 3)
  {
    averaging[i] -= (minimum[i] + maximum[i]);
    distance = averaging[i] / 8;
    if(distance >= 280 && distance <= 512)
      distances[i] = 28250 / (distance - 229.5);
    else
      distances[i] = 0;
    i++;
  }
}

