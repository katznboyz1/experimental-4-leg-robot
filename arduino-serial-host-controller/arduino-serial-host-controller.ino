//include the servo library
#include <Servo.h>

//define the servos
Servo FRONT_LEFT_SERVO, FRONT_RIGHT_SERVO, BACK_LEFT_SERVO, BACK_RIGHT_SERVO;

//the pins that are going to be used for controlling the servos
const int FRONT_LEFT_SERVO_PIN = 3;
const int FRONT_RIGHT_SERVO_PIN = 2;
const int BACK_LEFT_SERVO_PIN = 4;
const int BACK_RIGHT_SERVO_PIN = 5;

//the position that all of the servos will move to upon start/reset (degrees)
const int SERVO_RESET_POSITION = 90;

//the amount that servos will move to move the legs (degrees)
const int SERVO_LEG_MOVEMENT_AMOUNT = 180 / 6;


//the positions of the servos {F_L, F_R, B_L, B_R}
int servoPositions[4] = {SERVO_RESET_POSITION, SERVO_RESET_POSITION, SERVO_RESET_POSITION, SERVO_RESET_POSITION};

//the setup function
void setup() {

    //begin serial communication
    Serial.begin(9600);

    //wait for serial communication to begin
    while (!Serial) {;}

    //attach the servos to their pins
    FRONT_LEFT_SERVO.attach(FRONT_LEFT_SERVO_PIN);
    FRONT_RIGHT_SERVO.attach(FRONT_RIGHT_SERVO_PIN);
    BACK_LEFT_SERVO.attach(BACK_LEFT_SERVO_PIN);
    BACK_RIGHT_SERVO.attach(BACK_RIGHT_SERVO_PIN);

    //move all of the servos to the reset position
    FRONT_LEFT_SERVO.write(SERVO_RESET_POSITION);
    FRONT_RIGHT_SERVO.write(SERVO_RESET_POSITION);
    BACK_LEFT_SERVO.write(SERVO_RESET_POSITION);
    BACK_RIGHT_SERVO.write(SERVO_RESET_POSITION);

    //set up the built in LED
    pinMode(LED_BUILTIN, OUTPUT);
}

//the main loop
void loop() {

    //while there is still serial left to read then continue to loop
    while (Serial.available() > 0) {

        //blink the LED to show that there is serial being read
        digitalWrite(LED_BUILTIN, HIGH);

        //read the serial data
        int serialData = Serial.read();

        //if the reading is the character "a" then move the front left servo forwards
        if (serialData == 'a') {

            //set the servo position to forwards
            servoPositions[0] = SERVO_RESET_POSITION + SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "A" then move the front left servo backwards
        } else if (serialData == 'A') {

            //set the servo position to backwards
            servoPositions[0] = SERVO_RESET_POSITION - SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "1" then move the front left servo to the reset position
        } else if (serialData == '1') {

            //set the servo position to the reset position
            servoPositions[0] = SERVO_RESET_POSITION;

        //if the reading is the character "b" then move the front right servo forwards
        } else if (serialData == 'b') {

            //set the servo position to forwards (inverted because of the direction of the leg)
            servoPositions[1] = SERVO_RESET_POSITION - SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "B" then move the front right servo backwards 
        } else if (serialData == 'B') {

            //set the servo position to backwards (inverted because of the direction of the leg)
            servoPositions[1] = SERVO_RESET_POSITION + SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "2" then move the front right servo to the reset position
        } else if (serialData == '2') {

            //set the servo position to the reset position
            servoPositions[1] = SERVO_RESET_POSITION;

        //if the reading is the character "c" then move the back left servo forwards
        } else if (serialData == 'c') {

            //set the servo position to forwards
            servoPositions[2] = SERVO_RESET_POSITION + SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "C" then move the back left servo backwards
        } else if (serialData == 'C') {

            //set the servo position to backwards
            servoPositions[2] = SERVO_RESET_POSITION - SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "3" then move the back left servo to the reset position
        } else if (serialData == '3') {

            //set the servo position to the reset position
            servoPositions[2] = SERVO_RESET_POSITION;

        //if the reading is the character "d" then move the back right servo forwards
        } else if (serialData == 'd') {

            //set the servo position to forwards (inverted because of the direction of the leg)
            servoPositions[3] = SERVO_RESET_POSITION - SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "D" then move the back right servo backwards 
        } else if (serialData == 'D') {

            //set the servo position to backwards (inverted because of the direction of the leg)
            servoPositions[3] = SERVO_RESET_POSITION + SERVO_LEG_MOVEMENT_AMOUNT;

        //if the reading is the character "4" then move the back right servo to the reset position
        } else if (serialData == '4') {

            //set the servo position to the reset position
            servoPositions[3] = SERVO_RESET_POSITION;
        }

        //move all of the servos to their new position
        FRONT_LEFT_SERVO.write(servoPositions[0]);
        FRONT_RIGHT_SERVO.write(servoPositions[1]);
        BACK_LEFT_SERVO.write(servoPositions[2]);
        BACK_RIGHT_SERVO.write(servoPositions[3]);

        //delay inbetween each communication
        delay(20);
    }

    //set the LED to off to show that there is no serial being read
    digitalWrite(LED_BUILTIN, LOW);
}
