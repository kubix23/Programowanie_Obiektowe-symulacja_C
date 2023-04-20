#pragma once
#include "Zwierze.h"
class Owca :
    public Zwierze
{
public:
    Owca(int posY, int posX, Swiat* swiat);
    Owca* scion() override;
    size_t size() const;
};

