#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"

#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "math.h"
#include "stdio.h"
#include "stdlib.h"


LV_FONT_DECLARE(lv_font_CN_SYHT_N_28)//思源黑体28号
LV_FONT_DECLARE(lv_font_CN_SYHT_N_32)//思源黑体32号
LV_FONT_DECLARE(lv_font_CN_SYHT_N_40)//思源黑体40号
LV_FONT_DECLARE(lv_font_CN_SYHT_N_48)//思源黑体48号


void lv_time(void);
void update_time_cb(lv_timer_t *timer);
