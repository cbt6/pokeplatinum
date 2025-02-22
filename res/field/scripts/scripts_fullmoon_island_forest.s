#include "macros/scrcmd.inc"
#include "res/text/bank/fullmoon_island_forest.h"

    .data

    ScriptEntry _000A
    ScriptEntry _000C
    ScriptEntryEnd

_000A:
    End

_000C:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    DrawPokemonPreview SPECIES_CRESSELIA, GENDER_FEMALE
    WaitABPress
    ScrCmd_209
    PlayCry SPECIES_CRESSELIA, 0
    GetPlayerDir 0x800C
    CallIfEq 0x800C, 0, _007E
    ScrCmd_063 0
    ScrCmd_26A 0, 6, 8
    ScrCmd_062 0
    SetFlag 0x24F
    RemoveObject 0
    ActivateRoamingPokemon ROAMING_SLOT_CRESSELIA
    GoToIfEq 0x4058, 3, _0074
    ClearFlag 0x452
    AddObject 1
    SetFlag 0x11F
    Message 0
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

_0074:
    SetVar 0x4058, 0
    ReleaseAll
    End

_007E:
    SetObjectEventPos 1, 16, 14
    ApplyMovement 0, _0094
    WaitMovement
    Return

    .balign 4, 0
_0094:
    MoveAction_071
    MoveAction_012
    MoveAction_072
    EndMovement
