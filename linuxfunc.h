#ifndef __Linux_F__
#define __Linux_F__
#include <stdio.h>
#include <stdlib.h>
#include <termio.h> //read...etc
#include <unistd.h> //usleep
void init_keyboard();
void close_keyboard();
int _kbhit();
int _getch();
int _putch(int c);
#endif
/* 
// How to use...

init_keyboard();
while (1) {
    if (_kbhit()) {
        int ch = _getch();
        _putch(ch);
        switch (ch) {
            ...
        }
    }
}
close_keyboard();
*/
