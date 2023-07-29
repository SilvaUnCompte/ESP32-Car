#ifndef SERVER_H
#define SERVER_H

#include <SPIFFS.h> // Contrains FS.h
#include "esp_camera.h"
#include "ESPAsyncWebServer.h"

#define LEFT_PWM_CHANNEL 2
#define LEFT_MOTOR_EN 12
#define LEFT_MOTOR_IN1 14
#define LEFT_MOTOR_IN2 27

#define RIGHT_PWM_CHANNEL 4
#define RIGHT_MOTOR_EN 32
#define RIGHT_MOTOR_IN1 33
#define RIGHT_MOTOR_IN2 26


void setupServer();
void streamJpg(AsyncWebServerRequest *request);

typedef struct
{
    camera_fb_t *fb;
    size_t index;
} camera_frame_t;

#endif