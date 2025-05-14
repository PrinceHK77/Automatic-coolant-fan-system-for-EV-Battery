 

#include <Adafruit_Sensor.h> 

#include <DHT.h> 

#include <DHT_U.h> 

#include <Wire.h> 

#include <LiquidCrystal_I2C.h> 

#define DHTPIN 7         // DHT11 sensor data pin 

#define DHTTYPE DHT11    // DHT sensor type 

#define FAN_PIN 9        // Fan control pin 

#define TEMPERATURE_THRESHOLD_HIGH 45 // High temperature threshold 

#define TEMPERATURE_THRESHOLD_MED  40 // Medium temperature threshold 

#define TEMPERATURE_THRESHOLD_LOW  33 // Low temperature threshold 

DHT dht(DHTPIN, DHT11); 

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the I2C address if necessary 

void setup() { 

  Serial.begin(9600); 

  dht.begin(); 

  Wire.begin(); 

  lcd.init(); 

  lcd.backlight(); 

  lcd.begin(16, 2); 

  lcd.setCursor(0, 0); 

  lcd.print("Temperature:"); 

  pinMode(FAN_PIN, OUTPUT); 

} 

void loop() { 

  delay(2000); // Delay between readings (adjust as needed) 

  float temperature = dht.readTemperature(); // Read temperature in Celsius 

  if (isnan(temperature)) { 

    Serial.println("Failed to read temperature from DHT sensor!"); 

    return; 

  } 

  Serial.print("Temperature: "); 

  Serial.print(temperature); 

  Serial.println(" °C"); 

  lcd.setCursor(0, 1); // Set cursor to the second line 

  lcd.print("                "); // Clear the previous fan speed 

  // Adjust fan speed based on temperature 

  if (temperature >= TEMPERATURE_THRESHOLD_HIGH) { 

    // Turn on the fan at high speed 

    digitalWrite(FAN_PIN, HIGH); 

    lcd.setCursor(0, 1); 

    lcd.print("Fan Speed: High"); 

  } 

  else if (temperature >= TEMPERATURE_THRESHOLD_MED) { 

    // Turn on the fan at medium speed 

    analogWrite(FAN_PIN, 128); // Adjust the PWM value for medium speed 

    lcd.setCursor(0, 1); 

    lcd.print("Fan Speed: Med"); 

  } 

  else if (temperature >= TEMPERATURE_THRESHOLD_LOW) { 

    // Turn on the fan at low speed 

    analogWrite(FAN_PIN, 64); // Adjust the PWM value for low speed 

    lcd.setCursor(0, 1); 

    lcd.print("Fan Speed: Low"); 

  } 

  else { 

    // Turn off the fan if temperature is below all thresholds 

    digitalWrite(FAN_PIN, LOW); 

    lcd.setCursor(0, 1); 

    lcd.print("Fan Off"); 

  } 

  lcd.setCursor(12, 0); // Set cursor to the temperature position on the first line 

  lcd.print(temperature); // Print temperature 

} 