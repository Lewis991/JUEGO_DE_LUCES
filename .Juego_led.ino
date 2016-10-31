JOSE LUIS JARRIN
30/10/2016



n //Inicializar variables de pines
int sw_3 = 13; //switch 3
int sw_2 = 12; //switch 2
int sw_1 = 11; //switch 1
int ran = 0;
int i;
int j;
int vector_leds [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void setup() {
  pinMode(1, OUTPUT); //pin 1 como salida
  pinMode(2, OUTPUT); //pin 2 como salida
  pinMode(3, OUTPUT); //pin 3 como salida
  pinMode(4, OUTPUT); //pin 4 como salida
  pinMode(5, OUTPUT); //pin 5 como salida
  pinMode(6, OUTPUT); //pin 6 como salida
  pinMode(7, OUTPUT); //pin 7 como salida
  pinMode(8, OUTPUT); //pin 8 como salida
  pinMode(9, OUTPUT); //pin 9 como salida
  pinMode(10, OUTPUT); //pin 10 como salida
  pinMode(sw_1, INPUT); //pin 11 como entrada
  pinMode(sw_2, INPUT); //pin 12 como entrada
  pinMode(sw_3, INPUT); //pin 13 como entrada
}

void loop() {
  if (digitalRead(sw_1) == LOW && digitalRead(sw_2) == LOW && digitalRead(sw_3) == LOW) { // ESTADO 1
    // NO HACE NADA
  }
  else
    //Juego de luces 2 PARES
    if (digitalRead(sw_1) == LOW && digitalRead(sw_2) == HIGH && digitalRead(sw_3) == LOW) {// ESTADO 2
      delay(200);
      for (int i = 0; i <= 10; i = i + 2) {
        digitalWrite(i, HIGH);
        delay(200);
        digitalWrite(i, LOW);
        delay(200);
      }
    }
    else
      //Juego de luces 3 IMPARES
      if (digitalRead(sw_1) == LOW && digitalRead(sw_2) == HIGH && digitalRead(sw_3) == HIGH) {// ESTADO 3
        delay(200);
        for (int j = 1; j <= 10; j = j + 2) {
          digitalWrite(j, HIGH);
          delay(200);
          digitalWrite(j, LOW);
          delay(200);
        }
      }
      else
        //Juego de luces 4 ALEARTORIO
        if (digitalRead(sw_1) == HIGH && digitalRead(sw_2) == LOW && digitalRead(sw_3) == HIGH) {// ESTADO 4
          delay(200);
          ran = random(10);
          digitalWrite(vector_leds[ran], HIGH);
          delay(200);
          digitalWrite(vector_leds[ran], LOW);
          delay(200);
        }
        else
          //Juego de luces 5 DE LSO EXTREMOS
          if (digitalRead(sw_1) == HIGH && digitalRead(sw_2) == HIGH && digitalRead(sw_3) == LOW) {// ESTADO 5
            delay(200);
            for (i = 0, j = 10; i <= 5; i++, j--) {
              digitalWrite(vector_leds[i], HIGH), digitalWrite(vector_leds[j], HIGH);
              delay(200);
            }
            for (i = 5, j = 6; i >= 0; i--, j++) {
              digitalWrite(vector_leds[i], LOW), digitalWrite(vector_leds[j], LOW);
              delay(200);
            }
          }
          else
            //Juego de luces 6 REPITA 5
            if (digitalRead(sw_1) == HIGH && digitalRead(sw_2) == HIGH && digitalRead(sw_3) == HIGH) {// ESTADO 6
              delay(200);
              for (j=0; j <= 5; j++) {
                for (i=0; i <= 10; i++) {
                  digitalWrite(vector_leds[i], HIGH);
                  delay(200);
                  digitalWrite(vector_leds[i], LOW);
                  delay(200);
                }
                i = 0;
              }
              delay(1000);
            }
}


