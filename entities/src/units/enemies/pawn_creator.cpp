#include "pawn_creator.h"


std::shared_ptr<PawnModel> PawnCreator::model_ = std::make_shared<PawnModel>();

std::shared_ptr<Enemy> PawnCreator::createEnemy(time_t current_time,
                                                Coordinate position) const {
    return std::make_shared<Pawn>(PawnCreator::model_, current_time, position);
}
