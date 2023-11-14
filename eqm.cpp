int scVerde = 10; //Define a pota D10 do LED verde do sc
const int scAmarelo = 11; //Define a pota D11 do LED amarelo do sc
const int scVermelho = 12; //Define a pota D12 do LED vermelho do sc
const int spVerde = 8; //Define a pota D8 do LED verde do sp
const int spVermelho = 9; //Define a pota D9 do LED vermelho do sp
int ledState = LOW; //Define o estado do LED como desligado
long previousMillis = 0; //Começa a contar o tempo do zero
long interval = 5000; //Tempo de intervalo de 5000 milissegundos
int ctrlLuz = 0; //define o valor de mudança das luzes igual a 0
void setup() {
  Serial.begin(9600);
  pinMode(scVerde,OUTPUT); //Define a porta do LED como saída
  pinMode(scAmarelo,OUTPUT); //Define a porta do LED como saída
  pinMode(scVermelho,OUTPUT);//Define a porta do LED como saída
  pinMode(spVerde,OUTPUT); //Define a porta do LED como saída
  pinMode(spVermelho,OUTPUT); //Define a porta do LED como saída
  pinMode(2, INPUT); // Botao //Define a porta do botão como entrada
}
void loop() {
  unsigned long currentMillis = millis(); //O tempo dos milissegundos começa a correr
  int sensorValue = digitalRead(2); //O valor da porta D2 é lido
  if(currentMillis - previousMillis > //A variavel entra em ação após a leitura da porta 2
  interval) {
    previousMillis = currentMillis; //Os milessegundos previstos são iguais a corrente por milessegundo
    switch(ctrlLuz) { //O botão é precionado
      case 0 : // O valor faz com que ele fassa o semafaro de pedreste fique verde
        digitalWrite(scVermelho,LOW); //O LED do sc é desligado
        digitalWrite(scVerde,HIGH); //O LED do sc é ligado
        digitalWrite(spVerde,LOW); //O LED do sc é desligado
        digitalWrite(spVermelho,HIGH); //O LED do sc é ligado
        ctrlLuz++;
        interval = 15000; //Há um intervalo de 15 segundos
      break; //Mudança de estados dos LEDS
      case 1 : // O caso 1 é acionado (Amarelo)
        digitalWrite(scVerde,LOW); //O LED do sc é desligado
        digitalWrite(scAmarelo,HIGH);//O LED do sc é ligado
        digitalWrite(spVerde,LOW); //O LED do sp é desligado
        digitalWrite(spVermelho,HIGH);//O LED do sp é ligado
        ctrlLuz++;
        interval = 1000; //Há o intervalo de 1 segundo
      break;//Mudança de estados dos LEDS
      case 2 : // O caso 2 é acionado (Vermelho)
        digitalWrite(scAmarelo,LOW); //O LED do sc é desligado
        digitalWrite(scVermelho,HIGH);//O LED do sc é ligado
        digitalWrite(spVermelho,LOW);//O LED do sp é desligado
        digitalWrite(spVerde,HIGH);//O LED do sp é ligado
        interval = 7000; //Intervalo de 7 segundos
        ctrlLuz = 0;
      break;//Mudança de estado
    }
  }
  //Abaixo o valor do botão (Sensor) é lido novamente e o valor é redefino para diferente de 0, caso não haja mudança no estado o ciclo recomeça
  if((sensorValue == 1) && (ctrlLuz == 1)) {
    interval = 2000;
    Serial.print("Sensor ");
    Serial.println(sensorValue, DEC);
  }
}