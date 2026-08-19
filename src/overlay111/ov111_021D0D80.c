#include "overlay111/ov111_021D0D80.h"

#include <nitro.h>
#include <string.h>

#include "constants/items.h"

#include "struct_defs/struct_0203E608.h"

#include "overlay111/ov111_021D2F80.h"
#include "overlay111/ov111_021D33F4.h"
#include "overlay111/ov111_021D3548.h"
#include "overlay111/sco_narc_members.h"
#include "overlay111/struct_ov111_021D2F80.h"
#include "overlay111/temp.h"

#include "bg_window.h"
#include "font.h"
#include "font_special_chars.h"
#include "game_options.h"
#include "graphics.h"
#include "gx_layers.h"
#include "heap.h"
#include "math_util.h"
#include "message.h"
#include "narc.h"
#include "overlay_manager.h"
#include "palette.h"
#include "render_oam.h"
#include "render_window.h"
#include "save_player.h"
#include "savedata.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_playback.h"
#include "sprite.h"
#include "string_gf.h"
#include "string_template.h"
#include "system.h"
#include "text.h"
#include "touch_pad.h"
#include "touch_screen.h"
#include "unk_0201567C.h"
#include "vram_transfer.h"
#include "yes_no_touch_menu.h"

#include "res/text/bank/scratch_off_cards_game.h"

enum {
    anim_id_0,
    anim_id_1,
    anim_id_2,
    anim_id_3,
    anim_id_4,
};

typedef struct {
    u8 t;
    u8 b;
    u8 l;
    u8 r;
} UnkStruct_ov111_021D3728;

BOOL ScratchOffCards_Init(ApplicationManager *appMan, int *state);
BOOL ScratchOffCards_Main(ApplicationManager *appMan, int *state);
BOOL ScratchOffCards_Exit(ApplicationManager *appMan, int *state);
static BOOL ov111_021D0F7C(TheStruct *param0);
static BOOL ov111_021D0FC8(TheStruct *param0);
static BOOL ov111_021D10B8(TheStruct *param0);
static BOOL ov111_021D116C(TheStruct *param0);
static BOOL ov111_021D1284(TheStruct *param0);
static BOOL ov111_021D1508(TheStruct *param0);
static BOOL ov111_021D1980(TheStruct *param0);
static BOOL ov111_021D1A88(TheStruct *param0);
static void ov111_021D1AF4(TheStruct *param0);
static void ov111_021D1B44(TheStruct *param0);
static void ov111_021D1B90(TheStruct *param0);
static void ov111_021D1BEC(TheStruct *param0);
static void ov111_021D1C0C(TheStruct *param0);
static void ov111_021D1D30(void);
static void ov111_021D1D68(TheStruct *param0);
static void ov111_021D1F70(TheStruct *param0);
static void ov111_021D1F84(TheStruct *param0);
static void ov111_021D1FB4(TheStruct *param0);
static void ov111_021D2034(TheStruct *param0);
static void ScratchOffCards_InitGraphics(TheStruct *param0);
static void ov111_021D2044(BgConfig *bgConfig);
static void ov111_021D2090(void *param0);
static void ScratchOffCards_SetVRAMBanks(void);
static void ScratchOffCards_InitBgs(BgConfig *bgConfig);
static void ov111_021D2248(TheStruct *param0, u32 param1);
static void ScratchOffCards_LoadSubScreenPalette(void);
static void ov111_021D228C(TheStruct *param0, u32 param1);
static void ov111_021D233C(TheStruct *param0, u32 param1);
static void ScratchOffCards_LoadMainScreenPalette(void);
static void ov111_021D2380(TheStruct *param0, u32 param1);
static u8 ScratchOffCards_PrintMessage(TheStruct *param0, Window *window, int entryID, u32 xOffset, u32 yOffset, u32 renderDelay, u8 fgColor, u8 shadowColor, u8 bgColor, u8 fontID);
static u8 ScratchOffCards_PrintMessageAlignCenter(TheStruct *param0, Window *window, int entryID, u32 xOffset, u32 yOffset, u32 renderDelay, u8 fgColor, u8 shadowColor, u8 bgColor, u8 fontID);
static u8 ov111_021D2494(TheStruct *param0);
static u8 ov111_021D24D4(TheStruct *param0);
static u8 ov111_021D2518(TheStruct *param0);
static u8 ov111_021D255C(TheStruct *param0);
static u8 ov111_021D25BC(TheStruct *param0);
static u8 ov111_021D2604(TheStruct *param0);
static u8 ov111_021D263C(TheStruct *param0);
static u8 ov111_021D2674(TheStruct *param0, u8 param1);
static void ov111_021D26CC(TheStruct *param0, u32 index, s32 number);
static void ScratchOffCards_ChangeState(TheStruct *param0, int *state, int newState);
static void ov111_021D26EC(TheStruct *param0);
static void ov111_021D271C(TheStruct *param0);
static void ov111_021D27AC(TheStruct *param0, u8 unused);
static void ov111_021D27BC(TheStruct *param0);
static void ov111_021D27D4(TheStruct *param0, u8 unused);
static BOOL ov111_021D2868(TheStruct *param0, u8 param1);
static void ov111_021D28E8(TheStruct *param0, u32 bgLayer, u8 palette, u8 width, u8 height);
static u8 ov111_021D2918(TheStruct *param0);
static void ov111_021D2940(TheStruct *param0);
static void ov111_021D295C(TheStruct *param0);
static void ov111_021D297C(TheStruct *param0, int rectIndex);
static void ov111_021D29D8(TheStruct *param0);
static void ov111_021D2A18(TheStruct *param0, int param1, int param2);
static BOOL ov111_021D2A68(TheStruct *param0, u8 rectIndex);
static void ov111_021D2B20(TheStruct *param0);
static BOOL ov111_021D2BBC(TheStruct *param0);
static BOOL ov111_021D2D14(TheStruct *param0);
static BOOL ov111_021D2D60(TheStruct *param0, u8 param1);
static void ov111_021D2E18(TheStruct *param0);
static void ov111_021D2E20(TheStruct *param0);
static void ov111_021D2E28(TheStruct *param0);
static void ov111_021D2E4C(TheStruct *param0);
static void ov111_021D2E8C(TheStruct *param0);
static void ov111_021D2EB4(TheStruct *param0);
static void ov111_021D2ECC(TheStruct *param0, int param1, int param2);
static void ov111_021D2F38(TheStruct *param0, u32 param1, u32 param2);

static const Point2D Unk_ov111_021D3620[3] = {
    { 52, 68 },
    { 108, 68 },
    { 164, 68 },
};

static const Point2D Unk_ov111_021D3608 = { 38, 56 };

static const Point2D Unk_ov111_021D3770[9] = {
    { 57, 18 },
    { 124, 18 },
    { 191, 18 },
    { 57, 66 },
    { 124, 66 },
    { 191, 66 },
    { 57, 114 },
    { 124, 114 },
    { 191, 114 },
};

static const Point2D Unk_ov111_021D362C[4] = {
    { 0, 36 },
    { 56, 36 },
    { 112, 36 },
    { 168, 36 },
};

static const Point2D Unk_ov111_021D3604 = { 68, 160 };

static const Point2D Unk_ov111_021D3600 = { 88, 160 };

static const Point2D Unk_ov111_021D360C = { 68, 68 };

static const u16 sPrizes[] = {
    ITEM_POMEG_BERRY,
    ITEM_KELPSY_BERRY,
    ITEM_QUALOT_BERRY,
    ITEM_HONDEW_BERRY,
    ITEM_GREPA_BERRY,
    ITEM_TAMATO_BERRY,
    ITEM_OCCA_BERRY,
    ITEM_PASSHO_BERRY,
    ITEM_WACAN_BERRY,
    ITEM_RINDO_BERRY,
    ITEM_YACHE_BERRY,
    ITEM_CHOPLE_BERRY,
    ITEM_KEBIA_BERRY,
    ITEM_SHUCA_BERRY,
    ITEM_COBA_BERRY,
    ITEM_PAYAPA_BERRY,
    ITEM_TANGA_BERRY,
    ITEM_CHARTI_BERRY,
    ITEM_KASIB_BERRY,
    ITEM_HABAN_BERRY,
    ITEM_COLBUR_BERRY,
    ITEM_BABIRI_BERRY,
    ITEM_CHILAN_BERRY,
};

