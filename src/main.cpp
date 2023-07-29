#include <Arduino.h>
#include "camera.h"
#include "server.h"

// paramètres de votre réseau WiFi
// const char* ssid = "Esp32-SacroSaint-Wifi";
// const char* password = "patate12";
const char *ssid = "SacroSaint-Wifi";
const char *password = "patate12";

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 2);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  // ----------------- Serial -----------------

  Serial.begin(115200);

  // ------------------ Wifi ------------------

  // WiFi.mode(WIFI_AP);
  // WiFi.softAPConfig(local_IP, gateway, subnet);
  // WiFi.softAP(ssid, password);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("IP:");
  Serial.println(WiFi.localIP());

  // ---------------- SPIFFS -----------------

  if (!SPIFFS.begin())
  {
    Serial.println("SPIFFS err");
    return;
  }

  File root = SPIFFS.open("/");
  File file = root.openNextFile();

  while (file)
  {
    Serial.print("File: ");
    Serial.println(file.name());
    file.close();
    file = root.openNextFile();
  }

  // --------- Server & Camera ---------------

  setupCamera();
  setupServer();

  // --------------- Pin engine ---------------

  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(LEFT_MOTOR_EN, OUTPUT);

  ledcSetup(LEFT_PWM_CHANNEL, 30000, 8);
  ledcAttachPin(LEFT_MOTOR_EN, LEFT_PWM_CHANNEL);

  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_EN, OUTPUT);

  ledcSetup(RIGHT_PWM_CHANNEL, 30000, 8);
  ledcAttachPin(RIGHT_MOTOR_EN, RIGHT_PWM_CHANNEL);

  Serial.println("Setup done!");
}

void loop() { vTaskDelay(5000 / portTICK_PERIOD_MS); }
