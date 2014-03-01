/**
* Copy - Paste functionality with two push buttons on an Arduino Uno
*/

#define KEY_LEFT_CTRL	0x01
#define KEY_LEFT_SHIFT	0x02
 
uint8_t buf[8] = {}; 	/* Keyboard report buffer */
 
#define PIN_COPY 7
#define PIN_PASTE 8
#define PIN_C_LED 9
#define PIN_P_LED 6
 
int state = 1;
boolean c_flag = false;
boolean p_flag = false;

void setup() 
{
  Serial.begin(9600);
 
  pinMode(PIN_COPY, INPUT);
  pinMode(PIN_PASTE, INPUT);
  pinMode(PIN_C_LED, OUTPUT);
  pinMode(PIN_P_LED, OUTPUT);
  // Enable internal pull-ups
  digitalWrite(PIN_COPY, 1); 
  digitalWrite(PIN_PASTE, 1); 
  
  delay(200);
}
 // check if bug was solved because of buf=8 or because of adding last else statement.
void loop() 
{ 
  state = digitalRead(PIN_COPY);
  if (state != 1 && !c_flag) {
    c_flag = true;
    buf[0] = KEY_LEFT_CTRL; 	// Ctrl
    buf[2] = 6;    // Letter C
    Serial.write(buf, 8);	// Send keypress
    digitalWrite(PIN_C_LED, 1);
 //   Serial.write("\nc");
    releaseKey();
  } else if (state == 1) {
    c_flag = false;
    delay(50);
  }
 
  state = digitalRead(PIN_PASTE);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL; 	// Ctrl
    buf[2] = 25;    // Letter V
    Serial.write(buf, 8);	// Send keypress
    digitalWrite(PIN_P_LED, 1);
 //   Serial.write("\nv");
    releaseKey();
    
    // handles repetitive printing with initial pause
    if (!p_flag) {
      p_flag = true;
      delay(500);
    }// else delay(50);
  } else p_flag = false;
}
 
void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
  digitalWrite(PIN_C_LED, 0);
  digitalWrite(PIN_P_LED, 0);
  delay(100);
}
