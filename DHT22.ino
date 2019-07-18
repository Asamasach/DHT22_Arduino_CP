#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define ledPin 13
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int a;
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin, OUTPUT);
}

void loop()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
      if (hum < 35){
        digitalWrite(ledPin, HIGH);
        a="HIGH";
      }
      if (hum > 45){
        digitalWrite(ledPin, LOW);
      }
      Serial.println(a);  
        a="LOW";
    //delay(10000); //Delay 2 sec.
}
