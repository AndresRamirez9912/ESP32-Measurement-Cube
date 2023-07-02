// ********* LIBRARIES ***************
#include <Wire.h> 
#include <Adafruit_SSD1306.h>
// ***********************************

// ********* FUNCTIONS ***************

// ***********************************

// *********  Constants **************
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
// ***********************************

// ********* Global Variables ********
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // Create an object of the oled library

int option =0;
// ***********************************

// ********* Prototype Functions *****
void createMainMenu(Adafruit_SSD1306);
// ***********************************

void setup() {
  // Init Serial 
  Serial.begin(9600);

  // Init Oled Display 
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("The oled display doesn't response")); 
    for(;;); // Don't proceed, loop forever
  }

  // Set Oled Default Settings 
  display.clearDisplay(); // Clean the display
  display.setTextSize(2); // Set the scale of the text, 2x scale
  display.setTextColor(SSD1306_WHITE); // Draw white text

  // Print the Main menu
  createMainMenu(&display, option);
  drawArrow(&display, option);
  display.display(); // Show menu
}

void loop() {

}
