#define STATE_ON   1
#define STATE_OFF  0

#define OUTPUT_ON 101
#define OUTPUT_OFF  100

void fsm_init(int *state, int *output);
void fsm_run(int *state, int input, int *output);
