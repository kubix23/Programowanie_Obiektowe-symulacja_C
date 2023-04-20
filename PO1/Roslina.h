#pragma once
#include "Organizm.h"
class Roslina :
    public Organizm
{
public:
	using Organizm::Organizm;
	virtual void move(size_t& newY, size_t& newX) override;
	virtual void akcja() override;
	virtual void kolizja(Organizm* attacker) override;
};

