#include "drawing.h"

void drawingDemo(void){
    /**
     * 隐藏光标
     */
    hiddenCursor();
    /**
     * 清屏
     */
    cleanScreen();
    /**
     * 设置前景色为洋红色，30-37是前景色，这里使用的是宏定义颜色，
     * 具体请查阅vt100.h
     */
    setColor(FONT_CYAN);
    /**
     * 设置背景色为红色，40-47是背景色，这里使用的是宏定义颜色，
     * 具体请查阅vt100.h
     */
    setColor(BKGD_RED);
    /**
     * 绘制一个矩形框,第一个点行列坐标(1, 1)，第二个点行列坐标(20, 40)，
     * 行使用‘-’字符填充，列使用‘|’字符填充，转角使用‘+’字符填充
     */
    drawBox(1, 1, 20, 40, '-', '|', '+');
    /**
     * 设置背景色为紫色，40-47是背景色，这里使用的是宏定义颜色，
     * 具体请查阅vt100.h
     */
    setColor(FONT_WHITE);
    setColor(45);
    //setColor(BKGD_PURPLE);
    /**
     * 填充一个矩形框,第一个点行列坐标(1, 1)，第二个点行列坐标(20, 40)，
     * 使用‘ ’字符填充
     */
    fillBox(1, 1, 20, 40, ' ');
    /**
     * 绘制字符在行列坐标(12, 18), 用字符‘@’
     */
    drawText(12, 18, "@_^_@");
    //drawPoint(12, 18, '@');
    //drawPoint(12, 22, '@');
    //drawPoint(12, 19, '_');
    //drawPoint(12, 20, '^');
    //drawPoint(12, 21, '_');
    /**
     * 在行列坐标(17, 16)处绘制字符串
     */
    drawText(17, 17, "AplexOS");
    /**
     * 在行列坐标(2, 32)绘制时间
     */
    drawTime(2, 32);
    /**
     * 在行列坐标(2, 2)绘制日期
     */
    drawDate(2, 2);
    /**
     * 在行列坐标(19, 11)绘制日期和时间
     */
    drawDateAndTime(19, 11);
    /**
     * 绘制水平直线，在第18行，第2列开始，绘制38个*
     */
    horizonLine(18, 2, 38, '*');
    /**
     * 绘制垂直直线，在第11列，第19行开始，绘制1个|
     */
    verticalLine(11, 19, 1, '|');
    /**
     * 绘制垂直直线，在第30列，第19行开始，绘制1个|
     */
    verticalLine(30, 19, 1, '|');
    /**
     * 将光标移动到行列坐标(21, 1)
     */
    moveCursorToPoint(21, 1);
    /**
     * 清楚之前设置的所有属性设置，但隐藏、显示光标不属于这个范畴
     */
    cleanAllSet();
    /**
     * 显示光标
     */
    showCursor();
    /**
     * 一定要记得使用清空缓冲区函数，因为以上内容均未使用这个fflush函数
     * 做动态效果的时候，如果不是用着个，可能看不到动态效果
     */
    fflush(NULL);
}

void drawDateAndTime(int row, int col){
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    moveCursorToPoint(row,col);
    printf("%4d-%02d-%02d %02d:%02d:%02d", 1900+timeinfo->tm_year, 1+timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}
void drawDate(int row, int col){
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    moveCursorToPoint(row,col);
    printf("%4d-%02d-%02d", 1900+timeinfo->tm_year, 1+timeinfo->tm_mon, timeinfo->tm_mday);
}
void drawTime(int row, int col){
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    moveCursorToPoint(row,col);
    printf("%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}
void drawText(int row, int col, char* ch){
	moveCursorToPoint(row, col);
    printf("%s", ch);
}
void fillBox(int firstRow, int firstCol, int secondRow, int secondCol, char ch){
    int row = 0;
    int col = 0;
    for (row = (firstRow + 1); row < secondRow; row++){//因为填充字符是不需要包含填充边界的
        for (col = (firstCol + 1); col < secondCol; col++){
            drawPoint(row, col , ch);
        }
    }
}
void drawBox(int firstRow, int firstCol, int secondRow, int secondCol, char horizonChar, char verticalChar, char cornerChar){
	horizonLine(firstRow, firstCol, (secondCol-firstCol), horizonChar);
	horizonLine(secondRow, firstCol, (secondCol-firstCol), horizonChar);
	verticalLine(firstCol, firstRow, (secondRow-firstRow), verticalChar);
	verticalLine(secondCol, firstRow, (secondRow-firstRow), verticalChar);
    drawPoint(firstRow, firstCol, cornerChar);
    drawPoint(firstRow, secondCol, cornerChar);
    drawPoint(secondRow, secondCol, cornerChar);
    drawPoint(secondRow, firstCol, cornerChar);
}
void drawPoint(int row, int col, char ch){
	putCharAtPoint(row, col, ch);
}
void horizonLine(int row, int firstCol, int cols, char ch){
	int col = firstCol;
	int maxOfCols = firstCol + cols;
	for(; col < maxOfCols; col++){
		drawPoint(row, col, ch);
	}
}
void verticalLine(int col, int firstRow, int rows, char ch){
	int row = firstRow;
	int maxOfRows = firstRow + rows;
	for(; row < maxOfRows; row++){
		drawPoint(row, col, ch);
	}
}
