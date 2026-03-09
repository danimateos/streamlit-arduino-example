String content = "";

void setup() {
  Serial.begin(9600);

  pinMode(48, OUTPUT);
  pinMode(46, OUTPUT);
}

void loop() {
  Serial.println("Waiting for message...");

    content = Serial.readStringUntil('\n');

    Serial.print("received: ");
    Serial.println(content);


  if (content == "ledon") {
    digitalWrite(48, HIGH);
  } else if (content == "ledoff") {
    digitalWrite(48, LOW);
  } else if (content == "beep") {
    tone(46, 880, 200);
  }

  content = "";

  delay(500);
}

