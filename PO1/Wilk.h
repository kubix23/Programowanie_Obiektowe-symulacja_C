#pragma once
#include "Zwierze.h"
class Wilk :
    public Zwierze
{
public:
    Wilk(int posY, int posX, Swiat* swiat);
    Wilk* scion() override;
    size_t size() const;
};

