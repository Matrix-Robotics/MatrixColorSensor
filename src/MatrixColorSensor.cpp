#include "MatrixColorSensor.h"

bool MatrixColor::begin(){
	Wire.begin();
	i2cMUXSelect();
	delay(50);
	if(i2cReadData(Device_ID) == 0x43){
		i2cWriteData(Device_CONFIG, 0x10); // reset
		delay(500);
		i2cWriteData(Device_CONFIG, setting); // enable
		return true;
	}
	else{
		return false;
	}
}

void MatrixColor::setGamma(bool state){
	i2cMUXSelect();
	if(state){
		setting |= 0b00000100;
	}
	else{
		setting &= 0b00001011;
	}
	i2cWriteData(Device_CONFIG, setting);
}

void MatrixColor::setLight(bool state, bool mode, uint8_t pwm){
	i2cMUXSelect();

	if(state){
		setting |= 0b00000010;
	}
	else{
		setting &= 0b00001101;
	}
	if(mode){
		setting |= 0b00000001;
	}
	else{
		setting &= 0b00001110;
	}
	i2cWriteData(Device_CONFIG, setting);
	i2cWriteData(Device_LIGHT, pwm);
}

uint8_t MatrixColor::getColor(ColorType color){
	i2cMUXSelect();
	return i2cReadData(ColorRegType(color));
}

uint8_t MatrixColor::getGrayscale(){
	return i2cReadData(Device_GRAY);
}

/*
	Number of color as follow as below:
	0:Black
	1:White
	2:Cyan
	3:Ocean
	4:Blue
	5:Violet
	6:Magenta
	7:Raspberry
	8:Red
	9:Orange
	10:Yellow
	11:Spring Green
	12:Green
	13:Turquoise
*/
uint8_t MatrixColor::getColorNumber(){
	i2cMUXSelect();
	return i2cReadData(Device_NUM_COLOR);
}

uint8_t MatrixColor::i2cReadData(ColorRegType reg){
	
	Wire.beginTransmission(MatrixColor_ADDR);
	Wire.write(reg);
	Wire.endTransmission(1);

	delay(1);

	Wire.requestFrom(MatrixColor_ADDR, 1);

	delay(1);

	return Wire.read();
}

void MatrixColor::i2cMUXSelect(){
	switch (_ver)
	{
	case 2:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write(_ch + 4);
		Wire.endTransmission(1);

		delayMicroseconds(300);
		break;
	case 3:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write((1 << _ch));
		Wire.endTransmission(1);
		
		delayMicroseconds(300);
		break;
	default:
		break;
	}
}

void MatrixColor::i2cWriteData(ColorRegType reg, uint8_t data){

	Wire.beginTransmission(MatrixColor_ADDR);

	Wire.write(reg);
	Wire.write(data);

	Wire.endTransmission(1);
}
