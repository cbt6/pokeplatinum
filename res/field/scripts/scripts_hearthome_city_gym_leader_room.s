#include "macros/scrcmd.inc"
#include "res/text/bank/hearthome_city_gym_leader_room.h"

    .data

    ScriptEntry _0039
    ScriptEntry _0158
    ScriptEntry _0196
    ScriptEntry _01A0
    ScriptEntry _0248
    ScriptEntry _001A
    ScriptEntryEnd

_001A:
    GoToIfSet 142, _0027
    End

_0027:
    SetFlag 0x29C
    RemoveObject 2
    RemoveObject 1
    ClearFlag 142
    End

_0039:
    PlayFanfare SEQ_SE_CONFIRM
    LockAll
    FacePlayer
    ScrCmd_1BD 0x800C
    GoToIfEq 0x800C, 0, _007B
    GoToIfEq 0x800C, 1, _008B
    GoToIfEq 0x800C, 2, _009B
    GoToIfEq 0x800C, 3, _00AB
    End

_007B:
    ApplyMovement 0, _01B8
    WaitMovement
    GoTo _00BB

_008B:
    ApplyMovement 0, _01DC
    WaitMovement
    GoTo _00BB

_009B:
    ApplyMovement 0, _0200
    WaitMovement
    GoTo _00BB

_00AB:
    ApplyMovement 0, _0224
    WaitMovement
    GoTo _00BB

_00BB:
    CheckBadgeAcquired BADGE_ID_RELIC, 0x800C
    GoToIfEq 0x800C, 1, _01A0
    CreateJournalEvent LOCATION_EVENT_GYM_WAS_TOO_TOUGH, 91, 0, 0, 0
    Message 0
    CloseMessage
    SetFlag 142
    StartTrainerBattle TRAINER_LEADER_FANTINA
    ClearFlag 142
    CheckWonBattle 0x800C
    GoToIfEq 0x800C, FALSE, _0248
    Message 1
    BufferPlayerName 0
    Message 2
    PlaySound SEQ_BADGE
    WaitSound
    GiveBadge BADGE_ID_RELIC
    ScrCmd_260 23
    SetTrainerFlag TRAINER_CAMPER_DREW
    SetTrainerFlag TRAINER_ACE_TRAINER_ALLEN
    SetTrainerFlag TRAINER_ACE_TRAINER_CATHERINE
    SetTrainerFlag TRAINER_LASS_MOLLY
    SetTrainerFlag TRAINER_PICNICKER_CHEYENNE
    SetTrainerFlag TRAINER_SCHOOL_KID_CHANCE
    SetTrainerFlag TRAINER_SCHOOL_KID_MACKENZIE
    SetTrainerFlag TRAINER_YOUNGSTER_DONNY
    CreateJournalEvent LOCATION_EVENT_BEAT_GYM_LEADER, 91, TRAINER_LEADER_FANTINA, 0, 0
    SetVar 0x407B, 1
    SetFlag 0x206
    ClearFlag 0x207
    Message 3
    GoTo _0158

_0158:
    SetVar 0x8004, 0x188
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _0196
    CallCommonScript 0x7FC
    SetFlag 125
    BufferItemName 0, 0x8004
    BufferTMHMMoveName 1, 0x8004
    Message 4
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

_0196:
    CallCommonScript 0x7E1
    CloseMessage
    ReleaseAll
    End

_01A0:
    GoToIfUnset 125, _0158
    Message 5
    WaitABXPadPress
    CloseMessage
    ReleaseAll
    End

    .balign 4, 0
_01B8:
    MoveAction_002 4
    MoveAction_000 4
    MoveAction_003 4
    MoveAction_001 4
    MoveAction_002 4
    MoveAction_000 4
    MoveAction_003 4
    MoveAction_001 4
    EndMovement

    .balign 4, 0
_01DC:
    MoveAction_003 4
    MoveAction_001 4
    MoveAction_002 4
    MoveAction_000 4
    MoveAction_003 4
    MoveAction_001 4
    MoveAction_002 4
    MoveAction_000 4
    EndMovement

    .balign 4, 0
_0200:
    MoveAction_000 4
    MoveAction_002 4
    MoveAction_001 4
    MoveAction_003 4
    MoveAction_000 4
    MoveAction_002 4
    MoveAction_001 4
    MoveAction_003 4
    EndMovement

    .balign 4, 0
_0224:
    MoveAction_000 4
    MoveAction_003 4
    MoveAction_001 4
    MoveAction_002 4
    MoveAction_000 4
    MoveAction_003 4
    MoveAction_001 4
    MoveAction_002 4
    EndMovement

_0248:
    ClearFlag 0x29C
    BlackOutFromBattle
    ReleaseAll
    End

    .byte 0
    .byte 0
