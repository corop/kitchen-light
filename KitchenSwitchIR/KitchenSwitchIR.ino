#define SENSOR_LEVEL 800
#define SENSOR_PIN   A0
#define RELAY_PIN    12
#define BLUE_LED_PIN 13
#define PASS_PERIOD  100
#define PASS_COUNT   10

bool lightOn = false;
int counter = 0;
int oldValue = 0;


void setup() {
  oldValue = analogRead(SENSOR_PIN);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, HIGH);
}


void loop() {
  int currentValue = analogRead(SENSOR_PIN);
  if (currentValue < SENSOR_LEVEL && oldValue < SENSOR_LEVEL) {
    counter++;
    if (lightOn && (counter == PASS_COUNT)) {
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);
      lightOn = !lightOn;
    } else if (!lightOn && (counter == PASS_COUNT)) {
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, LOW);
      lightOn = !lightOn;
    }
  } else {
    counter = 0;
  }
  oldValue = currentValue;
  delay(PASS_PERIOD);
}
