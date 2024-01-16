# 1.8 TFT Display with Arduino Uno

## Overview
This readme file provides information on how to connect a 1.8-inch TFT display to an Arduino Uno and run a simple example code using the TFT and SPI libraries.

## Connection Diagram

Connect your 1.8 TFT display to the Arduino Uno using the following pin configuration:

- BL (Backlight): 9
- RST (Reset): 8
- DC (Data/Command): 7
- CS (Chip Select): 10
- CLK (Clock): 13
- DIN (Data In): 11
- GND (Ground): GND
- VCC (Power): VCC


## Usage Instructions

1. Connect the TFT display to the Arduino Uno following the provided connection diagram.
2. Copy and paste the Arduino code into your Arduino IDE.
3. Install the necessary libraries using the Library Manager in the Arduino IDE.
4. Upload the code to your Arduino Uno.
5. Observe the TFT display showing a changing colored message.

## Additional Notes

- **Library Installation:** Make sure to install the required libraries using the Library Manager.
- **Display Orientation:** Adjust the display rotation in the code if needed (`TFTscreen.setRotation()`).
- **Power Supply:** Ensure sufficient power supply to the Arduino Uno and TFT display.
- **Wiring Check:** Double-check wiring for correctness and tight connections.
- **Serial Monitor:** Use the Serial Monitor for debugging if necessary.

## Resources

- [Adafruit TFTLCD Library](https://learn.adafruit.com/adafruit-gfx-graphics-library/overview)
- [Adafruit GFX Library](https://learn.adafruit.com/adafruit-2-8-tft-touch-shield-v2)

