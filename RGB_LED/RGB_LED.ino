#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
#define MAX_PWM 255

void setup() {
    //LED pins need to be changed to output
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop() {

    //Change colour from red to green
    int i = 0;
    while (i < MAX_PWM) {
        analogWrite(RED_PIN, MAX_PWM - i);
        analogWrite(GREEN_PIN, i);
        analogWrite(BLUE_PIN, 0);
        //NEED delay() so the change in the colour of light is visible 
        delay(50);
        i +=1;
    }

    //Change from green to blue
    i = 0;
    while (i < MAX_PWM) {
        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, MAX_PWM - i);
        analogWrite(BLUE_PIN, i);
        //NEED delay() so the change in the colour of light is visible 
        delay(50);
        i +=1;
    }
    //Return to red after being blue
    i = 0;
    while (i < MAX_PWM) {
        analogWrite(RED_PIN, i);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, MAX_PWM - i);
        //NEED delay() so the change in the colour of light is visible 
        delay(50);
        i +=1;
    }
    

}
