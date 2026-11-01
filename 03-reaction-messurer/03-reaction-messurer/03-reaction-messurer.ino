#define button 2
#define green_light 8
#define red_light 5
unsigned long random_time;
int button_pressed = 0;
unsigned long time_round = 0; 
int current_time = 0;
bool greenison = false; 
bool rounddone = false; 
int reaction_time;
int buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(green_light, OUTPUT);
  pinMode(red_light, OUTPUT);
  random_time = random(2000,5000);
  rounddone = true;
  // put your setup code here, to run once:
}

void loop() {
  
    rounddone = false;
    random_time = random(2000,5000);
    current_time = millis();
    while (greenison == false){
      buttonState = digitalRead(button);
      if (buttonState == 1 && greenison == false){
        Serial.println("Too early");
        delay(2000);
      }
      digitalWrite(red_light, HIGH);
      if(millis() - current_time >= random_time){
        time_round = millis();
        digitalWrite(red_light,LOW);
        digitalWrite(green_light, HIGH);
        greenison = true;
      }
    }

    buttonState = digitalRead(button);
    if(buttonState == 1){
      button_pressed = millis();
      digitalWrite(green_light, LOW);
      Serial.print("Before calculation - current_time: ");
      Serial.println(current_time);
      Serial.print("Before calculation - button_pressed: ");
      Serial.println(button_pressed);
      reaction_time = button_pressed - time_round;
      Serial.print("Your reaction time is:");
      Serial.println(reaction_time);
      greenison = false;
      rounddone = true;
    }
    if(greenison == false && rounddone == true){
      delay(4000);
    }
    
    // put your main code here, to run repeatedly:
}
