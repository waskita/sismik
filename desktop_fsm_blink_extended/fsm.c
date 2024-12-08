#include "fsm.h"
void blink_fsm_init(int *state, int *output, int *fsm_counter)
{
    *state=STATE_ON;
    *output=OUTPUT_OFF;
    *fsm_counter=0;
}
void blink_fsm_run(int *state, int input, int *output,int *fsm_counter)
{
    int next_state=0;
    // hitung next state
    switch(*state)
    {
    case STATE_ON:
    {
        next_state=STATE_OFF;
        *output=OUTPUT_OFF;
        *fsm_counter=0;
        break;
    }
    case STATE_OFF:
    {
        if(*fsm_counter>=8)
        {
            next_state=STATE_ON;
            *output=OUTPUT_ON;
        }
        else
        {
            next_state=STATE_OFF;
            *output=OUTPUT_OFF;
            (*fsm_counter)++;
        }
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
