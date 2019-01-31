import processing.serial.*;

Serial portLeft;    //comm port left junction
Serial portRight;   // comm port right junction
Serial portLights;  // comm port alternating lights

int valueRight[] = new int[3];
int valueLeft[] = new int[3];
int incomingRight;
int incomingLeft;

String buff = "";
int NEWLINE = 10;
char header[] = {'A', 'B', 'C', 'D'};

void setup() {
  size(400, 400);
  println("Available serial ports:");
  for (int i=0; i<Serial.list().length; i++) {
    print("[" + i + "]");
    println(Serial.list()[i]);
  }
  // setup connection
  portLeft = new Serial(this, Serial.list()[3], 9600); 
  portRight = new Serial(this, Serial.list()[5], 9600); 
  println(portLeft);
  println(portRight);
}

void draw() {
  while (portRight.available() > 0) {
    serialEvent(portRight.read(), 'R');
  }
  int valueTotRight = 0;
  for (int i=0; i<valueRight.length; i++) {
    valueTotRight += valueRight[i];
  }

  while (portLeft.available() > 0) {
    serialEvent(portLeft.read(), 'L'); // read data
  }
  int valueTotLeft = 0;
  for (int i=0; i<valueLeft.length; i++) {
    valueTotLeft += valueLeft[i];
  }

  char junction;

  if (valueTotRight > valueTotLeft) {
    junction = 'L';
  } else if (valueTotRight < valueTotLeft) {
    junction = 'R';
  } else { //valueTotRight == valueTotLeft
    if (incomingRight < incomingLeft) {
      junction = 'R';
    } else if (incomingRight > incomingLeft) {
      junction = 'L';
    } else { //incomingRight == incomingLeft
      junction = 'L';
    }
  }

  println("valTotLeft = " + valueTotLeft + " " + incomingLeft);
  println("valTotRight = " + valueTotRight + " " + incomingRight);

  portLeft.write(junction);
}

//took this part from an assignment made for Programming and Physical Computing
//Nils Rugers, assignment makingMove
void serialEvent(int serial, char junctionValue) {
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
      if (junctionValue == 'L') {
        if (c == header[3]) {
          incomingLeft = Integer.parseInt(buff);
        } else {
          for (int z=0; z<3; z++) {
            if (c == header[z]) {
              valueLeft[z] = Integer.parseInt(buff);
            }
          }
        }
      } else if (junctionValue == 'R') { //if junctionValue == 'R'
        if (c == header[3]) {
          incomingRight = Integer.parseInt(buff);
        } else {
          for (int z=0; z<3; z++) {
            if (c == header[z]) {
              valueRight[z] = Integer.parseInt(buff);
            }
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
