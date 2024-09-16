#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Define constants
#define MAX_SPEED 5
#define MAX_LANES 3
#define FROG_START_X 2
#define FROG_START_Y 10

// Define variables
int score = 0;
int frog_x = FROG_START_X;
int frog_y = FROG_START_Y;

// Define functions
void draw_road(int lanes, int lane_width) {
    int i, j;
    for (i = 0; i < lanes; i++) {
        for (j = 0; j < lane_width; j++) {
            printf("-");
        }
        printf("\n");
    }
}

void draw_frog(int x, int y) {
    int i, j;
    for (i = 0; i < y; i++) {
        printf("\n");
    }
    for (i = 0; i < x; i++) {
        printf(" ");
    }
    printf("(@_#)\n");
}

void draw_car(int x, int y, int lane_width) {
    int i, j;
    for (i = 0; i < y; i++) {
        printf("\n");
    }
    for (i = 0; i < x; i++) {
        printf(" ");
    }
    printf("X");
    for (i = 0; i < lane_width - 2; i++) {
        printf(" ");
    }
    printf("X\n");
}

void clear_screen() {
    system("cls");
}

void game_over() {
    printf("Game over!\n");
    printf("Score: %d\n", score);
}

int main() {
    int lanes = MAX_LANES;
    int lane_width = 20;
    int speed = 1;
    int lane_offset = 0;
    int ch = 0;
    int game_running = 1;

    srand(time(NULL)); // Initialize random seed

    // Draw initial screen
    draw_road(lanes, lane_width);
    draw_frog(frog_x, frog_y);

    while (game_running) {
        // Wait for input
        if (kbhit()) {
            ch = getch();
            if (ch == 'w') {
                frog_y--;
                score++;
            }
            if (ch == 's') {
                frog_y++;
            }
            if (ch == 'a') {
                frog_x--;
            }
            if (ch == 'd') {
                frog_x++;
            }
        }

        // Move cars
        lane_offset++;
        if (lane_offset >= lane_width) {
            lane_offset = 0;
            speed++;
            if (speed > MAX_SPEED) {
                speed = MAX_SPEED;
            }
        }

        // Draw screen
        clear_screen();
        draw_road(lanes, lane_width);
        draw_frog(frog_x, frog_y);

        // Draw cars
        int car_y = rand() % lanes;
        int car_x = (lane_offset + ((car_y + 1) * (lane_width / (lanes + 1)))) % lane_width;
        draw_car(car_x, car_y, lane_width);

        // Check for collisions
        if (car_y == frog_y && car_x >= frog_x && car_x <= frog_x + 4) {
            game_running = 0;
        }

        // Wait for next frame
        Sleep(1000 / speed);
    }

    // Game over
    game_over();
}
