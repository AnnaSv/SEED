// Reads press of up/down arrow keys and notifies Arduino over serial
// Remember to compile with lncurses and lserial
// This is stupid, might want to add functionality to 
// input an integer RMP, hit enter, send that instead. 

#include <stdio.h>
#include <SerialStream.h>
#include <ctype.h>
#include <iostream>

using namespace LibSerial;
using namespace std;

SerialStream ardu;
int portNum;
const int BUFFER_SIZE = 4;
char output_buffer[BUFFER_SIZE];

int main(void) {

	string PORT1;
	cout << "Enter Arduino port # (e.g. enter 0 if port is /dev/ttyACM0): ";
	cin >> portNum;
	if (portNum == 0) {
		PORT1 = "/dev/ttyACM0";
	} else {
		PORT1 = "/dev/ttyACM1";
	}

    int pps = 0;
    int dir = 1;

    // Init and configure serial comm
    ardu.Open(PORT1);    
    ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);  
    ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
	
	while (true) {
		
	    cout << "Enter desired pulses per second, followed by a space and the direction bit: ";
	    cin >> pps >> dir; 

        output_buffer[0] = pps & 0xff;
	    output_buffer[1] = (pps >> 8) & 0xff;
	    output_buffer[2] = dir & 0xff;
	    output_buffer[3] = (dir >> 8) & 0xff;
	    ardu.write(output_buffer, BUFFER_SIZE);

    }
}

