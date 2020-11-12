#ifndef LAST_SAVIORS_CITADEL_H
#define LAST_SAVIORS_CITADEL_H

#import "attackable_building.h"
#include "model_factory.h"

class Citadel : public AttackableBuilding {
   private:
    CitadelModel* model;

   public:
    Citadel();
    Citadel(Coordinate position);
};

#endif  // LAST_SAVIORS_CITADEL_H
