void showHeightScreen(Adafruit_SSD1306* display, Adafruit_BMP085* bmp){

  // Get the reference pressure
  float referenceHeight = getAltitude(bmp); 

  while(true){ // Loop to measure
    // Clean the display from the main Menu
    display->clearDisplay();

    // Get the Height by the reference
    float currentHeight = getAltitude(bmp); 
    float height = currentHeight - referenceHeight;

    // Print the Height  
    printHeight(display, height);
    Serial.println(height);
    delay(50);
  }
}