static const TouchScreenRect sSelectCardTouchRects[] = {
    { 42, 154, 0, 80 },
    { 42, 154, 88, 138 },
    { 42, 154, 144, 195 },
    { 42, 154, 204, 254 },
    { TOUCHSCREEN_TABLE_TERMINATOR, 0, 0, 0 }
};

static const TouchScreenRect sNextCardTouchRects[] = {
    { 164, 191, 76, 180 },
    { TOUCHSCREEN_TABLE_TERMINATOR, 0, 0, 0 }
};

static const TouchScreenRect sCancelTouchRects[] = {
    { 164, 191, 94, 164 },
    { TOUCHSCREEN_TABLE_TERMINATOR, 0, 0, 0 }
};

static const TouchScreenRect sScratchAreaTouchRects[NUMBER_OF_SLOTS + 1] = {
    { 21, 54, 32, 89 },
    { 21, 54, 102, 157 },
    { 21, 54, 170, 227 },
    { 68, 100, 32, 89 },
    { 68, 100, 102, 157 },
    { 68, 100, 170, 227 },
    { 114, 148, 32, 89 },
    { 114, 148, 102, 157 },
    { 114, 148, 170, 227 },
    { TOUCHSCREEN_TABLE_TERMINATOR, 0, 0, 0 }
};

// t, b, l, r

static const UnkStruct_ov111_021D3728 Unk_ov111_021D3728[] = {
    { 21, 54, 32, 89 },
    { 21, 54, 102, 157 },
    { 21, 54, 170, 227 },
    { 68, 100, 32, 89 },
    { 68, 100, 102, 157 },
    { 68, 100, 170, 227 },
    { 114, 148, 32, 89 },
    { 114, 148, 102, 157 },
    { 114, 148, 170, 227 },
};

static const Point2D Unk_ov111_021D374C[9] = {
    { 42, 27 },
    { 117, 27 },
    { 189, 27 },
    { 42, 74 },
    { 117, 74 },
    { 189, 74 },
    { 42, 120 },
    { 117, 120 },
    { 189, 120 },
};

BOOL ScratchOffCards_Init(ApplicationManager *appMan, int *state)
{
    ov111_021D1D30();
    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_SCRATCH_OFF_CARDS, 0x48000);

    TheStruct *v1 = ApplicationManager_NewData(appMan, sizeof(TheStruct), HEAP_ID_SCRATCH_OFF_CARDS);
    memset(v1, 0, sizeof(TheStruct));

    v1->bgConfig = BgConfig_New(HEAP_ID_SCRATCH_OFF_CARDS);
    v1->unk_00 = appMan;
    ExternalDataSOC *v2 = (ExternalDataSOC *)ApplicationManager_Args(appMan);
    v1->saveData = v2->saveData;
    v1->dummy_09 = v2->dummy_04;
    v1->unk_3D8 = &v2->dummy_14;
    v1->options = SaveData_GetOptions(v1->saveData);
    v1->destVarItemId = &v2->strange_unk_08[0];
    v1->destVarItemQty = &v2->strange_unk_0E[0];

    ov111_021D27BC(v1);

    for (int v0 = 0; v0 < 3; v0++) {
        v1->destVarItemId[v0] = ITEM_NONE;
        v1->destVarItemQty[v0] = 0;
    }

    v1->unk_409 = 0;

    ov111_021D1D68(v1);
    *state = 0;
    Sound_SetSceneAndPlayBGM(SOUND_SCENE_SUB_68, SEQ_NONE, 0);

    return TRUE;
}

BOOL ScratchOffCards_Main(ApplicationManager *appMan, int *state)
{
    TheStruct *theDataOfStruct = ApplicationManager_Data(appMan);

    switch (*state) {
    case 0:
        if (ov111_021D0F7C(theDataOfStruct) == TRUE) { // fade both screens
            ScratchOffCards_ChangeState(theDataOfStruct, state, 1);
        }
        break;
    case 1:
        if (ov111_021D0FC8(theDataOfStruct) == TRUE) {
            ScratchOffCards_ChangeState(theDataOfStruct, state, 2);
        }
        break;
    case 2:
        if (ov111_021D10B8(theDataOfStruct) == TRUE) {
            ScratchOffCards_ChangeState(theDataOfStruct, state, 3);
        }
        break;
    case 3:
        if (ov111_021D116C(theDataOfStruct) == TRUE) {
            if (theDataOfStruct->unk_0E >= 3) {
                theDataOfStruct->unk_0E = 0;

                ov111_021D1BEC(theDataOfStruct);
                ov111_021D1AF4(theDataOfStruct);
                ov111_021D1B44(theDataOfStruct);
                ScratchOffCards_ChangeState(theDataOfStruct, state, 4);
            } else {
                ScratchOffCards_ChangeState(theDataOfStruct, state, 1);
            }
        }
        break;
    case 4:
        if (ov111_021D1284(theDataOfStruct) == TRUE) {
            ScratchOffCards_ChangeState(theDataOfStruct, state, 5);
        }
        break;
    case 5:
        if (ov111_021D1508(theDataOfStruct) == TRUE) {
            if (theDataOfStruct->unk_0E >= 3) {
                ScratchOffCards_ChangeState(theDataOfStruct, state, 7);
            } else {
                ScratchOffCards_ChangeState(theDataOfStruct, state, 6);
            }
        }
        break;
    case 6:
        if (ov111_021D1980(theDataOfStruct) == TRUE) {
            ScratchOffCards_ChangeState(theDataOfStruct, state, 4);
        }
        break;
    case 7:
        if (ov111_021D1A88(theDataOfStruct) == TRUE) {
            return TRUE;
        }
        break;
    }

    SpriteList_Update(theDataOfStruct->unk_16C.spriteList);

    return FALSE;
}

BOOL ScratchOffCards_Exit(ApplicationManager *appMan, int *state)
{
    TheStruct *v1 = ApplicationManager_Data(appMan);

    DisableTouchPad();
    *(v1->unk_3D8) = v1->unk_0C;
    VramTransfer_Free();

    ov111_021D1C0C(v1);

    ApplicationManager_FreeData(appMan);
    SetVBlankCallback(NULL, NULL);
    Heap_Destroy(HEAP_ID_SCRATCH_OFF_CARDS);

    return TRUE;
}

static BOOL ov111_021D0F7C(TheStruct *param0)
{
    switch (param0->subState) {
    case 0:
        StartScreenFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, COLOR_BLACK, 6, 3, HEAP_ID_SCRATCH_OFF_CARDS);
        param0->subState++;
        break;
    case 1:
        if (IsScreenFadeDone() == TRUE) {
            param0->unk_0E = 0;
            return TRUE;
        }
        break;
    }

    return FALSE;
}

static BOOL ov111_021D0FC8(TheStruct *param0)
{
    switch (param0->subState) {
    case 0:
        param0->unk_10 = -256;

        for (int v0 = 0; v0 < 4; v0++) {
            // { 0, 36 },
            // { 56, 36 },
            // { 112, 36 },
            // { 168, 36 },
            ov111_021D3474(param0->unk_390[v0], Unk_ov111_021D362C[v0].x + param0->unk_10, Unk_ov111_021D362C[v0].y);
            ScratchOffCardsSprite_SetPriority(param0->unk_390[v0], 20 + v0);
        }

        ScratchOffCards_DrawMessageBox(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_TEXTBOX], Options_Frame(param0->options));
        ov111_021D24D4(param0);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, TRUE);
        param0->unk_12 = 3;
        Sound_PlayEffect(SEQ_SE_PL_SYU03_sseq);
        param0->subState = 1;
        break;
    case 1:
        param0->unk_10 += 32;
        ov111_021D3474(param0->unk_390[param0->unk_12], Unk_ov111_021D362C[param0->unk_12].x + param0->unk_10, Unk_ov111_021D362C[param0->unk_12].y);

        if (param0->unk_10 >= 0) {
            if (param0->unk_12 == 0) {
                param0->subState = 2;
            } else {
                Sound_PlayEffect(SEQ_SE_PL_SYU03_sseq);
                param0->unk_12--;
                param0->unk_10 = -256;
            }
        }
        break;
    case 2:
        param0->unk_10 = 0;
        return TRUE;
    }

    return FALSE;
}

