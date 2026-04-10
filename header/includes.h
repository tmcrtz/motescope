#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//devkitpro
#include <gccore.h>
#include <wiiuse/wpad.h>

//headers
#include "buttons.h"
#include "init.h"

extern int num_of_buttons;
extern int curr_wiimote;

extern ir_t ir;
extern vec3w_t accel;
extern orient_t orient;
extern expansion_t expan;

#endif