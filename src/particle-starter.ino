int led1 = D0;
int led2 = D7;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  int randomNumber = random(100);
  int randomNumberDoubled = randomNumber * 2;

  if (randomNumber < 50) {
    Particle.publish("channel-one", String(randomNumber), 60, PRIVATE);
  }

  if (randomNumber > 50) {
    Particle.publish("channel-two", String(randomNumberDoubled), 60, PRIVATE);
  }
  
  delay(100);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  delay(1000);
}
