// LED blink with FSM and timer interrupt
#include "fsm.h"

#define LED_OUTPUT 22  // 22 untuk lolin32_lite, 2 untuk Devkit-C1
#define TIMER_FREQUENCY 1000000L
#define TIMER_PERIOD 1000000L

int fsm_state;
int fsm_output;
int fsm_job=0;
int timer_counter=0;

hw_timer_t *My_timer = NULL;

void IRAM_ATTR onTimer() {
  fsm_job = 1;  // 1 jika perlu ada pencetakan di main loop
  timer_counter++; 

  blink_fsm_run(&fsm_state, 0, &fsm_output);
  // kirim output ke GPIO
  if (fsm_output == OUTPUT_ON) {
    digitalWrite(LED_OUTPUT, LOW);  // Lolin32 output pin 22 active low
  }
  if (fsm_output == OUTPUT_OFF) {
    digitalWrite(LED_OUTPUT, HIGH);
  }
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.println("\nLED blink with FSM and timer interrupt");
  pinMode(LED_OUTPUT, OUTPUT);
  My_timer = timerBegin(TIMER_FREQUENCY);  // set timer frequency
  timerAttachInterrupt(My_timer, &onTimer);
  timerAlarm(My_timer, TIMER_PERIOD, true, 0);  // set alarm period
  blink_fsm_init(&fsm_state, &fsm_output);      // inisialisasi FSM
}

// the loop function runs over and over again forever
void loop() {

  if (fsm_job == 1) {
    fsm_job = 0;
    Serial.print("counter value: ");
    Serial.println(timer_counter);
  }
}
