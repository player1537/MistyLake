/*
 * MessageReader.cpp
 *
 * Created: 8/1/2016 1:49:58 PM
 *  Author: Andrew_2
 */ 

#include "MessageReader.h"
#include "Controller.h"
#include "Controller_Arduino.h"

#define MESSAGE_BUFFER_SIZE 254
#define READ_BUFFER_SIZE 256
#define  SPEC_ID 1

unsigned char inMessageBuffer [MESSAGE_BUFFER_SIZE];
unsigned char readBuffer [READ_BUFFER_SIZE];
unsigned char len;

void unStuffData(const unsigned char *ptr, unsigned char length, unsigned char *dst);

void setupReader() {
	len = 0;
}

void readData() {
	while(serial.available() > 0) {
		readBuffer[len++] = serial.read();
		if(readBuffer[len - 1] == 0) {
			unStuffData(readBuffer, len, inMessageBuffer);
			
			if(inMessageBuffer[1] == 1) {
				requestWriteSpec();
			}
			
			len = 0;
		}
	}
}


void unStuffData(const unsigned char *ptr, unsigned char length, unsigned char *dst)
{
	const unsigned char *end = ptr + length - 1;
	while (ptr < end)
	{
		int i, code = *ptr++;
		for (i=1; i<code; i++) {
			*dst++ = *ptr++;
		}
		*dst++ = 0;
	}
}