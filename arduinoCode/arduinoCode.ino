/*  HARDCORE PRODUCE WATERING SYSTEM:
 *  AUTHORS: JON PERRI AND JUSTIN CHAN
 *  
 *   
 *  REFERENCES/EXAMPLES:
 *  Pushbutton: https://www.arduino.cc/en/Tutorial/Button
 *  Millis() timing: http://stackoverflow.com/questions/26006250/execute-a-function-for-x-seconds-every-y-seconds-on-arduino
 *  
 */

// TIMING CONFIGURATION -------------------
const int wateringInterval=5000; // ms to wait between each watering; 1000 ms = 1 s
const int wateringDuration=2000; // ms to water (ms to leave pump+lights+music on while watering)
boolean wateringOn=false; // initialize variable for the state of watering system
unsigned long startTime; //

// BUTTON MAPPING -------------------------
const int slayerButtonPin = 2; // pin number of the slayer button
int slayerButtonState = 0; // initialize variable for reading slayer button status

const int testPumpButtonPin = 3; // pin number for the test pump button. pressing this button activates the pump only.
int testPumpButtonState = 0; 
boolean tempPumpOn=false; // initialize variable for testing pump on/off state

// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:

  // initialize pushbuttons:
  pinMode(slayerButtonPin, INPUT); // set the slayer push button pin as an input
  pinMode(testPumpButtonPin, INPUT); // set the test pump button as an input

  // millis() gets the # of milliseconds since the Arduino began running the program
  startTime=millis(); // initialize watering timer
}

void loop() {
  // put your main code here, to run repeatedly:

  // Manually run the pump for testing:
  testPumpButtonState = digitalRead(testPumpButtonPin);
  if (testPumpButtonState == HIGH && tempPumpOn == false) {
    // test pump button is pressed down for the first time
    waterPump(true);
    tempPumpOn = true;
  }
  else if (testPumpButtonState == LOW && tempPumpOn == true) {
    // test pump button has been let go, turn the pump off
    waterPump(false);
    tempPumpOn = false; 
  }


  // Manually trigger SLAYER WATERING when slayer button is pressed:
  slayerButtonState = digitalRead(slayerButtonPin); // read the state of the slayer button
  if (slayerButtonState == HIGH){
    // button is being pressed down, activate SLAYER MODE
    // triggers watering for standard watering duration, except with METALLLL.
    // next watering will occur after the waterInterval from the time of this metal watering.
    lights(true); // activate lights
    music(true, 2); // activate music, track 2 FOR SLAYERRRR
    wateringOn=true;
    startTime=millis(); // reset watering timer    
  }
  
  /** BEGIN SCHEDULED WATERING CODE **/ 
  // start watering
  if (!wateringOn && millis() > startTime+wateringInterval){    
    waterPump(true); // activate water pump
    lights(true); // activate lights
    music(true, 1); // activate music, track 1
    wateringOn=true; 
    }

  // stop watering
  if (wateringOn && millis() > startTime+wateringInterval+wateringDuration){    
    waterPump(false); // deactivate water pump
    lights(false); // deactivate lights
    music(false, 0); // deactivate music
    wateringOn=false;
    startTime=millis(); // reset watering timer   
    }
  /** END SCHEDULED WATERING CODE **/ 
}

// Function to turn the pump on/off
// input is boolean variable 
void waterPump(boolean pumpOn){
  if (pumpOn){
    // code to turn the pump on here
    
  }  
  else{
    // code to turn pump off here
    
  } 
}


// Function to turn lights on/off
void lights(boolean lightsOn){
  if (lightsOn){
    // code to turn the lights on here
    
  }  
  else{
    // code to turn lights off here
    
  } 
}

/* Function to turn music on/off
inputs are boolean musicOn and int trackNum, ie:
music(true, 1) // turn music on, set to track 1
music(false, 0) // turn music off
musicOn = true to turn the music on
trackNum = 1 for thunderstorm
trackNum = 2 for customTrack1
trackNum = 3 for customTrack2
*/ 
void music(boolean musicOn, int trackNum){
  if (musicOn){
    // code to turn the music on with selected track
    switch (trackNum) {
      case 0: 
        // do nothing
      case 1:
        // set thunderstorm track here
        
        break;
      case 2:
        // set slayer track here
        
        break;
      case 3:
        // set another trackhere
        
        break;
    }
  }   
  else{
    // turn music off
    }
}

