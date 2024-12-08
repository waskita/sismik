#include "fsm.h"
void blink_fsm_init(int *state, int *output)
{
    *state=STATE_OFF;
    *output=OUTPUT_OFF;
}
void blink_fsm_run(int *state, int input, int *output)
{
    // hitung next state
    switch(*state)
    {
    case STATE_OFF:
    {
        *output=OUTPUT_ON  ;     // hitung output di perhitungan transisi (Mealy)
        *state=STATE_ON;
        break;
    }
    case STATE_ON:
    {
        *output=OUTPUT_OFF    ;
        *state=STATE_OFF;
        break;
    }
    default:
    {
        *state=STATE_OFF;
        break;
    }
    }
    // hitung output berdasarkan state (Moore), tidak dilakukan di contoh ini
}