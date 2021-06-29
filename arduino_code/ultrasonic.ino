#define Echo_pin 13
#define Trig_pin 12

float Time_Echo = 0;
float leng = 0;
float sound_velocity = 34300; //cm/s

void setup() {
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin,INPUT);

  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(Trig_pin,HIGH);
  delayMicroseconds(50);
  digitalWrite(Trig_pin,LOW);
  
  Time_Echo = float(pulseIn(Echo_pin,HIGH));

  leng = (Time_Echo*sound_velocity)/2000000; // cm

  Serial.println(leng);
  
  
  
}
