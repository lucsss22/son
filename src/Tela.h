#ifndef TELA_H
#define TELA_H

#include <Adafruit_SSD1306.h>
#include <Wire.h>


class Tela
{
    private:
        Adafruit_SSD1306 display ;
        int scl ; 
        int sda ;

    public: 
       

        Tela(int al , int lar , int sclPin , int sdaPin)  ;
        


        void IniciarTela();

        void LimpaTela();

        void ImprimimDB(int n );
};


#endif 