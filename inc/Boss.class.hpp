#ifndef _BOSS_CLASS_H
# define _BOSS_CLASS_H

#include <string>
#include "GameEntity.class.hpp"

class Boss : public GameEntity
{
public:
    Boss();
    Boss(const Boss& Boss);
    Boss(int y);
    ~Boss();
    using GameEntity::operator=;
    void	brain(unsigned long long cycle);
private:
};

#endif
