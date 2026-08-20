#ifndef POKEPLATINUM_OV111_021D33F4_H
#define POKEPLATINUM_OV111_021D33F4_H

#include <nitro/fx/fx.h>

#include "overlay111/struct_ov111_021D2F80.h"

typedef struct ScratchOffCardsSprite {
    u16 unused0;
    u8 onSubScreen;
    u8 unused1;
    u64 unused2;
    Sprite *sprite;
} ScratchOffCardsSprite;

ScratchOffCardsSprite *ScratchOffCardsSprite_New(UnkStruct_ov111_021D2F80 *param0, u32 resourceID, u32 animID, u16 x, u16 y, u8 onSubScreen, u32 resourcePriority, u32 priority);
void *ScratchOffCardsSprite_Delete(ScratchOffCardsSprite *sprite);
void ScratchOffCardsSprite_SetDrawFlag(ScratchOffCardsSprite *sprite, BOOL draw);
void ScratchOffCardsSprite_SetPriority(ScratchOffCardsSprite *sprite, u32 priority);
void ScratchOffCardsSprite_SetPosition(ScratchOffCardsSprite *sprite, int x, int y);
void ScratchOffCardsSprite_GetPosition(ScratchOffCardsSprite *sprite, int *x, int *y);
void ScratchOffCardsSprite_SetAnimID(ScratchOffCardsSprite *sprite, u32 animID);
void ScratchOffCardsSprite_ResetAffineScale(ScratchOffCardsSprite *sprite, u32 unused);
void ScratchOffCardsSprite_SetAffineScale(ScratchOffCardsSprite *sprite, VecFx32 *scale);
void ScratchOffCardsSprite_SetPalette(ScratchOffCardsSprite *sprite, u32 palette);
void ScratchOffCardsSprite_SetAnimate(ScratchOffCardsSprite *sprite, BOOL animate);
void ScratchOffCardsSprite_SetMosaic(ScratchOffCardsSprite *sprite, BOOL mosaic);
BOOL ScratchOffCardsSprite_IsAnimated(ScratchOffCardsSprite *sprite);

#endif // POKEPLATINUM_OV111_021D33F4_H
