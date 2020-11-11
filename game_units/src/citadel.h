#ifndef LAST_SAVIORS_CITADEL_H
#define LAST_SAVIORS_CITADEL_H

#import "attackable_building.h"
#import "citadel_model.h"

class Citadel : public AttackableBuilding {
   private:
    CitadelModel* model;
};

#endif  // LAST_SAVIORS_CITADEL_H
