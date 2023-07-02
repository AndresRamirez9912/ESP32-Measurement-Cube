void showHeightScreen(Adafruit_SSD1306* display, Adafruit_BMP085* bmp){
  // Variables 
  float height = 0;  

  while(true){ // Loop to measure
    // Clean the display from the main Menu
    display->clearDisplay();

    // Get the Height 
    height = getHeight(bmp);

    // Print the Height  
    printHeight(display, height);
    Serial.println(height);
    delay(100);
  }
}