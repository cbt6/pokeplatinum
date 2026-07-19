// window.c

#include "overlay111/ov111_021D3548.h"

#include <nitro.h>
#include <string.h>

#include "bg_window.h"
#include "render_window.h"

static const WindowTemplate sWindows[MAX_SCRATCH_OFF_CARDS_WINDOW] = {
    [SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING] = {
        .bgLayer = BG_LAYER_MAIN_2,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 27,
        .height = 4,
        .palette = 12,
        .baseTile = 1,
    },
    [SCRATCH_OFF_CARDS_WINDOW_UNK_01] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 24,
        .tilemapTop = 13,
        .width = 7,
        .height = 4,
        .palette = 13,
        .baseTile = 109,
    },
    [SCRATCH_OFF_CARDS_WINDOW_PRIZE_NAME_0] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 17,
        .tilemapTop = 3,
        .width = 11,
        .height = 5,
        .palette = 13,
        .baseTile = 137,
    },
    [SCRATCH_OFF_CARDS_WINDOW_PRIZE_NAME_1] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 17,
        .tilemapTop = 8,
        .width = 11,
        .height = 5,
        .palette = 13,
        .baseTile = 192,
    },
    [SCRATCH_OFF_CARDS_WINDOW_PRIZE_NAME_2] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 17,
        .tilemapTop = 14,
        .width = 11,
        .height = 5,
        .palette = 13,
        .baseTile = 247,
    },
    [SCRATCH_OFF_CARDS_WINDOW_PRIZE_NAME_3] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 17,
        .tilemapTop = 19,
        .width = 11,
        .height = 5,
        .palette = 13,
        .baseTile = 302,
    },
    [SCRATCH_OFF_CARDS_WINDOW_UNK_06] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 10,
        .tilemapTop = 3,
        .width = 5,
        .height = 3,
        .palette = 13,
        .baseTile = 357,
    },
    [SCRATCH_OFF_CARDS_WINDOW_UNK_07] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 10,
        .tilemapTop = 8,
        .width = 5,
        .height = 3,
        .palette = 13,
        .baseTile = 372,
    },
    [SCRATCH_OFF_CARDS_WINDOW_UNK_08] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 10,
        .tilemapTop = 14,
        .width = 5,
        .height = 3,
        .palette = 13,
        .baseTile = 387,
    },
    [SCRATCH_OFF_CARDS_WINDOW_UNK_09] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 10,
        .tilemapTop = 19,
        .width = 5,
        .height = 3,
        .palette = 13,
        .baseTile = 402,
    },
    [SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO] = {
        .bgLayer = BG_LAYER_MAIN_2,
        .tilemapLeft = 10,
        .tilemapTop = 9,
        .width = 12,
        .height = 4,
        .palette = 13,
        .baseTile = 417,
    },
    [SCRATCH_OFF_CARDS_WINDOW_UNK_11] = {
        .bgLayer = BG_LAYER_MAIN_2,
        .tilemapLeft = 10,
        .tilemapTop = 9,
        .width = 12,
        .height = 4,
        .palette = 13,
        .baseTile = 417,
    },
    [SCRATCH_OFF_CARDS_WINDOW_TOO_BAD] = {
        .bgLayer = BG_LAYER_MAIN_2,
        .tilemapLeft = 10,
        .tilemapTop = 9,
        .width = 12,
        .height = 4,
        .palette = 13,
        .baseTile = 417,
    },
    [SCRATCH_OFF_CARDS_WINDOW_NEXT_CARD] = {
        .bgLayer = BG_LAYER_MAIN_2,
        .tilemapLeft = 10,
        .tilemapTop = 21,
        .width = 13,
        .height = 3,
        .palette = 13,
        .baseTile = 465,
    },
    [SCRATCH_OFF_CARDS_WINDOW_CANCEL] = {
        .bgLayer = BG_LAYER_MAIN_2,
        .tilemapLeft = 13,
        .tilemapTop = 21,
        .width = 13,
        .height = 3,
        .palette = 13,
        .baseTile = 465,
    },
    [SCRATCH_OFF_CARDS_WINDOW_TEXTBOX] = {
        .bgLayer = BG_LAYER_SUB_0,
        .tilemapLeft = 2,
        .tilemapTop = 19,
        .width = 27,
        .height = 4,
        .palette = 12,
        .baseTile = 1,
    },
};

void ScratchOffCards_AddWindows(BgConfig *bgConfig, Window *windows)
{
    for (u8 i = 0; i < NELEMS(sWindows); i++) {
        Window_AddFromTemplate(bgConfig, &windows[i], &sWindows[i]);
        Window_FillTilemap(&windows[i], 0);
    }
}

void ScratchOffCards_RemoveWindows(Window *windows)
{
    for (u16 i = 0; i < NELEMS(sWindows); i++) {
        Window_Remove(&windows[i]);
    }
}

void ScratchOffCards_DrawWindow(BgConfig *bgConfig, Window *window)
{
    LoadStandardWindowGraphics(bgConfig, BG_LAYER_MAIN_2, (1024 - 9), 11, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Window_DrawStandardFrame(window, 1, (1024 - 9), 11);
}

void ScratchOffCards_DrawMessageBox(Window *window, int frame)
{
    LoadMessageBoxGraphics(window->bgConfig, Window_GetBgLayer(window), ((1024 - 9) - (18 + 12)), 10, frame, HEAP_ID_SCRATCH_OFF_CARDS);
    Window_FillTilemap(window, 15);
    Window_DrawMessageBoxWithScrollCursor(window, FALSE, ((1024 - 9) - (18 + 12)), 10);
}
