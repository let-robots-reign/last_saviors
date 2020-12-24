#include "particle.h"

Particle::Particle(size_t posx, size_t posy, SfmlEnemy *target_, size_t strength_, size_t fieldSize_, size_t id) :
        sf::Sprite(), target(target_), strength(strength_), fieldSize(fieldSize_) {
    setPosition(posx - 2, posy - 2);
    setTexture(*loader.getParticleTextures(id));
    hitTarget = false;
    lasts = 10, speed = 10;
}

bool Particle::alive() {
    if (hitTarget) {
        lasts--;
        if (lasts < 0) {
            return false;
        }
    } else {
        sf::Vector2f pos = getPosition();
        sf::Vector2f pos2 = target->getPosition();
        float dis = std::pow(pos.x - pos2.x, 2) + std::pow(pos.y - pos2.y, 2);
        if (dis <= speed * speed + 10) {
            target->hurt(strength);
            hitTarget = true;
        } else {
            float angle = atan((pos.y - pos2.y) / (pos2.x - pos.x));
            float x = cos(angle) * speed, y = sin(angle) * speed;
            if (pos.x > pos2.x) {
                x = -x;
            }
            if (pos.x < pos2.x) {
                y = -y;
            }
            move(x, y);
        }
    }
    return true;
}

void updateParticles(std::vector<Particle> &particles) {
    auto i = particles.begin();
    while (i != particles.end()) {
        if (!i->alive()) {
            i = particles.erase(i);
        } else {
            ++i;
        }
    }
}
