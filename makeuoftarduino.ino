#define SAMPLE_RATE 8000 // set the sample rate to 8 kHz
#define SPEAKER_PIN 9 // set the speaker pin to pin 9

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);
  Serial.begin(9600); // initialize the serial communication
}

void loop() {
  // read the audio data from the serial port
  while (Serial.available() > 0) {
    int audioData = Serial.read();

    // convert the audio data from 8-bit signed to 16-bit signed format
    audioData <<= 8;

    // play the audio data through the speaker
    analogWrite(SPEAKER_PIN, audioData);
    delayMicroseconds(1000000 / SAMPLE_RATE);
  }
}