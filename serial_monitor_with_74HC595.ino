int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0;
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  updateShiftRegister();
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      int led = ch - '0';
      // Toggle the LED bit using XOR operator
      leds = leds ^ (1 << led);
      updateShiftRegister();
      
      // Check if LED is now on or off
      if (bitRead(leds, led)) {
        Serial.print("Turned on LED ");
      } else {
        Serial.print("Turned off LED ");
      }
      Serial.println(led);
    }
    if (ch == 'x')
    {
      leds = 0;
      updateShiftRegister();
      Serial.println("Cleared");
    }
  }
}


