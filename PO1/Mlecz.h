#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{
public:
    Mlecz(int posY, int posX, Swiat* swiat);
    void akcja() override;
    Mlecz* scion() override;
    size_t size() const;

};

