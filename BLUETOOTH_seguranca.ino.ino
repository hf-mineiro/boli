/****************************************************************
Projeto: Buzz Line
* Criado     : 12/Jul/2023
* Atualizado : 12/Jul/2023
* Autor      : Luiz Eduardo
* Descrição :                
****************************************************************/

char caractereLido;
long caoGuarda;

void setup() {
  // Aqui seu código rodará uma vez:
  Serial.begin(9600);
  pinMode(2, OUTPUT);//IN1
  pinMode(3, OUTPUT);//IN2
  pinMode(4, OUTPUT);//IN3
  pinMode(5, OUTPUT);//IN4
  pinMode(8, OUTPUT);// alimantacao BT
  digitalWrite(2,LOW);//OUT1
  digitalWrite(3,LOW);//OUT2
  digitalWrite(4,LOW);//OUT3
  digitalWrite(5,LOW);//OUT4
  digitalWrite(8,HIGH); 
  caoGuarda = millis();

}

void loop() {
  if (Serial.available()){
    caractereLido = Serial.read();
    caoGuarda = millis();
    if(caractereLido == 'F') //para frente
    {
      Serial.println("Para Frente"); 
      digitalWrite(2,HIGH);//OUT1
      digitalWrite(3,LOW);//OUT2
      digitalWrite(4,HIGH);//OUT3
      digitalWrite(5,LOW);//OUT4
    }
    if(caractereLido == 'B') //para trás
    {
      Serial.println("Para Tras"); 
      digitalWrite(2,LOW);//OUT1
      digitalWrite(3,HIGH);//OUT2
      digitalWrite(4,LOW);//OUT3
      digitalWrite(5,HIGH);//OUT4
    }
    if(caractereLido == 'R') //para direita
    {
      Serial.println("Para Direita"); 
      digitalWrite(2,HIGH);//OUT1
      digitalWrite(3,LOW);//OUT2
      digitalWrite(4,LOW);//OUT3
      digitalWrite(5,LOW);//OUT4
    }
    if(caractereLido == 'L') //para esquerda
    {
      Serial.println("Para Esquerda"); 
      digitalWrite(2,LOW);//OUT1
      digitalWrite(3,LOW);//OUT2
      digitalWrite(4,HIGH);//OUT3
      digitalWrite(5,LOW);//OUT4
    }
    if(caractereLido == 'S') //para esquerda
    {
      Serial.println("Parar");  
      digitalWrite(2,LOW);//OUT1
      digitalWrite(3,LOW);//OUT2
      digitalWrite(4,LOW);//OUT3
      digitalWrite(5,LOW);//OUT4
    } 

  }
  else{
    if ((millis()- caoGuarda) > 500){
      digitalWrite(2,LOW);//OUT1
      digitalWrite(3,LOW);//OUT2
      digitalWrite(4,LOW);//OUT3
      digitalWrite(5,LOW);//OUT4
      Serial.println("Parar sem Sinal"); 
    }
  }
}
