float getAltitude(Adafruit_BMP085* bmp){
  // const int numberValues =20;
  // float average=0;

  // for(short i=0; i<numberValues; i++) {
  //   average = bmp->readAltitude(101300) + average; // Read the altitude with the standar sea level pressure
  //   delay(30); // Delay between measurement
  // }
  // return  average/numberValues;
  return bmp->readAltitude(101300); // Read the altitude with the standar sea level pressure
}

float getPressure(Adafruit_BMP085* bmp){
  return bmp->readPressure();
}

float getHeightByReference(Adafruit_BMP085* bmp, float pressureReference){
  return bmp->readAltitude(pressureReference);
}