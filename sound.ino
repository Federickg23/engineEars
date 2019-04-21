//tone(pin, frequency, duration)
const int speaker = 13;
const int pitches[] = { 1, 2, 3, 4, 5 };
const int tones[] = { 100, 200, 300, 400, 500 };
const int buttonOne = 1;
const int buttonTwo = 2;
const int buttonThree = 3;
const int buttonFour = 4;
const int buttonFive = 5;
const int choice;
const int game;

void setup() {
  // put your setup code here, to run once:
  pinMode (speaker,OUTPUT);
  pinMode (buttonOne,INPUT);
  pinMode (buttonTwo,INPUT);
  pinMode (buttonThree,INPUT);
  pinMode (buttonFour,INPUT);
  pinMode (buttonFive,INPUT);
  digitalWrite (buttonOne, HIGH);
  digitalWrite (buttonTwo, HIGH);
  digitalWrite (buttonThree, HIGH);
  digitalWrite (buttonFour, HIGH);
  digitalWrite (buttonFive, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  playNote();
  buttonPlaysSound();
  if (choice == game) {
    //play game again
  }

}

//NOT SURE HOW TO USE SPEAKER (LOOK LOWER)
void buttonPlaysSound() {
  
  noTone(13);
  if (digitalRead(buttonOne) == LOW)
  {
    tone(13, 100, 1000);
    noTone(13);
    choice = 1;
  }

  if (digitalRead(buttonTwo) == LOW)
  {
    tone(13, 200, 1000);
    noTone(13);
    choice = 2;
  }

  if (digitalRead(buttonThree) == LOW)
  {
    tone(13, 300, 1000);
    noTone(13);
    choice = 3;
  }

  if (digitalRead(buttonFour) == LOW)
  {
    tone(13, 400, 1000);
    noTone(13);
    choice = 4;
  }

  if (digitalRead(buttonFive) == LOW)
  {
    tone(13, 500, 1000);
    noTone(13);
    choice = 5;
  }
}

//TRIED USING ONLINE VERSION AND MODIFIED IT
void playNote() {

  int count = 5;
  int index = 0;
  index = (int)random(1, count);

  // play the tone corresponding to the note name
  for (int i = 0; i < 5; i++) {
    if (pitches[i] == index) {
      playTone(tones[i], 1000);
      game = i;
    }
  }
}

//NOT SURE HOW TO USE SPEAKER LOL
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speaker, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speaker, LOW);
    delayMicroseconds(tone);
  }
}
