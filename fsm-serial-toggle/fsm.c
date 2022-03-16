#include "fsm.h"
#include <mega328p.h>

void fsm(int *state,int input,int *output){
    switch(*state){
    case STATE_OFF1:{
        if(input==1){
            *state=STATE_ON0; 
            *output=1;
        }else{
            // tetap 
            *output=0;                   
        }
        break;
    }
    case STATE_ON0:{
        if(input==1){
            *output=1;
        }else{
            *state=STATE_ON1;
            *output=1;        
        }
        break;
    }
    case STATE_ON1:{
        if(input==1){
            *state=STATE_OFF0;
            *output=0;
        }else{
            // tetap
            *output=1;        
        }
        break;
    }
    case STATE_OFF0:{
        if(input==1){
            *output=0;            
        }else{
            *state=STATE_OFF1;
            *output=0;                    
        }
        break;
    }
    default:{
        *state=STATE_OFF1;  // mestinya tidak pernah ke sini
        break;
        }        
    }  
}