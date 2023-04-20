#pragma once
#include "Roslina.h"
class Guarana :
    public Roslina
{
public:
    Guarana(int posY, int posX, Swiat* swiat);
    void kolizja(Organizm* attacker) override;
    Guarana* scion() override;
    size_t size() const;

};

