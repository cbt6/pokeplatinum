#include "macros/scrcmd.inc"
#include "res/text/bank/solaceon_ruins_room_2.h"

    .data

    ScriptEntry _0006
    ScriptEntryEnd

_0006:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    GoToIfSet 210, _00C7
    GoToIfSet 232, _004F
    CheckItem ITEM_HM05, 1, 0x800C
    GoToIfEq 0x800C, 1, _0044
    Message 0
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

_0044:
    Message 1
    GoTo _004F
    End

_004F:
    ApplyMovement 0, _00D4
    WaitMovement
    Message 2
    ShowYesNoMenu 0x800C
    GoToIfEq 0x800C, MENU_YES, _007C
    GoToIfEq 0x800C, MENU_NO, _00B8
    End

_007C:
    Message 3
    SetVar 0x8004, 75
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _00AE
    SetFlag 210
    CallCommonScript 0x7E0
    CloseMessage
    ReleaseAll
    End

_00AE:
    CallCommonScript 0x7E1
    CloseMessage
    ReleaseAll
    End

_00B8:
    SetFlag 232
    Message 4
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

_00C7:
    Message 5
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

    .balign 4, 0
_00D4:
    MoveAction_075
    EndMovement
