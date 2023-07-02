// *********  Constants **************
#define SCREEN_ROW1 0
#define SCREEN_ROW2 16
#define SCREEN_ROW3 32
#define SCREEN_ROW4 48

const String menuOptions[]={"Distancia", "Altura", "Angulo", "Rolling", "Temperatura"};
const int menuRows[]={SCREEN_ROW1, SCREEN_ROW2, SCREEN_ROW3, SCREEN_ROW4};
// ***********************************

void createMainMenu(Adafruit_SSD1306* display, int option){
  // Variables
  int size=sizeof(menuRows) / sizeof(menuRows[0]);
  const int arrowSpace = 15; // Offset in X axis to draw the arrow
  
  // Print the menu
  for(short i=0; i<size; i++){
    display->setCursor(arrowSpace,menuRows[i]);
    display->println(menuOptions[i]); // Print the opction
  }  
} 

void drawArrow(Adafruit_SSD1306* display, int option){
  const int xOffset = 3;
  int middleYPosition = menuRows[option] + 8;
  int startYPoint = middleYPosition - 5;
  for(short i=0; i<=5; i++){
    display->drawLine(xOffset+i, startYPoint+i, xOffset+i, (startYPoint+i) + (10 - 2*i), SSD1306_WHITE);
  }
}

void printHeight(Adafruit_SSD1306* display, float height){
  // Print the Title
  display->setCursor(30, SCREEN_ROW1);
  display->println("Altura");

  // Print the measurement
  display->setCursor(30, SCREEN_ROW2+12);
  display->println(height);
  display->display();
}