#define Echo_pin 13
#define Trig_pin 12

#define Buzzer 7

int i = 0;
int k = 0;
float media = 0;
float Time_Echo = 0;
float leng = 0;
float sound_velocity = 34300; //cm/s

void setup() {
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin,INPUT);

  pinMode(Buzzer,OUTPUT);
  digitalWrite(Buzzer,LOW);

  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(Trig_pin,HIGH);
  delayMicroseconds(50);
  digitalWrite(Trig_pin,LOW);
  
  Time_Echo = float(pulseIn(Echo_pin,HIGH));

  leng = (Time_Echo*sound_velocity)/2000000; // cm
  
    Serial.println(leng);
  
  if(leng < 20){
    if(media > 10 && media < 20)
        k = 80;
    else
        k = 10;

   
  digitalWrite(Buzzer,HIGH);
  delay(k*leng);
  digitalWrite(Buzzer,LOW);
  delay(k*leng);

  }
  
  
}
