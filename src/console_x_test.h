#ifndef CONSOLE_X_TEST_H
#define CONSOLE_X_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/zephyr.h>
#include <zephyr/drivers/uart.h>

#define LONG 1
#define LAT 2

void print_uart(char *buf);
void init_console (void);
bool read_console_data (uint8_t *mfg_data_lo, uint8_t tlc);

#endif /* CONSOLE_X_TEST_H */