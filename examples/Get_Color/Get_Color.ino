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
  MXColor1.setGamma(true);
  Serial.println("Set gamma correction as open");

  MXColor1.setLight(true, true, 0);
  Serial.println("Set fill-light open and in auto adjust mode");
}

void loop() {
  Serial.println("===============================================================");
  Serial.print("R=");
  Serial.println(MXColor1.getColor(R));
  Serial.print("G=");
  Serial.println(MXColor1.getColor(G));
  Serial.print("B=");
  Serial.println(MXColor1.getColor(B));
  Serial.print("C=");
  Serial.println(MXColor1.getColor(C));
  Serial.print("M=");
  Serial.println(MXColor1.getColor(M));
  Serial.print("Y=");
  Serial.println(MXColor1.getColor(Y));
  Serial.print("K=");
  Serial.println(MXColor1.getColor(K));

  delay(500);
}
