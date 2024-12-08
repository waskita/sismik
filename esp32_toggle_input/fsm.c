#include "fsm.h"
#include "string.h"

void toggle_fsm_init(int *state, int *output)
{
    *state=STATE_OFF_0;
    *output=OUTPUT_OFF;
}
void toggle_fsm_run(int *state, int input, int *output)
{
    int next_state=0;
    next_state=*state; // default current state
    // hitung next state
    switch(*state)
    {
    case STATE_OFF_0:
    {
        if(input==INPUT_OFF)
        {
            *output=OUTPUT_OFF;
        }
        else
        {
            next_state=STATE_ON_1;
            *output=OUTPUT_ON;
        }
        break;
    }
    case STATE_ON_1:
    {
        if(input==INPUT_OFF)
        {
            next_state=STATE_ON_0;
            *output=OUTPUT_ON;
        }
        else
        {
            *output=OUTPUT_ON;
        }
        break;
    }
    case STATE_ON_0:
    {
        if(input==INPUT_OFF)
        {
            *output=OUTPUT_ON;
        }
        else
        {
            next_state=STATE_OFF_1;
            *output=OUTPUT_OFF;
        }
        break;
    }
    case STATE_OFF_1:
    {
        if(input==INPUT_OFF)
        {
            next_state=STATE_OFF_0;
            *output=OUTPUT_OFF;
        }
        else
        {
            *output=OUTPUT_OFF;
        }
        break;
    }

    default:
    {
        toggle_fsm_init(state,output);
        break;
    }

    }
    *state=next_state;
}

void to_string(int value,char *buffer_output)
{
    switch(value)
    {
    case STATE_ON_0:
    {
        strcpy(buffer_output, "STATE_ON_0");
        break;

    }
    case STATE_ON_1:
    {
        strcpy(buffer_output, "STATE_ON_1");
        break;

    }
    case STATE_OFF_0:
    {
        strcpy(buffer_output, "STATE_ON_0");
        break;

    }
    case STATE_OFF_1:
    {
        strcpy(buffer_output, "STATE_OFF_1");
        break;

    }
    case OUTPUT_OFF:
    {
        strcpy(buffer_output, "OUTPUT_OFF");
        break;

    }
    case OUTPUT_ON:
    {
        strcpy(buffer_output, "OUTPUT_ON");
        break;

    }
    case INPUT_OFF:
    {
        strcpy(buffer_output, "INPUT_OFF");
        break;

    }
    case INPUT_ON:
    {
        strcpy(buffer_output, "INPUT_ON");
        break;

    }
    }
}
