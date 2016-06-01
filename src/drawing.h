#ifndef __DRAWING_H__
	#define __DRAWING_H__

	#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
	#include "vt100.h"
    /**
     * 使用drawing、vt100制作的Demo，内有详细的代码说明.
     */
    void drawingDemo(void);
    /**
     * 填充一个矩形框，因为是填充，所以不包括边界
     * 参数说明：
     *      firstRow:第一个点的行坐标；
     *      firstCol:第一个点的列坐标；
     *      secondRow:第二个点的行坐标；
     *      secondCol:第二个点的列坐标；
     *      ch:用该字符进行填充。
     */
	void fillBox(int firstRow, int firstCol, int secondRow, int secondCol, char ch);
    /**
     * 绘制一个矩形框
     * 参数说明：
     *      firstRow:第一个点的行坐标；
     *      firstCol:第一个点的列坐标；
     *      secondRow:第二个点的行坐标；
     *      secondCol:第二个点的列坐标；
     *      horizonChar:绘制行所使用的字符；
     *      verticalChar:绘制列所使用的字符；
     *      cornerChar:绘制转角所使用的字符。
     */
	void drawBox(int firstRow, int firstCol, int secondRow, int secondCol, char horizonChar, char verticalChar, char cornerChar);
    /**
     * 绘制一个点
     * 参数说明：
     *      row:点的行坐标；
     *      col:点的列坐标；
     *      ch:绘制点所使用的字符。
     */
	void drawPoint(int row, int col, char ch);
    /**
     * 绘制一条水平直线
     * 参数说明：
     *      row:点的行坐标；
     *      firstCol:第一个点的列坐标；
     *      cols:总共要绘制的列的个数；
     *      ch:绘制直线所使用的字符。
     */
	void horizonLine(int row, int firstCol, int cols, char ch);
    /**
     * 绘制一条垂直直线
     * 参数说明：
     *      col:点的列坐标；
     *      firstRow:第一个点的行坐标；
     *      rows:总共要绘制的行的个数；
     *      ch:绘制直线所使用的字符。
     */
	void verticalLine(int col, int firstRow, int rows, char ch);
    /**
     * 绘制一个字符串
     * 参数说明：
     *      row:字符串起始的行坐标；
     *      col:字符串起始的列坐标；
     *      ch:字符串首地址；
     * 
     */
    void drawText(int row, int col, char* ch);
    /**
     * 绘制一个日期时间字符串，格式是：yyyy-MM-dd hh:mm:ss
     * 参数说明：
     *      row:起始的行坐标；
     *      col:起始的列坐标；
     */
    void drawDateAndTime(int row, int col);
    /**
     * 绘制一个日期时间字符串，格式是：hh:mm:ss
     * 参数说明：
     *      row:起始的行坐标；
     *      col:起始的列坐标；
     */
    void drawTime(int row, int col);
    /**
     * 绘制一个日期时间字符串，格式是：yyyy-MM-dd
     * 参数说明：
     *      row:起始的行坐标；
     *      col:起始的列坐标；
     */
    void drawDate(int row, int col);
#endif
