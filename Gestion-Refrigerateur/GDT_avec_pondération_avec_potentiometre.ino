/*
zone de commantaire 

Projet de gestion d'ecran
Dans un premier temps nous allons importer la librairie LiquidCrystal.

*/
#include <LiquidCrystal.h>

// nous allons initialiser nos constantes d'ecran PIN DIGITAL
const int rs=12, en=11, d4=4, d5=5, d6=6, d7=7;

// Nous allons initialiser nos constente températeur PIN ANALOG
const int sensorTempPin1=0;
const int sensorTempPin2=1;

//Gestion de la pondérance des sondes par rapport a leur postion H||B
const int sonde1Base = 1;
const int sonde2Haute = 3;

//Reglage de temperature
const int degMaxTemp = 8;
const int degMinTemp = 0;
const float acceptDifDeg = 0.15;
float limitRegleTempMax;
float limitRegleTempMin;
int resultTempOI=0;
int degRglageTemp = 4;

//affichage bonne tempuerature (Gestion module peltier)
const int lumiere=10;

//GEstion de la temperature par potentiometre PIN ANALOG
const int reglageTemp = 2;
const float pasReglTemp = 127.875;

//Nous allons parametrer LiquidCristal
LiquidCrystal lcd( rs, en, d4, d5, d6, d7);

void setup() 
{
 //ici nous allons caractériser notre ecran 16x2
  lcd.begin(16,2);
    
  //declaration alumage
  pinMode(lumiere, OUTPUT);
}

void loop()
{
  //nous allons placer notre curseur d'entrer premier ligne
  lcd.setCursor(0,0);
  //ici nous allons ecrir sur l'ecran
  lcd.print("T0: ");
  
  //gestion de la pondérance
  int ponderance = sonde1Base + sonde2Haute;
  
  //Gestion de la températion moyen
  float moyTemp = ( ( getTemp() * sonde1Base) + ( getTemp2() * sonde2Haute ) ) / ponderance;
    
  //Affichage de la temperature a la suite
  lcd.print(moyTemp);  
  lcd.print(" Deg");
  
  //nous allons placer notre curseur d'entrer second ligne
  lcd.setCursor(0,1);
  
  //ici nous allons ecrir sur l'ecran
  lcd.print("Tn: ");
  
  //Temperature a partir du potentionmetre
  float temperateurPotentiel = analogRead(reglageTemp) / pasReglTemp;
  
  //Nous allons gerer la marge d'erreur
  limitRegleTempMin = temperateurPotentiel * (1-acceptDifDeg);
  limitRegleTempMax = temperateurPotentiel * (acceptDifDeg+1);
  
  //Nous verifions si la marge et dans les rangs prévue
  if(moyTemp>limitRegleTempMax)
  {
    resultTempOI = 1;
  }
  else
  {
    if(moyTemp<=limitRegleTempMin)
    {
      resultTempOI = 0; 
    }
  }
  
  if(resultTempOI==1)
  {
   digitalWrite(lumiere, HIGH);
  }
  else
  {
    digitalWrite(lumiere, LOW);
  }
  
  //ici nous allons ecrir sur l'ecran 
  lcd.print(temperateurPotentiel);
  lcd.print(" Deg ");
  lcd.print(resultTempOI);
  
  //Nous allons mettre un temps d'affichage 0.1 second ou 100ms
  delay(100);
  lcd.clear();

}

float getTemp()
{
  /* 
  Nous allons récuperer getTemparé et
  appliquer une formule pour convertire les volts en C°
  */
  int tempRec = analogRead(sensorTempPin1);
  float voltage = tempRec * 5.0;
  voltage /= 1024;
  return (voltage - 0.5) * 100;
}

float getTemp2()
{
  /* 
  Nous allons récuperer getTemparé et
  appliquer une formule pour convertire les volts en C°
  */
  int tempRec = analogRead(sensorTempPin2);
  float voltage = tempRec * 5.0;
  voltage /= 1024;
  return (voltage - 0.5) * 100;
}