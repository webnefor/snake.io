#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

static struct xyPlace {
    int x;
    int y;
} value = {25,25};

static struct xyPlace *p_xy = &value;

int c_getch(void);
int c_getche(void);
int c_kbhit(void);


int tail(int *position_snake_x, int i, int j, int *position_snake_y, int decrement_x);
int  snake_tail();
int  snake(struct xyPlace *p_xy);
int  input(struct xyPlace *p_xy);
void applePosition(int *value_position_fruit);
