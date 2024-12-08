// LED blink with Extended FSM and delay in superloop
#include "fsm.h"

#define LED_OUTPUT 22  // 22 untuk lolin32_lite, 2 untuk Devkit-C1
int fsm_state;
int fsm_output;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.println("\nLED blink with Extended FSM and delay");
  pinMode(LED_OUTPUT, OUTPUT);
  blink_fsm_init(&fsm_state, &fsm_output);
}

// the loop function runs over and over again forever
void loop() {
  blink_fsm_run(&fsm_state, 0, &fsm_output);
  // kirim output ke GPIO
  if (fsm_output == OUTPUT_ON) {
    digitalWrite(LED_OUTPUT, LOW);  // Lolin32 output pin 22 active low
  }
  if (fsm_output == OUTPUT_OFF) {
    digitalWrite(LED_OUTPUT, HIGH);
  }
  // cetak status untuk debugging
  Serial.print(fsm_state);
  Serial.print(" ");
  Serial.print(fsm_output);
  Serial.print("\n");
  delay(1000);  // delay 1 detik
}
