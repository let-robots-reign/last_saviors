#ifndef LAST_SAVIORS_CITADEL_H
#define LAST_SAVIORS_CITADEL_H

#include "attackable.h"
#include "citadel_model.h"
#include "unit.h"

class Citadel : public Attackable {
   private:
    CitadelModel model_;

   public:
    explicit Citadel(const CitadelModel& model,
                     Coordinate position = Coordinate());
};

#endif  // LAST_SAVIORS_CITADEL_H
