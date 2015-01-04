// ping timer
int counter = 0;

// indicator toggle
boolean lightOn = false;

/*
 * Runs once when you press reset or power the board
 */
void setup() {
  // open serial port 
  Serial.begin(115200);
  
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

/*
 * Main
 */
void loop() {
  
  /*
   * Read Serial Bus
   */
  if (Serial.peek() != -1) {    
    // read data from bus
    char c;
    do {
      c = (char) Serial.read();
    } while (Serial.peek() != -1);
    
    // toggle light if any input was found
    if (c != 0) {
      toggle();
    }
  }
  
  /*
   * Ping Serial Bus
   */
  if (++counter > 20) { // ping serial bus every 2s
    // ping
    Serial.print('a');
    counter = 0;
  }
  
  // loop throttle
  delay(100);
}

// toggle light on board
void toggle() {
  // switch
  lightOn = !lightOn;
  
  // set light as appropriate
  if (lightOn) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
