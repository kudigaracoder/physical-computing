/*
  EchoBot

  This example shows how to program a Telegram Bot
  that echoes your messages.

  For a step-by-step tutorial visit:
  https://create.arduino.cc/projecthub/Arduino_Genuino/telegram-bot-library-ced4d4

  In oreder to make the bot more reliable in the long run we suggest using a watchdog
  The Adafruit_SleepyDog is a handy library that will reset the board if something goes wrong

  Updated 29 May 2016
  by Tommaso Laterza
  Updated 13 February 2018
  by Tommaso Laterza

  This example code is in the public domain.

*/

#include "arduino_secrets.h"
#include <WiFi101.h>
#include <SPI.h>
#include <TelegramBot.h> 

// Initialize Wifi connection to the router
char ssid[] = VFL;             // your network SSID (name)
char pass[] = VFL12345;           // your network key

// Initialize Telegram BOT
const char BotToken[] = 760862414:AAG3erPEmUPEXEd1SaCmKPyW3JA0SSTxNu0;

WiFiSSLClient client;
TelegramBot bot (BotToken, client);


void setup() {

  Serial.begin(115200);
  while (!Serial) {} // Wait for the Serial monitor to be opened
  delay(3000);

  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");

  bot.begin();
}

void loop() {

    message m = bot.getUpdates(); // Read new messages
    if ( m.chat_id != 0 ){ // Checks if there are some updates
      Serial.println(m.text);
      bot.sendMessage(m.chat_id, m.text);  // Reply to the same chat with the same text
    } else {
      Serial.println("no new message");
    }

}
