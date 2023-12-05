int analogPin = 0; // Analog Pin A3 (A0 doesn't work)
int raw =  0; // Initializes a variable raw to store the raw analog reading.
int Vin = 5; // input voltage 3.5 volts
float Vout = 0; // Initializes a variable Vout to store the calculated output voltage.
float R1 = 1000; // Sets the known resistance (R1) to 1000 Ohms.
float R2 = 0; // Initializes a variable R2 to store the calculated resistance.
float buffer = 0; //  Initializes a buffer variable.

void setup()
{

  Serial.begin(9600);
}

void loop()
{
  raw = analogRead(analogPin);

  if(raw) 
  { 
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R2 = R1 * buffer;
    Serial.print("Raw Value: ");
    Serial.println(raw);
    
    Serial.print("Buffer Value: ");
    Serial.println(buffer);

    Serial.print("Output voltage: ");
    Serial.print(Vout);
    Serial.println(" Volts");
    Serial.print("Resistor value: ");
    Serial.print(R2);
    Serial.println(" Ohm");
    delay(1000);
  }
  else
  {
    Serial.println("Error reading analog pin.");
  }
}
