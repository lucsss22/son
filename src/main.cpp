#include <Tela.h>
#include <Analog.h>
#include <Servidor.h>



Analog meuMicrofone(35);
Tela minhaTela(128, 64, 22, 21);
Servidor meuServidor("POCO X6 Pro 5G", "12345679");
// Servidor meuServidor("Wokwi-GUEST", "");
int som = 0;




void setup()
{
  Serial.begin(115200);
  minhaTela.IniciarTela();
  meuServidor.ConectarWiFi();

  if (!LittleFS.begin(true))
  {
    Serial.println("Erro ao montar o sistema de arquivos LittleFS");
    return;
  }
  Serial.println("Sistema de arquivos LittleFS montado com sucesso");

  meuServidor.IniciarServidor(som);
}





void loop()
{
  som = meuMicrofone.PegarSonDecibeis();
  Serial.println(som);

  minhaTela.LimpaTela();
  minhaTela.ImprimimDB(som);

  meuServidor.AtenderClientes();

  delay(100);
}

