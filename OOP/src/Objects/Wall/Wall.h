#pragma once
#include "../../Graphics/Texture/CustomTexture.h"
#include "../../Point/Point.h"
#include "../../Map/ICellElement.h"

class Wall : public ICellElement {
private:
	Point m_mapPosition;
	CustomTexture *texture;
	Entity entity;
	bool avaliable;
public:
	Wall();
	Wall(Point mapPosition);
	virtual int getHealth();

	virtual Entity getEntity();
	virtual void setEntity(Entity ent);

	virtual Point getMapPosition();
	virtual void setMapPosition(Point mapPosition);

	virtual CustomTexture * getTexture();
	virtual void setTexture(CustomTexture* t);


	virtual std::string GetLog();
	virtual void update();
	virtual int attack();
	virtual void takeDamage(int health);

	virtual bool isAvaliable();
	virtual void disable();
	
	virtual std::string getData();
};

