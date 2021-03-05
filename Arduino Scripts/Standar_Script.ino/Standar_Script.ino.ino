/*

list of commands to put on this file

- pinMode()
- digitalRead()
- digitalWrite()
- analogRead()
- analogWrite()
- Serial.begin()
- Serial.print()
- Serial.println()
- map()
- max()
- min()
- delay() 
- delayMicroseconds() 
- micros() 
- millis() 
- interrupts() 
- noInterrupts() 
- attachInterrupt() 
- detachInterrupt() 
- random() 
- randomSeed() 

*/

void pinMode_onePin(int pin, bool mode = true);
void pinMode_severalPins(int *v, bool standard = false, int length = 0);
void initArray(int *v, int length = 70);

int vetorPins[70];
int numbersOfPins_ARDUINO_MEGA_2560_DIGITALS[54];

void setup() {
  Serial.begin(9600);
  initArray(numbersOfPins_ARDUINO_MEGA_2560_DIGITALS, 54);
}

void loop() {

  bool its_my_content = false;

  if (Serial.available()) {
    String mySerial = Serial.readStringUntil('\n');

      if (mySerial[0] == '$') {
        its_my_content = true;
      }

      if (!its_my_content) {

        int cases = 0;

        if (mySerial == "pinMode"){
          cases = 1;
        } else {
          cases = 0;
        }

        switch (cases) {

          case 1: 
                Serial.println("$send the pins");
                //definePinsByArray(vetorPins);

                //for (int i = 0; i < 70; i++){
                //  Serial.println(vetorPins[i]);
                //}

                while(true) {

                  if (Serial.available()) {
                    String _mySerial = Serial.readStringUntil('\n');

                    String aux = "00" + _mySerial;
                  
                    if (_mySerial[0] != '$') {
                      if (aux.length() > 2) {
                          int port = aux.toInt();

                          Serial.println(port);
                          //for (int i = 0; i < 54; i++) {
                          //  Serial.println(numbersOfPins_ARDUINO_MEGA_2560_DIGITALS[i]);
                          //}

                          break;
                      }

                    } else {
                      Serial.println("Is my content");
                    }

                  }
                }
                break;
        }
        its_my_content = false;
      } else {
        Serial.println("is my content");
      }

    }
}

void pinMode_onePin(int pin, bool mode) {
    static int pinsModed[70];
    static int index = 0;
    bool not_moded = false;

    for (int i = 0; i < 70; i++) {
        if (pin == pinsModed[i]){
          not_moded = !not_moded;
          break;
        }
    }

    if (!not_moded) {
      pinMode(pin, mode);

      pinsModed[index] = pin;

      index += 1;

    } else {
      Serial.println("Error on the set mode pin, pin already seted...");

    }
    
}

void pinMode_severalPins(int *v, bool standard, int length) {
    static int pinsModed[70];
    static int index = 0;
    bool not_moded = false;

    if (!(length < 1)) {
      for (int i = 0; i < 70; i++) {
          for (int l = 0; l < length; l++) {
            if (v[l] == pinsModed[i]) {
                not_moded = !not_moded;
                break;
            }
          }
      }
    }

    if (!not_moded) {
      if (!(length < 1)) {
        
      }      
    }

}

void initArray(int *v, int length) {
    for (int i = 0; i < length; i++) {
      v[i] = i;
    }
}
