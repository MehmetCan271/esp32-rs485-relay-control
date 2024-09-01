# esp32-rs485-relay-control
Control multiple relays using an ESP32 and RS485 communication with Modbus RTU commands. The project demonstrates how to send commands to toggle relays on and off, using a HardwareSerial interface on the ESP32. Includes example code and detailed explanations for implementing relay control via Modbus RTU.

Project Overview:
This project aims to control relays using an ESP32 microcontroller and RS485 communication protocol. Relays are toggled on and off using Modbus RTU commands. The hardware connections utilize ESP32's hardware serial interface to transmit and receive data via the RS485 module.

Hardware Connections:
ESP32 TX (GPIO 41) - RS485 module DI (Data Input) pin
ESP32 RX (GPIO 42) - RS485 module RO (Data Output) pin
ESP32 CONTROL_PIN (GPIO 2) - RS485 module DE and RE (Data Enable and Receiver Enable) pins (These pins are often combined)
RS485 Module VCC - 5V power supply
RS485 Module GND - Ground (GND)
RS485 Module A and B - Data transmission lines connected to the relay module
Code Explanation:
#define CONTROL_PIN 2: Defines the control pin that switches the RS485 module between sending and receiving modes.
#define TX_PIN 41 and #define RX_PIN 42: Defines the TX and RX pins on the ESP32 for communication with the RS485 module.
HardwareSerial rs485Serial(1);: Creates an interface for RS485 communication using the second hardware serial port of the ESP32.
relayCmds array: Contains Modbus RTU commands for each relay. These commands control the relay's on and off states.
setup() function: Initializes serial communication settings for the RS485 module and sets the control pin as an output.
loop() function: Sequentially toggles all relays on and off, displaying the process on the serial monitor.
sendModbusCommand() function: Sends the specified Modbus command via RS485.
This project provides a basic structure for relay control applications, which can be utilized in industrial control systems.

/*******MCB*******TÜRKÇE AÇIKLAMA**********************MCB*******/
Proje Özeti:
Bu proje, ESP32 mikrodenetleyicisi ve RS485 haberleşme protokolü kullanarak röleleri kontrol etmeyi amaçlamaktadır. Modbus RTU komutları ile rölelerin açılıp kapanması sağlanır. Projede kullanılan donanım bağlantıları, ESP32’nin donanım serisi üzerinden RS485 modülüne veri iletimi ve alımı gerçekleştirir.

Donanım Bağlantıları:
ESP32 TX (GPIO 41) - RS485 modülü DI (Veri Girişi) pini
ESP32 RX (GPIO 42) - RS485 modülü RO (Veri Çıkışı) pini
ESP32 CONTROL_PIN (GPIO 2) - RS485 modülü DE ve RE (Data Enable ve Receiver Enable) pinleri (Bu pinler genellikle birleştirilir)
RS485 Modülü VCC - 5V güç kaynağı
RS485 Modülü GND - Toprak hattı (GND)
RS485 Modülü A ve B - Röle modülüne bağlanan veri iletim hatları
Kod Açıklaması:
#define CONTROL_PIN 2: RS485 modülünü veri gönderme/alma moduna geçirecek kontrol pinini tanımlar.
#define TX_PIN 41 ve #define RX_PIN 42: ESP32 için RS485 modülüne bağlanacak TX ve RX pinlerini tanımlar.
HardwareSerial rs485Serial(1);: ESP32'nin ikinci donanım seri portu kullanılarak RS485 iletişimi için bir arayüz oluşturulur.
relayCmds dizisi: Her röle için Modbus RTU komutlarını içerir. Bu komutlar, rölenin açılması veya kapanmasını sağlar.
setup() fonksiyonu: RS485 modülü için seri haberleşme ayarlarını yapar ve kontrol pinini çıkış olarak tanımlar.
loop() fonksiyonu: Tüm röleleri sırayla açıp kapatır ve bu işlemi seri monitörde görüntüler.
sendModbusCommand() fonksiyonu: Belirtilen Modbus komutunu RS485 üzerinden gönderir.
Bu proje, endüstriyel kontrol sistemlerinde kullanılabilecek röle kontrol uygulamaları için temel bir yapı sunmaktadır.

MCB
