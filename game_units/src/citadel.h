#ifndef LAST_SAVIORS_CITADEL_H
#define LAST_SAVIORS_CITADEL_H

#include "attackable_building.h"
#include "model_factory.h"

class Citadel : public AttackableBuilding {
   private:
    const CitadelModel* model_;

   public:
    explicit Citadel(const CitadelModel* model,
                     Coordinate position = Coordinate());
};

#endif  // LAST_SAVIORS_CITADEL_H
