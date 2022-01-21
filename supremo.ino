//declaração de variaveis 
#include <Servo.h>

#include <Stepper.h>   //biblioteca para controle de motor de passo
#define botao 2
#define base_transistor 4
int cont = 0;

int buttonState_Motor = 0;
int buttonState_motor_Escolha = 2 ;
int buttonState_motor_Esquerda = 13;
int buttonState_motor_Direita = 12;
//servo motor
Servo servomotor; // Cria objeto para controlar o servo
int Abertura = 100;
int Fechamento = 0;
int UltimoEstado = 0;
int sevoPin = 3; // Especifica o pino usado para controlar o servo         
int readPin_D = 12;// Variável para armazenar o valor lido do potenciometro
int readPin_L = 13;

//motor dc
int buttonState_Motordc = 0;

// --- Mapeamento de Hardware motor de passo---
#define   in1   8      //entrada 1 do ULN2003
#define   in2   9      //entrada 2 do ULN2003
#define   in3  10      //entrada 3 do ULN2003
#define   in4  11      //entrada 4 do ULN2003

// ========================================================================================================
// --- Constantes Auxiliares ---
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// --- Declaração de Objetos ---
Stepper myStepper(stepsPerRevolution, in1,in3,in2,in4); 


void setup() {
  pinMode(botao,INPUT_PULLUP);
 ///servo
  pinMode(readPin_L, INPUT);
  pinMode(readPin_D, INPUT);
  pinMode(buttonState_motor_Escolha, INPUT);
  Serial.begin(9600);
  servomotor.attach(sevoPin); // Associa o pino 7 ao objeto servomotor
  servomotor.write(Fechamento); // Inicia servomotor na posição zero

  //motor de passo
  // setar a velocidade a 60 rpm:
  myStepper.setSpeed(30);


}

void loop() {

// condição do botão de seleção
if (digitalRead(botao)== HIGH) {
      delay(500);
      cont++;
      Serial.print(cont);
      
if (cont>3){
  cont=0;
  }   
}
//motor de passo
  if (cont==1){
    //se botão pressionado escolhe a direção direita e esquerda
    if (digitalRead(buttonState_motor_Esquerda) == HIGH ) {
         myStepper.step(stepsPerRevolution);
         //delay(500);
}
    else if (digitalRead(buttonState_motor_Direita)== HIGH) {
        myStepper.step(-stepsPerRevolution);
         // delay(500); 
}
    }  
  // servo motor
if (cont==2){
  //se botão pressionado escolhe a direção direita e esquerda
  if (digitalRead(readPin_D) == HIGH && UltimoEstado == 0){
    servomotor.write(Abertura);
    UltimoEstado = 1;
   // delay(100);
  }else if (digitalRead(readPin_L) == HIGH && UltimoEstado == 1){
    servomotor.write(Fechamento);
    UltimoEstado = 0;
  //  delay(100);
}
}
//motor dc 
if (cont==3){
    buttonState_Motordc = digitalRead(12);
  
  //se botão pressionado escolhe a direção
  if (buttonState_Motordc == HIGH) {
    // turn LED on
    digitalWrite(base_transistor, HIGH);
    delay(100);
  } else {
    // turn LED off
    digitalWrite(base_transistor, LOW);
    
  }
}
}
