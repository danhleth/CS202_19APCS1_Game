#include "CPEOPLE.h"

void CPEOPLE::Up(int)
{
}

void CPEOPLE::Left(int)
{
}

void CPEOPLE::Right(int)
{
}

void CPEOPLE::Down(int)
{
}

bool isImpact(const CVEHICLE*&) {
    return true;
}
bool isImpact(const CANIMAL*&) {
    return true;
}


bool CPEOPLE::isFinish()
{
    return false;
}

bool CPEOPLE::isDead()
{
    return false;
}
