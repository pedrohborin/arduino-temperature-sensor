// C++ code
#include <LiquidCrystal.h>
#include <ctype.h>

LiquidCrystal lcd(12, 13, 7, 6, 5, 4); // Pinagem do LCD

int base = 2; // transistor bipolar
int sensor=A0; // sensor tmp36
int pinoSensorLuz = A1;
int valorLuz = 0;
int buzzer = 3;

const int azul = 10;     // led rgb
const int verde = 9;   // led rgb
const int vermelho = 11;// led rgb
String cor = "Verde";
void setup()
{
  lcd.begin(16, 2); // Inicia o lcd de 16x2

  Serial.begin(9600);        // led rgb e sensor tmp
  pinMode(azul, OUTPUT);     // led rgb
  pinMode(verde, OUTPUT);    // led rgb
  pinMode(vermelho, OUTPUT); // led rgb
  pinMode(buzzer,OUTPUT); // BUZZER
  pinMode(base,OUTPUT); // transistor bipolar

}

void vermelhoFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);
}

void verdeFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
}

void brancoFuncao(){
  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
}

void apagadoFuncao(){
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
}

void mostrarDados(){
  float valor=analogRead(sensor);
  float tensao=(valor/1024)*5;
  float temperatura=(tensao-0.5)*100;
  valorLuz = analogRead(pinoSensorLuz);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Celsius: ");
  lcd.println(temperatura);
  lcd.setCursor(0, 1);
  lcd.print("Luz: ");
  if(valorLuz < 67){
  lcd.println("acesa");
  }else{
    lcd.println("apagada");
  }
}

void loop()
{
  
  float valor=analogRead(sensor);
  float tensao=(valor/1024)*5;
  float temperatura=(tensao-0.5)*100;
  
  valorLuz = analogRead(pinoSensorLuz);
  
  if(Serial.available()){
    cor = Serial.readString();
    Serial.println(cor);
  }
  
  mostrarDados();
  digitalWrite(base,LOW);
  
  if(temperatura>=40){
    mostrarDados();
    digitalWrite(base,HIGH);
    
    cor = "Vermelho";
    if (cor=="Vermelho"){
      vermelhoFuncao();
    }
    
    tone(buzzer,150);

    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    
    noTone(buzzer);
    
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
    delay(500);
    mostrarDados();
      
  }else if(valorLuz<67){
    cor = "Branco";
    if(cor=="Branco"){
      brancoFuncao();
    }
  }else{
    cor = "Verde";
    if(cor=="Verde"){
    verdeFuncao();
    }
  }
  
  delay(500);

}
