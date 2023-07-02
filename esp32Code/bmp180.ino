float getHeight(Adafruit_BMP085* bmp){
  return bmp->readAltitude(101300); // Read the altitude with the standar sea level pressure
}