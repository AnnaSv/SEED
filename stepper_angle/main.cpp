// Send integer angle over serial. Motor moves to that angle (hopefully).
// Remember to compile with lncurses and lserial

#include <stdio.h>
#include <SerialStream.h>
#include <ctype.h>
#include <iostream>

using namespace LibSerial;
using namespace std;

SerialStream ardu;
int portNum;
const int BUFFER_SIZE = 2;
char output_buffer[BUFFER_SIZE];

int main(void) {

	string PORT1;
	cout << "Enter Arduino port # (e.g. enter 0 if port is /dev/ttyACM0): ";
	cin >> portNum;
	if (portNum == 0) {
		PORT1 = "/dev/ttyACM0";
	} else if (portNum == 1) {
		PORT1 = "/dev/ttyACM1";
	} else {
		PORT1 = "/dev/ttyACM2";
	}

    int angle = 0;

    // Init and configure serial comm
    ardu.Open(PORT1);    
    ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);  
    ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
	
	while (true) {
		
	    cout << "Enter desired angle: ";
	    cin >> angle; 

        output_buffer[0] = angle & 0xff;
	    output_buffer[1] = (angle >> 8) & 0xff;
	    ardu.write(output_buffer, BUFFER_SIZE);

    }
}

