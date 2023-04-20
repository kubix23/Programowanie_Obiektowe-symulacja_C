#pragma once
#include "Roslina.h"
class Trawa :
    public Roslina
{
public:
    Trawa(int posY, int posX, Swiat* swiat);
    Trawa* scion() override;
    size_t size() const;

};

