#pragma once
#include "Organizm.h"

class Zwierze :
	public Organizm
{
public:
	using Organizm::Organizm;
	void move(size_t& newY, size_t& newX) override;
	virtual void akcja() override;
	virtual void kolizja(Organizm* attacker) override;
};

