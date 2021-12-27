#pragma once
#include "../Point/Point.h"
#include "Entity.h"
#include "../log/Subject.h"

class ICellElement : public Subject {
public:
	virtual int getHealth() = 0;

	virtual Entity getEntity() = 0;
	virtual void setEntity(Entity ent) = 0;

	virtual Point getMapPosition() = 0;
	virtual void setMapPosition(Point mapPosition) = 0;

	//virtual void update() = 0;
	virtual int attack() = 0;
	virtual void takeDamage(int health) = 0;
	virtual bool isAvaliable() = 0;
	virtual void disable() = 0;

	virtual std::string getData() = 0;
};

