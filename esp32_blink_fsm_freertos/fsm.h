#define STATE_ON 1
#define STATE_OFF 0

#define OUTPUT_ON 101
#define OUTPUT_OFF 100

// perlu tambahan agar fungsi C dapat dikenali oleh C++
// https://forum.arduino.cc/t/undefined-reference-to-a-function-i/45113

#ifdef __cplusplus
extern "C" {
#endif
  void blink_fsm_init(int *state, int *output);
  void blink_fsm_run(int *state, int input, int *output);
#ifdef __cplusplus
}

#endif
