import processing.serial.*;

Serial testPort;
String val;
int thresholdValue = 10;

int xPos = 0;
int yPos = 0;
int colWidth = 100;

// Values for the markers
int markWidth = 90;
int markHeight = 30;
int markRadius = 5;
int markXpadding = 10;
int markYpadding = 5;

int markX = 5;
int markY = 550;

void setup()
{
  size(800,600);
  background(255);
  String portName = Serial.list()[2];
  testPort = new Serial(this, portName, 9600);
}

void drawGrid()
{
  while( xPos < width ) {
    rect(xPos,yPos, colWidth, height);
    xPos = xPos + colWidth;
  }
}

void draw()
{
  drawGrid();
  processInput();
  drawMark();
  
}

void processInput()
{
  if (testPort.available() > 0)
  {
    val = testPort.readStringUntil('\n');
    if ( int(val) < thresholdValue )
    {
       println(val); 
    }
  }
  
  
  //while (inputVal > thresholdValue)
  //{
  //    //Channel the inputVal to drawMark() to draw the markers
  //}
}

void drawMark()
{
  //while ( markX < width && markY > 0)
  //{
  //  rect(markX, markY, markWidth, markHeight, markRadius);
  //  markX = markX + markWidth + markXpadding;
  //  rect(markX, markY, markWidth, markHeight, markRadius);
  //  markY = markY - markHeight - markYpadding;
  //}
  while ( markX < width )
  {
        while ( markY > 0 )
        {
          rect(markX, markY, markWidth, markHeight, markRadius);
          markX = markX + markWidth + markXpadding;
          rect(markX, markY, markWidth, markHeight, markRadius);
          markY = markY - markHeight - markYpadding;
        }
  }
}
