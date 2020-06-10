/*  
   UNTUK ATOMISASI GERBANG PENYEMPROT DISENFEKTAN
   create by : Bagus Miftah Rizqullah
*/
 
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
const int pinRelay = 11;   // definisikan Relay pada pin digital 11

void setup() {
  // CODINGAN SENSOR PIR AKTIF
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
   // CODINGAN RELAY aktif
  pinMode(pinRelay,OUTPUT);          // definisikan keluaran
  digitalWrite(pinRelay,HIGH); // nyalain relay
  digitalWrite(led, HIGH);   // turn LED ON
  Serial.begin(115200);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if ((val == HIGH) && (state == LOW)) {           // check if the sensor is HIGH
      digitalWrite(led, LOW);   // turn LED ON
      Serial.println("TERDETEKSI PERGERAKAN !!!"); 
      state = HIGH;       // update variable state to HIGH
      digitalWrite(pinRelay,LOW); // nyalain relay
      delay(9000);                // delay 100 milliseconds
      Serial.println("MATIKAN ALARAM !!!");
      digitalWrite(led, HIGH); // turn LED OFF
      digitalWrite(pinRelay,HIGH); // matikan relay
      state = LOW;       // update variable state to LOW
    }
     
  else {
      
      if ((val == LOW) && (state == HIGH )){
        Serial.println("TIDAK ADA PERGERAKAN !!!");
        state = LOW;       // update variable state to LOW
        digitalWrite(led, HIGH); // turn LED OFF
    }
  }
}
