//Arduino workshop code to generate sound by changing the duration
//2021-05-13
//By Jeremy
#define SOUND_PIN 2
#define DURATION 100

void setup() {
	pinMode(SOUND_PIN, OUTPUT);
}

void loop () {
    digitalWrite(SOUND_PIN, HIGH);
	delay(DURATION ); 
	digitalWrite(SOUND_PIN, LOW);
	delay(DURATION ); 
}
