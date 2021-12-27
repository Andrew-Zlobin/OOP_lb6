#include "Level.h"

Level::Level() {
    
    //generateSimpleMap();
    //generateEnemies();
    //generateItems();
    
    
    map = new Map();
    player = new Player();
    player->setMap(map);
    player->setMapPosition(map->getStartPoint());
    map->getCell(map->getStartPoint())->setCellElement(player);
    

    LoggerImplication* log = new ConcreteLog();
    base = new ConsoleLogger(log);

}

Map * Level::getMap()
{
    return map;
}

void Level::setMap(Map* map) {
    this->map = map;
    this->player->setMap(this->map);
    this->player->setMapPosition(this->map->getStartPoint());
    this->map->getCell(this->map->getStartPoint())->setCellElement(player);
}

void Level::setEnemies(Enemy** enm) {
    enemies = enm;
    enemyArrarySize = sizeof(enemies) / sizeof(Enemy *);
    for (int i = 0; i < enemyArrarySize; i++) {
        int x = 0;
        int y = 0;
        while (map->getCell(Point(x, y))->getCellElement() != nullptr) {
            x = rand() % (map->getwidth());
            y = rand() % (map->getheight());
        }
        enemies[i]->setMapPosition(Point(x, y));
        map->getCell(Point(x, y))->setCellElement(enemies[i]);
    }
}

void Level::setEnemiesFromSave(Enemy** enm) {
    enemies = enm;
}

void Level::setEnemyArrarySize(int size) {
    enemyArrarySize = size;
}

void Level::setItems(Item** itm) {
    items = itm;
    itemArraySize = sizeof(items) / sizeof(Item *);
    for (int i = 0; i < itemArraySize; i++) {
        int x = 0;
        int y = 0;
        while (map->getCell(Point(x, y))->getCellElement() != nullptr) {
            x = rand() % (map->getwidth());
            y = rand() % (map->getheight());
        }
        items[i]->setMapPosition(Point(x, y));
        map->getCell(Point(x, y))->setCellElement(items[i]);
    }
}

void Level::setItemsFromSave(Item** itm) {
    items = itm;
}

void Level::setItemArraySize(int size) {
    itemArraySize = size;
}

void Level::setPlayer(Player* player) {
    //map->getCell(this->player->getMapPosition())->setCellElement(nullptr);
    this->player = player;
}

void Level::generateEnemies(int count, Enemy ** enemies) {
    int direction;
    enemyArrarySize = count;
    int x = 0, y = 0;
    srand(time(NULL));
    for (int i = 0; i < enemyArrarySize; i++) {
        
        while (map->getCell(Point(x, y))->getCellElement() != nullptr) {
            x = rand() % (map->getwidth());
            y = rand() % (map->getheight());
        }
        enemies[i]->setMap(map);
        enemies[i]->setMapPosition(Point(x, y));
        map->getCell(Point(x, y))->setCellElement(enemies[i]);
    }
    this->enemies = enemies;
}

void Level::generateItems(int count, Item ** items) {
    int direction;
    itemArraySize = count;
    int x = 0, y = 0;
    srand(time(NULL));
    for (int i = 0; i < itemArraySize; i++) {
        
        while (map->getCell(Point(x, y))->getCellElement() != nullptr) {
            x = rand() % (map->getwidth());
            y = rand() % (map->getheight());
        }
        items[i]->setMapPosition(Point(x, y));
        map->getCell(Point(x, y))->setCellElement(items[i]);
    }
    this->items = items;
}

Player * Level::getPlayer()
{
    return player;
}

std::string Level::getData()
{
    std::string res = "";
    for (int i = 0; i < map->getwidth(); i++) {
        for (int j = 0; j < map->getheight(); j++) {
            if (map->getCell(Point(i, j))->getCellElement() != nullptr) {
                res = res + map->getCell(Point(i, j))->getCellElement()->getData() + "\n";
            }
        }
    }
    return res;
}

void Level::generateSimpleMap() {
    for (int i = 0; i < map->getheight(); i++) {
        Wall* wall = new Wall();
        map->getCell(Point(0, i))->setCellElement(wall);

        wall = new Wall();
        map->getCell(Point(map->getwidth() - 1, i))->setCellElement(wall);

    }
    for (int i = 0; i < map->getwidth(); i++) {
        Wall* wall = new Wall();
        map->getCell(Point(i, 0))->setCellElement(wall);

        wall = new Wall();
        map->getCell(Point(i, map->getheight() - 1))->setCellElement(wall);
    }

    
    for (int i = 2; i <= map->getwidth() - 1 - 2; i = i + 3) {
        for (int j = 1; j <= map->getheight() - 1 - 1; j = j + 3) {
            Wall* wall = new Wall();
            map->getCell(Point(i, j))->setCellElement(wall);
        }
    }
    
}



void Level::update() {
    std::cout << "Player " << player->getMapPosition().x << ' ' << player->getMapPosition().y << '\n';
    //std::cout << map.getCell(Point(1, 1))->getCellElement() << '\n';
    for (int i = 0; i < enemyArrarySize; i++) {
        if (enemies[i]->getHealth() != 0) {
            enemies[i]->update();
            Logger* logger = Logger::GetInstance(enemies[i], base);
            logger->Update();
        }
    }
    Logger* logger = Logger::GetInstance(player, base);
    logger->Update();
}
