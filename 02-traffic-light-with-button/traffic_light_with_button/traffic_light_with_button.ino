#define BUTTON_PIN 13
#define RED_LED 2
#define YELLOW_LED 6
#define GREEN_LED 10
unsigned long currentMillis = 0;
unsigned long startMillis;
int time1 = 2000;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  startMillis = millis();
  int buttonState = digitalRead(BUTTON_PIN);
  //button pressed
  if (buttonState == HIGH){
    if (startMillis - currentMillis >= time1){
      digitalWrite(GREEN_LED, LOW);
      currentMillis = startMillis;
      buttonState = LOW;
    }
    digitalWrite(YELLOW_LED, HIGH);
    delay(2000);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    delay(7000);
    digitalWrite(RED_LED, LOW);
  }
    //always green
  else{
      digitalWrite(GREEN_LED,HIGH);
    }
  }




