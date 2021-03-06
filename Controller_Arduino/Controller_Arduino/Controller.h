/*
 * Controller.h
 *
 * Created: 7/31/2016 9:58:58 PM
 *  Author: Andrew_2
 */


#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "SoftwareWire.h"

#define HARDWARE_VERSION 1
#define SOFTWARE_VERSION 1
#define NUM_BUTTONS 4

struct Trackpad {
  unsigned short x;
  unsigned short y;
  unsigned short strength;
};

void setupController(SoftwareWire *w1, SoftwareWire *w2);
void updateController();

Trackpad getTrack1();
Trackpad getTrack2();

unsigned short getButtons();
unsigned short getJoystickX();
unsigned short getJoystickY();

void requestWriteSpec();

#endif /* CONTROLLER_H_ */
