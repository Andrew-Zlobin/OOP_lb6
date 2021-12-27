#pragma once
#include "Level/Level.h"
#include "../Graphics/Graphics.h"
#include "../Input/Input.h"
#include "../save/SaveAndLoad.h"

//#include "../Objects/Units/Player/MovePlayer/MovePlayer.h"

template<typename R1, typename R2, typename R3>
class Game {
private:
	bool isRun;
	Graphics graphics;
	Input input;
	Level level;
public:
	Game() {
		std::cout << "level build\n" << std::endl;
	};
	Game(R1 ruleBuilder, R2 ruleEnemy, R3 ruleThing) {
		std::cout << "level build\n" << std::endl;
		isRun = true;

		input.setGraphics(&graphics);
		input.setButtons("WSADL");
		level.setMap(ruleBuilder.GetFieldFromBuilder());
		level.generateEnemies(ruleEnemy.GetValue(), ruleEnemy.GetEnemy());
		level.generateItems(ruleThing.GetValue(), ruleThing.GetThing());

		SaveAndLoad::Load(&level, SaveType::DEFAULT);
		graphics.setLevel(&level);
	};
	void execute() {

		std::cout << "game execute\n";

		while (isRun) {
			level.update();
			input.update();
			graphics.update();



			if (input.closeButtonPressed()) {
				exit();
			}
			if (input.pressed(ControlButtons::UP)) {
				//std::cout << "up\n";

				level.getPlayer()->move(Direction::UP);
			}
			if (input.pressed(ControlButtons::DOWN)) {
				//std::cout << "down\n";
				level.getPlayer()->move(Direction::DOWN);
			}
			if (input.pressed(ControlButtons::LEFT)) {
				//std::cout << "left\n";
				level.getPlayer()->move(Direction::LEFT);
			}
			if (input.pressed(ControlButtons::RIGHT)) {
				//std::cout << "right\n";
				level.getPlayer()->move(Direction::RIGHT);
			}
			if (input.pressed(ControlButtons::ATTACK)) {
				//std::cout << "attack\n";
				level.getPlayer()->interact();
			}
			if (level.getPlayer()->getHealth() == 0) {
				exit();
			}
			if (level.getPlayer()->getMapPosition().x == level.getMap()->getFinishPoint().x &&
				level.getPlayer()->getMapPosition().y == level.getMap()->getFinishPoint().y) {
				exit();
			}




		}


	};
	void exit() {
		isRun = false;
		graphics.close();
		//SaveAndLoad::Save(&level, SaveType::DEFAULT);
	};
};

