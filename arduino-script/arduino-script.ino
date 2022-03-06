int switchState2 = 0;
int switchState3 = 0;
int const potPin = A5;
int potVal;
int percentage;
int activeButton;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  activeButton = 0;
  potVal = analogRead(potPin);
  switchState2 = digitalRead(2);
  switchState3 = digitalRead(3);

  if (switchState2 == HIGH) {
    activeButton = 2;        
  } else if (switchState3 == HIGH) {
    activeButton = 3;
  }

  percentage = map(potVal, 0, 1023, 0, 99);

  Serial.print("{ 'percentage': ");
  Serial.print(percentage);
  Serial.print(", 'activeButton': ");
  Serial.print(activeButton);
  Serial.print(" }");
  Serial.print("\n");

  delay(100);
}
