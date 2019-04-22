const int speaker = 13;
const int pitches[] = { 1, 2, 3, 4, 5 };
const int tones[] = { 100, 200, 300, 400, 500 };
void setup() {
  // put your setup code here, to run once:
  pinMode (speaker,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  playNote();
  delay(100);
}

void playNote() {

  int count = 5;
  int index = 0;
  index = (int)random(1, count);

  // play the tone corresponding to the note name
  for (int i = 0; i < 5; i++) {
    if (pitches[i] == index) {
      playTone(tones[i], 1000);
//      game = i;
    }
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speaker, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speaker, LOW);
    delayMicroseconds(tone);
  }
}
