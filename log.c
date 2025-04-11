#include "log.h"

static uint64_t game_log[MAX_LOGS];
static uint64_t now_board;
static uint8_t index;
static uint8_t size;
int moves[MAX_LOGS];


void log_init(void)
{
    index = 0;
    for (int i = 0; i < MAX_LOGS; i++) {
        moves[i] = 0;
    }
    for (int i = 0; i < MAX_LOGS; i++) {
        game_log[i] = 0;
    }
    now_board = 0;
    pr_info("log: log_init: init\n");
}

void log_board_update(int move)
{
    now_board |= ((uint64_t) move) << moves[index];
    moves[index] += 4;
    pr_info("record_append_board: %d %llx %d %d\n", index, now_board, move,
            moves[index]);
}

void log_append_board(void)
{
    game_log[index] = now_board;
    pr_info("append_board: %d %llx\n", index, now_board);
    index++;
    if (index > MAX_LOGS - 1) {
        index = 0;
    }
    moves[index] = 0;
    size++;
    now_board = 0;
}

uint64_t log_get_board(uint8_t index)
{
    return game_log[index];
}

uint8_t log_get_size(void)
{
    return size;
}

uint8_t log_get_index(void)
{
    return index;
}

uint64_t log_get_board_moves(uint8_t index)
{
    return moves[index];
}