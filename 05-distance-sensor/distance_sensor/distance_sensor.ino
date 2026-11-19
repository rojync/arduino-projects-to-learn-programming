//define leds

#define red_light 8
#define blue_light 10
#define green_light 12

//define sensor pins
#define trigPin 2
#define echoPin 4

unsigned long distance = 0; 
unsigned long duration = 0;
unsigned long one_impulse = 60;
unsigned long current_time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(red_light, OUTPUT);
  pinMode(blue_light, OUTPUT);
  pinMode(green_light, OUTPUT);
  
  // put your setup code here, to run once:
}

void loop() {

//if(millis()- current_time >= one_impulse){
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//}
  // Impulse and distance 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (0.0343*duration)/2;
  if(distance >= 30){
    digitalWrite(green_light, HIGH);
    digitalWrite(blue_light, LOW);
    digitalWrite(red_light,LOW);
  }
  else if((distance<30) && (distance>=15)){
    digitalWrite(green_light, LOW);
    digitalWrite(blue_light, HIGH);
    digitalWrite(red_light,LOW);
  }
  else if(distance <= 15){
    digitalWrite(green_light, LOW);
    digitalWrite(blue_light,LOW);
    digitalWrite(red_light,HIGH);
  }

  Serial.println(String("Distance: ") + distance + "cm");

  // put your main code here, to run repeatedly:

}