static BOOL ov111_021D10B8(TheStruct *param0)
{
    switch (param0->subState) {
    case 0:
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, TRUE);
        param0->unk_0F = 30;
        param0->subState = 1;
        break;
    case 1:
        if (param0->unk_0F == 0) {
            GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, FALSE);
            ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, FALSE);
        } else {
            param0->unk_0F--;
        }

        int rectIndex = TouchScreen_CheckRectangleHeld(sSelectCardTouchRects);
        if (rectIndex != TOUCHSCREEN_INPUT_NONE) {
            GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, FALSE);
            ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, FALSE);
            Sound_PlayEffect(SEQ_SE_DP_BUTTON9_sseq);

            param0->unk_15[param0->unk_0E] = rectIndex;
            param0->unk_0E++;

            u32 x, y;
            TouchScreen_GetHoldState(&x, &y);
            Window_EraseMessageBox(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_TEXTBOX], FALSE);
            GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, FALSE);
            param0->subState = 2;
        }
        break;
    case 2:
        return TRUE;
    }

    return FALSE;
}

static BOOL ov111_021D116C(TheStruct *param0)
{
    int v1 = param0->unk_15[param0->unk_0E - 1];

    switch (param0->subState) {
    case 0:
        param0->unk_1C.x = 0x1000;
        param0->unk_1C.y = 0x1000;
        param0->unk_1C.z = 0x1000;
        param0->unk_10 = 0;
        param0->unk_40C_1 = 0;
        ScratchOffCardsSprite_SetPriority(param0->unk_390[v1], 0);
        param0->subState = 1;
        break;
    case 1:
        ov111_021D2868(param0, v1);

        param0->unk_1C.x += 0x100;
        param0->unk_1C.y += 0x100;
        param0->unk_1C.z += 0x100;
        param0->unk_10++;

        if (param0->unk_10 % 1 == 0) {
            ov111_021D34F4(param0->unk_390[v1], &param0->unk_1C);
        }

        if (param0->unk_1C.x == 0x1800) {
            param0->unk_10 = 0;
            param0->unk_1C.x = 0x1000;
            param0->unk_1C.y = 0x1000;
            param0->unk_1C.z = 0x1000;
            Sound_PlayEffect(SEQ_SE_PL_SYU03_sseq);
            param0->subState = 2;
        }
        break;
    case 2:
        param0->unk_10 += 16;

        for (int i = 0; i < 4; i++) {
            int x, y;
            ov111_021D349C(param0->unk_390[i], &x, &y);
            ov111_021D3474(param0->unk_390[i], x + 16, y);
        }

        if (param0->unk_10 >= 256) {
            ov111_021D34E0(param0->unk_390[v1], 0);
            param0->subState = 3;
        }
        break;
    case 3:
        param0->unk_10 = 0;
        return TRUE;
    }

    return FALSE;
}

static BOOL ov111_021D1284(TheStruct *param0)
{
    int v0, v1;

    switch (param0->subState) {
    case 0:
        ov111_021D2EB4(param0);

        Bg_LoadTiles(param0->bgConfig, BG_LAYER_MAIN_0, param0->unk_3F8, param0->charData->szByte, 0);
        Bg_CopyTilemapBufferToVRAM(param0->bgConfig, BG_LAYER_MAIN_0);

        param0->unk_12 = 256;

        Bg_SetOffset(param0->bgConfig, BG_LAYER_SUB_2, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        Bg_SetOffset(param0->bgConfig, BG_LAYER_MAIN_0, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        Bg_SetOffset(param0->bgConfig, BG_LAYER_MAIN_1, BG_OFFSET_UPDATE_SET_X, param0->unk_12);

        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, TRUE);
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG1, TRUE);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG2, TRUE);

        param0->unk_10 = -256;
        param0->unk_19[param0->unk_0E] = 0;

        for (v0 = 0; v0 < (240 * 160); v0++) {
            param0->unk_466[v0] = 0;
        }

        param0->unk_40D = 0;

        ov111_021D27BC(param0);
        ov111_021D27AC(param0, param0->unk_19[param0->unk_0E]);
        ov111_021D27D4(param0, param0->unk_19[param0->unk_0E]);
        ov111_021D2940(param0);
        ov111_021D295C(param0);

        param0->subState = 1;
        break;
    case 1:

        for (v0 = 0; v0 < 4; v0++) {
            ov111_021D3474(param0->unk_35C[v0], 60 + param0->unk_10, 26 + (v0 * 42));
            ScratchOffCardsSprite_SetDrawFlag(param0->unk_35C[v0], TRUE);
        }

        for (v0 = 0; v0 < 3; v0++) {
            ScratchOffCardsSprite_SetPalette(param0->unk_3A8[v0], 1);
        }

        param0->unk_409 = 0;
        param0->unk_40C_0 = 0;
        param0->unk_40E[0] = 177;
        param0->unk_40E[1] = 178;
        param0->unk_40E[2] = 179;

        for (v0 = 0; v0 < NUMBER_OF_SLOTS; v0++) {
            ov111_021D3474(param0->unk_36C[v0], Unk_ov111_021D3770[v0].x + param0->unk_10, Unk_ov111_021D3770[v0].y);
            ScratchOffCardsSprite_SetDrawFlag(param0->unk_36C[v0], TRUE);
            ScratchOffCardsSprite_SetAnimID(param0->unk_36C[v0], param0->unk_3C4[v0]);
        }

        ov111_021D28E8(param0, BG_LAYER_MAIN_1, param0->unk_15[param0->unk_0E] + 4, 32, 24);
        ov111_021D28E8(param0, BG_LAYER_SUB_2, param0->unk_15[param0->unk_0E] + 1, 32, 24);
        Sound_PlayEffect(SEQ_SE_PL_SYU03_sseq);
        param0->subState = 2;
        break;
    case 2:
        Bg_SetOffset(param0->bgConfig, BG_LAYER_SUB_2, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        Bg_SetOffset(param0->bgConfig, BG_LAYER_MAIN_0, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        Bg_SetOffset(param0->bgConfig, BG_LAYER_MAIN_1, BG_OFFSET_UPDATE_SET_X, param0->unk_12);

        param0->unk_12 += -16;

        if (param0->unk_10 >= 0) {
            param0->subState = 3;
        } else {
            for (v0 = 0; v0 < 4; v0++) {
                ov111_021D3474(param0->unk_35C[v0], 60 + param0->unk_10, 26 + (v0 * 42));
            }

            for (v0 = 0; v0 < 9; v0++) {
                ov111_021D3474(param0->unk_36C[v0], Unk_ov111_021D3770[v0].x + param0->unk_10, Unk_ov111_021D3770[v0].y);
            }
        }

        param0->unk_10 += 16;
        break;
    case 3:
        param0->unk_10 = 0;
        param0->unk_12 = 0;
        return 1;
    }

    return 0;
}

static BOOL ov111_021D1508(TheStruct *param0)
{
    int v0, rectIndex;
    u32 yesNoResult, v3;

    switch (param0->subState) {
    case 0:
        if (param0->unk_0E == (3 - 1)) {
            Window_ClearAndCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_NEXT_CARD]);
            ov111_021D263C(param0);
            ov111_021D3474(param0->unk_3A0, Unk_ov111_021D3600.x, Unk_ov111_021D3600.y);
            ScratchOffCardsSprite_SetAnimID(param0->unk_3A0, anim_id_0);
        } else {
            Window_ClearAndCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_CANCEL]);
            ov111_021D2604(param0);
        }

        param0->unk_0F = 30;

        ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, TRUE);
        ov111_021D2518(param0);

        for (v0 = 0; v0 < 4; v0++) {
            ov111_021D2674(param0, v0);
        }

        ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A0, TRUE);
        ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, FALSE);
        Sound_PlayEffect(SEQ_SE_PL_UG_020_sseq);
        param0->subState = 1;
        break;
    case 1:
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, TRUE);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, TRUE);
        param0->subState = 2;
        break;
    case 2:
        if (param0->unk_0F == 0) {
            ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, FALSE);
            Window_FillTilemap(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO], 0);
            Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO]);
            param0->subState = 3;
        } else {
            param0->unk_0F--;
        }
        break;
    case 3:
        WriteAutoSamplingDataToBuffer(&param0->unk_424, TOUCH_PAD_EXTERNAL_BUFFER_WRITE_METHOD_ALL_DATA_WITHOUT_WRAPPING, 2);
        rectIndex = TouchScreen_CheckRectangleHeld(sScratchAreaTouchRects);

        if (rectIndex != TOUCHSCREEN_INPUT_NONE) {
            if (ov111_021D2918(param0) < 3) {
                param0->unk_400[rectIndex] = 1;
            }

            if (param0->unk_400[rectIndex] == 1) {
                ov111_021D29D8(param0);
                ov111_021D2A68(param0, rectIndex);
                ov111_021D297C(param0, rectIndex);

                if (Sound_IsEffectPlaying(1358) == FALSE) {
                    Sound_PlayEffect(SEQ_SE_PL_KEZURI_sseq);
                }
            }

            if (ov111_021D2BBC(param0) == TRUE) {
                Sound_StopEffect(1358, 0);
                ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, TRUE);

                param0->destVarItemId[param0->unk_0E] = param0->prizes[param0->unk_40B];

                if (param0->prizes[param0->unk_40B] == ITEM_NUGGET) {
                    param0->destVarItemQty[param0->unk_0E] = 1;
                } else {
                    param0->destVarItemQty[param0->unk_0E] = 3;
                }

                param0->unk_0F = ov111_021D2D14(param0) == TRUE ? 30 : 0;

                ov111_021D255C(param0);
                param0->subState = 4;
                return 0;
            }

            if (param0->unk_40D >= 3) {
                Sound_StopEffect(1358, 0);
                param0->unk_0F = 60;
                ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, TRUE);
                ov111_021D25BC(param0);
                param0->subState = 7;
                return 0;
            }
        } else {
            Sound_StopEffect(1358, 0);
        }

        if (param0->unk_40C_0 == 1) {
            ov111_021D2B20(param0);
        }

        if (param0->unk_0E == (3 - 1)) {
            if (TouchScreen_CheckRectanglePressed(sCancelTouchRects) != TOUCHSCREEN_INPUT_NONE) {
                ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, TRUE);
                ov111_021D2494(param0);

                Sound_PlayEffect(SEQ_SE_DP_BUTTON9_sseq);

                ScratchOffCardsSprite_SetAnimID(param0->unk_3A0, anim_id_0);
                ov111_021D1F70(param0);
                ov111_021D1F84(param0);
                param0->subState = 10;
                break;
            }
        } else {
            if (TouchScreen_CheckRectanglePressed(sNextCardTouchRects) != TOUCHSCREEN_INPUT_NONE) {
                ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, TRUE);
                ov111_021D2494(param0);

                Sound_PlayEffect(SEQ_SE_DP_BUTTON9_sseq);

                ScratchOffCardsSprite_SetAnimID(param0->unk_3A0, anim_id_1);
                ov111_021D1F70(param0);
                ov111_021D1F84(param0);
                param0->subState = 9;
                break;
            }
        }
        break;
    case 4:
        if (param0->unk_0F == 0) {
            if (ov111_021D2D60(param0, 0) == 0) {
                param0->subState = 5;
            }
        } else {
            param0->unk_0F--;
        }
        break;
    case 5:
        if (ov111_021D2D60(param0, 1) == 0) {
            param0->unk_0F = 0;
            param0->subState = 6;
        }
        break;
    case 6:
        if (ScratchOffCardsSprite_IsAnimated(param0->unk_3C0) == TRUE) {
            break;
        }

        if (param0->unk_0F == 0) {
            for (v0 = 0; v0 < 3; v0++) {
                ScratchOffCardsSprite_SetDrawFlag(param0->unk_3B4[v0], FALSE);
            }

            ScratchOffCardsSprite_SetDrawFlag(param0->unk_3C0, FALSE);
            ov111_021D2E20(param0);
            ov111_021D2E28(param0);
            return 1;
        } else {
            param0->unk_0F--;
        }
        break;
    case 7:
        if (param0->unk_0F == 0) {
            GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, FALSE);
            ov111_021D2E20(param0);
            ov111_021D2E28(param0);
            param0->unk_0F = 30;
            param0->subState = 8;
        } else {
            param0->unk_0F--;
        }
        break;
    case 8:
        if (param0->unk_0F == 0) {
            return 1;
        } else {
            param0->unk_0F--;
        }
        break;
    case 9:
        yesNoResult = YesNoTouchMenu_ProcessInputInstant(param0->yesNoMenu);

        if (yesNoResult == YES_NO_TOUCH_MENU_YES) {
            ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, FALSE);
            Window_EraseStandardFrame(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING], 0);
            Window_ClearAndCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING]);
            ov111_021D2E20(param0);
            ov111_021D1FB4(param0);
            return 1;
        } else if (yesNoResult == YES_NO_TOUCH_MENU_NO) {
            ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, FALSE);
            Window_EraseStandardFrame(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING], 0);
            Window_ClearAndCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING]);
            ov111_021D1FB4(param0);
            param0->subState = 11;
        }
        break;
    case 10:
        yesNoResult = YesNoTouchMenu_ProcessInputInstant(param0->yesNoMenu);

        if (yesNoResult == YES_NO_TOUCH_MENU_YES) {
            ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, FALSE);
            Window_EraseStandardFrame(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING], 0);
            Window_ClearAndCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING]);
            ov111_021D2E18(param0);
            ov111_021D1FB4(param0);
            return 1;
        } else if (yesNoResult == YES_NO_TOUCH_MENU_NO) {
            ScratchOffCardsSprite_SetAnimate(param0->unk_3A0, FALSE);
            Window_EraseStandardFrame(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING], 0);
            Window_ClearAndCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING]);
            ov111_021D1FB4(param0);
            param0->subState = 11;
        }
        break;
    case 11:
        if (TouchScreen_Touched() == 0) {
            param0->subState = 3;
        }
        break;
    }

    return 0;
}

