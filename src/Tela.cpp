
#include <Adafruit_GFX.h>
#include "Tela.h"


Tela :: Tela(int al , int lar , int sclPin , int sdaPin) : display(al, lar, &Wire, -1) 
    {
        this->scl = sclPin;
        this->sda = sdaPin;
    }


void Tela :: IniciarTela()
    {
            
        display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    }

void Tela :: LimpaTela()
    {
        display.clearDisplay();
    }

void Tela :: ImprimimDB(int n )
    {
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0,0);
        display.print("Ruido:");
        display.print(n); 
        display.print("dB");

        display.display();
    }


 