#include "fsm.h"

void fsm(int *state,int *output){
   if(*state==0){
        *state=1;
        *output=1;
    }else{      
        *state=0;        
        *output=0;
    }
}