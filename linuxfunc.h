#ifndef __Linux_F__
#define __LInux_F__
void init_keyboard();
void close_keyboard();
int _kbhit();
int _getch();
int _putch(int c)
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
