/*
Copyright 2022 sporewoh

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keezyboost40.h"
#include "keezyboost40.h"

#include <string.h>
#include <math.h>
#include "quantum.h"
#include <hal_pal.h>
#include "hal.h"
#include "stdlib.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"

#include "qp.h"

painter_device_t lcd;


//const int HEIGHT = 160;
//const int WIDTH = 128;
#define WIDTH 128
#define HEIGHT 160


void keyboard_post_init_kb(void) {
    // Turn on the LCD
    setPinOutput(GP15);
    writePinHigh(GP15);

    // Let the LCD get some power...
    wait_ms(150);
    // Initialise the LCD
	lcd = qp_st7789_make_spi_device(HEIGHT, WIDTH, GP17, GP16, GP14, 1, 3);

    qp_init(lcd, QP_ROTATION_180);
	qp_comms_start(lcd);
	qp_comms_command(lcd, ST77XX_CMD_INVERT_OFF);
	qp_comms_stop(lcd);

    // Turn on the LCD and clear the display
    qp_power(lcd, true);

    // begin drawing space
    qp_rect(lcd, 0, 0, WIDTH, HEIGHT, 127, 230, 255, true);

   
    // Allow for user post-init
    keyboard_post_init_user();
}

#define NUM_PLANETS 4

void housekeeping_task_user(void) {

}