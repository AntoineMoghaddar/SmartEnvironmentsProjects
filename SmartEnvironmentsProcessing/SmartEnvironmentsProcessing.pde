import processing.serial.*;

Serial portLeft;    //comm port left junction
Serial portRight;   // comm port right junction
Serial portLights;  // comm port alternating rights

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
  portLeft = new Serial(this, Serial.list()[3], 9600); // setup connection
  println(portLeft);
}

void draw() {
  while (portLeft.available() > 0) {
    serialEvent(portLeft.read()); // read data
  }
  int valueTotLeft = 0;
  for (int i=0; i<valueLeft.length; i++){
    valueTotLeft += valueLeft[i];
  }
  println(valueTotLeft);
  
  portLeft.write(valueTotLeft);
}

//took this part from an assignment made for Programming and Physical Computing
//Nils Rugers, assignment makingMove
void serialEvent(int serial) {
  try {    // try-catch because of transmission errors
    if (serial != NEWLINE) { 
      buff += char(serial);
    } else {
      // The first character tells us which axis this value is for
      char c = buff.charAt(0);
      // Remove it from the string
      buff = buff.substring(1);
      // Discard the carriage return at the end of the buffer
      buff = buff.substring(0, buff.length()-1);
      // Parse the String into an integer
      for (int z=0; z<2; z++) {
        if (c == header[z]) {
          valueLeft[z] = Integer.parseInt(buff);
        }
      }
      buff = "";         // Clear the value of "buff"
    }
  }
  catch(Exception e) {
    println("no valid data");
  }
}
