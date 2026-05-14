#include "Servidor.h"


Servidor::Servidor(const char* ssid , const char* passsword ) : server(80)
{
    this->ssid = ssid;
    this->password = passsword;
}




void Servidor::ConectarWiFi()
{
    WiFi.begin(ssid, password);
    LittleFS.begin();

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(1000);
        Serial.println("Conectando ao WiFi...");
    }
    Serial.println("Servidor pronto! IP do ESP32 : ");
    Serial.println(WiFi.localIP());
}

void Servidor::IniciarServidor(int &valorRuido) {

    server.on("/", [this]() {
       enviarArquivo("/index.html", "text/html");
    });
    server.on("/style.css", [this]() {
       enviarArquivo("/style.css", "text/css");
    });
    server.on("/script.js", [this]() {
       enviarArquivo("/script.js", "application/javascript");
    });
    server.on("/ruido", [&valorRuido, this]() {
        server.send(200, "text/plain", String(valorRuido));
    });

    server.begin();
    Serial.println("Servidor Web iniciado!");
}

void Servidor::enviarArquivo(String path , String contentType){
    if (LittleFS.exists(path))
    {
        File file =LittleFS.open(path,"r");
        server.streamFile(file,contentType);
        file.close();
    }
    else
    {
        server.send(404, "text/plain", "Arquivo nao encontrado");
    }
    
}

void Servidor::AtenderClientes()
{
    server.handleClient();
}