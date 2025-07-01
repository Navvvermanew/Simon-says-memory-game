// Pins for LEDs and Buttons
const int ledPins[] = {8, 9, 10, 11, 12};
const int buttonPins[] = {2, 3, 4, 5, 6};

// Game variables
int sequence[100];  // Stores the sequence
int level = 1;      // Current level (sequence length)

void setup() {
  Serial.begin(9600);
  // Initialize LEDs as OUTPUT
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Initialize Buttons as INPUT
  for (int i = 0; i < 5; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  randomSeed(analogRead(0));  // Seed for random numbers
}

void loop() {
  if (level == 1) {
    generateSequence();  // Start a new game
  }
  playSequence();        // Show the sequence
  if (!checkUserInput()) {  // Check if user failed
    gameOver();          // Blink all LEDs if wrong
    level = 1;           // Reset game
    delay(1000);
  } else {
    level++;             // Increase level
    delay(500);
  }
}

// Generate a random sequence
void generateSequence() {
  for (int i = 0; i < 100; i++) {
    sequence[i] = random(5);  // Random number (0-4)
  }
}

// Blink the current sequence
void playSequence() {
  for (int i = 0; i < level; i++) {
    digitalWrite(ledPins[sequence[i]], HIGH);
    delay(500);
    digitalWrite(ledPins[sequence[i]], LOW);
    delay(300);
  }
}

// Check if user input matches the sequence
bool checkUserInput() {
  for (int i = 0; i < level; i++) {
    bool correctButton = false;
    while (!correctButton) {
      for (int j = 0; j < 5; j++) {
        if (digitalRead(buttonPins[j]) == HIGH) {
          digitalWrite(ledPins[j], HIGH);
          delay(200);
          digitalWrite(ledPins[j], LOW);
          if (j != sequence[i]) {
            return false;  // Wrong button pressed
          }
          correctButton = true;
          delay(200);
          break;
        }
      }
    }
  }
  return true;  // All inputs correct
}

// Blink all LEDs when game over
void gameOver() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(200);
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(200);
  }
}
