#pragma once
#include "Zwierze.h"
class Lis :
    public Zwierze
{
public:
    Lis(int posY, int posX, Swiat* swiat);
    virtual void akcja() override;
    Lis* scion() override;
    size_t size() const;
};

