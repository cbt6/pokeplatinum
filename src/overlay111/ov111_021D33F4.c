#include "overlay111/ov111_021D33F4.h"

#include <nitro.h>
#include <string.h>

#include "overlay111/ov111_021D2F80.h"
#include "overlay111/sco_narc_members.h"
#include "overlay111/struct_ov111_021D2F80.h"

#include "heap.h"
#include "sprite.h"

UnkStruct_ov111_021D33F4 *ov111_021D33F4(UnkStruct_ov111_021D2F80 *param0, u32 resourceID, u32 animID, u16 x, u16 y, u8 onSubScreen, u32 resourcePriority, u32 priority)
{
    UnkStruct_ov111_021D33F4 *v0 = Heap_Alloc(HEAP_ID_SCRATCH_OFF_CARDS, sizeof(UnkStruct_ov111_021D33F4));
    memset(v0, 0, sizeof(UnkStruct_ov111_021D33F4));
    v0->sprite = ov111_021D3280(param0, resourceID, animID, resourcePriority, priority, onSubScreen);
    v0->onSubScreen = onSubScreen;

    ov111_021D3474(v0, x, y);

    return v0;
}

void *ov111_021D3448(UnkStruct_ov111_021D33F4 *param0)
{
    Sprite_Delete(param0->sprite);
    Heap_Free(param0);
    return NULL;
}

void ov111_021D345C(UnkStruct_ov111_021D33F4 *param0, BOOL draw)
{
    Sprite_SetDrawFlag(param0->sprite, draw);
}

void ov111_021D3468(UnkStruct_ov111_021D33F4 *param0, u32 priority)
{
    Sprite_SetPriority(param0->sprite, priority);
}

void ov111_021D3474(UnkStruct_ov111_021D33F4 *param0, int x, int y)
{
    VecFx32 pos;

    pos.x = x * FX32_ONE;
    pos.y = y * FX32_ONE;

    if (param0->onSubScreen == TRUE) {
        pos.y += 512 * FX32_ONE;
    }

    Sprite_SetPosition(param0->sprite, &pos);
}

void ov111_021D349C(UnkStruct_ov111_021D33F4 *param0, int *x, int *y)
{
    const VecFx32 *pos = Sprite_GetPosition(param0->sprite);

    *x = pos->x / FX32_ONE;
    *y = pos->y / FX32_ONE;
}

void ov111_021D34C4(UnkStruct_ov111_021D33F4 *param0, u32 param1)
{
    Sprite_SetAnimSpeed(param0->sprite, FX32_ONE);
    Sprite_SetAnimNoRestart(param0->sprite, param1);
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

void ov111_021D34E0(UnkStruct_ov111_021D33F4 *param0, u32 param1)
{
    Sprite_SetAffineScaleEx(param0->sprite, &Unk_ov111_021D3834[0], 1);
}

void ov111_021D34F4(UnkStruct_ov111_021D33F4 *param0, VecFx32 *scale)
{
    Sprite_SetAffineScaleEx(param0->sprite, scale, AFFINE_OVERWRITE_MODE_DOUBLE);
}

void ov111_021D3500(UnkStruct_ov111_021D33F4 *param0, u32 param1)
{
    Sprite_SetExplicitPaletteWithOffset(param0->sprite, param1);
}

void ov111_021D350C(UnkStruct_ov111_021D33F4 *param0, BOOL animate)
{
    Sprite_SetAnimateFlag(param0->sprite, animate);
    Sprite_SetAnimSpeed(param0->sprite, FX32_ONE);
    Sprite_SetAnim(param0->sprite, Sprite_GetActiveAnim(param0->sprite));
}

void ov111_021D3530(UnkStruct_ov111_021D33F4 *param0, BOOL mosaic)
{
    Sprite_SetMosaicFlag(param0->sprite, mosaic);
}

BOOL ov111_021D353C(UnkStruct_ov111_021D33F4 *param0)
{
    return Sprite_IsAnimated(param0->sprite);
}
