#include "ADAS_Types.h"
#include "ADAS_Cfg.h"
#include "ADAS_Debug.h"

/*Periperals*/
#include "HAL_IOManager.h"
#include "HAL_Serial_IF.h"

/*App Layer*/
#include "App_Navigation.h"

// Debug pins
#define PIN_ROT_DONE    12
#define PIN_DIST_DONE   11

void setup() {
    Serial.begin(9600);
    Serial.write("hello\n\r");
  //Hw initialization
  serPort.Init(SERIAL1_INITIAL_BAUD_RATE, SERIAL1_TIMEOUT);
  Serial.begin(115200);
  DPRINTLN("Hello\n\r");


  // IO Init
  pinMode(PIN_ROT_DONE, INPUT_PULLUP);
  pinMode(PIN_DIST_DONE, INPUT_PULLUP);
}

void loop() {
  // Set debug data...
  nav_o.rotationDone = !digitalRead(PIN_ROT_DONE);
  nav_o.distanceDone = !digitalRead(PIN_DIST_DONE);

  char datain = Serial.read();
  if (datain == 's') {
    uint16_t offset = Serial.parseInt();
    int8_t angle = Serial.parseInt();
    uint16_t nxt_wall = Serial.parseInt();

    nav_o.setPLSdata(offset, angle, nxt_wall);
  } else if (datain == 'd') {
    DPRINTLN("Run");
    nav_o.continueDrive();
  } else if (datain == 'f') {
    DPRINTLN("Stop");
    nav_o.stopDrive();
  }

