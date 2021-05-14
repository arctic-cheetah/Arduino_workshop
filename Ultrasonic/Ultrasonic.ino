#define ECHO_PIN 5
#define TRIG_PIN 6

void setup() {
    Serial.begin(9600);

    //Initialise pins
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
    digitalWrite(TRIG_PIN, LOW);
}

void loop() {
    //Send a 10ms Ultrasonic signal
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH);//In microseconds


    //340 m/s 1000000microsseconds * time
    float distance = float(340.0 / 1000000.0 * 100.0 * duration / 2);
    //Get the distance in microseconds
    Serial.print(distance);
    Serial.print("cm\n");
    
    delay(100);
}
