#include "fsm.h"
#include <mega328p.h>

void fsm(int *state,int *output){
   if(*state==0){
        *state=1;
        PORTB=PORTB|(1<<5);
        *output=1;
    }else{      
        *state=0;        
        *output=0;
    }
}