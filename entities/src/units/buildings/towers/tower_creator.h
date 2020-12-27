#include "tower.h"

class TowerCreator {

   public:
    virtual ~TowerCreator() = default;
    virtual std::shared_ptr<Tower> createTower(unsigned int current_time,
                                               Coordinate position) const = 0;
};