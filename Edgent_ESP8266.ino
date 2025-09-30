/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
 *************************************************************
  Blynk.Edgent implements:
  - Blynk.Inject - Dynamic WiFi credentials provisioning
  - Blynk.Air    - Over The Air firmware updates
  - Device state indication using a physical LED
  - Credentials reset using a physical Button
 *************************************************************/

/* Fill in information from your Blynk Template here */
/* Read more: https://bit.ly/BlynkInject */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"

#define BLYNK_TEMPLATE_ID "TMPL6z9T4wPvL"
#define BLYNK_TEMPLATE_NAME "nhietDoVaDoAm"
// #define BLYNK_AUTH_TOKEN "KLTmgb3hciHPXgI4RbFJlQilk_VxugnQ"


#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
 
#include "BlynkEdgent.h"
#include <DHT.h>

// Chân kết nối DHT (D4 = GPIO2, thường hay dùng trên NodeMCU)
#define DHTPIN D4          
#define DHTTYPE DHT11      // Nếu bạn dùng DHT22 thì đổi thành DHT22

DHT dhtcb(DHTPIN, DHTTYPE);
BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  dhtcb.begin();

  // Gửi dữ liệu mỗi 2 giây
}

void loop()
{
  BlynkEdgent.run();
  float h = dhtcb.readHumidity();
  float t = dhtcb.readTemperature(); // Đọc theo độ C

  if (isnan(h) || isnan(t)) {
    Serial.println("❌ Không đọc được dữ liệu từ cảm biến DHT!");
    return;
  }
  Blynk.virtualWrite(V0, t); // Gửi nhiệt độ lên V0
  Blynk.virtualWrite(V1, h); // Gửi độ ẩm lên V1
  Serial.print("🌡 Nhiet do: ");
  Serial.print(t);
  Serial.print(" °C | 💧 Do am: ");
  Serial.print(h);
  Serial.println(" %");
}
