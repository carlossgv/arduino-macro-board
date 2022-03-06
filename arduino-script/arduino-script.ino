int switchState2 = 0;
int const potPin = A5;
int potVal;
int percentage;
int activeButton;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  activeButton = 0;
  switchState2 = digitalRead(2);
  potVal = analogRead(potPin);

  if (switchState2 == HIGH) {
    activeButton = 2;        
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
