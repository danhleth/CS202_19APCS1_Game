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
	sf::Sound* sound;
	sf::SoundBuffer* soundBuffer;
	//Component
	Movement* movement;
	AnimationComponent* animation;

	void createSprite(sf::Texture*);
	void createMovement(float maxVeclocity);
	void createAnimation(sf::Texture& texture);
	void initTexture();
public:
	//Constructor
	COBJECT();
	COBJECT(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	COBJECT(float x, float y);
	COBJECT(float, float, sf::Texture* texture, sf::SoundBuffer* soundBuffer);

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
	virtual void update();
	void playSound();
};

class CVEHICLE : public COBJECT {
private:

public:
	CVEHICLE(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	CVEHICLE(float, float, sf::Texture* texture, sf::SoundBuffer* soundBuffer);
};

class CTRUCK : public CVEHICLE {
private:

public:
	CTRUCK(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	CTRUCK(float, float);
};

class CCAR : public CVEHICLE {
private:

public:
	CCAR(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	CCAR(float, float);
};

class CANIMAL : public COBJECT {
private:

public:
	CANIMAL(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	CANIMAL(float, float);
	//virtual void Tell();
};

class CDINOSAUR : public CANIMAL {
public:
	CDINOSAUR(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	CDINOSAUR(float, float);
	void update();
};

class CBIRD : public CANIMAL {
public:
	CBIRD(sf::Texture* texture, sf::SoundBuffer* soundBuffer);
	CBIRD(float, float);
	void update();
};


class PEOPLE : public COBJECT {
private:
	bool mState;
	bool isMoving;
public:
	PEOPLE();
	PEOPLE(float, float, sf::Texture* texture, sf::SoundBuffer* soundBuffer);

	void KeyBoadMove_WithDt(float, sf::Event &);
	//bool isImpact(const CVEHICLE*&);
	//bool isImpact(const CANIMAL);

	void setSpeed(float);
	bool isImpact() { return false; }
	void Draw(sf::RenderTarget*);
	bool isFinish();
	bool isDead();
	void collisionAnimation();
	void update();
};

