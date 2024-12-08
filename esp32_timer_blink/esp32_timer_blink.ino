// demo interupsi timer
// output ke serial tiap detik
// lampu kedip dengan perioda 2 detik
// https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/api/timer.html
#define LED_BUILTIN 22

hw_timer_t *My_timer = NULL;

int timer_counter = 0; // menghitung berapa kali interupsi timer terjadi
int print_job = 0;

#define TIMER_FREQUENCY 1000000L
#define TIMER_ALARM_PERIOD 1000000L // perioda alarm, dalam hitungan

void IRAM_ATTR onTimer() {
  int prev;
  prev = digitalRead(LED_BUILTIN);
  digitalWrite(LED_BUILTIN, !prev);
  timer_counter++;
  print_job = 1; // 1 jika perlu ada pencetakan di main loop
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  Serial.print(F("\nStarting TimerInterruptTest on "));
  Serial.println(ARDUINO_BOARD);
  Serial.print(F("CPU Frequency = "));
  Serial.print(F_CPU / 1000000);
  Serial.println(F(" MHz"));
  Serial.print(F("Source Code: "));
  Serial.println(__FILE__);

  pinMode(LED_BUILTIN, OUTPUT);

  My_timer = timerBegin(TIMER_FREQUENCY);  // prescaler
  timerAttachInterrupt(My_timer, &onTimer);
  timerAlarm(My_timer, TIMER_ALARM_PERIOD, true, 0);
  sei();
}

// the loop function runs over and over again forever
void loop() {
  if (print_job == 1) {
    print_job = 0;
    Serial.print("counter value: ");
    Serial.println(timer_counter);
  }
}