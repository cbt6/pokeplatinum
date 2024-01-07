#ifndef POKEPLATINUM_CONSTANTS_BATTLE_SIDE_EFFECTS_H
#define POKEPLATINUM_CONSTANTS_BATTLE_SIDE_EFFECTS_H

#define MOVE_SIDE_EFFECT_BREAK_SCREENS              (1 << 23)
#define MOVE_SIDE_EFFECT_CHECK_SUBSTITUTE           (1 << 24)
#define MOVE_SIDE_EFFECT_CHECK_HP_AND_SUBSTITUTE    (1 << 25)
#define MOVE_SIDE_EFFECT_PROBABILISTIC              (1 << 26)
#define MOVE_SIDE_EFFECT_CANNOT_PREVENT             (1 << 27)
#define MOVE_SIDE_EFFECT_CHECK_HP                   (1 << 28)
#define MOVE_SIDE_EFFECT_ON_HIT                     (1 << 29)
#define MOVE_SIDE_EFFECT_TO_ATTACKER                (1 << 30)
#define MOVE_SIDE_EFFECT_TO_DEFENDER                (1 << 31)

#define MOVE_SIDE_EFFECT_FLAGS                      (MOVE_SIDE_EFFECT_BREAK_SCREENS \
                                                     | MOVE_SIDE_EFFECT_CHECK_SUBSTITUTE \
                                                     | MOVE_SIDE_EFFECT_CHECK_HP_AND_SUBSTITUTE \
                                                     | MOVE_SIDE_EFFECT_PROBABILISTIC \
                                                     | MOVE_SIDE_EFFECT_CANNOT_PREVENT \
                                                     | MOVE_SIDE_EFFECT_CHECK_HP \
                                                     | MOVE_SIDE_EFFECT_ON_HIT \
                                                     | MOVE_SIDE_EFFECT_TO_ATTACKER \
                                                     | MOVE_SIDE_EFFECT_TO_DEFENDER)
#define MOVE_SIDE_EFFECT_SUBSCRIPT_POINTER          (~MOVE_SIDE_EFFECT_FLAGS)

#endif // POKEPLATINUM_CONSTANTS_BATTLE_SIDE_EFFECTS_H