static BOOL ov111_021D1980(TheStruct *param0)
{
    int v0, v1;

    v1 = param0->unk_15[param0->unk_0E - 1];

    switch (param0->subState) {
    case 0:
        GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, FALSE);
        GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, FALSE);
        ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A0, FALSE);

        param0->unk_10 = 0;
        param0->unk_12 = 0;

        Sound_PlayEffect(SEQ_SE_PL_SYU03_sseq);

        param0->subState = 1;
        break;

    case 1:
        Bg_SetOffset(param0->bgConfig, BG_LAYER_SUB_2, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        Bg_SetOffset(param0->bgConfig, BG_LAYER_MAIN_0, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        Bg_SetOffset(param0->bgConfig, BG_LAYER_MAIN_1, BG_OFFSET_UPDATE_SET_X, param0->unk_12);
        param0->unk_12 += -16;

        if (param0->unk_10 >= 256) {
            param0->subState = 2;
        } else {
            for (v0 = 0; v0 < 4; v0++) {
                ov111_021D3474(param0->unk_35C[v0], 60 + param0->unk_10, 26 + (v0 * 42));
            }

            for (v0 = 0; v0 < 3; v0++) {
                ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A8[v0], FALSE);
            }

            for (v0 = 0; v0 < 9; v0++) {
                ov111_021D3474(param0->unk_36C[v0], Unk_ov111_021D3770[v0].x + param0->unk_10, Unk_ov111_021D3770[v0].y);
            }
        }

        param0->unk_10 += 16;
        break;

    case 2:
        param0->unk_10 = 0;
        param0->unk_12 = 0;
        return 1;
    }

    return 0;
}

static BOOL ov111_021D1A88(TheStruct *param0)
{
    int v0;

    switch (param0->subState) {
    case 0:
        param0->unk_0D = 10;
        param0->subState++;
        break;
    case 1:
        param0->unk_0D--;

        if (param0->unk_0D == 0) {
            Window_EraseMessageBox(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING], FALSE);
            StartScreenFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, COLOR_BLACK, 6, 1, HEAP_ID_SCRATCH_OFF_CARDS);
            param0->subState++;
        }
        break;
    case 2:
        if (IsScreenFadeDone() == TRUE) {
            return 1;
        }
        break;
    }

    return 0;
}

static void ov111_021D1AF4(TheStruct *param0)
{
    for (int i = 0; i < 3; i++) {
        param0->unk_3A8[i] = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_3, anim_id_2, Unk_ov111_021D3770[i].x, Unk_ov111_021D3770[i].y, FALSE, 2, 10 + 1);

        ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A8[i], FALSE);
    }
}

static void ov111_021D1B44(TheStruct *param0)
{
    for (int i = 0; i < 3; i++) {
        param0->unk_3B4[i] = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_1, anim_id_0, Unk_ov111_021D3620[i].x, Unk_ov111_021D3620[i].y, FALSE, 0, 0);
        ScratchOffCardsSprite_SetDrawFlag(param0->unk_3B4[i], FALSE);
    }
}

