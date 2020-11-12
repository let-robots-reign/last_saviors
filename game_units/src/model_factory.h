#ifndef LAST_SAVIORS_MODEL_FACTORY_H
#define LAST_SAVIORS_MODEL_FACTORY_H

#include <unordered_map>
#include <vector>

#include "area_damage_tower_model.h"
#include "citadel_model.h"
#include "mindmaster_model.h"
#include "pawn_model.h"
#include "point_damage_tower_model.h"
#include "shaft_model.h"

emun ModelType{
    AreaDamageTower, PointDamageTower, Citadel, Shaft, Pawn, Mindmaster,
};

class ModelFactory {
   private:
    std::unordered_map<std::string, void *> models;
    std::string getKey(ModelType type) const;
    bool hasModel(ModelType type);

   public:
    explicit ModelFactory(std::vector<ModelType> types);
    void *getModel(ModelType type);
};

#endif  // LAST_SAVIORS_MODEL_FACTORY_H
