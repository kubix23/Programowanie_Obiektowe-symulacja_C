#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
    public Roslina
{
public:
    BarszczSosnowskiego(int posY, int posX, Swiat* swiat);
    void akcja() override;
    BarszczSosnowskiego* scion() override;
    size_t size() const;
};

