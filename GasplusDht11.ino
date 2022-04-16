#include <dht.h>
#define dht_apin A0 // Analog Pin sensor is connected to
dht DHT;
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
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
 
}// end loop()