// lampu kedip dengan 10% duty cycle, extended FSM

#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"


int main()
{
    int i;
    printf("Testing FSM Toggle with input\n");
    int state;
    int input,output;
    input=0;
    output=0;
    toggle_fsm_init(&state,&output); // inisialisasi state
    printf("  T   S   I   O   C\n");
    for(i=0; i<30; i++)
    {
        // make pulse
        input=INPUT_OFF;
        if(i>5 && i<10){
            input=INPUT_ON;
        }
        if(i>15 && i<18){
            input=INPUT_ON;
        }

                if(i>22 && i<25){
            input=INPUT_ON;
        }

        toggle_fsm_run(&state,input,&output);
        printf("%3d %3d %3d %3d\n",i,state,input,output);
        char input_string[100];
        char state_string[100];
        char output_string[100];
        to_string(input,input_string);
        to_string(state,state_string);
        to_string(output,output_string);

//        printf("%d %s %s %s\n",i,state_string,input_string,output_string);

    }
    return 0;
}
