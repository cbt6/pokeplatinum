    .include "macros/scrcmd.inc"

    .data

    .long _0006-.-4
    .short 0xFD13

_0006:
    ScrCmd_028 0x800C, 0
    ScrCmd_20A 0x800C
    ScrCmd_029 0x8008, 0x800C
    CompareVarToValue 0x8008, 0
    ScrCmd_01C 1, _0043
    CompareVarToValue 0x8008, 1
    ScrCmd_01C 1, _0047
    CompareVarToValue 0x8008, 2
    ScrCmd_01C 1, _0050
    GoTo _0059

_0043:
    ScrCmd_061
    End

_0047:
    ScrCmd_02C 0
    GoTo _0068

_0050:
    ScrCmd_02C 1
    GoTo _0068

_0059:
    ScrCmd_003 30, 0x800C
    ScrCmd_02C 2
    GoTo _0068

_0068:
    ScrCmd_031
    ScrCmd_034
    ScrCmd_061
    End
