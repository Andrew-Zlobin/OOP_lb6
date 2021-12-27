#pragma once
#include "../../Map/Map/Map.h"
#include "../../Objects/Units/Player/Player.h"
#include "../../Objects/Units/Enemy/Enemy.h"
#include "../../Objects/Units/Enemy/Warrior/Warrior.h"
#include "../../Objects/Units/Enemy/Tank/Tank.h"
#include "../../Objects/Units/Enemy/Ghost/Ghost.h"
#include "../../Objects/Items/Item.h"
#include "../../Objects/Items/heal/Heal.h"
#include "../../Objects/Items/IncreaseDamage/IncreaseDamage.h"
#include "../../Objects/Items/IncreaseMaxHealth/IncreaseMaxHealth.h"

#include "../../log/Observer.h"
#include "../../log/Subject.h"
#include "../../log/ConsoleLogger.h"
#include "../../log/FileLogger.h"
#include "../../log/Logger.h"
#include "../../log/LoggerImplication.h"
#include "../../log/Decorator.h"
#include "../../log/ConcreteLog.h"

class Level {
private:
	Map * map;
	Player *player;

	Enemy ** enemies;
	int enemyArrarySize = 0;
	Item** items;
	int itemArraySize = 0;
	LoggerImplication* base;
	void generateSimpleMap();
	void generateEnemies();
	void generateItems();
public:
	Level();
	Map* getMap();
	void setMap(Map * map);
	void setEnemies(Enemy ** enm);
	void setEnemiesFromSave(Enemy** enm);
	void setEnemyArrarySize(int size);
	void setItems(Item ** itm);
	void setItemsFromSave(Item** itm);
	void setItemArraySize(int size);
	void setPlayer(Player* player);

	void generateEnemies(int count, Enemy ** enemies);
	void generateItems(int count, Item ** items);

	Player *getPlayer();

	std::string getData();

	void update();

};

