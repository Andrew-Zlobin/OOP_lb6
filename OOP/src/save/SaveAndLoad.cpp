#include "SaveAndLoad.h"


void SaveAndLoad::Save(Level* level, SaveType type) {
    std::string file;
    if(type == SaveType::DEFAULT){
        file = "save1";
    }
    else{
        std::cout << "Please, enter the name of save:" << std::endl;
        std::cin >> file;
        if(file == "save1"){
            std::cout << "This name don't available" << std::endl;
            return;
        }
    }

    std::ofstream save_file;
    save_file.open("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\save\\"+file + ".txt");

    save_file << level->getData();
    //std::cout << level->getData() << std::endl;
    save_file.close();
}

void SaveAndLoad::Load(Level* level, SaveType type) {
    std::string file;
    if(type == SaveType::DEFAULT){
        file = "save1";
    }
    else{
        std::cout << "Please, enter the name to load:" << std::endl;
        std::cin >> file;
    }

    std::ifstream save_file;
    save_file.open("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\save\\" +file + ".txt", std::ios::in);
    if (save_file.fail())
    {
        throw LoadError("This save does not exist");
    }

    //new field
    Map* new_map = new Map();
    Player* player = new Player();
    Enemy** enemies = new Enemy*[10];
    int enemyArraySize = 0;
    Item** items = new Item*[10];
    int itemArraySize = 0;

    while (!save_file.eof()) {
        Entity currentEntity;
        int number;
        save_file >> number;
        std::cout << number << '\n';
        currentEntity = static_cast<Entity>(number);
        if (currentEntity == Entity::GHOST) {
            int damage = 0;
            int health = 0;
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y >> health >> damage;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(enemyEr, posEr);
            }
            enemies[enemyArraySize] = new Ghost(mapPosition, health, damage);
            enemies[enemyArraySize]->setMap(new_map);
            new_map->getCell(mapPosition)->setCellElement(enemies[enemyArraySize]);
            enemyArraySize++;
        }
        if (currentEntity == Entity::WARRIOR) {
            int damage = 0;
            int health = 0;
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y >> health >> damage;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(enemyEr, posEr);
            }
            enemies[enemyArraySize] = new Warrior(mapPosition, health, damage);
            enemies[enemyArraySize]->setMap(new_map);
            new_map->getCell(mapPosition)->setCellElement(enemies[enemyArraySize]);
            
            enemyArraySize++;
        }
        if (currentEntity == Entity::TANK) {
            int damage = 0;
            int health = 0;
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y >> health >> damage;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(enemyEr, posEr);
            }
            enemies[enemyArraySize] = new Tank(mapPosition, health, damage);
            enemies[enemyArraySize]->setMap(new_map);
            new_map->getCell(mapPosition)->setCellElement(enemies[enemyArraySize]);
            enemyArraySize++;
        }

        if (currentEntity == Entity::HEAL) {
            int heal = 0;
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y >> heal;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(thingEr, posEr);
            }
            items[itemArraySize] = new Heal(mapPosition, heal);
            new_map->getCell(mapPosition)->setCellElement(items[itemArraySize]);
            itemArraySize++;
        }
        if (currentEntity == Entity::IA) {
            int increaseDamage = 0;
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y >> increaseDamage;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(thingEr, posEr);
            }
            items[itemArraySize] = new IncreaseDamage(mapPosition, increaseDamage);
            new_map->getCell(mapPosition)->setCellElement(items[itemArraySize]);
            itemArraySize++;
        }
        if (currentEntity == Entity::IMH) {
            int increaseMaxHealth = 0;
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y >> increaseMaxHealth;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(thingEr, posEr);
            }
            items[itemArraySize] = new IncreaseMaxHealth(mapPosition, increaseMaxHealth);
            new_map->getCell(mapPosition)->setCellElement(items[itemArraySize]);
            itemArraySize++;
        }

        if (currentEntity == Entity::PLAYER) {
            Point mapPosition;
            int health = 0;
            int damage = 0;
            int direction;
            int maxHealth;
            save_file >> mapPosition.x >> mapPosition.y >> health >> damage >> direction >> maxHealth;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(playerEr, posEr);
            }
            player = new Player(mapPosition, health, damage, direction, maxHealth);
            new_map->getCell(mapPosition)->setCellElement(player);
        }

        if (currentEntity == Entity::WALL) {
            Point mapPosition;
            save_file >> mapPosition.x >> mapPosition.y;
            if (mapPosition.x > level->getMap()->getwidth() || mapPosition.y > level->getMap()->getheight() ||
                mapPosition.x < 0 || mapPosition.y < 0) {
                throw LoadError(wallEr, posEr);
            }
            Wall* wall = new Wall(mapPosition);
            new_map->getCell(mapPosition)->setCellElement(wall);
        }

    }
    for (int i = 0; i < enemyArraySize; i++) {
        std::cout << enemies[i]->GetLog() << '\n';
    }

    for (int i = 0; i < itemArraySize; i++) {
        std::cout << items[i]->GetLog() << '\n';
    }

    level->setPlayer(player);
    level->setMap(new_map);
    level->setEnemiesFromSave(enemies);
    level->setEnemyArrarySize(enemyArraySize);
    level->setItemsFromSave(items);
    level->setItemArraySize(itemArraySize);
}