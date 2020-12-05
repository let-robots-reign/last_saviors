#include "enemy_creator.h"
#include "pawn.h"
class PawnCreator : public EnemyCreator {
   private:
    static std::shared_ptr<PawnModel> model_;

   public:
    PawnCreator() = default;  // todo параметры для конструктора модели
    std::shared_ptr<Enemy> createEnemy(time_t current_time,
                                       Coordinate position) const override;
};