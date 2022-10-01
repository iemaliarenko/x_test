# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hci_lpuart)

# NORDIC SDK APP START
target_sources(app PRIVATE main.c src/console_x_test.c src/beacon_x_test.c)
# NORDIC SDK APP END
