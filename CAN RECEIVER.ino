// This code is an improved version for CAN receiver
// This single code can receive data from 100 nodes by connecting additional nodes with incrementing IDs

#include <SPI.h>              // Library for using SPI Communication
#include <mcp2515.h>          // Library for using CAN Communication (https://github.com/autowp/arduino-mcp2515/)

struct can_frame canMsg;      // Define a CAN frame structure to hold received data

MCP2515 mcp2515(5);           // Create a MCP2515 object with the CS pin connected to pin 5


void setup()
{
  Serial.begin(9600);        // Begins Serial Communication at 9600 baud rate
  SPI.begin();               // Begins SPI communication
  mcp2515.reset();           // Reset the MCP2515 module
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); // Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();   // Sets CAN at normal mode
}


void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    // Print the received CAN ID to the Serial monitor
    Serial.println(canMsg.can_id);

    // Loop through IDs from 1 to 9 to check if the received CAN ID matches any of them
    for (int i = 1; i < 10; i++)
    {
      // If the received CAN ID matches the current ID in the loop
      if (canMsg.can_id == i)
      {
        // Print a message indicating the cage number based on the matching CAN ID
        Serial.println("CAGE" + String(i));

        // Extract data from the received CAN message
        int t = canMsg.data[0];   // Temperature value
        int h = canMsg.data[1];   // Humidity value
        int hic = canMsg.data[2]; // Temperature Index
        int hif = canMsg.data[3]; // Humidity Index

        // Print the received data for the matching cage number
        Serial.print("Cage" + String(i) + " Temp :");
        Serial.println(t);
        Serial.print("Cage" + String(i) + " Humi :");
        Serial.println(h);
        Serial.print("Cage" + String(i) + " Temp Index :");
        Serial.println(t);
        Serial.print("Cage " + String(i) + " Humi Index :");
        Serial.println(h);

        // Print a separator line for clarity
        Serial.println("**********************************");

        // Add a delay to avoid flooding the Serial monitor with messages
        delay(5000);
      }
    }
  }
}
