#include <MatrixColorSensor.h>

MatrixColor MXColor1;

void setup() {
  Serial.begin(115200);
  if (MXColor1.begin()){
    Serial.println("Matirx Color Sensor activated");
  }
  else{
    Serial.println("Matirx Color Sensor activation failed");
  }
}

void loop() {
  Serial.println("===============================================================");
  Serial.print("grayscale=");
  Serial.println(MXColor1.getGrayscale());

  delay(500);
}