static void ov111_021D1B90(TheStruct *param0)
{
    param0->unk_3A0 = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_3, anim_id_1, Unk_ov111_021D3604.x, Unk_ov111_021D3604.y, FALSE, 1, 0);
    ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A0, FALSE);

    param0->unk_3A4 = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_3, anim_id_3, Unk_ov111_021D360C.x, Unk_ov111_021D360C.y, FALSE, 1, 0);
    ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, FALSE);
}

static void ov111_021D1BEC(TheStruct *param0)
{
    for (int i = 0; i < 4; i++) {
        if (param0->unk_390[i] != NULL) {
            ScratchOffCardsSprite_Delete(param0->unk_390[i]);
        }
    }
}

static void ov111_021D1C0C(TheStruct *param0)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (param0->unk_35C[i] != NULL) {
            ScratchOffCardsSprite_Delete(param0->unk_35C[i]);
        }
    }

    for (i = 0; i < 9; i++) {
        if (param0->unk_36C[i] != NULL) {
            ScratchOffCardsSprite_Delete(param0->unk_36C[i]);
        }
    }

    if (param0->unk_3A0 != NULL) {
        ScratchOffCardsSprite_Delete(param0->unk_3A0);
    }

    if (param0->unk_3A4 != NULL) {
        ScratchOffCardsSprite_Delete(param0->unk_3A4);
    }

    for (i = 0; i < 3; i++) {
        if (param0->unk_3A8[i] != NULL) {
            ScratchOffCardsSprite_Delete(param0->unk_3A8[i]);
        }
    }

    for (i = 0; i < 3; i++) {
        if (param0->unk_3B4[i] != NULL) {
            ScratchOffCardsSprite_Delete(param0->unk_3B4[i]);
        }
    }

    if (param0->unk_3C0 != NULL) {
        ScratchOffCardsSprite_Delete(param0->unk_3C0);
    }

    Font_Free(FONT_SUBSCREEN);
    PaletteData_FreeBuffer(param0->paletteData, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffer(param0->paletteData, PLTTBUF_MAIN_BG);
    PaletteData_Free(param0->paletteData);

    param0->paletteData = NULL;

    ov111_021D3320(&param0->unk_16C);

    sub_02015760(param0->unk_34);
    MessageLoader_Free(param0->messageLoader);
    StringTemplate_Free(param0->stringTemplate);
    String_Free(param0->displayString);
    String_Free(param0->formatString);
    FontSpecialChars_Free(param0->specialChars);
    Heap_Free(param0->unk_3F0);
    Heap_Free(param0->unk_3F8);

    ScratchOffCards_RemoveWindows(param0->windows);
    ov111_021D2044(param0->bgConfig);

    NARC_dtor(param0->narc);
}

static void ov111_021D1D30(void)
{
    SetVBlankCallback(NULL, NULL);
    SetHBlankCallback(NULL, NULL);
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
}

static void ov111_021D1D68(TheStruct *param0)
{
    param0->narc = NARC_ctor(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, HEAP_ID_SCRATCH_OFF_CARDS);

    ScratchOffCards_InitGraphics(param0);
    ov111_021D2034(param0);

    param0->messageLoader = MessageLoader_Init(MSG_LOADER_LOAD_ON_DEMAND, NARC_INDEX_MSGDATA__PL_MSG, TEXT_BANK_SCRATCH_OFF_CARDS_GAME, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->stringTemplate = StringTemplate_Default(HEAP_ID_SCRATCH_OFF_CARDS);
    param0->displayString = String_Init(600, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->formatString = String_Init(600, HEAP_ID_SCRATCH_OFF_CARDS);

    Font_LoadTextPalette(PAL_LOAD_MAIN_BG, PLTT_OFFSET(13), HEAP_ID_SCRATCH_OFF_CARDS);
    Font_LoadTextPalette(PAL_LOAD_SUB_BG, PLTT_OFFSET(13), HEAP_ID_SCRATCH_OFF_CARDS);
    Font_LoadScreenIndicatorsPalette(PAL_LOAD_MAIN_BG, PLTT_OFFSET(12), HEAP_ID_SCRATCH_OFF_CARDS);
    Font_LoadScreenIndicatorsPalette(PAL_LOAD_SUB_BG, PLTT_OFFSET(12), HEAP_ID_SCRATCH_OFF_CARDS);
    Font_InitManager(FONT_SUBSCREEN, HEAP_ID_SCRATCH_OFF_CARDS);

    param0->specialChars = FontSpecialChars_Init(15, 14, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    ScratchOffCards_AddWindows(param0->bgConfig, param0->windows);
    param0->unk_34 = sub_0201567C(NULL, 1, 12, HEAP_ID_SCRATCH_OFF_CARDS);

    ov111_021D2E4C(param0);
    ov111_021D2E8C(param0);
    ov111_021D2EB4(param0);

    GXLayers_TurnBothDispOn();

    int v0;

    for (v0 = 0; v0 < 4; v0++) {
        param0->unk_35C[v0] = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_0, v0, 60, 26 + (v0 * 42), TRUE, 0, 0);
        ScratchOffCardsSprite_SetDrawFlag(param0->unk_35C[v0], FALSE);
    }

    for (v0 = 0; v0 < 9; v0++) {
        param0->unk_36C[v0] = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_1, anim_id_0, Unk_ov111_021D3770[v0].x, Unk_ov111_021D3770[v0].y, FALSE, 2, 10);
        ScratchOffCardsSprite_SetDrawFlag(param0->unk_36C[v0], FALSE);
    }

    ov111_021D1B90(param0);

    for (v0 = 0; v0 < 4; v0++) {
        param0->unk_390[v0] = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_2, v0, Unk_ov111_021D362C[v0].x, Unk_ov111_021D362C[v0].y, FALSE, 1, 0);

        ov111_021D3474(param0->unk_390[v0], Unk_ov111_021D362C[v0].x - 256, Unk_ov111_021D362C[v0].y);
        ScratchOffCardsSprite_SetPriority(param0->unk_390[v0], 20 + v0);
    }

    param0->unk_3C0 = ScratchOffCardsSprite_New(&param0->unk_16C, res_id_4, anim_id_0, Unk_ov111_021D3608.x, Unk_ov111_021D3608.y, FALSE, 0, 10);
    ScratchOffCardsSprite_SetDrawFlag(param0->unk_3C0, FALSE);

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    EnableTouchPad();
    InitializeTouchPad(1);
    SetVBlankCallback(ov111_021D2090, (void *)param0);
}

static void ov111_021D1F70(TheStruct *param0)
{
    param0->yesNoMenu = YesNoTouchMenu_New(HEAP_ID_SCRATCH_OFF_CARDS);
}

static void ov111_021D1F84(TheStruct *param0)
{
    YesNoTouchMenuParams params;

    params.bgConfig = param0->bgConfig;
    params.bgLayer = BG_LAYER_MAIN_2;
    params.baseTile = (1024 - 128);
    params.palette = 10;
    params.tilemapLeft = 24;
    params.tilemapTop = 8;

    YesNoTouchMenu_InitWithParams(param0->yesNoMenu, &params);
}

static void ov111_021D1FB4(TheStruct *param0)
{
    YesNoTouchMenu_Free(param0->yesNoMenu);
}

static void ScratchOffCards_InitGraphics(TheStruct *param0)
{
    ScratchOffCards_SetVRAMBanks();
    ScratchOffCards_InitBgs(param0->bgConfig);

    param0->paletteData = PaletteData_New(HEAP_ID_SCRATCH_OFF_CARDS);

    PaletteData_AllocBuffer(param0->paletteData, PLTTBUF_MAIN_OBJ, PALETTE_SIZE_BYTES * SLOTS_PER_PALETTE, HEAP_ID_SCRATCH_OFF_CARDS);
    PaletteData_AllocBuffer(param0->paletteData, PLTTBUF_MAIN_BG, PALETTE_SIZE_BYTES * SLOTS_PER_PALETTE, HEAP_ID_SCRATCH_OFF_CARDS);

    ov111_021D2248(param0, BG_LAYER_SUB_3);
    ScratchOffCards_LoadSubScreenPalette();
    ov111_021D228C(param0, BG_LAYER_SUB_2);
    ov111_021D233C(param0, BG_LAYER_MAIN_1);
    ScratchOffCards_LoadMainScreenPalette();
    ov111_021D2380(param0, BG_LAYER_MAIN_0);

    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG2, FALSE);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0, FALSE);
}

static void ov111_021D2034(TheStruct *param0)
{
    ov111_021D2F80(&param0->unk_16C);
}

