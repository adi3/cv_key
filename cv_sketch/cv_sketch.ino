/**
* Copy - Paste functionality with two push buttons on an Arduino Uno
*/

#define KEY_LEFT_CTRL	0x01
#define KEY_LEFT_SHIFT	0x02
 
uint8_t buf[8] = {}; 	/* Keyboard report buffer */
 
#define PIN_COPY 6
#define PIN_PASTE 7
 
int state = 1;
int c_flag = 0;
int p_flag = 0;

void setup() 
{
  Serial.begin(9600);
 
  pinMode(PIN_COPY, INPUT);
  pinMode(PIN_PASTE, INPUT);
  // Enable internal pull-ups
  digitalWrite(PIN_COPY, 1); 
  digitalWrite(PIN_PASTE, 1); 
 
  delay(200);
}
 // check if bug was solved because of buf=8 or because of adding last else statement.
void loop() 
{ 
  state = digitalRead(PIN_COPY);
  if (state != 1 && c_flag == 0) {
    c_flag = 1;
    buf[0] = KEY_LEFT_CTRL; 	// Ctrl
    buf[2] = 6;    // Letter C
    // buf[2] = 124;	  // Copy key: Less portable
    Serial.write(buf, 8);	// Send keypress
//    Serial.write("c");
    releaseKey();
  } else if (state == 1) {
    c_flag = 0;
    delay(100);
  } else {
    releaseKey();
  }
 
  state = digitalRead(PIN_PASTE);
  if (state != 1 && p_flag == 0) {
    p_flag = 1;
    buf[0] = KEY_LEFT_CTRL; 	// Ctrl
    buf[2] = 25;    // Letter V
    // buf[2] = 125;	  // Paste key: Less portable
    Serial.write(buf, 8);	// Send keypress
//    Serial.write("v");
    releaseKey();
  } else if (state == 1) {
    p_flag = 0;
    delay(100);
  } else {
    releaseKey();
  }
}
 
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
  delay(200);
}
