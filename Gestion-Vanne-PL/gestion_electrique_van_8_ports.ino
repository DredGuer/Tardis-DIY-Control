/*
Gestion de la lumiere du véhicule T3 VW
*/

// Constante des pins lumiere

const int lumiere1=0, lumiere2=1, lumiere3=2, lumiere4=3, lumiere5=4, lumiere6=5, lumiere7=6; 

// Constante des pins Bouton 

const int bouton1=7, bouton2=8, bouton3=9, bouton4=10, bouton5=11, bouton6=12, bouton7=13;

// Declaration des variable etat bouton en button *For Read

int pushbutton1=0, pushbutton2=0, pushbutton3=0, pushbutton4=0, pushbutton5=0, pushbutton6=0, pushbutton7=0;

// Declaration des variable de lumiere en light *For Read

int light1=0, light2=0, light3=0, light4=0, light5=0, light6=0, light7=0;

void setup()
{
  // Declarons les pins lumiere en OUTPUT
  
  pinMode(lumiere1, OUTPUT);
  pinMode(lumiere2, OUTPUT);
  pinMode(lumiere3, OUTPUT);
  pinMode(lumiere4, OUTPUT);
  pinMode(lumiere5, OUTPUT);
  pinMode(lumiere6, OUTPUT);
  pinMode(lumiere7, OUTPUT);
  
  // Declarons les pins bouton en INPUT
  
  pinMode(bouton1, INPUT);
  pinMode(bouton2, INPUT);
  pinMode(bouton3, INPUT);
  pinMode(bouton4, INPUT);
  pinMode(bouton5, INPUT);
  pinMode(bouton6, INPUT);
  pinMode(bouton7, INPUT);
  
}

void loop()
{
  //Preparation au condition des buttons 
  
  pushbutton1 = digitalRead(bouton1);
  pushbutton2 = digitalRead(bouton2);
  pushbutton3 = digitalRead(bouton3);
  pushbutton4 = digitalRead(bouton4);
  pushbutton5 = digitalRead(bouton5);
  pushbutton6 = digitalRead(bouton6);
  pushbutton7 = digitalRead(bouton7);
  
  //preparation au condition lumiere 
  
  light1 = digitalRead(lumiere1);
  light2 = digitalRead(lumiere2);
  light3 = digitalRead(lumiere3);
  light4 = digitalRead(lumiere4);
  light5 = digitalRead(lumiere5);
  light6 = digitalRead(lumiere6);
  light7 = digitalRead(lumiere7);
  
  //les conditions d'alumage des diode 
  
  
  // Gestion de la premiere lumiere
  
  if(pushbutton1 == HIGH && light1 == LOW)
  {
    digitalWrite(lumiere1, HIGH);
  }
  else
  {
    if(pushbutton1 == HIGH && light1 == HIGH)
    {
    digitalWrite(lumiere1, LOW);
    }
  }
  
  // Gestion de la Seconde lumiere
  
  if(pushbutton2 == HIGH && light2 == LOW)
  {
    digitalWrite(lumiere2, HIGH);
  }
  else
  {
    if(pushbutton2 == HIGH && light2 == HIGH)
    {
    digitalWrite(lumiere2, LOW);
    }
  }
  
  // Gestion de la troisieme lumiere
  
  if(pushbutton3 == HIGH && light3 == LOW)
  {
    digitalWrite(lumiere3, HIGH);
  }
  else
  {
  	if(pushbutton3 == HIGH && light3 == HIGH)
    {
    digitalWrite(lumiere3, LOW);
    }
  }
  
  // Gestion de la quatrieme lumiere
  
  if(pushbutton4 == HIGH && light4 == LOW)
  {
    digitalWrite(lumiere4, HIGH);
  }
  else
  {
    if(pushbutton4 == HIGH && light4 == HIGH)
    {
    digitalWrite(lumiere4, LOW);
    }
  }
  
  // Gestion de la cinquieme lumiere
  
  if(pushbutton5 == HIGH && light5 == LOW)
  {
    digitalWrite(lumiere5, HIGH);
  }
  else
  {
    if(pushbutton5 == HIGH && light5 == HIGH)
    {
    digitalWrite(lumiere5, LOW);
    }
  }
  
  // Gestion de la sixieme lumiere
  
  if(pushbutton6 == HIGH && light6 == LOW)
  {
    digitalWrite(lumiere6, HIGH);
  }
  else
  {
    if(pushbutton6 == HIGH && light6 == HIGH)
    {
    digitalWrite(lumiere6, LOW);
    }
  }
  
  // Gestion de la septieme lumiere
  
  if(pushbutton7 == HIGH && light7 == LOW)
  {
    digitalWrite(lumiere7, HIGH);
  }
  else
  {
    if(pushbutton7 == HIGH && light7 == HIGH)
    {
    digitalWrite(lumiere7, LOW);
    }
  }
  
}