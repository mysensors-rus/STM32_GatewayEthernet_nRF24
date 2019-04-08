/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * REVISION HISTORY
 * Version 1.0 - Henrik EKblad
 * Contribution by a-lurker and Anticimex,
 * Contribution by Norbert Truchsess <norbert.truchsess@t-online.de>
 * Contribution by Tomas Hozza <thozza@gmail.com>
 *
 *
 * DESCRIPTION
 * The EthernetGateway sends data received from sensors to the ethernet link.
 * The gateway also accepts input on ethernet interface, which is then sent out to the radio network.
 *
 * The GW code is designed for Arduino 328p / 16MHz.  ATmega168 does not have enough memory to run this program.
 *
 * LED purposes:
 * - To use the feature, uncomment MY_DEFAULT_xxx_LED_PIN in the sketch below
 * - RX (green) - blink fast on radio message received. In inclusion mode will blink fast only on presentation received
 * - TX (yellow) - blink fast on radio message transmitted. In inclusion mode will blink slowly
 * - ERR (red) - fast blink on error during transmission error or receive crc error
 *
 * See http://www.mysensors.org/build/ethernet_gateway for wiring instructions.
 *
 */


// Enable debug prints to serial monitor
#define MY_DEBUG                      // Включаем отладку 
#define SERIAL_USB                    // Порты UART начинаются с Serial1
#define MY_SERIALDEVICE     Serial1   
#define MY_BAUD_RATE        115200

// Enable and select radio type attached
#define MY_RADIO_RF24

// Define this to change the chip enable pin from the default.
// CE (Chip enable)  Управляет режимом радимодуля - приём или передача (пин можно назначить любой)
#define MY_RF24_CE_PIN PB0	

//Define this to change the chip select pin from the default.
// CSN (SPI Chip select) Пин для выбора устройства на шине SPI с которым мы хотим работать (пин можно назначить любой)
#define MY_RF24_CS_PIN PA4

// Set LOW transmit power level as default, if you have an amplified NRF-module and
// power your radio separately with a good regulator you can turn up PA level.
#define MY_RF24_PA_LEVEL RF24_PA_LOW	// Устанавливаем мощность передатчика

// Enable gateway ethernet module type
//#define MY_GATEWAY_SERIAL
#define MY_GATEWAY_W5100

/* 
Т.к. у нас используются два SPI устройства: радиомодуль nRF24 и Ethernet контроллер w5500,
то мы посадим их на разные SPI порты. nRF24 оставим на SPI1, а w5500 подключим к SPI2
*/

// Enable UDP communication
//#define MY_USE_UDP  // If using UDP you need to set MY_CONTROLLER_IP_ADDRESS below

// Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
#define MY_IP_ADDRESS 10,10,11,126

// If using static ip you can define Gateway and Subnet address as well
//#define MY_IP_GATEWAY_ADDRESS 192, 168, 1, 1
#define MY_IP_SUBNET_ADDRESS 255,255,255,0

// Renewal period if using DHCP
//#define MY_IP_RENEWAL_INTERVAL 60000

// The port to keep open on node server mode / or port to contact in client mode
#define MY_PORT 5003

// How many clients should be able to connect to this gateway (default 1)
#define MY_GATEWAY_MAX_CLIENTS 3// Set blinking period

// Controller ip address. Enables client mode (default is "server" mode).
// Also enable this if MY_USE_UDP is used and you want sensor data sent somewhere.
//#define MY_CONTROLLER_IP_ADDRESS 192, 168, 178, 254

// The MAC address can be anything you want but should be unique on your network.
// Newer boards have a MAC address printed on the underside of the PCB, which you can (optionally) use.
// Note that most of the Arduino examples use  "DEAD BEEF FEED" for the MAC address.
#define MY_MAC_ADDRESS 0xDE, 0xAD, 0x19, 0x3F, 0xFE, 0xEC

// Enable inclusion mode
//#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
//#define MY_INCLUSION_BUTTON_FEATURE
// Set inclusion mode duration (in seconds)
//#define MY_INCLUSION_MODE_DURATION 60
// Digital pin used for inclusion mode button
//#define MY_INCLUSION_MODE_BUTTON_PIN  3

// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Flash leds on rx/tx/err
// Uncomment to override default HW configurations
#define MY_DEFAULT_ERR_LED_PIN PC13  // Error led pin
#define MY_DEFAULT_RX_LED_PIN  PC13  // Receive led pin
#define MY_DEFAULT_TX_LED_PIN  PC13  // Transmit led pin

//#define MY_SPLASH_SCREEN_DISABLED    // Отключаем Splash screen
//#define MY_DEBUG_VERBOSE_OTA_UPDATE

//#if defined(MY_USE_UDP)
//#include <EthernetUdp.h>
//#endif

#include <Ethernet_STM.h>
#include <MySensors.h>


void setup()
{

  
}

void receive(const MyMessage &message)
{
  #ifdef MY_DEBUG 
    Serial.println("message");
    Serial.println(message.sensor);
    Serial.println(message.type);
    Serial.println(message.getBool());
    Serial.println(message.getByte());
    Serial.println(message.getString());
    //Serial.println(message.getCustom());
    //Serial.println(message.getFloat());
    //Serial.println(message.getInt());
    //Serial.println(message.getLong());
    Serial.println(message.getCommand());
 #endif // MY_DEBUG 
}

void presentation()
{
  
   
}

void loop()
{

  
}
