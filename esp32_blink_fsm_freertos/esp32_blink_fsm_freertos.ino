// LED blink with FSM and FreeRTOS
#include "fsm.h"

#define LED_OUTPUT 22  // 22 untuk lolin32_lite, 2 untuk Devkit-C1
#define TIMER_FREQUENCY 1000000L
#define TIMER_PERIOD 1000000L

int fsm_state;
int fsm_output;

int task_counter = 0;
void TaskFSM(void *parameter) {
  // task init
  TickType_t xLastWakeTime;
  const TickType_t xPeriod = 1000;
  xLastWakeTime = xTaskGetTickCount();

  while (1) {
    // task loop
    blink_fsm_run(&fsm_state, 0, &fsm_output);
    // kirim output ke GPIO
    if (fsm_output == OUTPUT_ON) {
      digitalWrite(LED_OUTPUT, LOW);  // Lolin32 output pin 22 active low
    }
    if (fsm_output == OUTPUT_OFF) {
      digitalWrite(LED_OUTPUT, HIGH);
    }
    vTaskDelayUntil(&xLastWakeTime, xPeriod);
    task_counter++;
  }
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.println("\nLED blink with FSM and FreeRTOS");
  pinMode(LED_OUTPUT, OUTPUT);

  blink_fsm_init(&fsm_state, &fsm_output);  // inisialisasi FSM
  xTaskCreate(
    TaskFSM,   /* Task function. */
    "TaskFSM", /* String with name of task. */
    10000,     /* Stack size in bytes. */
    NULL,      /* Parameter passed as input of the task */
    1,         /* Priority of the task. */
    NULL);     /* Task handle. */
}

// the loop function runs over and over again forever
int prev_task_counter = 0;
void loop() {
  if (task_counter != prev_task_counter) {
    prev_task_counter = task_counter;
    Serial.print("task counter: ");
    Serial.println(task_counter); // Serial.print() di main loop supaya tidak konflik
  }
}
