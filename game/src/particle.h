#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "globals.hpp"
#include "sfml_enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

class Particle : public sf::Sprite {
public:
    Particle(size_t posx, size_t posy, SfmlEnemy *target_, size_t strength_, size_t tileSize_, size_t id);

    bool alive();

private:
    SfmlEnemy *target;
    size_t speed, strength, fieldSize;
    int lasts;
    bool hitTarget;
};

void updateParticles(std::vector<Particle> &particles);

#endif
