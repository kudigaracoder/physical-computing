
#include "arduino_secrets.h"
#include <SPI.h>
#include <WiFi101.h>
#include <WiFiSSLClient.h>
#include <CapacitiveSensor.h>
#include <TelegramBot.h>


//#include "TelegramBot.ino"

const char* ssid = "MFA IxD";    //  your network SSID (name)
const char* password = "1nter@ct10n";  // your network password
const char BotToken[] = "760862414:AAG3erPEmUPEXEd1SaCmKPyW3JA0SSTxNu0"; // you bot API token


WiFiSSLClient client;
TelegramBot bot (BotToken, client);

unsigned long timer;
bool pressed = false;
String chat_id;
int threshold = 5000; // this value might change depending on the amount of alluminium foil used
int heart_beat = -1;
int Buzzer = 8; // Pin attached to the buzzer

// List of Emoji we are going to send taken from
// https://apps.timwhitlock.info/emoji/tables/unicode
String emoji[] {
  "\U0001F44A", // fist
  "\U0001F60D", // eyes
  "\U00002764" // heart
};

CapacitiveSensor foil = CapacitiveSensor(5, 4);       // 10M resistor between pins 5 & 4, pin 4 is sensor pin, add a wire and or foil if desired

void setup() {
  Serial.begin(115200);

  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  bot.begin();
  foil.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {

  if (!pressed) {
    message m = bot.getUpdates(); // Read new messages
    if ( m.chat_id != 0 ) { // Check if there are some updates
      Serial.println(m.text);
      // Check if the text is an emoji and react accordingly
      if (m.text == "u2764" || m.text == "ud83dudc4a" || m.text == "ud83dude0d" ) HeartBeat();
      chat_id = m.chat_id;
    }
  }
  long start = millis();
  long sensor_value =  foil.capacitiveSensor(30);

  //   Uncomment this line to debug and calibrate the threshold
  Serial.println(sensor_value);

  if (sensor_value > threshold && !pressed) {
    pressed = true;
  }
  else if (sensor_value > threshold && pressed) {
    HeartBeat();
    heart_beat += 1;
    // Avoid the heart_beat value to exceed the emoji[] array length
    if (heart_beat >= sizeof(emoji) / sizeof(String)) heart_beat = 0;
  }
  else if (sensor_value < threshold && pressed) {
    pressed = false;
    Serial.print(heart_beat);
    Serial.println(" heart beats");
    SendMessage(heart_beat);
    heart_beat = -1;
  }
}

void SendMessage(int heart_beat) {
  // Check if you know the chat_id of the chat you want to send the message to
  // You cannot send messages without knowing the chat_id
  if (chat_id != 0) bot.sendMessage(chat_id, emoji[heart_beat]);
  // Use heart_beat variable to navigate the array emoji[]
}

void HeartBeat() {
  tone(Buzzer, 31, 200); // tone(Pin, Note, Duration);
  delay(200);
  tone(Buzzer, 31, 400);
  delay(200);
  noTone(Buzzer);
  delay(1000);
}