static void ov111_021D2044(BgConfig *bgConfig)
{
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ, FALSE);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ, FALSE);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_SUB_3);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_SUB_2);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_SUB_0);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_MAIN_1);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_MAIN_0);
    Bg_FreeTilemapBuffer(bgConfig, BG_LAYER_MAIN_2);
    Heap_Free(bgConfig);
}

static void ov111_021D2090(void *param0)
{
    TheStruct *v0 = param0;

    if (v0->unk_04 != NULL) {
        return;
    }

    if (v0->paletteData != NULL) {
        PaletteData_CommitFadedBuffers(v0->paletteData);
    }

    Bg_RunScheduledUpdates(v0->bgConfig);
    VramTransfer_Process();
    RenderOam_Transfer();

    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void ScratchOffCards_SetVRAMBanks(void)
{
    GXBanks banks = {
        GX_VRAM_BG_128_A,
        GX_VRAM_BGEXTPLTT_NONE,
        GX_VRAM_SUB_BG_128_C,
        GX_VRAM_SUB_BGEXTPLTT_NONE,
        GX_VRAM_OBJ_128_B,
        GX_VRAM_OBJEXTPLTT_NONE,
        GX_VRAM_SUB_OBJ_16_I,
        GX_VRAM_SUB_OBJEXTPLTT_NONE,
        GX_VRAM_TEX_NONE,
        GX_VRAM_TEXPLTT_NONE
    };

    GXLayers_SetBanks(&banks);
}

static void ScratchOffCards_InitBgs(BgConfig *bgConfig)
{
    GraphicsModes graphicsModes = {
        GX_DISPMODE_GRAPHICS,
        GX_BGMODE_0,
        GX_BGMODE_0,
        GX_BG0_AS_2D,
    };

    SetAllGraphicsModes(&graphicsModes);

    BgTemplate template1 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x1000,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x0000,
        .charBase = GX_BG_CHARBASE_0x04000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 0,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_SUB_0, &template1, BG_TYPE_STATIC);
    Bg_ClearTilesRange(4, 32, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Bg_ClearTilemap(bgConfig, BG_LAYER_SUB_0);

    BgTemplate template2 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x1000,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x1000,
        .charBase = GX_BG_CHARBASE_0x0c000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 3,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_SUB_3, &template2, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_SUB_3);

    BgTemplate template3 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x1000,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_512x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x3000,
        .charBase = GX_BG_CHARBASE_0x14000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 2,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_SUB_2, &template3, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_SUB_2);

    BgTemplate template4 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x1000,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_512x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x0000,
        .charBase = GX_BG_CHARBASE_0x04000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 2,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_MAIN_1, &template4, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_MAIN_1);

    BgTemplate template5 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x1000,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_512x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x1000,
        .charBase = GX_BG_CHARBASE_0x0c000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 1,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_MAIN_0, &template5, BG_TYPE_STATIC);
    Bg_ClearTilemap(bgConfig, BG_LAYER_MAIN_0);

    BgTemplate template6 = {
        .x = 0,
        .y = 0,
        .bufferSize = 0x800,
        .baseTile = 0,
        .screenSize = BG_SCREEN_SIZE_256x256,
        .colorMode = GX_BG_COLORMODE_16,
        .screenBase = GX_BG_SCRBASE_0x2000,
        .charBase = GX_BG_CHARBASE_0x14000,
        .bgExtPltt = GX_BG_EXTPLTT_01,
        .priority = 0,
        .areaOver = 0,
        .mosaic = FALSE,
    };

    Bg_InitFromTemplate(bgConfig, BG_LAYER_MAIN_2, &template6, BG_TYPE_STATIC);
    Bg_ClearTilesRange(BG_LAYER_MAIN_2, 32, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Bg_ClearTilemap(bgConfig, BG_LAYER_MAIN_2);

    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, FALSE);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG1, FALSE);
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG2, FALSE);
}

static void ov111_021D2248(TheStruct *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->narc, sco_member_00035_NCGR, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->narc, sco_member_00037_NSCR, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
}

static void ov111_021D228C(TheStruct *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->narc, sco_member_00038_NCGR, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->narc, sco_member_00040_NSCR, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
}

static void ScratchOffCards_LoadSubScreenPalette(void)
{
    NNSG2dPaletteData *plttData;
    void *palette = Graphics_GetPlttData(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_top_screen_00034_NCLR, &plttData, HEAP_ID_SCRATCH_OFF_CARDS);
    DC_FlushRange(plttData->pRawData, sizeof(u16) * 16 * 5);
    GXS_LoadBGPltt(plttData->pRawData, 0, sizeof(u16) * 16 * 5);
    Heap_Free(palette);
}

static void ScratchOffCards_LoadMainScreenPalette(void)
{
    NNSG2dPaletteData *plttData;
    void *palette = Graphics_GetPlttData(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_bottom_screen_00000_NCLR, &plttData, HEAP_ID_SCRATCH_OFF_CARDS);
    DC_FlushRange(plttData->pRawData, sizeof(u16) * 16 * 9);
    GX_LoadBGPltt(plttData->pRawData, 0, sizeof(u16) * 16 * 10);
    Heap_Free(palette);
}

static void ov111_021D233C(TheStruct *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->narc, sco_member_00004, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->narc, sco_member_00006, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
}

static void ov111_021D2380(TheStruct *param0, u32 param1)
{
    Graphics_LoadTilesToBgLayerFromOpenNARC(param0->narc, sco_member_00007_NCGR, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
    Graphics_LoadTilemapToBgLayerFromOpenNARC(param0->narc, sco_member_00009_NSCR, param0->bgConfig, param1, 0, 0, 0, HEAP_ID_SCRATCH_OFF_CARDS);
}

static u8 ScratchOffCards_PrintMessage(TheStruct *param0, Window *window, int entryID, u32 xOffset, u32 yOffset, u32 renderDelay, u8 fgColor, u8 shadowColor, u8 bgColor, u8 fontID)
{
    Window_FillTilemap(window, bgColor);
    MessageLoader_GetString(param0->messageLoader, entryID, param0->formatString);
    StringTemplate_Format(param0->stringTemplate, param0->displayString, param0->formatString);

    return Text_AddPrinterWithParamsAndColor(window, fontID, param0->displayString, xOffset, yOffset, renderDelay, TEXT_COLOR(fgColor, shadowColor, bgColor), NULL);
}

static u8 ScratchOffCards_PrintMessageAlignCenter(TheStruct *param0, Window *window, int entryID, u32 xOffset, u32 yOffset, u32 renderDelay, u8 fgColor, u8 shadowColor, u8 bgColor, u8 fontID)
{
    Window_FillTilemap(window, bgColor);
    MessageLoader_GetString(param0->messageLoader, entryID, param0->formatString);
    StringTemplate_Format(param0->stringTemplate, param0->displayString, param0->formatString);
    xOffset -= (Font_CalcStringWidth(fontID, param0->displayString, 0) + 1) / 2;
    return Text_AddPrinterWithParamsAndColor(window, fontID, param0->displayString, xOffset, yOffset, renderDelay, TEXT_COLOR(fgColor, shadowColor, bgColor), NULL);
}

static u8 ov111_021D2494(TheStruct *param0)
{
    ScratchOffCards_DrawWindow(param0->bgConfig, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING]);
    u8 textPrinterID = ScratchOffCards_PrintMessage(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING], ScratchOffCardsGame_Text_StopScratching, 1, 1, TEXT_SPEED_INSTANT, 1, 2, 15, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_STOP_SCRATCHING]);
    return textPrinterID;
}

static u8 ov111_021D24D4(TheStruct *param0)
{
    ov111_021D26CC(param0, 0, param0->unk_0E + 1);
    u8 textPrinterID = ScratchOffCards_PrintMessage(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_TEXTBOX], ScratchOffCardsGame_Text_PleaseSelect, 1, 1, TEXT_SPEED_INSTANT, 1, 2, 15, FONT_MESSAGE);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_TEXTBOX]);
    return textPrinterID;
}

static u8 ov111_021D2518(TheStruct *param0)
{
    ov111_021D26CC(param0, 0, param0->unk_0E + 1);
    u8 textPrinterID = ScratchOffCards_PrintMessageAlignCenter(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO], ScratchOffCardsGame_Text_StartCard, 8 * 6, 1 + 4, TEXT_SPEED_INSTANT, 1, 2, 0, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO]);
    return textPrinterID;
}

