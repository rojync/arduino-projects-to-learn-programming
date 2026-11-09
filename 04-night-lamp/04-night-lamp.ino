
int red_light = 12;
int analog_pin = A0;
int voltage_value_light_on = 0; 
int voltage_value_light_off = 0;


void setup() {
  pinMode(red_light, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  voltage_value_light_on = analogRead(analog_pin);
  Serial.println(voltage_value_light_on);
  if(voltage_value_light_on > 600){
    digitalWrite(red_light, HIGH);
  }
  else{
    digitalWrite(red_light, LOW);
  }
  // put your main code here, to run repeatedly:

}
