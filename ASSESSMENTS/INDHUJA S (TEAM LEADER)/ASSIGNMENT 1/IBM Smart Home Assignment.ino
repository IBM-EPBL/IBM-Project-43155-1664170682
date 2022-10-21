//defining pins for the inputs and outputs
const int gas_input = A0;
int gas = 0;
const int led = 6;
const int buzzer = 12;
int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 10; 
int time;
int distance;

void setup()
{
  //setting up the correct pin modes
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
        pinMode (buzzer_pin, OUTPUT);
  //initializing the serial monitor
  Serial.begin(9600);
}

void loop()
{
  //read the input from mq2 gas sensor
  gas  = analogRead(gas_input);
  //print the input om serial monitor
  Serial.print(" The gas value is :");
   Serial.println(gas);
  //remapping the value of input from mq2 to 0-255
  int led_out = map(gas, 80, 400, 0, 255); 
  
  //send the output to buzzer
  tone(buzzer,led_out,100);
  //send the pwm signal to led
  analogWrite(led,led_out);
  //delay of 100ms
  delay(100);
  digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

  if (distance <= 10) 
        {
        Serial.println (" Door Open ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, HIGH);
        delay (500);
        }
  else {
        Serial.println (" Door closed ");
        Serial.print (" Distance= ");              
        Serial.println (distance);        
        digitalWrite (buzzer_pin, LOW);
        delay (500);        
       }
}	 
