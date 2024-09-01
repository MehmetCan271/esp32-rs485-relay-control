#define CONTROL_PIN 2
#define TX_PIN 41 // TX pin for ESP32
#define RX_PIN 42 // RX pin for ESP32

#include <HardwareSerial.h>

// Set up TX and RX pins for RS485 communication using ESP32's internal hardware serial
HardwareSerial rs485Serial(1);

// Relay commands
byte relayCmds[][8] = {
    {0x01, 0x05, 0x00, 0x00, 0xFF, 0x00, 0x8C, 0x3A}, // Relay No. 0 ON
    {0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0xCD, 0xCA}, // Relay No. 0 OFF
    {0x01, 0x05, 0x00, 0x01, 0xFF, 0x00, 0xDD, 0xFA}, // Relay No. 1 ON
    {0x01, 0x05, 0x00, 0x01, 0x00, 0x00, 0x9C, 0x0A}, // Relay No. 1 OFF
    {0x01, 0x05, 0x00, 0x02, 0xFF, 0x00, 0x2D, 0xFA}, // Relay No. 2 ON
    {0x01, 0x05, 0x00, 0x02, 0x00, 0x00, 0x6C, 0x0A}, // Relay No. 2 OFF
    {0x01, 0x05, 0x00, 0x03, 0xFF, 0x00, 0x7C, 0x3A}, // Relay No. 3 ON
    {0x01, 0x05, 0x00, 0x03, 0x00, 0x00, 0x3D, 0xCA}, // Relay No. 3 OFF
    {0x01, 0x05, 0x00, 0x04, 0xFF, 0x00, 0xCD, 0xFB}, // Relay No. 4 ON
    {0x01, 0x05, 0x00, 0x04, 0x00, 0x00, 0x8C, 0x0B}, // Relay No. 4 OFF
    {0x01, 0x05, 0x00, 0x05, 0xFF, 0x00, 0x9C, 0x3B}, // Relay No. 5 ON
    {0x01, 0x05, 0x00, 0x05, 0x00, 0x00, 0xDD, 0xCB}, // Relay No. 5 OFF
    {0x01, 0x05, 0x00, 0x06, 0xFF, 0x00, 0x6C, 0x3B}, // Relay No. 6 ON
    {0x01, 0x05, 0x00, 0x06, 0x00, 0x00, 0x2D, 0xCB}, // Relay No. 6 OFF
    {0x01, 0x05, 0x00, 0x07, 0xFF, 0x00, 0x3D, 0xFB}, // Relay No. 7 ON
    {0x01, 0x05, 0x00, 0x07, 0x00, 0x00, 0x7C, 0x0B}  // Relay No. 7 OFF
};

void setup() {
  // Set RS485 module control pin as output
  pinMode(CONTROL_PIN, OUTPUT);
  
  // Initialize HardwareSerial interface (Serial port 1, 9600 baud rate, RX and TX pins)
  rs485Serial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

  // Set RS485 module to transmit mode
  digitalWrite(CONTROL_PIN, HIGH);

  // Initialize serial monitor
  Serial.begin(9600);
}

void loop() {
  // Sequentially turn all relays on and off
  for (int i = 0; i < 16; i++) {
    sendModbusCommand(relayCmds[i], sizeof(relayCmds[i]));

    // Print to serial monitor which relay is being turned on or off
    if (i % 2 == 0) {
      Serial.print("Relay No. ");
      Serial.print(i / 2);
      Serial.println(" turned ON.");
    } else {
      Serial.print("Relay No. ");
      Serial.print(i / 2);
      Serial.println(" turned OFF.");
    }
    
    delay(1000); // Wait 1 second between each command
  }
}

void sendModbusCommand(byte *cmd, int len) {
  // Set RS485 module to transmit mode
  digitalWrite(CONTROL_PIN, HIGH);

  // Send the command
  for (int i = 0; i < len; i++) {
    rs485Serial.write(cmd[i]);
  }

  // Wait briefly after sending the command
  delay(10);

  // Set RS485 module to receive mode
  digitalWrite(CONTROL_PIN, LOW);
}
