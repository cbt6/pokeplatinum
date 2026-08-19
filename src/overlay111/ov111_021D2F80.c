#include "overlay111/ov111_021D2F80.h"

#include <nitro.h>
#include <string.h>

#include "overlay111/sco_narc_members.h"
#include "overlay111/struct_ov111_021D2F80.h"

#include "char_transfer.h"
#include "gx_layers.h"
#include "narc.h"
#include "pltt_transfer.h"
#include "render_oam.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_transfer.h"
#include "sprite_util.h"
#include "vram_transfer.h"

static void ov111_021D3378(void);
static void ov111_021D30D8(UnkStruct_ov111_021D2F80 *param0, int param1, int param2, int vramType);
static void ov111_021D304C(UnkStruct_ov111_021D2F80 *param0, int param1);
static void ov111_021D3168(UnkStruct_ov111_021D2F80 *param0, int param1);
static void ov111_021D31F4(UnkStruct_ov111_021D2F80 *param0, int param1);

static const u8 Unk_ov111_021D3820[4] = { 5, 5, 5, 5 };

void ov111_021D2F80(UnkStruct_ov111_021D2F80 *param0)
{
    VramTransfer_New(32, HEAP_ID_SCRATCH_OFF_CARDS);
    ov111_021D3378();

    NNS_G2dInitOamManagerModule();

    RenderOam_Init(0, 128, 0, 32, 0, 128, 0, 32, 115);
    param0->spriteList = SpriteList_InitRendering(40, &param0->g2dRenderer, HEAP_ID_SCRATCH_OFF_CARDS);
    SetSubScreenViewRect(&param0->g2dRenderer, 0, 512 * FX32_ONE);

    for (int i = 0; i < 4; i++) {
        param0->spriteResources[i] = SpriteResourceCollection_New(Unk_ov111_021D3820[i], i, HEAP_ID_SCRATCH_OFF_CARDS);
    }

    ov111_021D304C(param0, NNS_G2D_VRAM_TYPE_2DMAIN);
    ov111_021D30D8(param0, 1, res_id_1, NNS_G2D_VRAM_TYPE_2DMAIN);
    ov111_021D3168(param0, NNS_G2D_VRAM_TYPE_2DMAIN);
    ov111_021D31F4(param0, NNS_G2D_VRAM_TYPE_2DMAIN);
    ov111_021D30D8(param0, 0, res_id_0, NNS_G2D_VRAM_TYPE_2DSUB);

    for (int i = 0; i < 5; i++) {
        SpriteTransfer_RequestChar(param0->unk_1A0[i][0]);
        SpriteTransfer_RequestPlttWholeRange(param0->unk_1A0[i][1]);
    }

    GXLayers_EngineBToggleLayers(GX_PLANEMASK_OBJ, 1);
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_OBJ, 1);
}

