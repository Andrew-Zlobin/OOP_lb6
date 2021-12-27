#ifndef GAME_SAVEANDLOAD_H
#define GAME_SAVEANDLOAD_H

#include <fstream>
#include <string>
#include "../Game/Level/Level.h"

#include "../Objects/Units/Player/Player.h"
/*
#include "../Objects/Units/Enemy/Warrior/Warrior.h"
#include "../Objects/Units/Enemy/Tank/Tank.h"
#include "../Objects/Units/Enemy/Ghost/Ghost.h"
*/
#include "../Objects/Items/heal/Heal.h"
#include "../Objects/Items/IncreaseDamage/IncreaseDamage.h"
#include "../Objects/Items/IncreaseMaxHealth/IncreaseMaxHealth.h"

#include "./LoadError.h"

enum class SaveType {
    DEFAULT,
    CUSTOM
};


class SaveAndLoad{
public:
    static void Save(Level *level, SaveType type);
    static void Load(Level* level, SaveType type);
};

#endif //GAME_SAVEANDLOAD_H
