#include "snake.h"

int height = 30;
int width  = 30;
int tail_snake_vls    =  0;
int i, j,apple_position = 10;
static int decrement_x = 1;

char last_key = ' '; // w a s d

// The functions for reading a press key
int c_kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
int c_getch(void) {

    struct termios old, news;
    int ch;

    tcgetattr(0, &old);

    news = old;
    news.c_lflag &= ~ICANON;
    news.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &news);

    ch = getchar();

    tcsetattr(0, TCSANOW, &old);

    return ch;
}
int c_getche(void) {
    struct termios old, news;
    int ch;

    tcgetattr(0, &old);

    news = old;
    news.c_lflag &= ~ICANON;
    news.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &news);

    ch = getchar();

    tcsetattr(0, TCSANOW, &old);
    return ch;
}

void applePosition(int *value_position_fruit) {

    srand(time(NULL));

    if (((*value_position_fruit) = (rand() % height) - 1) > 0 ||
        ((*value_position_fruit) = (rand() % height) - 1) < (height - 1));

}
int tail(int *position_snake_x, int i, int j, int *position_snake_y, int decrement_x) {

    for (int y = 1; y < decrement_x;y++) {
        if (last_key == 'w')
            if (i - y == *position_snake_x && j == *position_snake_y)
                printf("*");

        if (last_key == 'a')
            if (i == *position_snake_x && j - y -1 == *position_snake_y)
                printf("*");

        if (last_key == 's')
            if (i + y == *position_snake_x && j == *position_snake_y)
                printf("*");

        if (last_key == 'd')
            if (i == *position_snake_x && j + y == *position_snake_y)
                printf("*");
    }

    return 0;
}

int input(struct xyPlace *p_xy) {
    while (1)
    {
        if (c_kbhit()) {
            switch (c_getch()) {
                case 'a':
                    p_xy->y -= 1;
                    last_key = 'a';
                    return p_xy->y;
                    break;
                case 's':
                    p_xy->x += 1;
                    last_key = 's';

                    return p_xy->x;
                    break;
                case 'd':
                    p_xy->y += 1;
                    last_key = 'd';

                    return p_xy->y;
                    break;
                case 'w':
                    p_xy->x -= 1;
                    last_key = 'w';
                    return p_xy->x;
                    break;
                case 'x':
                    printf("STOP!");
                    exit(EXIT_FAILURE);
            }
        }
    }

}
int snake(struct xyPlace *p_xy) {
    input(p_xy);
    int *ptr_s = &tail_snake_vls;
    int *position_snake_x = &p_xy->x;
    int *position_snake_y = &p_xy->y;

    system("clear");
    for (i = 0; i < height; i++) { // ^
        for (j = 0; j < width; j++) { // >
            if (i == 0 || i == width - 1 || j == 0 || j == height-1) {
                printf("$");
            } else {

                if ((*position_snake_x) < 1) {
                    (*position_snake_x) = height - 2;
                }

                if ((*position_snake_x) > height - 2) {
                    (*position_snake_x) = 1;
                }

                if ((*position_snake_y) > width - 2) {
                    (*position_snake_y) = 1;
                }

                if ((*position_snake_y) < 1) {
                    (*position_snake_y) = width - 2;
                }

                tail(position_snake_x, i, j, position_snake_y, decrement_x);

                if ((i == *position_snake_x && j == *position_snake_y))
                {
                    printf("0");
                    if (((*position_snake_x) == apple_position) && ((*position_snake_y) == apple_position))
                    {
                        (*ptr_s) += 1;
                        applePosition( &apple_position);
                        decrement_x +=1;
                    }

                } else {
//                {
                    if (i == apple_position && j == apple_position) {
                        printf("@");
                    }
                    else
                        printf(" ");
                }

            }
        }
        printf("\n");
    }
}
