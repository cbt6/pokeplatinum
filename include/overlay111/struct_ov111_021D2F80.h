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
} UnkStruct_ov111_021D2F80;

#endif // POKEPLATINUM_STRUCT_OV111_021D2F80_H
