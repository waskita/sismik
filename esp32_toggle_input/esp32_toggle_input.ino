// LED blink with Extended FSM and delay in superloop
#include "fsm.h"

#define LED_OUTPUT 22  // 22 untuk lolin32_lite, 2 untuk Devkit-C1
#define TOMBOL_INPUT 0
int fsm_state;
int fsm_output;
int fsm_counter;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.println("\nLED blink with Extended FSM and delay");
  pinMode(LED_OUTPUT, OUTPUT);
  pinMode(TOMBOL_INPUT, INPUT_PULLUP);
  toggle_fsm_init(&fsm_state, &fsm_output);
}

// the loop function runs over and over again forever
void loop() {
  int fsm_input;
  int data_read;
  data_read = digitalRead(TOMBOL_INPUT);
  // input active low, maka perlu dibalik dulu
  if (data_read == LOW)
    fsm_input = INPUT_ON;
  if (data_read == HIGH)
    fsm_input = INPUT_OFF;

  toggle_fsm_run(&fsm_state, fsm_input, &fsm_output);
  // kirim output ke GPIO
  if (fsm_output == OUTPUT_ON) {
    digitalWrite(LED_OUTPUT, LOW);  // Lolin32 output pin 22 active low
  }
  if (fsm_output == OUTPUT_OFF) {
    digitalWrite(LED_OUTPUT, HIGH);
  }
  // cetak status untuk debugging
  Serial.print("S:");
  Serial.print(fsm_state);
  Serial.print(" I:");
  Serial.print(fsm_input);
  Serial.print(" O:");
  Serial.print(fsm_output);
  Serial.print(" C:");
  Serial.print(fsm_counter);
  Serial.print("\n");
  delay(100);  // delay 100ms , perlu cepat agar responsif. dapat diperlambat untuk debugging
}
