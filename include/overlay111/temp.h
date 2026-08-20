#include "overlay111/ov111_021D33F4.h"
#include "overlay111/ov111_021D3548.h"

#include "font_special_chars.h"
#include "game_options.h"
#include "message.h"
#include "overlay_manager.h"
#include "string_template.h"
#include "touch_pad.h"
#include "unk_0201567C.h"
#include "yes_no_touch_menu.h"

#define NUMBER_OF_SLOTS 9

enum SelectCard {
    SELECT_CARD_BLUE,
    SELECT_CARD_PINK,
    SELECT_CARD_YELLOW,
    SELECT_CARD_GREEN,
    MAX_SELECT_CARD,
};

typedef struct TheStruct {
    ApplicationManager *unk_00;
    ApplicationManager *unk_04;
    u8 subState;
    u8 dummy_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D;
    u8 currentSelectCardIndex;
    u8 timer;
    s16 unk_10;
    s16 unk_12;
    u8 unk_14;
    u8 selectedCards[MAX_SELECT_CARD];
    u8 unk_19[3];
    VecFx32 unk_1C;
    VecFx32 unk_28;
    PaletteAnimator *unk_34;
    MessageLoader *messageLoader;
    StringTemplate *stringTemplate;
    String *displayString;
    String *formatString;
    u16 unk_48[8];
    BgConfig *bgConfig;
    Window windows[MAX_SCRATCH_OFF_CARDS_WINDOW];
    PaletteData *paletteData;
    FontSpecialCharsContext *specialChars;
    Options *options;
    SaveData *saveData;
    UnkStruct_ov111_021D2F80 unk_16C;
    ScratchOffCardsSprite *unk_35C[4];
    ScratchOffCardsSprite *unk_36C[9];
    ScratchOffCardsSprite *selectCards[MAX_SELECT_CARD];
    ScratchOffCardsSprite *unk_3A0;
    ScratchOffCardsSprite *unk_3A4;
    ScratchOffCardsSprite *unk_3A8[3];
    ScratchOffCardsSprite *unk_3B4[3];
    ScratchOffCardsSprite *unk_3C0;
    u8 unk_3C4[NUMBER_OF_SLOTS];
    u16 prizes[4];
    u16 *unk_3D8;
    u16 *destVarItemId;
    u16 *destVarItemQty;
    NARC *narc;
    u8 padding_3E8[8];
    void *unk_3F0;
    NNSG2dCharacterData *charData;
    u8 *unk_3F8;
    YesNoTouchMenu *yesNoMenu;
    u8 unk_400[9];
    u8 unk_409;
    u8 unk_40A;
    u8 unk_40B;
    u8 unk_40C_0 : 1;
    u8 unk_40C_1 : 7;
    u8 unk_40D;
    u8 unk_40E[3];
    u8 unk_411[9];
    u32 unk_41C;
    u32 unk_420;
    TouchPadDataBuffer unk_424;
    u8 unk_466[38400];
} TheStruct;
