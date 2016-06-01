#ifndef __VT100_H__
    #define __VT100_H__

    #include <stdio.h>
    
    //font是字体的意思
    #define FONT_BLACK      30  //黑
    #define FONT_RED        31  //红
    #define FONT_GREEN      32  //绿
    #define FONT_YELLOW     33  //黄
    #define FONT_BLUE       34  //蓝
    #define FONT_PURPLE     35  //紫
    #define FONT_CYAN       36  //深绿
    #define FONT_WHITE      37  //白
    //BKGD是background的缩写
    #define BKGD_BLACK      40  //黑
    #define BKGD_RED        41  //红
    #define BKGD_GREEN      42  //绿
    #define BKGD_YELLOW     43  //黄
    #define BKGD_BLUE       44  //蓝
    #define BKGD_PURPLE     45  //紫
    #define BKGD_CYAN       46  //深绿
    #define BKGD_WHITE      47  //白
    /**
     * 将光标移动到row，col指定的位置
     */
    void moveCursorToPoint(int row, int col);
    /**
     * 在row，col指定的位置打印字符ch
     */
    void putCharAtPoint(int row, int col, char ch);
    /**
     * 清屏
     */
    void cleanScreen(void);
    /**
     * 隐藏光标
     */
    void hiddenCursor(void);
    /**
     * 显示光标
     */
    void showCursor(void);
    /**
     * 清楚之前所有的属性设置
     */
    void cleanAllSet(void);
    /**
     * 设置前景色、背景色
     * 前景色数值范围是：30-37
     * 背景色数值范围是：40-47
     * 也可以使用前面的红定义颜色
     */
    void setColor(int color);
#endif
