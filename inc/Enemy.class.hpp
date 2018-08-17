#ifndef ENEMY_CLASS_H
# define ENEMY_CLASS_H

#include <string>
#include "GameEntity.class.hpp"

class Enemy : public GameEntity
{
public:
    Enemy();
    Enemy(const Enemy& enemy);
    Enemy(int y);
    ~Enemy();
    using GameEntity::operator=;
    void	brain(unsigned long long cycle);
};

#endif
