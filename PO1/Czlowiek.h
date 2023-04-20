#pragma once
#include "Zwierze.h"
class Czlowiek :
    public Zwierze
{
private:
    short dx = 0;
    short dy = 0;
    unsigned char skillCooldown = 0;
public:
    Czlowiek(int posY, int posX, Swiat* swiat);
    void moveSpeedYX(short dy, short dx);
    void skill();
    void akcja() override;
    void assign(Organizm* old) override;
    size_t size() const;
    Czlowiek* scion() override;
};

