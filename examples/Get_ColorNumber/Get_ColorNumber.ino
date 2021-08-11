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
  MXColor1.setGamma(false);
  Serial.println("Set gamma correction as close");

  MXColor1.setLight(true, false, 200);
  Serial.println("Set fill-light open and fix in pwm 200");
}

void loop() {
  Serial.println("===============================================================");
  Serial.print("color number=");

  switch (MXColor1.getColorNumber())
  {
  case 0:
    Serial.println("Black");
    break;
  case 1:
    Serial.println("White");
    break;
  case 2:
    Serial.println("Cyan");
    break;
  case 3:
    Serial.println("Ocean");
    break;
  case 4:
    Serial.println("Blue");
    break;
  case 5:
    Serial.println("Violet");
    break;
  case 6:
    Serial.println("Magenta");
    break;
  case 7:
    Serial.println("Raspberry");
    break;
  case 8:
    Serial.println("Red");
    break;
  case 9:
    Serial.println("Orange");
    break;
  case 10:
    Serial.println("Yellow");
    break;
  case 11:
    Serial.println("Spring Green");
    break;
  case 12:
    Serial.println("Green");
    break;
  case 13:
    Serial.println("Turquoise");
    break;
  
  default:
    break;
  }
  delay(500);
}
