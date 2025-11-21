#include <Adafruit_SSD1306.h> //inclui a biblioteca para o controle do display
#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);  // define o tamanho do display

#define PI 3.1415926535897932384626433832795  //define um valor com várias casas decimais de pi

// inclui os botões e variáveis para o controle
int botao = 5;
int botao2 = 4;
int botao3 = 3;
int botao4 = 2;
int countUp = 0;
int lados = 0;
int countlado = 0;
float area = 0;
int p = 0;
float apot = 0;


void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //inicia o display
  display.clearDisplay(); //limpa o display
  // inclui os botões
  pinMode(botao, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);
}

void loop() {
  //bloco responsável por passar o menu 
  if (digitalRead(botao2) == LOW){
    delay(500);
    countUp++;}
  if (digitalRead(botao4) == LOW){
    delay(500);
    countUp--;}
  
  if(countUp == 0){
    tela1();
  }
   else if(countUp == 1){
    tela2();
  }
   else if(countUp == 2){
    tela3();
  }
   else if(countUp == 3){
    calcularea();
  }
 
 //bloco responsável por não permitir valores impossíveis na calculadora
  if(countUp == 4){
   countUp = 0;}
  if(lados < 3){
   lados = 3;}

}
void tela1(){  //função responsável por chamar a tela 1
  display.clearDisplay();
  display.setTextSize(2); 
  display.setTextColor(1); 
  display.setCursor(17,25); 
  display.print("C.D.A V1");
  display.display();
}

void tela2(){ //função responsável por chamar a tela 2
  if (digitalRead(botao) == LOW){
    delay(500);
    lados++;}
  if (digitalRead(botao3) == LOW){
    delay(500);
    lados--;}
  display.clearDisplay();
  display.fillRect(0, 0, 128, 15, WHITE); 
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE); 
  display.setCursor(2,4); 
  display.print("Quantidade de lados:");
  display.setTextSize(2); 
  display.setTextColor(1); 
  display.setCursor(5,30); 
  display.print("Lados: ");
  display.setTextSize(2); 
  display.setTextColor(1); 
  display.setCursor(80,30); 
  display.print(lados);
  display.display();
}

void tela3(){  //função responsável por chamar a tela 3

   if (digitalRead(botao) == LOW){
    delay(500);
    countlado++;}
   if(digitalRead(botao3) == LOW){
    delay(500);
    countlado--;}
   if(countlado < 0){
    countlado = 0;}

  display.clearDisplay();
  display.fillRect(0, 0, 128, 15, WHITE); 
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE); 
  display.setCursor(22,4); 
  display.print("Valor do lado:");
  display.setTextSize(3); 
  display.setTextColor(1); 
  display.setCursor(30,30); 
  display.print(countlado);
  display.setTextSize(3); 
  display.setTextColor(1); 
  display.setCursor(80,30); 
  display.print("Cm");
  display.display();
}

void calcularea(){  //função responsável por chamar a tela 4(tela que mostra o resultado da área)
  area = (p/2) * apot;
  p = countlado * lados;
  apot = countlado/(2*tan(PI/lados));

  display.clearDisplay();
  display.fillRect(0, 0, 128, 15, WHITE); 
  display.setTextSize(1);
  display.setTextColor(BLACK,WHITE); 
  display.setCursor(50,4); 
  display.print("Area:");
  display.setTextSize(2); 
  display.setTextColor(1); 
  display.setCursor(0,35); 
  display.print(area);
  display.setTextSize(2); 
  display.setTextColor(1); 
  display.setCursor(90,35); 
  display.print("Cm");
  display.setTextSize(1); 
  display.setTextColor(1); 
  display.setCursor(115,30); 
  display.print("2");
  display.display();
}