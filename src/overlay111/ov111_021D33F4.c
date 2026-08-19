#include "overlay111/ov111_021D33F4.h"

#include <nitro.h>
#include <string.h>

#include "overlay111/ov111_021D2F80.h"
#include "overlay111/sco_narc_members.h"
#include "overlay111/struct_ov111_021D2F80.h"

#include "heap.h"
#include "sprite.h"

ScratchOffCardsSprite *ScratchOffCardsSprite_New(UnkStruct_ov111_021D2F80 *param0, u32 resourceID, u32 animID, u16 x, u16 y, u8 onSubScreen, u32 resourcePriority, u32 priority)
{
    ScratchOffCardsSprite *sprite = Heap_Alloc(HEAP_ID_SCRATCH_OFF_CARDS, sizeof(ScratchOffCardsSprite));
    memset(sprite, 0, sizeof(ScratchOffCardsSprite));
    sprite->sprite = ov111_021D3280(param0, resourceID, animID, resourcePriority, priority, onSubScreen);
    sprite->onSubScreen = onSubScreen;

    ov111_021D3474(sprite, x, y);

    return sprite;
}

void *ScratchOffCardsSprite_Delete(ScratchOffCardsSprite *sprite)
{
    Sprite_Delete(sprite->sprite);
    Heap_Free(sprite);
    return NULL;
}

void ScratchOffCardsSprite_SetDrawFlag(ScratchOffCardsSprite *sprite, BOOL draw)
{
    Sprite_SetDrawFlag(sprite->sprite, draw);
}

void ScratchOffCardsSprite_SetPriority(ScratchOffCardsSprite *sprite, u32 priority)
{
    Sprite_SetPriority(sprite->sprite, priority);
}

void ov111_021D3474(ScratchOffCardsSprite *sprite, int x, int y)
{
    VecFx32 pos;

    pos.x = x * FX32_ONE;
    pos.y = y * FX32_ONE;

    if (sprite->onSubScreen == TRUE) {
        pos.y += 512 * FX32_ONE;
    }

    Sprite_SetPosition(sprite->sprite, &pos);
}

void ov111_021D349C(ScratchOffCardsSprite *sprite, int *x, int *y)
{
    const VecFx32 *pos = Sprite_GetPosition(sprite->sprite);

    *x = pos->x / FX32_ONE;
    *y = pos->y / FX32_ONE;
}

void ScratchOffCardsSprite_SetAnimID(ScratchOffCardsSprite *sprite, u32 animID)
{
    Sprite_SetAnimSpeed(sprite->sprite, FX32_ONE);
    Sprite_SetAnimNoRestart(sprite->sprite, animID);
}

static const VecFx32 Unk_ov111_021D3834[] = {
    { FX32_ONE, FX32_ONE, FX32_ONE },
    { FX32_ONE + (FX32_ONE / 5), FX32_ONE + (FX32_ONE / 5), FX32_ONE + (FX32_ONE / 5) },
    { FX32_ONE + (FX32_ONE / 4), FX32_ONE + (FX32_ONE / 4), FX32_ONE + (FX32_ONE / 4) },
    { FX32_ONE + (FX32_ONE / 3), FX32_ONE + (FX32_ONE / 3), FX32_ONE + (FX32_ONE / 3) },
    { FX32_ONE + (FX32_ONE / 2), FX32_ONE + (FX32_ONE / 2), FX32_ONE + (FX32_ONE / 2) },
    { FX32_ONE + (FX32_ONE) - (FX32_ONE / 5), FX32_ONE + (FX32_ONE) - (FX32_ONE / 5), FX32_ONE + (FX32_ONE) - (FX32_ONE / 5) },
    { FX32_ONE + (FX32_ONE / 7), FX32_ONE + (FX32_ONE / 7), FX32_ONE + (FX32_ONE / 7) },
    { FX32_ONE - (FX32_ONE / 2), FX32_ONE - (FX32_ONE / 2), FX32_ONE - (FX32_ONE / 2) },
    { FX32_ONE - (FX32_ONE / 4), FX32_ONE - (FX32_ONE / 4), FX32_ONE - (FX32_ONE / 4) },
    { FX32_ONE - (FX32_ONE / 5), FX32_ONE - (FX32_ONE / 5), FX32_ONE - (FX32_ONE / 5) },
    { FX32_ONE - (FX32_ONE / 7), FX32_ONE - (FX32_ONE / 7), FX32_ONE - (FX32_ONE / 7) }
};

void ov111_021D34E0(ScratchOffCardsSprite *sprite, u32 param1)
{
    Sprite_SetAffineScaleEx(sprite->sprite, &Unk_ov111_021D3834[0], AFFINE_OVERWRITE_MODE_NORMAL);
}

void ov111_021D34F4(ScratchOffCardsSprite *sprite, VecFx32 *scale)
{
    Sprite_SetAffineScaleEx(sprite->sprite, scale, AFFINE_OVERWRITE_MODE_DOUBLE);
}

void ScratchOffCardsSprite_SetPalette(ScratchOffCardsSprite *sprite, u32 palette)
{
    Sprite_SetExplicitPaletteWithOffset(sprite->sprite, palette);
}

void ScratchOffCardsSprite_SetAnimate(ScratchOffCardsSprite *sprite, BOOL animate)
{
    Sprite_SetAnimateFlag(sprite->sprite, animate);
    Sprite_SetAnimSpeed(sprite->sprite, FX32_ONE);
    Sprite_SetAnim(sprite->sprite, Sprite_GetActiveAnim(sprite->sprite));
}

void ScratchOffCardsSprite_SetMosaic(ScratchOffCardsSprite *sprite, BOOL mosaic)
{
    Sprite_SetMosaicFlag(sprite->sprite, mosaic);
}

BOOL ScratchOffCardsSprite_IsAnimated(ScratchOffCardsSprite *sprite)
{
    return Sprite_IsAnimated(sprite->sprite);
}
