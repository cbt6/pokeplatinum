#ifndef POKEPLATINUM_STRUCT_0203E608_H
#define POKEPLATINUM_STRUCT_0203E608_H

#include "savedata.h"

typedef struct ExternalDataSOC {
    SaveData *saveData;
    u8 dummy_04;
    u8 padding_05[3];
    u16 strange_unk_08[3];
    u16 strange_unk_0E[3];
    u16 dummy_14;
    u8 padding_16[2];
} ExternalDataSOC;

#endif // POKEPLATINUM_STRUCT_0203E608_H
