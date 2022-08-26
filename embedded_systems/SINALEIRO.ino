const int verde = 8;
const int amarelo = 9;
const int vermelho = 10;

const int verdePedestre = 11;
const int vermelhoPedestre = 12;
const int botao = 2;
int x = 0;


int estadoBotao = 0;

void setup()
{
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  
  pinMode(verdePedestre, OUTPUT);
  pinMode(vermelhoPedestre, OUTPUT);
  
  pinMode(botao, INPUT);
}

void loop()
{
  x = 0;
  estadoBotao = digitalRead(botao);
  
  digitalWrite(verde,HIGH);
  digitalWrite(vermelhoPedestre,HIGH);
  digitalWrite(verdePedestre,LOW);
  
  if (estadoBotao == HIGH ){
      delay(1000);  
    
      //amarelo
      digitalWrite(amarelo,HIGH);
      digitalWrite(verde,LOW);
      delay(1000);
    
      //vermelho
    
      digitalWrite(vermelhoPedestre,LOW);
      digitalWrite(verdePedestre,HIGH);
        digitalWrite(amarelo,LOW);
      digitalWrite(vermelho,HIGH);
      delay(1000);
    
        digitalWrite(verdePedestre,LOW);
        while(x < 3){
          digitalWrite(vermelhoPedestre,HIGH);
          delay(500);
          digitalWrite(vermelhoPedestre,LOW);
          delay(500);
          x = x + 1;
        }
    
      //verde
      digitalWrite(vermelho,LOW);    
    
      
          
  }
}
