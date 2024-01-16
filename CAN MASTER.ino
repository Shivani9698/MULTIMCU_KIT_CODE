// Sender Code: This code is for sending Temperature and Humidity value

#include <SPI.h>          // Library for using SPI Communication
#include <mcp2515.h>      // Library for using CAN Communication (https://github.com/autowp/arduino-mcp2515/)
#include <DHT.h>          // Library for using DHT sensor

#define DHTPIN 26     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 22 (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE); // Create a DHT object with the specified pin and type

#define DHTPIN 26
#define DHTTYPE DHT11

struct can_frame canMsg; // Define a CAN frame structure to hold the data to be sent

MCP2515 mcp2515(5); // Create a MCP2515 object with the CS pin connected to pin 5

void setup()
{
  while (!Serial); // Wait until a serial connection is established
  Serial.begin(9600); // Initialize the serial communication at 9600 bps
  dht.begin(); // Initialize the DHT sensor

  SPI.begin(); // Begin SPI communication

  mcp2515.reset(); // Reset the MCP2515 module
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); // Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode(); // Set the MCP2515 to normal mode

  Serial.println("I am Started"); // Print a message indicating the setup is complete
}

void loop()
{
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float h = dht.readHumidity(); // Read humidity value from the DHT sensor
  float t = dht.readTemperature(); // Read temperature value from the DHT sensor
  float f = dht.readTemperature(true); // Read temperature value in Fahrenheit from the DHT sensor

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!")); // Print an error message if any sensor reading failed
    return; // Exit the function and try again
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahrenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // Print the sensor readings and computed heat index values
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  canMsg.can_id = 0x02;           // CAN id as 0x036
  canMsg.can_dlc = 8;             // CAN data length as 8
  canMsg.data[0] = t;             // Update humidity value in [0]
  canMsg.data[1] = h;             // Update temperature value in [1]
  canMsg.data[2] = hic;           // Rest all with 0
  canMsg.data[3] = hif;
  canMsg.data[4] = 0x00;
  canMsg.data[5] = 0x00;
  canMsg.data[6] = 0x00;
  canMsg.data[7] = 0x00;

  mcp2515.sendMessage(&canMsg);   // Sends the CAN message
  delay(1000); // Wait for a second before sending the next message
}
