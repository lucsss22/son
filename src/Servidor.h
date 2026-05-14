#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <LittleFS.h>
#include <WebServer.h>

class Servidor
{
    private:
        const char* ssid ; 
        const char* password ;
        WebServer server ;

    public:

        Servidor(const char* ssid , const char* passsword );
        

        void ConectarWiFi();

        void IniciarServidor(int &valorRuido);

        void enviarArquivo(String path , String contentType);

        void AtenderClientes();
        
};


#endif 