#pragma once
#include "Zwierze.h"
class Zolw :
    public Zwierze
{
public:
    Zolw(int posY, int posX, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* attacker) override;
    Zolw* scion() override;
    size_t size() const;
};

