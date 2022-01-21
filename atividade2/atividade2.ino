#define PINO_PWM                      9    //pino do Arduino que terá a ligação para o driver de motor (ponte H) L298N) 
int buttonState_Motordc = 2 ; 
int cont = 0 ;
#define botao 2

//display
const int A = 7;
const int B = 6;
const int C = 5;
const int D = 4;

void setup()
{ 
    //configura como saída pino terá a ligação para o driver de motor (ponte H) L298N)
    pinMode(PINO_PWM, OUTPUT);
}
  
void loop()
{   
    int valor_pwm = 0;   //variavel que armazena o valor do PWM (0..255 -> 0%..100% da rotação do motor) 
    
// condição do botão de seleção
if (digitalRead(botao)== HIGH) {
      delay(500);
      cont++;
         
if (cont==4){
  cont=1;
 } 
    
 
   
 if (cont==1) {
     
    analogWrite(PINO_PWM, 50);
   
        
    digitalWrite(A, 1); 
    digitalWrite(B, 0);
    digitalWrite(C, 0);
    digitalWrite(D, 0);

    
}
  if (cont==2) {
      analogWrite(PINO_PWM, 100);
     
  
      digitalWrite(A, 0); 
      digitalWrite(B, 1);
      digitalWrite(C, 0);
      digitalWrite(D, 0);
}
  if (cont==3) {
     analogWrite(PINO_PWM, 200);
     

    digitalWrite(A, 1); 
    digitalWrite(B, 1);
    digitalWrite(C, 0);
    digitalWrite(D, 0);
 }
 }
}
