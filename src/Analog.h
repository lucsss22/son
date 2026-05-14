#ifndef ANALOG_H
#define ANALOG_H

#include <Arduino.h>
#include <iostream>


class Analog
{

    private:
        int sig;

    public:
        Analog(int sigPin);

        int PegarSonDecibeis();

};

#endif 