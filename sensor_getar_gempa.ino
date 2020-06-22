// create by : Bagus Miftah Rizqullah

const int vibrationSensorPin = 2; // Vibration Sensor di hubungkan ke Pin 2
int led = 13;                // the pin that the LED is atteched to
int vibrationSensorState = 0; // Status saat pertama mulai = 0
const int pinRelay = 11;   // definisikan Relay pada pin digital 11


 

void setup() {

  
  pinMode(led, OUTPUT);      // initalize LED as an output
 // CODINGAN RELAY aktif
  pinMode(pinRelay,OUTPUT);          // definisikan keluaran
  digitalWrite(pinRelay,HIGH); // matikan relay
  digitalWrite(led, HIGH);   // turn LED ON
  Serial.begin(115200);        // initialize serial
  pinMode(vibrationSensorPin, INPUT); // Jadikan Vibration sensor sebagai input



}

void loop() {

vibrationSensorState = digitalRead(vibrationSensorPin);

if (vibrationSensorState == HIGH) { // Jika ada getaran di sensor = HIGH
      Serial.println("Ada Getaran!");
      digitalWrite(pinRelay,LOW); // nyalain relay
      delay(6000);                // delay 6 detik
      Serial.println("MATIKAN ALARAM !!!");
      digitalWrite(led, HIGH); // turn LED OFF
      digitalWrite(pinRelay,HIGH); // matikan relay
  }

else {

      Serial.println("Tidak Ada Getaran!");
      digitalWrite(led, HIGH); // turn LED OFF
      delay(1000);             // delay 6 detik

}

}
