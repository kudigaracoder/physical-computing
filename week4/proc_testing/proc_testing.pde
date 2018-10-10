import processing.serial.*;

int xPos = 0;
int yPos = 0;
int colWidth = 100;


void setup()
{
  size(800,600);
  background(255);
}

void drawGrid()
{
  while(xPos < width ) {
    rect(xPos,yPos, colWidth, height);
    xPos = xPos + colWidth;
  }
}

void draw()
{
  drawGrid(); 
  drawMark();
}

void drawMark()
{
  rect(5,20,90,30,5);
}
