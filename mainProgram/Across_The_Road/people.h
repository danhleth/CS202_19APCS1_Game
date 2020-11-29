#ifndef PEOPLE
#define PEOPLE
#include "includePath.h"
class PEOPLE {
private:
	int mX, mY;
	bool mState;
public:
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const Vehicle*&);
	// bool isImpact(const CAnimal)
	bool isFinish();
	bool isDead();
};
#endif