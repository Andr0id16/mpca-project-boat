int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup()
{
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(smokeA0, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int analogSensor = analogRead(smokeA0);

    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
    // Checks if it has reached the threshold value
    if (analogSensor > sensorThres)
    {
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
    }
    else
    {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
    }
    delay(100);
}
