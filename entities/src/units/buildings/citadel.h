#ifndef LAST_SAVIORS_CITADEL_H
#define LAST_SAVIORS_CITADEL_H

#include "attackable.h"
#include "unit.h"

class Citadel : public Attackable {
   public:
    explicit Citadel(unsigned int max_health,
                     Coordinate position = Coordinate());
};

#endif  // LAST_SAVIORS_CITADEL_H
