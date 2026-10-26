#define BUTTON_PIN 13
#define RED_LED 2
#define YELLOW_LED 6
#define GREEN_LED 10
unsigned long startMillis;
const unsigned long time1 = 3000;
const unsigned long time2 = 2000;
const unsigned long time3 = 7000;

void setup() {
  Serial.begin(9600);
  startMillis = millis();
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  

  String lightstate = "Green";
  int buttonState = digitalRead(BUTTON_PIN);
  //button pressed
  if (buttonState = 1){
    if (startMillis - time1 >= 0){
      digitalWrite(GREEN_LED, LOW);
    }
    digitalWrite(YELLOW_LED, HIGH);
    delay(2000);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    delay(7000);
    //always green
  else{
      digitalWrite(GREEN_LED,HIGH);
    }


}
