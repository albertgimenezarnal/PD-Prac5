#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED
 
// Objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);


int IN=4;

void setup() {
#ifdef __DEBUG__
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
#endif
 
  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }
 
  // Limpiar buffer
  display.clearDisplay();

  display.setCursor(7, 0);
  display.setTextColor(SSD1306_WHITE);
  display.println("Lectura de voltaje:");
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,20);
  display.println("Los datos que se mostraran a continuacion tienen un error de hasta un 10% aproximadamente.");
  display.display();
  delay(15000);
}
 
void loop() {
  
  
  int measure;
  float volts;
  
    measure=analogRead(IN);
    Serial.println(measure);

    volts=measure*3.3/4095;

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(7, 0);
    display.println("Lectura de tension:");

    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(7, 25);   
    display.print(volts);
    display.println(" V");
    display.display();
    delay(1000);


}