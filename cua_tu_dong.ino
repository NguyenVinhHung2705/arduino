#define BLYNK_TEMPLATE_ID "TMPL6qHnktK0E"
#define BLYNK_TEMPLATE_NAME "cua tu dong"
#define BLYNK_AUTH_TOKEN "k8pcPMaH5JdFG7kcaOz7W5KeEQJ9nayd"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo myservo; 
char ssid[] = "iPhone of Hien";
char pass[] = "hien12345";
char auth[] = "k8pcPMaH5JdFG7kcaOz7W5KeEQJ9nayd";

int pos = 0;
void setup() {
  // put your setup code here, to run once:
  
  Blynk.begin(auth, ssid, pass);
  myservo.attach(D4);
}
BLYNK_WRITE(V1){
  int nut = param.asInt();
  if(nut == 1){
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);
    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15); // chỉnh tốc độ quay
    }
  }
}
BLYNK_WRITE(V2){
  int nut = param.asInt();
  if(nut == 1){
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V3, 0);
    myservo.write(90); // myservo.write(90) la dieu khien cai truc kia xoay 90 do nha
  }
}
BLYNK_WRITE(V3){
  int nut = param.asInt();
  if(nut == 1){
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 0);
    for (pos = myservo.read(); pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
void loop() {
  Blynk.run();

}
