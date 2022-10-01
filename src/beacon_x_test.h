#ifndef BEACON_X_TEST_H
#define BEACON_X_TEST_H

#include <zephyr/zephyr.h>
#include <zephyr/bluetooth/bluetooth.h>

#define MSG_SIZE 11
extern uint8_t mfg_data_lo[MSG_SIZE];
extern uint8_t mfg_data_la[MSG_SIZE];

void init_beacon (void);
void update_beacon_data (void);

#endif /* BEACON_X_TEST_H */