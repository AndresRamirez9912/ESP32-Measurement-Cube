float getAltitude(Adafruit_BMP085* bmp){
  return bmp->readAltitude(101300); // Read the altitude with the standar sea level pressure
}

float getFilteredData(Adafruit_BMP085* bmp){
  float altitude = bmp->readAltitude(101300);
  return filterData(altitude);
}

float getPressure(Adafruit_BMP085* bmp){
  return bmp->readPressure();
}

float getHeightByReference(Adafruit_BMP085* bmp, float pressureReference){
  return bmp->readAltitude(pressureReference);
}

float filterData(float currentHeight){
  // Filter constants
  const double num[]={0.0219396206884642, 0.109698103442321, 0.219396206884642, 0.219396206884642, 0.109698103442321, 0.0219396206884642};
  const double den[]={1, -0.985325239279238, 0.973849331836765, -0.386356558648449, 0.111163840578342, -0.0112635124565659};
  const int ORDER = (sizeof(den) / sizeof(den[0])) - 1; // Calculate the filter order based on the number of constants

  // Variables
  static float measures[ORDER];
  float numerator=0;
  float denominator=0;
  static double outputs[ORDER];

  // Assign the current Height
  measures[0]=currentHeight;

  // Calculate the part of the numerator
  for(short i=0; i<ORDER; i++){    
    numerator += num[i]*measures[i];
  }  
  
  // Calculate the part of the numerator
  for(short i=1; i<ORDER; i++){    
    denominator += den[i]*outputs[i];
  } 

  // Calculate the Output
  outputs[0] = numerator - denominator; 

  // Update variables
  for(short i=ORDER-1; i>0; i--){
    measures[i]=measures[i-1];
    outputs[i]=outputs[i-1];
  }

  return outputs[0];
}