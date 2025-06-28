/**
 * @file lv_examples.h
 *
 */

#ifndef LVGL_APP_H
#define LVGL_APP_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "lvgl_porting/lv_mount_cus_font.h"
     /*********************
      *      DEFINES
      *********************/

      /**********************
       *      TYPEDEFS
       **********************/
    enum
    {
        WEATHER_MAIN_CITY,
        WEATHER_MAIN_TEMP,
        WEATHER_MAIN_HUMI,
        WEATHER_MAIN_AIR,
        WEATHER_MAIN_TIME,
        WEATHER_MAIN_DATA,
        WEATHER_MAIN_WEEK,
        WEATHER_MAIN_IMG,
    };
    /**********************
     * GLOBAL PROTOTYPES
     **********************/

     /**********************
      *      MACROS
      **********************/
    void lv_weather_main(void);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_APP_H*/
