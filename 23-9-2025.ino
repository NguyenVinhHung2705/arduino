#include <ESP8266WiFi.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

// ======================= WiFi Info =======================
const char* ssid = "Đức Bảo";
const char* password = "13092005";

// ======================= Sinric Pro Info =================
const char* APP_KEY    = "72856f9f-68ae-4f77-9c48-3d8f8862f4f6";
const char* APP_SECRET = "4fe069a7-bab2-4f36-aabd-a8235b7f7f98-9c3f7872-ee84-48db-8377-7b6d6af7365c";

// ======================= Device IDs ======================
const char* SmartLed         = "68d23fff51811ad2b74f4ec0";
// const char* SmartFan         = "66c7282354041e4ff6220283";
// const char* SmartLivingRoom  = "66cdb017deddece34b838ec9";

// ======================= GPIO Pins =======================
const int LED_PIN        = D2;
const int FAN_PIN        = D1;
const int LivingRoom_PIN = D3;

// ======================= SinricPro Switches ==============
SinricProSwitch& ledSwitch        = SinricPro[SmartLed];
// SinricProSwitch& fanSwitch        = SinricPro[SmartFan];
// SinricProSwitch& livingroomSwitch = SinricPro[SmartLivingRoom];

// ======================= Callbacks =======================
bool onLedPowerState(const String &deviceId, bool &state) {
  Serial.printf("LED %s was turned %s\r\n", deviceId.c_str(), state ? "on" : "off");
  digitalWrite(LED_PIN, state ? HIGH : LOW);  // LOW = bật, HIGH = tắt
  return true;
}

bool onFanPowerState(const String &deviceId, bool &state) {
  Serial.printf("Fan %s was turned %s\r\n", deviceId.c_str(), state ? "on" : "off");
  digitalWrite(FAN_PIN, state ? LOW : HIGH);
  return true;
}

bool onLivingRoomPowerState(const String &deviceId, bool &state) {
  Serial.printf("LivingRoom %s was turned %s\r\n", deviceId.c_str(), state ? "on" : "off");
  digitalWrite(LivingRoom_PIN, state ? LOW : HIGH);
  return true;
}

// ======================= Setup ===========================
void setup() {
  Serial.begin(115200);

  // Kết nối WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Đang kết nối đến WiFi...");
  }
  Serial.println("Đã kết nối với WiFi");

  // Cấu hình GPIO
  pinMode(LED_PIN, OUTPUT);
  // pinMode(FAN_PIN, OUTPUT);
  // pinMode(LivingRoom_PIN, OUTPUT);

  // Gán callback
  ledSwitch.onPowerState(onLedPowerState);
  // fanSwitch.onPowerState(onFanPowerState);
  // livingroomSwitch.onPowerState(onLivingRoomPowerState);

  // Bắt đầu Sinric Pro
  SinricPro.begin(APP_KEY, APP_SECRET);
}

// ======================= Loop ============================
void loop() {
  SinricPro.handle();
}
