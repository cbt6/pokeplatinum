#ifndef POKEPLATINUM_STRUCT_OV111_021D2F80_H
#define POKEPLATINUM_STRUCT_OV111_021D2F80_H

#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_util.h"

typedef struct {
    SpriteList *spriteList;
    G2dRenderer g2dRenderer;
    SpriteResourceCollection *spriteResources[4];
    SpriteResource *unk_1A0[5][4];
    // 0    top screen icons
    // 1    bottom screen icons
    // 2    4 cards
    // 3    button and frames
    // 4    anim when 3 same
} UnkStruct_ov111_021D2F80;

#endif // POKEPLATINUM_STRUCT_OV111_021D2F80_H
