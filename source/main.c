#include "../header/includes.h"

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------
	Init();

	char *str = malloc((num_of_buttons * sizeof(char)) + 1);
	printf("HELLO WORLD");

	while(SYS_MainLoop()) {

		// Call WPAD_ScanPads each loop, this reads the latest controller states
		WPAD_ScanPads();
		WPAD_Expansion(curr_wiimote, &expan);
		WPAD_Accel(curr_wiimote, &accel);
		WPAD_Orientation(curr_wiimote, &orient);
		WPAD_IR(curr_wiimote, &ir);


		ButtonCheck(str, curr_wiimote);
		printf("\x1b[0;0H"); // set cursor to y = 0, x = 0


		// clear the screen before printing, all other code should be before to save time
		VIDEO_ClearFrameBuffer(rmode, xfb, COLOR_BLACK);
		printf("%s\n", str); // print buttons
		printf("expansion: %i\n", expan.type); 
		printf("roll: %f, yaw: %f, pitch: %f\n", orient.roll, orient.yaw, orient.pitch);
		printf("pointer x: %f, y: %f\n", ir.x, ir.y);
		printf("battery level: %d\n", WPAD_BatteryLevel(curr_wiimote));
		
		// sleep(1);


		// // We return to the launcher application via exit
		// if ( WPAD_ButtonsHeld(currWiimote) & WPAD_BUTTON_HOME ) exit(0);

		// Wait for the next frame
		VIDEO_WaitVSync();
	}

	free(str);
	return 0;
}
