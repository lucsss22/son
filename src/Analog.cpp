#include "Analog.h"


Analog::Analog(int sigPin)
{
    this->sig = sigPin;
    pinMode(sig, INPUT);
}

int Analog::PegarSonDecibeis()
{
        
     int sum = 0 ; 
    for (int i = 0; i < 100; ++i) {
                
        sum += analogRead(this->sig);
    }
    int som = map(sum/100,0,4095,30 , 120);
    return som;
}