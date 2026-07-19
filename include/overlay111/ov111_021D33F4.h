#ifndef POKEPLATINUM_OV111_021D33F4_H
#define POKEPLATINUM_OV111_021D33F4_H

#include <nitro/fx/fx.h>

#include "overlay111/struct_ov111_021D2F80.h"

typedef struct UnkStruct_ov111_021D33F4 {
    u16 unk_00;
    u8 onSubScreen;
    u8 unk_03;
    u32 unk_04;
    u32 unk_08;
    Sprite *sprite;
} UnkStruct_ov111_021D33F4;

UnkStruct_ov111_021D33F4 *ov111_021D33F4(UnkStruct_ov111_021D2F80 *param0, u32 resourceID, u32 animID, u16 x, u16 y, u8 onSubScreen, u32 resourcePriority, u32 priority);
void *ov111_021D3448(UnkStruct_ov111_021D33F4 *param0);
void ov111_021D345C(UnkStruct_ov111_021D33F4 *param0, BOOL draw);
void ov111_021D3468(UnkStruct_ov111_021D33F4 *param0, u32 param1);
void ov111_021D3474(UnkStruct_ov111_021D33F4 *param0, int param1, int param2);
void ov111_021D349C(UnkStruct_ov111_021D33F4 *param0, int *param1, int *param2);
void ov111_021D34C4(UnkStruct_ov111_021D33F4 *param0, u32 param1);
void ov111_021D34E0(UnkStruct_ov111_021D33F4 *param0, u32 param1);
void ov111_021D34F4(UnkStruct_ov111_021D33F4 *param0, VecFx32 *scale);
void ov111_021D3500(UnkStruct_ov111_021D33F4 *param0, u32 param1);
void ov111_021D350C(UnkStruct_ov111_021D33F4 *param0, BOOL animate);
void ov111_021D3530(UnkStruct_ov111_021D33F4 *param0, BOOL mosaic);
BOOL ov111_021D353C(UnkStruct_ov111_021D33F4 *param0);

#endif // POKEPLATINUM_OV111_021D33F4_H
