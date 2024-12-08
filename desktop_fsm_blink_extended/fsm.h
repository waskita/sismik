
#define STATE_ON     100
#define STATE_OFF    200

#define OUTPUT_OFF 300
#define OUTPUT_ON  301

// perlu tambahan agar fungsi C dapat dikenali oleh C++
// https://forum.arduino.cc/t/undefined-reference-to-a-function-i/45113

#ifdef __cplusplus
extern "C" {
#endif
  void blink_fsm_init(int *state, int *output, int *counter);
  void blink_fsm_run(int *state, int input, int *output, int *counter);
#ifdef __cplusplus
}

#endif
