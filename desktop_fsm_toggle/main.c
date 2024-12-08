#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

int main()
{
    int i;
    printf("Pengujian FSM\n");
    int fsm_state, fsm_input,fsm_output;
    fsm_input=0;
    fsm_init(&fsm_state,&fsm_output); // inisialisasi state
    for(i=0; i<10; i++)
    {
        fsm_run(&fsm_state,fsm_input,&fsm_output);
        printf("%d %d %d\n",fsm_state,fsm_input,fsm_output);
    }
    return 0;
}