// 4 cards
// ./build/tools/nitrogfx/nitrogfx scratch.narc.d/00012.NCGR 00012.png -palette scratch.narc.d/00013.NCLR -cell scratch.narc.d/00011.NCER -convertTo8Bpp
static void ov111_021D304C(UnkStruct_ov111_021D2F80 *param0, int unused)
{
    param0->unk_1A0[2][0] = SpriteResourceCollection_AddTiles(param0->spriteResources[0], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00012_NCGR, FALSE, res_id_2, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[2][1] = SpriteResourceCollection_AddPalette(param0->spriteResources[1], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00013_NCLR, FALSE, res_id_2, NNS_G2D_VRAM_TYPE_2DMAIN, 4, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[2][2] = SpriteResourceCollection_Add(param0->spriteResources[2], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00011_NCER, FALSE, res_id_2, SPRITE_RESOURCE_CELL, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[2][3] = SpriteResourceCollection_Add(param0->spriteResources[3], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00010_NANR, FALSE, res_id_2, SPRITE_RESOURCE_ANIM, HEAP_ID_SCRATCH_OFF_CARDS);
}

// 5 icons
// ./build/tools/nitrogfx/nitrogfx scratch.narc.d/00032.NCGR 00032.png -palette scratch.narc.d/00033.NCLR -cell scratch.narc.d/00031.NCER -convertTo8Bpp
static void ov111_021D30D8(UnkStruct_ov111_021D2F80 *param0, int param1, int param2, int vramType)
{
    param0->unk_1A0[param1][0] = SpriteResourceCollection_AddTiles(param0->spriteResources[0], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00032_NCGR, FALSE, param2, vramType, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[param1][1] = SpriteResourceCollection_AddPalette(param0->spriteResources[1], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00033_NCLR, FALSE, param2, vramType, 5, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[param1][2] = SpriteResourceCollection_Add(param0->spriteResources[2], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00031_NCER, FALSE, param2, SPRITE_RESOURCE_CELL, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[param1][3] = SpriteResourceCollection_Add(param0->spriteResources[3], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00030_NANR, FALSE, param2, SPRITE_RESOURCE_ANIM, HEAP_ID_SCRATCH_OFF_CARDS);
}

// buttons and frames
// ./build/tools/nitrogfx/nitrogfx scratch.narc.d/00016.NCGR 00016.png -palette scratch.narc.d/00017.NCLR -cell scratch.narc.d/00015.NCER -convertTo8Bpp
static void ov111_021D3168(UnkStruct_ov111_021D2F80 *param0, int unused)
{
    param0->unk_1A0[3][0] = SpriteResourceCollection_AddTiles(param0->spriteResources[0], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00016_NCGR, FALSE, res_id_3, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[3][1] = SpriteResourceCollection_AddPalette(param0->spriteResources[1], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00017_NCLR, FALSE, res_id_3, NNS_G2D_VRAM_TYPE_2DMAIN, 4, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[3][2] = SpriteResourceCollection_Add(param0->spriteResources[2], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00015_NCER, FALSE, res_id_3, SPRITE_RESOURCE_CELL, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[3][3] = SpriteResourceCollection_Add(param0->spriteResources[3], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00014_NANR, FALSE, res_id_3, SPRITE_RESOURCE_ANIM, HEAP_ID_SCRATCH_OFF_CARDS);
}

// the animation when got 3 same
static void ov111_021D31F4(UnkStruct_ov111_021D2F80 *param0, int unused)
{
    param0->unk_1A0[4][0] = SpriteResourceCollection_AddTiles(param0->spriteResources[0], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00020_NCGR, FALSE, res_id_4, NNS_G2D_VRAM_TYPE_2DMAIN, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[4][1] = SpriteResourceCollection_AddPalette(param0->spriteResources[1], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00021_NCLR, FALSE, res_id_4, NNS_G2D_VRAM_TYPE_2DMAIN, 1, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[4][2] = SpriteResourceCollection_Add(param0->spriteResources[2], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00019_NCER, FALSE, res_id_4, SPRITE_RESOURCE_CELL, HEAP_ID_SCRATCH_OFF_CARDS);
    param0->unk_1A0[4][3] = SpriteResourceCollection_Add(param0->spriteResources[3], NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, sco_member_00018_NANR, FALSE, res_id_4, SPRITE_RESOURCE_ANIM, HEAP_ID_SCRATCH_OFF_CARDS);
}

Sprite *ov111_021D3280(UnkStruct_ov111_021D2F80 *param0, u32 resourceID, u32 animID, u32 resourcePriority, u32 priority, u8 onSubScreen)
{
    SpriteResourcesHeader resourceHeader;
    SpriteResourcesHeader_Init(&resourceHeader, resourceID, resourceID, resourceID, resourceID, -1, -1, 0, resourcePriority, param0->spriteResources[0], param0->spriteResources[1], param0->spriteResources[2], param0->spriteResources[3], NULL, NULL);

    AffineSpriteListTemplate template;
    template.list = param0->spriteList;
    template.resourceData = &resourceHeader;
    template.position.x = 0;
    template.position.y = 0;
    template.position.z = 0;
    template.affineScale.x = FX32_ONE;
    template.affineScale.y = FX32_ONE;
    template.affineScale.z = FX32_ONE;
    template.affineZRotation = 0;
    template.priority = priority;
    template.heapID = HEAP_ID_SCRATCH_OFF_CARDS;
    if (onSubScreen == FALSE) {
        template.vramType = NNS_G2D_VRAM_TYPE_2DMAIN;
    } else {
        template.vramType = NNS_G2D_VRAM_TYPE_2DSUB;
    }

    Sprite *sprite = SpriteList_AddAffine(&template);

    Sprite_SetAnimateFlag(sprite, FALSE);
    Sprite_SetAnimSpeed(sprite, FX32_ONE);
    Sprite_SetAnim(sprite, animID);

    return sprite;
}

void ov111_021D3320(UnkStruct_ov111_021D2F80 *param0)
{
    u8 i;

    for (i = 0; i < 5; i++) {
        SpriteTransfer_ResetCharTransfer(param0->unk_1A0[i][0]);
        SpriteTransfer_ResetPlttTransfer(param0->unk_1A0[i][1]);
    }

    for (i = 0; i < 4; i++) {
        SpriteResourceCollection_Delete(param0->spriteResources[i]);
    }

    SpriteList_Delete(param0->spriteList);
    RenderOam_Free();
    CharTransfer_Free();
    PlttTransfer_Free();
}

static void ov111_021D3378(void)
{
    CharTransferTemplate template = {
        .maxTasks = 5,
        .sizeMain = 3000,
        .sizeSub = 5120,
        .heapID = HEAP_ID_SCRATCH_OFF_CARDS,
    };

    CharTransfer_InitWithVramModes(&template, GX_OBJVRAMMODE_CHAR_1D_128K, GX_OBJVRAMMODE_CHAR_1D_128K);

    PlttTransfer_Init(14, HEAP_ID_SCRATCH_OFF_CARDS);
    CharTransfer_ClearBuffers();
    PlttTransfer_Clear();
}

static u8 Unk_ov111_021D3940[] = {
    sco_member_00022_NCLR,
    sco_member_00023_NCLR,
    sco_member_00024_NCLR,
    sco_member_00025_NCLR,
    sco_member_00026_NCLR,
    sco_member_00027_NCLR,
    sco_member_00028_NCLR,
    sco_member_00029_NCLR,
};

void ov111_021D33B0(UnkStruct_ov111_021D2F80 *param0, int param1)
{
    GF_ASSERT(param1 < (s32)NELEMS(Unk_ov111_021D3940));

    SpriteResource *resource = SpriteResourceCollection_Find(param0->spriteResources[1], 3);
    SpriteResourceCollection_ModifyPalette(param0->spriteResources[1], resource, NARC_INDEX_RESOURCE__ENG__SCRATCH__SCRATCH, Unk_ov111_021D3940[param1], FALSE, HEAP_ID_SCRATCH_OFF_CARDS);
    SpriteTransfer_ReplacePlttData(resource);
}
