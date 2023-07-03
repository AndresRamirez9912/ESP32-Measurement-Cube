void showHeightScreen(Adafruit_SSD1306* display, Adafruit_BMP085* bmp){

  // Get the reference pressure
  float referenceHeight = getHeightReference(bmp);

  while(true){ // Loop to measure
    // Clean the display from the main Menu
    display->clearDisplay();

    // Get the Height over the reference
    float currentHeight = getAltitude(bmp);
    float height = currentHeight - referenceHeight; // Calculate the heigh 

    // Print the Height  
    printHeight(display, height);
    delay(200);
  }
}

float getHeightReference(Adafruit_BMP085* bmp){
  float average=0;
  const int elements = 20;

  for(short i=0; i<elements; i++){
    // average += getFilteredData(bmp);
    average += getAltitude(bmp);
    delay(200);
  }

  return average/elements;
}