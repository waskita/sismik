#include "fsm.h"
void blink_fsm_init(int *state, int *output)
{
    *state=STATE_ON;
    *output=OUTPUT_OFF;
}
void blink_fsm_run(int *state, int input, int *output)
{
    int next_state=0;
    // hitung next state
    switch(*state)
    {
    case STATE_ON:
    {
        next_state=STATE_OFF_1;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_1:
    {
        next_state=STATE_OFF_2;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_2:
    {
        next_state=STATE_OFF_3;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_3:
    {
        next_state=STATE_OFF_4;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_4:
    {
        next_state=STATE_OFF_5;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_5:
    {
        next_state=STATE_OFF_6;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_6:
    {
        next_state=STATE_OFF_7;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_7:
    {
        next_state=STATE_OFF_8;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_8:
    {
        next_state=STATE_OFF_9;
        *output=OUTPUT_OFF;
        break;
    }
    case STATE_OFF_9:
    {
        next_state=STATE_ON;
        *output=OUTPUT_ON;
        break;
    }
    default:
    {
        *state=STATE_ON;
        *output=OUTPUT_ON;
        break;
    }

    }
    *state=next_state;
}
