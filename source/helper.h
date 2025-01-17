#ifndef HELPER_H
#define HELPER_H

#define GetBlue(rgb)      (LOBYTE(rgb))
#define GetGreen(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetRed(rgb)      (LOBYTE((rgb)>>16))

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char* target_color;
    char *hold_key;
    int scan_area_x;
    int scan_area_y;
    int color_sens;
	int tap_time;
    int hold_mode;
} CONFIG;

void disable_quickedit();
void free_config(CONFIG* pCfg);
bool get_config(CONFIG* pCfg);
unsigned int* get_screenshot(const char* save_name, int crop_width, int crop_height);
bool is_color_found(DWORD* pPixels, int pixel_count, int red, int green, int blue, int color_sens);
int get_key_code(char* input_key);
bool get_valorant_colors(const char* pColor, int* pRed, int* pGreen, int* pBlue);
char* get_str(char* key_name);
int get_int(char* key_name);
double get_float(char* key_name);
double get_reaction_average(double total_reaction, int reaction_count);
void init_performance_counters();
void start_counter();
void stop_counter();
void left_click();
bool is_key_pressed(int hold_key);
void print_logo();

#endif
