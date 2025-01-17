#include "helper.h"

int main(int argc, char* argv[]) {
    int red, blue, green;
    CONFIG cfg = {0};

    if (!get_config(&cfg)) {
        printf("Error: The variable name could not be found in the txt file.");
        printf("\nPress enter to exit: ");
        getchar();
        return 1;
    }

	if (!get_valorant_colors(cfg.target_color, &red, &green ,&blue)) {
        printf("Error: Unknown color.");
        printf("\nPress enter to exit: ");
        getchar();
        return 1;
    }

    init_performance_counters();
    int pixel_count = cfg.scan_area_x * cfg.scan_area_y;
    get_screenshot(0, cfg.scan_area_x, cfg.scan_area_y); // Call it once
    print_logo();

    while (true) {
        start_counter();
        if (get_key_code(cfg.hold_key) == -1) {
            printf("The hold_key you choose could not be found");
            printf("\nPress enter to exit: ");
            getchar();
            return 1;
        }

        if (cfg.hold_mode == 0 || is_key_pressed(get_key_code(cfg.hold_key))) {
            unsigned int *pPixels = get_screenshot(0, cfg.scan_area_x, cfg.scan_area_y);

            if (pPixels == 0) {
                printf("ERROR: get_screenshot() failed!");
                printf("\nPress enter to exit: ");
                getchar();
                return 1;
            }

            if (is_color_found(pPixels, pixel_count, red, green, blue, cfg.color_sens)) {
				left_click();
                stop_counter();
                Sleep(cfg.tap_time);
            }
            free(pPixels);
        }
        else{
            Sleep(1);
        }
    }

    free_config(&cfg);
    return 0;
}
