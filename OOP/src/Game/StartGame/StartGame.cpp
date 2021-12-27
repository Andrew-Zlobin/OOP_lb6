#include "StartGame.h"

void StartGame::startGame() {
    RulesBuilder<1> rulesBuilder;
    RulesEnemy<5> rulesEnemy;
    RulesThing<10> rulesThing;
    std::cout << "startGame\n";
    Game<RulesBuilder<1>, RulesEnemy<5>, RulesThing<10>> game(rulesBuilder, rulesEnemy, rulesThing);
    //Game<int, int, int> game(1, 2, 3);
    game.execute();
}
