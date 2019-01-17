import processing.serial.*;

Serial portLeft;    //comm port left junction
Serial portRight;   // comm port right junction
Serial portLights;  // comm port alternating lights

int valueRight[] = new int[2];
int valueLeft[] = new int[2];
String buff = "";
int NEWLINE = 10;
char header[] = {'A', 'B'};

void setup() {
  size(400, 400);
  println("Available serial ports:");
  for (int i=0; i<Serial.list().length; i++) {
    print("[" + i + "]");
    println(Serial.list()[i]);
  }
  // setup connection
  portLeft = new Serial(this, Serial.list()[0], 9600); 
  portRight = new Serial(this, Serial.list()[1], 9600); 
  println(portLeft);
  println(portRight);
}

void draw() {
  String junction;
  while (portRight.available() > 0) {
    serialEvent(portRight.read(), 0);
  }
  int valueTotRight = 0;

  for (int i=0; i<valueRight.length; i++) {
    valueTotRight += valueRight[i];
  }

  while (portLeft.available() > 0) {
    serialEvent(portLeft.read(), 1); // read data
  }
  int valueTotLeft = 0;
  for (int i=0; i<valueLeft.length; i++) {
    valueTotLeft += valueLeft[i];
  }

  if (valueTotRight < valueTotLeft) {
    junction = "LEFT";
  } else {
    junction = "RIGHT";
  }
  println("TotalValueRight" + valueTotRight);
  println("TotalValueLeft" + valueTotLeft);
  println(junction);
  portLeft.write(junction);
}

//took this part from an assignment made for Programming and Physical Computing
//Nils Rugers, assignment makingMove
void serialEvent(int serial, int junctionValue) {
  try {    // try-catch because of transmission errors
    if (serial != NEWLINE) { 
      buff += char(serial); //add value of port.read to the buff
    } else {
      // The first character tells us which axis this value is for
      char c = buff.charAt(0);
      // Remove it from the string
      buff = buff.substring(1);
      // Discard the carriage return at the end of the buffer
      buff = buff.substring(0, buff.length()-1);
      // Parse the String into an integer
      if (junctionValue == 1) {
        for (int z=0; z<2; z++) {
          if (c == header[z]) {
            valueLeft[z] = Integer.parseInt(buff);
          }
        }
      } else {
        for (int z=0; z<2; z++) {
          if (c == header[z]) {
          valueRight[z] = Integer.parseInt(buff);
          }
        }
      }    
      buff = "";
    }
  }
  catch(Exception e) {
    //e.printStackTrace();
  }
}
