// lampu kedip dengan 10% duty cycle, extended FSM

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Testing FSM Toggle with input\n");
    int state;
    int input,output;
    int counter;
    input=0;
    output=0;
    blink_fsm_init(&state,&output,&counter); // inisialisasi state
    printf("  T   S   I   O   C\n");
    for(i=0; i<30; i++)
    {
        blink_fsm_run(&state,input,&output,&counter);
        printf("%3d %3d %3d %3d %3d\n",i,state,input,output,counter);
    }
    return 0;
}
