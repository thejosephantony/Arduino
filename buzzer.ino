#define BUZZER 4
#define BUTTON 3
void setup(){ 
  pinMode(BUTTON, INPUT_PULLUP); 
  pinMode(BUZZER, OUTPUT); 
  Serial.begin(9600);  
  delay(100);  
} 
void loop(){ 
  if (digitalRead(BUTTON) == LOW){ 
  digitalWrite(BUZZER, HIGH);  
  } else { 
    digitalWrite(BUZZER, LOW); 
} 
  delay(100); 
}