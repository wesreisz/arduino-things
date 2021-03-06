const int BTN = 12;
const int RED = 10;
const int YELLOW = 9;
const int GREEN = 8;

void setup() {
  pinMode(BTN, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(GREEN, HIGH);
}

void loop() {
  if (digitalRead(BTN) == HIGH){
    delay(15); //software debounce
    if(digitalRead(BTN)==HIGH){
      //if the switch is HIGH, ie pushed down = change the lights
      changeLights();
      delay(15000);
      //digitalWrite(BTN, LOW)
    }  
  }
  changeLights();
  delay(15000);
}

void changeLights(){
  //green off, yellow on for 3 seconds
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(3000); 

  //yellow off, then turn red on for 5 seconds
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
  delay(5000);

  //red and yellow on for 2 seconds (red is already on though)
  digitalWrite(YELLOW, HIGH);
  delay(2000);

  //turn off red and yellow, then turn on green
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  delay(3000);
}
