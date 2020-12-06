#ifndef PEOPLE
#define PEOPLE
#include"includePath.h"
#include"OBJECT.h"

class CPEOPLE {
private:
	int mX, mY;
	bool mState;
public:
	CPEOPLE() {};
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};
#endif