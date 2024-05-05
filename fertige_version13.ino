// Motor PWM Definition
#define PWM     6 
int potiWert = 512;
int pwmSpeed;
int startiter=0;
//Der Motor läuft anscheinend immer wenn der PWM noch nicht angesprochen ist
// Motor direction definition
void setup() {  
  pinMode(PWM,OUTPUT);
  Serial.begin(115200);
}
                      
void motorbewegung_je_fach() {
  // Motor PWM Code
  potiWert = 212; 
  //512 ist AUS, 212 ist 150/AN !!!!!!!
  //!!!!!!! hier den Kippschalter in richtiger Richtung (zum Fenster) betätigen, wenn Leine schlaff
  pwmSpeed = abs(potiWert-512)/2;
  analogWrite(PWM, pwmSpeed);
  Serial.println((String)"AN");
  delay(9000); 
  potiWert = 512; 
  //512 ist AUS, 212 ist 150/AN !!!!!!!
  pwmSpeed = abs(potiWert-512)/2;   
  // Geschwindigkeit
  analogWrite(PWM, pwmSpeed);
  Serial.println((String)"AUS");
}

void prestart_2_stunden() {
  
  for(int w=1; w <= 40; w++) 
          {
            Serial.println(w);
            delay(180000);
 
          }
}

void anlauf() {
          motorbewegung_je_fach();
}

void vorlauf() {

          for(int h=1; h<=3; h++) 
          {
            
            for(int x=1; x<=6; x++) 
            {
              Serial.println(x + (String)"-te Vorlauf Iteration " + (String)"im " + h + (String)"-ten 12 h Vorlauf");
              prestart_2_stunden();
              
            }
            Serial.println(h + (String)"-ter Vorlauf 12 h beendet");
            
          }
}

void tag() {
  Serial.println((String)"Beginn Tag Iteration");
  
  for(int y=1; y<=5; y++) 
  {
    motorbewegung_je_fach();
    prestart_2_stunden();
    
  }

}

void nacht() {          
  Serial.println((String)"Beginn Nacht Iteration");
  
  for(int n=1; n<=7; n++) 
  {
              Serial.println(n + (String)"-te Nacht Iteration");
              prestart_2_stunden();
  }
}

void programmende() {
  prestart_2_stunden();
  Serial.println((String)"PROGRAMMENDE");
}

void loop() {
  char dato=startiter;
    switch(dato){
      case 0:
          Serial.println((String)"PROGRAMM START");
          anlauf();
          vorlauf();
          // jetzt 6 Doppelstunden je Iteration h
          tag();
          nacht();
          tag();
          nacht();
          anlauf();
          startiter=1;
      default: programmende();
  }
}
