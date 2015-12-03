// Alice Giordani for ENSAIT e-textile workshops
// upload with "Arduino Pro ou Pro Mini"
// Atmega328 (3.3V, 8MHz)
// TLC 5940

#include "Tlc5940.h"

//Déclaration des LEDs utilisées/branchées au TLC5490
#define  LED1              0
#define  LED2              1
#define  LED3              2
#define  LED4              3
#define  LED5              4

//valeure maximale 4095, intermediaire 3069, moitié 2046, minimale 1023
#define  ULTRA_BRIGHT     4095     // valeur maximale intensité LED
#define  BRIGHT           3069     // valeur intermédiaire intensité LED
#define  LESS_BRIGHT      2046     // valeur moitié intensité LED
#define  MIN_BRIGHT       1023     // valeur minimale intensité LED
#define  OFF              0        // LED éteinte

int LED1_intensity = ULTRA_BRIGHT;
int LED2_intensity = BRIGHT;
int LED3_intensity = LESS_BRIGHT;
int LED4_intensity = MIN_BRIGHT;
int LED5_intensity = ULTRA_BRIGHT;

int Timing = 1000; // millisecondes

/////////////////////// INITIALISATION
void setup()
{
  Tlc.init(); // initialise le TLC5940
}

/////////////////////// BOUCLE PRINCIPALE
void loop()
{
  // Paramètre toutes les valeurs définies précédemment
  Tlc.set(LED1, LED1_intensity);
  Tlc.set(LED2, LED2_intensity);
  Tlc.set(LED3, LED3_intensity);
  Tlc.set(LED4, LED4_intensity);
  Tlc.set(LED5, LED5_intensity);
  // Envoit les valeurs au TLC5490
  Tlc.update();
  // Temps d'affichage
  delay(Timing);

  Tlc.set(LED1, OFF);
  Tlc.set(LED2, OFF);
  Tlc.set(LED3, OFF);
  Tlc.set(LED4, OFF);
  Tlc.set(LED5, OFF);
  // Envoit les valeurs au TLC5490
  Tlc.update();

  delay(Timing);
}
