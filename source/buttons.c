#include "../header/includes.h"

/*
#define WPAD_BUTTON_2							0x0001
#define WPAD_BUTTON_1							0x0002
#define WPAD_BUTTON_B							0x0004
#define WPAD_BUTTON_A							0x0008
#define WPAD_BUTTON_MINUS						0x0010
#define WPAD_BUTTON_HOME						0x0080
#define WPAD_BUTTON_LEFT						0x0100
#define WPAD_BUTTON_RIGHT						0x0200
#define WPAD_BUTTON_DOWN						0x0400
#define WPAD_BUTTON_UP							0x0800
#define WPAD_BUTTON_PLUS						0x1000

empty space for buttons on extension controllers
                       + UDRL H  - AB12
0000 0000 0000 0000 0001 1111 1001 1111
*/


// inputs are a string to return to and which wiimote to read from; ideally separate printing and reading for multipurpose
void ButtonCheck(char* str, int chan) {
    u32 held = WPAD_ButtonsHeld(chan); // chan indicates controller number
    int size = num_of_buttons + 1; // plus null
    int num_of_bits_to_read = 13; // see above reference, can be optimized by skipping unused bits

    char buf[size]; // AB12UDLR+-H string format
    memset(buf,' ', size - 1); // buf set to all spaces except last char
    buf[size] = '\0'; // ensure final char is null

    u32 held_buf = held; //store data of held buttons in buffer for editing incase original data is needed later
    for (int i = 0; i < num_of_bits_to_read; i++) {
        HeldScan(buf, i, held_buf & 1);
        held_buf >>= 1;
    }

    strcpy(str,buf);
}

void HeldScan(char* buf, int i, int bit) {

    u32 current_button = bit <<= i; // shift the bit back to where it should be according to above reference

    //then check what button it is and if it is held or not and update our string
    switch (current_button) {

        case (WPAD_BUTTON_A): {
            buf[0] = 'A';
            break;
        }

        case (WPAD_BUTTON_B): {
            buf[1] = 'B';
            break;
        }

        case (WPAD_BUTTON_1): {
            buf[2] = '1';
            break;
        }
        
        case (WPAD_BUTTON_2): {
            buf[3] = '2';
            break;
        }

        case (WPAD_BUTTON_UP): {
            buf[4] = 'U';
            break;
        }

        case (WPAD_BUTTON_DOWN): {
            buf[5] = 'D';
            break;
        }

        case (WPAD_BUTTON_LEFT): {
            buf[6] = 'L';
            break;
        }

        case (WPAD_BUTTON_RIGHT): {
            buf[7] = 'R';
            break;
        }

        case (WPAD_BUTTON_PLUS): {
            buf[8] = '+';
            break;
        }

        case (WPAD_BUTTON_MINUS): {
            buf[9] = '-';
            break;
        }

        case (WPAD_BUTTON_HOME): {
            buf[10] = 'H';
            break;
        }

        default: {
            break;
        }
    }
    
    switch (~current_button) {

        case (WPAD_BUTTON_A): {
            buf[0] = ' ';
            break;
        }

        case (WPAD_BUTTON_B): {
            buf[1] = ' ';
            break;
        }

        case (WPAD_BUTTON_1): {
            buf[2] = ' ';
            break;
        }
        
        case (WPAD_BUTTON_2): {
            buf[3] = ' ';
            break;
        }

        case (WPAD_BUTTON_UP): {
            buf[4] = ' ';
            break;
        }

        case (WPAD_BUTTON_DOWN): {
            buf[5] = ' ';
            break;
        }

        case (WPAD_BUTTON_LEFT): {
            buf[6] = ' ';
            break;
        }

        case (WPAD_BUTTON_RIGHT): {
            buf[7] = ' ';
            break;
        }

        case (WPAD_BUTTON_PLUS): {
            buf[8] = ' ';
            break;
        }

        case (WPAD_BUTTON_MINUS): {
            buf[9] = ' ';
            break;
        }

        case (WPAD_BUTTON_HOME): {
            buf[10] = ' ';
            break;
        }

        default: {
            break;
        }
    }

    buf[11] = '\0';
}