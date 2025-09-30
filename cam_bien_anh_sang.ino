#define relay A0
#define LED 3
void setup() {
  pinMode(relay, OUTPUT);
  Serial.begin(9600); // Khởi động Serial ở baudrate 9600
  Serial.println("Da khoi dong xong");
  pinMode(LED, OUTPUT);
}

void loop() {
  int giatri = analogRead(relay); // Đọc tín hiệu cảm biến
  Serial.println(giatri);
  if(giatri >= 501) {digitalWrite(LED, HIGH);}
  else {digitalWrite(LED, LOW);}

}