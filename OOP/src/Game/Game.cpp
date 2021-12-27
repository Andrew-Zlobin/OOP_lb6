//#include "Game.h"
/*
template<typename R1, typename R2, typename R3>
Game<R1, R2, R3>::Game() {
	

}

template<typename R1, typename R2, typename R3>
Game<R1, R2, R3>::Game(R1 ruleBuilder, R2 ruleEnemy, R3 ruleThing)
{
	isRun = true;
	input.setGraphics(&graphics);
	graphics.setLevel(&level);
}

template<typename R1, typename R2, typename R3>
void Game<R1, R2, R3>::execute() {
	

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
	

}

template<typename R1, typename R2, typename R3>
void Game<R1, R2, R3>::exit() {
	isRun = false;
	graphics.close();
}

*/
