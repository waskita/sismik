#define STATE_ON     100
#define STATE_OFF_1    201
#define STATE_OFF_2    202
#define STATE_OFF_3    203
#define STATE_OFF_4    204
#define STATE_OFF_5    205
#define STATE_OFF_6    206
#define STATE_OFF_7    207
#define STATE_OFF_8    208
#define STATE_OFF_9    209

#define OUTPUT_OFF 300
#define OUTPUT_ON  301

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
