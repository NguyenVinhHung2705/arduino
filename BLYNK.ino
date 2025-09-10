#define BLYNK_TEMPLATE_ID "TMPL6a5uVGjbu"
#define BLYNK_TEMPLATE_NAME "home"
#define BLYNK_AUTH_TOKEN "ovh00XtIjG67CFZi3wVcTAxaHrjNYbzY"

//thay vao day nha


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;


char ssid[] = "GUESTS"; // tên wifi
char pass[] = "Guest@2023"; // mật khảu wifi
char auth[] = BLYNK_AUTH_TOKEN; // ghi nhu em la duoc
#define led D1
void setup() {
  // put your setup code here, to run once:
  Blynk.begin(auth, ssid, pass);
  pinMode(led, OUTPUT);
}
BLYNK_WRITE(V0)
{
  int nut = param.asInt(); //lay gia tri cua nut
  // digitalWrite(led, nut);
  if(nut == 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
