
#define STATE_ON_0     100
#define STATE_ON_1     101
#define STATE_OFF_0    200
#define STATE_OFF_1    201
#define OUTPUT_OFF 300
#define OUTPUT_ON  301
#define INPUT_OFF 400
#define INPUT_ON  401

// perlu tambahan agar fungsi C dapat dikenali oleh C++
// https://forum.arduino.cc/t/undefined-reference-to-a-function-i/45113

#ifdef __cplusplus
extern "C" {
#endif
  void toggle_fsm_init(int *state, int *output);
  void toggle_fsm_run(int *state, int input, int *output);
  void to_string(int value,char *buffer_output);
#ifdef __cplusplus
}

#endif
