const int ledPin = 48;
const int buzzerPin = 46;

String content = "";
int ledState = LOW;
unsigned long beepTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  readInput();
  update();
}

void update() {
  digitalWrite(ledPin, ledState);

  if (millis() - beepTime < 200) {
    tone(buzzerPin, 880);
  } else {
    noTone(buzzerPin);
  }
}


void readInput() {
  Serial.println("Waiting for message...");

  content = Serial.readStringUntil('\n');

  Serial.print("received: ");
  Serial.println(content);

  if (content == "ledon") {
    ledState = HIGH;
  } else if (content == "ledoff") {
    ledState = LOW;
  } 
  
  if (content == "beep") {
    beepTime = millis();
  }
}