#pragma once
#include "Zwierze.h"
class Antylopa :
    public Zwierze
{
public:
    Antylopa(int posY, int posX, Swiat* swiat);
    void akcja() override;
    void kolizja(Organizm* attacker) override;
    Antylopa* scion() override;
    size_t size() const;
};