static u8 ov111_021D255C(TheStruct *param0)
{
    for (u8 i = 0; i < 3; i++) {
        ScratchOffCardsSprite_SetAnimID(param0->unk_3B4[i], param0->unk_3C4[param0->unk_40E[i]]);
        ScratchOffCardsSprite_SetDrawFlag(param0->unk_3B4[i], TRUE);
    }

    ScratchOffCardsSprite_SetDrawFlag(param0->unk_3C0, TRUE);
    ScratchOffCardsSprite_SetAnimate(param0->unk_3C0, TRUE);

    Sound_PlayEffect(SEQ_SE_PL_CALL_sseq);

    return 0;
}

static u8 ov111_021D25BC(TheStruct *param0)
{
    Sound_PlayEffect(SEQ_SE_DP_BOX03_sseq);
    u8 textPrinterID = ScratchOffCards_PrintMessageAlignCenter(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_TOO_BAD], ScratchOffCardsGame_Text_TooBad, 8 * 6, 1 + 4, TEXT_SPEED_INSTANT, 1, 2, 0, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_TOO_BAD]);
    return textPrinterID;
}

static u8 ov111_021D2604(TheStruct *param0)
{
    u8 textPrinterID = ScratchOffCards_PrintMessageAlignCenter(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_NEXT_CARD], ScratchOffCardsGame_Text_NextCard, 8 * 6, 1, TEXT_SPEED_INSTANT, 1, 1, 0, FONT_SUBSCREEN);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_NEXT_CARD]);
    return textPrinterID;
}

static u8 ov111_021D263C(TheStruct *param0)
{
    u8 textPrinterID = ScratchOffCards_PrintMessageAlignCenter(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_CANCEL], ScratchOffCardsGame_Text_Cancel, 8 * 3, 1, TEXT_SPEED_INSTANT, 1, 1, 0, FONT_SUBSCREEN);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_CANCEL]);
    return textPrinterID;
}

static const u8 sOffsetY[4] = { 10, 12, 6, 8 };

static u8 ov111_021D2674(TheStruct *param0, u8 param1)
{
    StringTemplate_SetItemName(param0->stringTemplate, 0, param0->prizes[param1]);
    u8 textPrinterID = ScratchOffCards_PrintMessageAlignCenter(param0, &param0->windows[SCRATCH_OFF_CARDS_WINDOW_PRIZE_NAME_0 + param1], pl_msg_00000540_00001, 8 * 6 - 4, sOffsetY[param1], TEXT_SPEED_INSTANT, 1, 2, 0, FONT_SYSTEM);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_PRIZE_NAME_0 + param1]);
    return textPrinterID;
}

static void ov111_021D26CC(TheStruct *param0, u32 index, s32 number)
{
    StringTemplate_SetNumber(param0->stringTemplate, index, number, 1, PADDING_MODE_NONE, CHARSET_MODE_EN);
}

static void ScratchOffCards_ChangeState(TheStruct *param0, int *state, int newState)
{
    param0->subState = 0;
    *state = newState;
}

static void ov111_021D26EC(TheStruct *param0)
{
    for (int i = 0; i < 2; i++) {
        while (TRUE) {
            u8 slot = LCRNG_Next() % NUMBER_OF_SLOTS;

            if (param0->unk_3C4[slot] == 176) {
                param0->unk_3C4[slot] = 4;
                break;
            }
        }
    }
}

static void ov111_021D271C(TheStruct *param0)
{
    int v0, v2, v3, slot;
    u8 v5 = LCRNG_Next() % 4;
    v3 = 0;

    for (v0 = 0; v0 < NUMBER_OF_SLOTS; v0++) {
        while (TRUE) {
            slot = LCRNG_Next() % NUMBER_OF_SLOTS;

            if (param0->unk_3C4[slot] == 176) {
                v3 = 0;
                param0->unk_3C4[slot] = v5;

                if ((v0 == 2) || (v0 == 4) || (v0 == 6)) {
                    v5++;

                    if (v5 == (5 - 1)) {
                        v5 = 0;
                    }
                }
                break;
            }

            v3++;

            if (v3 >= 30) {
                v3 = 0;

                for (v2 = 0; v2 < NUMBER_OF_SLOTS; v2++) {
                    if (param0->unk_3C4[v2] == 176) {
                        param0->unk_3C4[v2] = v5;

                        if ((v0 == 2) || (v0 == 4) || (v0 == 6)) {
                            v5++;

                            if (v5 == (5 - 1)) {
                                v5 = 0;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
}

// int v0, v2, v3, v4, v5;

static void ov111_021D27AC(TheStruct *param0, u8 unused)
{
    ov111_021D26EC(param0);
    ov111_021D271C(param0);
}

static void ov111_021D27BC(TheStruct *param0)
{
    for (int i = 0; i < NUMBER_OF_SLOTS; i++) {
        param0->unk_3C4[i] = 176;
    }
}

static void ov111_021D27D4(TheStruct *param0, u8 unused)
{
    int i, j;
    u16 prizes[4];

    for (i = 0; i < 4; i++) {
        prizes[i] = 0xff;
    }

    u16 nuggetIndex = LCRNG_Next() % 4;

    for (i = 0; i < 4; i++) {
        if (i == nuggetIndex) {
            param0->prizes[i] = ITEM_NUGGET;
        } else {
            while (TRUE) {
                prizes[i] = LCRNG_Next() % NELEMS(sPrizes);

                for (j = 0; j < i; j++) {
                    if (prizes[j] == prizes[i]) {
                        break;
                    }
                }

                if (j == i) {
                    param0->prizes[i] = sPrizes[prizes[i]];
                    break;
                }
            }
        }
    }
}

static const s8 Unk_ov111_021D3708[4][8] = {
    { 9, 9, 9, 8, 7, 6, 5, 4 },
    { 2, 2, 2, 1, 1, 1, 1, 1 },
    { -8, -8, -8, -7, -7, -6, -5, -4 },
    { -18, -16, -15, -14, -13, -12, -10, -8 }
};

static const s8 Unk_ov111_021D3818[8] = { -4, -4, -4, -4, -4, -4, -4, -4 };

static BOOL ov111_021D2868(TheStruct *param0, u8 param1)
{
    if (param0->unk_40C_1 >= 8) {
        return TRUE;
    }

    int x, y;
    ov111_021D349C(param0->unk_390[param1], &x, &y);

    int v2 = x + Unk_ov111_021D3708[param1][param0->unk_40C_1];
    int v3 = y + Unk_ov111_021D3818[param0->unk_40C_1];
    param0->unk_40C_1++;

    ov111_021D3474(param0->unk_390[param1], v2, v3);

    return FALSE;
}

static void ov111_021D28E8(TheStruct *param0, u32 bgLayer, u8 palette, u8 width, u8 height)
{
    Bg_ChangeTilemapRectPalette(param0->bgConfig, bgLayer, 0, 0, width, height, palette);
    Bg_ScheduleTilemapTransfer(param0->bgConfig, bgLayer);
}

static u8 ov111_021D2918(TheStruct *param0)
{
    u8 i, v1 = 0;

    for (i = 0; i < 9; i++) {
        if (param0->unk_400[i] == 1) {
            v1++;
        }
    }

    return v1;
}

static void ov111_021D2940(TheStruct *param0)
{
    for (u8 i = 0; i < 9; i++) {
        param0->unk_400[i] = 0;
    }
}

static void ov111_021D295C(TheStruct *param0)
{
    for (u8 i = 0; i < 9; i++) {
        param0->unk_411[i] = 0;
    }
}

static void ov111_021D297C(TheStruct *param0, int rectIndex)
{
    for (int i = 0; i < param0->unk_424.bufferSize; i++) {
        int x = param0->unk_424.buffer[i].x;
        int y = param0->unk_424.buffer[i].y;

        if ((Unk_ov111_021D3728[rectIndex].l <= x) && (x <= Unk_ov111_021D3728[rectIndex].r) && (Unk_ov111_021D3728[rectIndex].t <= y) && (y <= Unk_ov111_021D3728[rectIndex].b)) {
            ov111_021D2ECC(param0, x, y);
        }
    }
}

static void ov111_021D29D8(TheStruct *param0)
{
    for (int v0 = 0; v0 < param0->unk_424.bufferSize; v0++) {
        u8 v1 = param0->unk_424.buffer[v0].x;
        u8 v2 = param0->unk_424.buffer[v0].y;

        ov111_021D2A18(param0, v1, v2);
    }
}

static void ov111_021D2A18(TheStruct *param0, int param1, int param2)
{
    for (int v1 = -3; v1 < 3; v1++) {
        for (int v0 = -3; v0 < 3; v0++) {
            if (((param1 + v0) > 0) && ((param1 + v0) < 240) && ((param2 + v1) > 0) && ((param2 + v1) < 160)) {
                param0->unk_466[(param1 + v0) + ((param2 + v1) * 240)] = 1;
            }
        }
    }
}

static BOOL ov111_021D2A68(TheStruct *param0, u8 rectIndex)
{
    int y, x;

    int v4 = 0;
    int v2 = Unk_ov111_021D374C[rectIndex].x;
    int v3 = Unk_ov111_021D374C[rectIndex].y;

    for (y = v3; y < (v3 + 20); y++) {
        for (x = v2; x < (v2 + 25); x++) {
            if (param0->unk_466[y * 240 + x] == 1) {
                v4++;
            }
        }
    }

    if (v4 >= 380) {
        if (param0->unk_411[rectIndex] == 0) {
            Sound_PlayEffect(SEQ_SE_DP_PIRORIRO_sseq);
            param0->unk_40E[param0->unk_40D] = rectIndex;
            param0->unk_40D++;
        }

        param0->unk_411[rectIndex] = 1;
        return TRUE;
    }

    return FALSE;
}

static void ov111_021D2B20(TheStruct *param0)
{
    param0->unk_40A++;

    if (param0->unk_40A >= 1) {
        param0->unk_40A = 0;

        param0->unk_409++;

        if (param0->unk_409 >= 8) {
            param0->unk_409 = 0;
        }

        if (param0->unk_40D == 2) {
            for (int v0 = 0; v0 < 2; v0++) {
                ScratchOffCardsSprite_SetPalette(param0->unk_3A8[v0], 3);
                ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A8[v0], TRUE);
                ov111_021D3474(param0->unk_3A8[v0], Unk_ov111_021D3770[param0->unk_40E[v0]].x + -36, Unk_ov111_021D3770[param0->unk_40E[v0]].y + -10);
            }
        }

        ov111_021D33B0(&param0->unk_16C, param0->unk_409);
    }
}

static BOOL ov111_021D2BBC(TheStruct *param0)
{
    int v0, v1 = 0;

    if (param0->unk_40D <= 1) {
        return FALSE;
    }

    if (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[1]]) {
        param0->unk_40C_0 = 1;
    } else if (param0->unk_3C4[param0->unk_40E[0]] == 4) {
        param0->unk_40C_0 = 1;
    } else if (param0->unk_3C4[param0->unk_40E[1]] == 4) {
        param0->unk_40C_0 = 1;
    }

    if (param0->unk_40D <= 2) {
        return FALSE;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[1]]) && (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[2]])) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == 4) && (param0->unk_3C4[param0->unk_40E[1]] == 4)) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == 4) && (param0->unk_3C4[param0->unk_40E[2]] == 4)) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[1]] == 4) && (param0->unk_3C4[param0->unk_40E[2]] == 4)) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[0]] == 4) && (param0->unk_3C4[param0->unk_40E[1]] == param0->unk_3C4[param0->unk_40E[2]])) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[1]] == 4) && (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[2]])) {
        v1 = 1;
    }

    if ((param0->unk_3C4[param0->unk_40E[2]] == 4) && (param0->unk_3C4[param0->unk_40E[0]] == param0->unk_3C4[param0->unk_40E[1]])) {
        v1 = 1;
    }

    if (v1 == 1) {
        for (v0 = 0; v0 < 3; v0++) {
            if (param0->unk_3C4[param0->unk_40E[v0]] != 4) {
                param0->unk_40B = param0->unk_3C4[param0->unk_40E[v0]];
                break;
            }
        }

        return TRUE;
    }

    return FALSE;
}

