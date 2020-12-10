#ifndef LAST_SAVIORS_PAWNMODEL_H
#define LAST_SAVIORS_PAWNMODEL_H


struct PawnModel {
    unsigned int maxHealth;
    unsigned int damage;
    double speed;
    unsigned int attackCooldown;
    size_t coinsForDeath;
};

#endif  // LAST_SAVIORS_PAWNMODEL_H
