#pragma once
#include "Roslina.h"
class Wilcza_jagoda :
    public Roslina
{
public:
    Wilcza_jagoda(int posY, int posX, Swiat* swiat);
    void kolizja(Organizm* attacker) override;
    Wilcza_jagoda* scion() override;
    size_t size() const;
};

