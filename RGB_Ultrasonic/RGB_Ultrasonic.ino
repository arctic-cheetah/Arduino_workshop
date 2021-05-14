
//Macros 
#define TRIGGER_PIN 6
#define ECHO_PIN 5

//RGB LED
#define RED_LED 11
#define GREEN_LED 10
#define BLUE_LED 9
#define MAX_DIST 100.0 //in cm
#define DIST_CLOSE 15.0
#define DIST_MED 40.0
#define DIST_FAR 70.0

//Function definitions
void init_RGB_led();
void init_ultrasonic();
float get_dist();

void setup()
{
  //Begin connection with PC at a specified transmission rate
    Serial.begin(9600);
      
    init_RGB_led();
    init_ultrasonic();
    
}

void loop()
{
    //Get the distance
    double dist = get_dist();
    Serial.println(dist);
    //RGB control

    //Need to map the values
    //and typecast the variable
    if (dist <= DIST_CLOSE) {
        
        analogWrite(RED_LED, int((DIST_CLOSE - dist)/ DIST_CLOSE * 256) );
        //Switch off all the other colours
        analogWrite(GREEN_LED, 0 );
        analogWrite(BLUE_LED, 0 );
    }
    //Take care to exclude the boundaries

    //RED Led 
    //Transition from Red to Green
    if (DIST_CLOSE < dist && dist < DIST_MED) {
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, int((DIST_MED - dist) / DIST_MED * 256));
        analogWrite(BLUE_LED, 0);
    }
    
    //Transition from green to blue
    if (DIST_MED < dist) {
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0 );
        analogWrite(BLUE_LED,  int((DIST_FAR - dist) / DIST_FAR * 256) );
    }
    
    // Pause and do it again
    delay(100);
}


////////////////////////////////////////////////////
//Functions exist here

void init_RGB_led() {
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    analogWrite(RED_LED, 0);
    analogWrite(GREEN_LED, 0);
    analogWrite(BLUE_LED, 0);
}
void init_ultrasonic() {
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    digitalWrite(TRIGGER_PIN, LOW);
    delay(1000);
}

float get_dist() {

    
    //Send 8 pulses at 40Khz for approx 10ms
    //Make Echo_pin high and  Trigger pin Low
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    //Wait for the echo pin to become high
    //Begin timing for the echo pin
    unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    //Calculate the distance, using the speed of sound (340m/s) in cm/s
    double dist = double (duration) * 34000 * (0.000001) / 2.0;
  
    // Print the results
    /*
    Serial.print(dist);
    Serial.print("cm \n");
    */
    return dist;
}
