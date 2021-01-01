#pragma once
#include "includePath.h"
#include "Movement.h"
#include "Animation.h"

class COBJECT
{
private:
	float mX, mY;
	vector<vector<float>> shape;
protected:
	sf::ConvexShape convex;
	sf::Texture *texture;
	sf::Sprite *sprite;
	//Component
	//sf::RectangleShape hitBox;
	Movement* movement;
	AnimationComponent* animation;

	void createSprite(sf::Texture*);
	void createMovement(float maxVeclocity);
	void createAnimation(sf::Texture& texture);
	//void createHitBox();
	void setSizeHitBox(float, float);
	void initTexture();
public:
	//Constructor
	COBJECT();
	COBJECT(sf::Texture* texture);
	COBJECT(float x, float y);
	COBJECT(float, float, sf::Texture* texture);

	float X();
	float Y();
	void X(float);
	void Y(float);
	float getX();
	float getY();

	void changeConvex(sf::ConvexShape _convex);
	sf::ConvexShape getConvex();
	void setShape(vector<vector<float>>);
	virtual void Move(float, float);
	virtual void KeyBoardMove(float, float);
	virtual void Draw(sf::RenderTarget*);
	virtual void setPosition(float, float);
	virtual sf::RectangleShape hitbox();
	virtual void update();
};

class CVEHICLE : public COBJECT {
private:

public:
	CVEHICLE(sf::Texture* texture);
	CVEHICLE(float, float, sf::Texture* texture);
	sf::RectangleShape hitbox();
};

class CTRUCK : public CVEHICLE {
private:

public:
	CTRUCK(sf::Texture* texture);
	CTRUCK(float, float);
	sf::RectangleShape hitbox();
};

class CCAR : public CVEHICLE {
private:

public:
	CCAR(sf::Texture* texture);
	CCAR(float, float);
	sf::RectangleShape hitbox();
};

class CANIMAL : public COBJECT {
private:

public:
	CANIMAL(sf::Texture* texture);
	CANIMAL(float, float);
	sf::RectangleShape hitbox();
	//virtual void Tell();
};

class CDINOSAUR : public CANIMAL {
public:
	CDINOSAUR(sf::Texture* texture);
	CDINOSAUR(float, float);
	sf::RectangleShape hitbox();
	void update();
};

class CBIRD : public CANIMAL {
public:
	CBIRD(sf::Texture* texture);
	CBIRD(float, float);
	sf::RectangleShape hitbox();
	void update();
};


class PEOPLE : public COBJECT {
private:
	bool mState;
	bool isMoving;
public:
	PEOPLE();
	PEOPLE(float, float, sf::Texture* texture);
	sf::RectangleShape hitbox();

	void KeyBoadMove_WithDt(float, sf::Event &);
	bool isImpact(vector<COBJECT*> enemies);

	void setSpeed(float);
	bool isImpact() { return false; }
	void Draw(sf::RenderTarget*);
	bool isFinish();
	bool isDead();
	void collisionAnimation();
	void update();
};

