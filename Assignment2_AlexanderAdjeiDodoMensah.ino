// ===== Segment pins (a, b, c, d, e, f, g) =====
int segmentPins[7] = {2, 3, 4, 5, 6, 7, 9};

// ===== Digit patterns: 1 = segment ON, 0 = segment OFF =====
// Order of each row: a, b, c, d, e, f, g
int digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int buzzerPin = 8;
int numSegments = 7;

// ===== showDigit: lights up the correct segments for digit n =====
void showDigit(int n) {
  for (int i = 0; i < numSegments; i++) {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT); // set up the buzzer

  for (int i = 0; i < numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT); // set up each segment
  }

  Serial.println("=== Beeping Countdown Starting ===");

  int count = 9;
  while (count >= 1) {
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);
    tone(buzzerPin, 1000, 200); // short beep

    delay(1000);
    count--;
  }

  showDigit(0);
  tone(buzzerPin, 1500, 1000); // longer completion tone

  Serial.println("=== Countdown Complete ===");
}

void loop() {
  // everything happens once in setup()
}