static BOOL ov111_021D2D14(TheStruct *param0)
{
    BOOL v1 = FALSE;

    for (int v0 = 0; v0 < 3; v0++) {
        if (param0->unk_3C4[param0->unk_40E[v0]] == 4) {
            ScratchOffCardsSprite_SetMosaic(param0->unk_3B4[v0], TRUE);
            v1 = TRUE;
        }
    }

    param0->unk_14 = 0;

    G2_SetOBJMosaicSize(param0->unk_14, param0->unk_14);

    return v1;
}

static BOOL ov111_021D2D60(TheStruct *param0, u8 param1)
{
    int v0;

    for (v0 = 0; v0 < 3; v0++) {
        if (param0->unk_3C4[param0->unk_40E[v0]] == 4) {
            break;
        }
    }

    if (v0 == 3) {
        return FALSE;
    }

    if (param1 == 0) {
        if (param0->unk_14 == 0) {
            Sound_PlayEffect(SEQ_SE_PL_W100_sseq);
        }

        if (param0->unk_14 < 4) {
            param0->unk_14++;
        } else {
            for (v0 = 0; v0 < 3; v0++) {
                if (param0->unk_3C4[param0->unk_40E[v0]] == 4) {
                    ScratchOffCardsSprite_SetAnimID(param0->unk_3B4[v0], param0->unk_40B);
                }
            }

            return FALSE;
        }
    } else {
        if (param0->unk_14 > 0) {
            param0->unk_14--;
        } else {
            for (v0 = 0; v0 < 3; v0++) {
                ScratchOffCardsSprite_SetMosaic(param0->unk_3B4[v0], FALSE);
            }

            return FALSE;
        }
    }

    G2_SetOBJMosaicSize(param0->unk_14, param0->unk_14);

    return TRUE;
}

static void ov111_021D2E18(TheStruct *param0)
{
    param0->unk_0E++;
}

static void ov111_021D2E20(TheStruct *param0)
{
    param0->unk_0E++;
}

static void ov111_021D2E28(TheStruct *param0)
{
    ScratchOffCardsSprite_SetDrawFlag(param0->unk_3A4, FALSE);
    Window_FillTilemap(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO], 0);
    Window_ScheduleCopyToVRAM(&param0->windows[SCRATCH_OFF_CARDS_WINDOW_START_CARD_NO]);
}

static void ov111_021D2E4C(TheStruct *param0)
{
    param0->unk_3F0 = Graphics_GetCharData(NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00007_NCGR, FALSE, &param0->charData, HEAP_ID_SCRATCH_OFF_CARDS);

    Bg_LoadTiles(param0->bgConfig, BG_LAYER_MAIN_0, param0->charData->pRawData, param0->charData->szByte, 0);
    Bg_CopyTilemapBufferToVRAM(param0->bgConfig, BG_LAYER_MAIN_0);
}

static void ov111_021D2E8C(TheStruct *param0)
{
    param0->unk_3F8 = Heap_Alloc(HEAP_ID_SCRATCH_OFF_CARDS, param0->charData->szByte);

    if (param0->unk_3F8 == NULL) { // necessary for matching
        GF_ASSERT(param0->unk_3F8 != NULL);
    }
}

static void ov111_021D2EB4(TheStruct *param0)
{
    memcpy(param0->unk_3F8, param0->charData->pRawData, param0->charData->szByte);
}

static void ov111_021D2ECC(TheStruct *param0, int x, int y)
{
    for (int dy = -3; dy < 3; dy++) {
        for (int dx = -3; dx < 3; dx++) {
            if (((x + dx) > 0) && ((x + dx) < HW_LCD_WIDTH) && ((y + dy) > 0) && ((y + dy) < HW_LCD_HEIGHT)) {
                ov111_021D2F38(param0, x + dx, y + dy);
            }
        }
    }

    Bg_LoadTiles(param0->bgConfig, BG_LAYER_MAIN_0, param0->unk_3F8, param0->charData->szByte, 0);
    Bg_CopyTilemapBufferToVRAM(param0->bgConfig, BG_LAYER_MAIN_0);
}

static void ov111_021D2F38(TheStruct *param0, u32 x, u32 y)
{
    u8 mask = 0xff;

    if (x % 2 == 0) {
        mask ^= 0xf;
    } else {
        mask ^= 0xf0;
    }

    u32 tileX = (x / 8 * 0x20);
    u32 tileY = (y / 8 * 0x20 * 32);
    u32 offsetX = (x % 8 / 2);
    u32 offsetY;
    if (y < 8) {
        offsetY = (y * 4);
    } else {
        offsetY = ((y % 8) * 4);
    }

    u32 pos = (tileY + tileX + offsetX + offsetY);
    param0->unk_3F8[pos] &= mask;
}
