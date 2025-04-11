#include <linux/types.h>
#include <linux/vmalloc.h>

#define MAX_LOGS 16

void log_init(void);

void log_board_update(int move);

void log_append_board(void);

uint64_t log_get_board(uint8_t index);

uint8_t log_get_size(void);

uint8_t log_get_index(void);

uint64_t log_get_board_moves(uint8_t index);