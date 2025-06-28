#include "lv_test_main.h"
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
// //屏幕水平宽度 根据实际使用修改
// #define LV_HOR_RES_MAX 800 
 
// //屏幕水平高度 根据实际使用修改
// #define LV_VER_RES_MAX 480
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"
#include <time.h>

lv_obj_t* label_date; //日期label控件
lv_obj_t* label_time; //时间label控件
lv_obj_t* label_duration; //时长label控件

void lv_time()
{
    lv_obj_t* time_bg = lv_obj_create(NULL);
    //设置背景颜色为黑色
    lv_obj_set_style_bg_color(time_bg, lv_color_make(0,0,0), 0);
    //设置屏幕尺寸
    lv_obj_set_size(time_bg, 1000, 800);
    //关闭界面的滚动
    lv_obj_set_scrollbar_mode(time_bg, LV_SCROLLBAR_MODE_OFF);
    lv_scr_load(time_bg);
    

    label_time = lv_label_create(time_bg);//时间控件
    lv_obj_set_size(label_time, 200, 36);
    lv_label_set_text(label_time, "00:00:00");
    lv_obj_align(label_time, LV_ALIGN_TOP_LEFT, 20, 60);
    lv_obj_set_style_text_color(label_time, lv_color_make(255,255,255), 0);
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(label_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    label_date = lv_label_create(time_bg);//日期控件
    lv_obj_set_size(label_date, 250, 36);
    lv_label_set_text(label_date, "2023-01-01");
    lv_obj_align(label_date, LV_ALIGN_TOP_LEFT, 20, 20);
    lv_obj_set_style_text_color(label_date, lv_color_make(255, 255, 255), 0);
    lv_obj_set_style_text_font(label_date, &lv_font_montserrat_36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(label_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_timer_create(update_time_cb, 1000, NULL); //创建一个定时器，每秒更新一次
}
//时间和日期更新回调函数
void update_time_cb(lv_timer_t *timer)
{
    time_t now;
    struct tm tm;

    now = time(NULL);
    localtime_s(&tm, &now);

    static time_t start_time = 0;//初始时长为0
    if (start_time == 0) {start_time = now;}

    char time_str[9]; //存放格式化后的时间字符串
    char date_str[20]; //存放格式化后的日期字符串

    // 将时间格式化为字符串，精确到秒
    snprintf(time_str, sizeof(time_str), "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    // 将日期格式化为字符串，精确到日
    snprintf(date_str, sizeof(date_str), "%04d/%02d/%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    lv_label_set_text(label_time, time_str); // 更新时间标签的文本
    lv_label_set_text(label_date, date_str); // 更新日期标签的文本
}