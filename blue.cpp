const int data = 2;
const int store = 3;
const int shift = 4;

int potiValue;

// column counter
int j = 0;
// showDuration counter
int k;

int row[8] = {127, 191, 223, 239, 247, 251, 253, 254};
// Smiley Happy
int columnH[8] = {60, 66, 165, 129, 165, 153, 66, 60};
// Smiley Normal
int columnN[8] = {60, 66, 165, 129, 129, 189, 66, 60};
// Smiley Sad
int columnS[8] = {60, 66, 165, 129, 153, 165, 66, 60};

void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(data, OUTPUT); // data
  pinMode(store, OUTPUT); // store
  pinMode(shift, OUTPUT); // shift
  
  pinMode(13, OUTPUT);
}

void poti()
{
  potiValue = analogRead(0);
}

void happy()
{
  for(k = 0; k<100; k++)
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(store, LOW);
      shiftOut(data, shift, LSBFIRST, columnH[j]);
      shiftOut(data, shift, LSBFIRST, row[i]);
      digitalWrite(store, HIGH);
      j++;
      poti();
      delay(potiValue);
    }
    j = 0;
  }
}

void normal()
{
  for(k = 0; k<100; k++)
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(store, LOW);
      shiftOut(data, shift, LSBFIRST, columnN[j]);
      shiftOut(data, shift, LSBFIRST, row[i]);
      digitalWrite(store, HIGH);
      j++;
      poti();
      delay(potiValue);
    }
    j = 0;
  }
}

void sad()
{
  for(k = 0; k<100; k++)
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(store, LOW);
      shiftOut(data, shift, LSBFIRST, columnS[j]);
      shiftOut(data, shift, LSBFIRST, row[i]);
      digitalWrite(store, HIGH);
      j++;
      poti();
      delay(potiValue);
    }
    j = 0;
  }
}

void loop()
{
  happy();
  normal();
  sad();
  normal();
}