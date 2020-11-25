#include "model_factory.h"


std::string ModelFactory::getKey(ModelType type) const { return ""; }

bool ModelFactory::hasModel(ModelType type) { return false; }

ModelFactory::ModelFactory(std::vector<ModelType> types) {}

void *ModelFactory::getModel(ModelType type) { return nullptr; }
