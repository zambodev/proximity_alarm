#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define BUZZER_PIN 14


float distance;
float error = 1.f;

float getDistance() {
  float distance;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  distance = pulseIn(ECHO_PIN, HIGH, 8000000) / 58.f;   // Get distance in cm

  return distance;
}

void tripleBip()
{
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(50);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(50);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(50);
}

void ledBlink()
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(400);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(400);
  digitalWrite(LED_BUILTIN, LOW);
  delay(400);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(400);
  digitalWrite(LED_BUILTIN, LOW);
  delay(400);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(400);
}

void setup()
{
  Serial.begin(115200);
  while(!Serial);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  ledBlink();
  delay(200);

  distance = getDistance();
  delay(200);
}

void loop()
{
  float newDistance = getDistance();
  Serial.print(distance);
  Serial.print(" - ");
  Serial.println(newDistance);
  if(distance - newDistance > error)
  { 
    tripleBip();
    tripleBip();
    tripleBip();
  }

  delay(200);
}
