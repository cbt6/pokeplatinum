#include <nitro.h>
#include <string.h>

#include "trainer_info.h"
#include "struct_decls/struct_021C0794_decl.h"

#include "unk_020244AC.h"
#include "unk_02025E08.h"
#include "trainer_info.h"
#include "unk_0203D178.h"
#include "unk_020507CC.h"
#include "unk_0206A8DC.h"
#include "overlay057/ov57_021D0F30.h"

void ov57_021D0F30 (int param0, SaveData * param1)
{
    if (!sub_020246A8(param1)) {
        OS_ResetSystem(0);
    }
}

void ov57_021D0F44 (int param0, SaveData * param1)
{
    TrainerInfo * v0;

    sub_0202479C(param1);
    sub_0203D1A8(param1);

    v0 = sub_02025E38(param1);
    TrainerInfo_SetMoney(v0, 3000);
    sub_0206A92C(SaveData_Events(param1));
}
