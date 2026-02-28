// Pin Definitions
const int redPin = 10;
const int yellowPin = 9;
const int greenPin = 8;
const int buttonPin = 3;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  // Seed the random generator using an unconnected analog pin
  randomSeed(analogRead(0));
}

void loop() {
  // Check if the button is pressed
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // PEDESTRIAN MODE
    allOff();
    digitalWrite(redPin, HIGH); // Red light for pedestrians
    delay(10000);               // Wait 10 seconds
    allOff();
  } else {
    // RANDOM MODE
    int randomLight = random(8, 11); // Picks a pin between 8 and 10
    
    allOff();
    digitalWrite(randomLight, HIGH);
    delay(500); // How long the random light stays on
  }
}

// Helper function to turn all LEDs off
void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}