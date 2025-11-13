#include <BluetoothSerial.h>
#if !defined(CONFIG_BT_ENABLE) || !defined(CONFIG_BLUEDROID_ENABLED)
//#error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif
//permet d'inclure le bluetooth au système
BluetoothSerial SerialBT;

const int mVitesseA1 = 12; //broche 12 roller gauche avant 
const int mVitesseR1 = 13; //broch 13 roller gauche arrière
const int mVitesseA2 = 14; //broche 14 roller droit avant 
const int mVitesseR2 = 27; //broch 27 roller droit arrière

void setup() {
  SerialBT.begin("raoulsaroule"); //nom de l'ESP32 pour mettre au bluetooth
  Serial.begin(96000);

  pinMode(mVitesseA1, OUTPUT); //config des broches de sortie pour les moteurs
  pinMode(mVitesseR1, OUTPUT);
  pinMode(mVitesseA2, OUTPUT);
  pinMode(mVitesseR2, OUTPUT);
  // put your setup code here, to run once:

} 

void loop() {
  if (SerialBT.available()) {
    char commandes = SerialBT.read();
    Serial.println("Commande Entrée :");
    //permet de lire les commandes en blluetooth et de contrôler la voiture en bluetooth
    switch (commandes) {
    case'1' : // exécute seulement si la condition avant est activé et quittera alors switch
      Serial.println("Avant");
      digitalWrite(mVitesseA1, HIGH);
      digitalWrite(mVitesseA2, HIGH);
      digitalWrite(mVitesseR1, LOW);
      digitalWrite(mVitesseR2, LOW);
      break;

    case'0':
      Serial.println("Arrêt Moteurs");
      digitalWrite(mVitesseA1, LOW);
      digitalWrite(mVitesseA2, LOW);
      digitalWrite(mVitesseR1, LOW);
      digitalWrite(mVitesseR2, LOW);
      break;
    case'2':
      Serial.println("ARRIERE");
      digitalWrite(mVitesseA1, LOW);
      digitalWrite(mVitesseA2, HIGH);
      digitalWrite(mVitesseR1, LOW);
      digitalWrite(mVitesseR2, HIGH);
      break;       
    
    }
  // put your main code here, to run repeatedly:

  }
}
