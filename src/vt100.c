#include "vt100.h"
/**
 * 所有的函数都没有进行参数检查
 */

void moveCursorToPoint(int row, int col){
    printf("\033[%d;%dH", row, col);
}

void putCharAtPoint(int row, int col, char ch){
    printf("\033[%d;%dH%c", row, col, ch);
}

void cleanAllSet(void){
    printf("\033[0m");
}

void showCursor(void){
    printf("\033[?25h");
}

void hiddenCursor(void){
    printf("\033[?25l");
}

void cleanScreen(void){
    printf("\033[2J");
}
void setColor(int color){
    printf("\033[%dm", color);
}
