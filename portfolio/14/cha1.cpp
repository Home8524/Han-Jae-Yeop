#include "cha1.h"

USING_NS_CC;

cha1::cha1()
{
}

cha1::~cha1()
{
}

static cha1 *instance;

cha1 * cha1::getInstance()
{
	if (!instance)
	{
		instance = new cha1();
	}
	return instance;
}


