

class SomeEnemy : public Enemy {
   public:
    SomeEnemy() : Enemy(0, 100, 1, 1, 100, Coordinate()) {}
    SomeEnemy(unsigned int health) : Enemy(0, health, 1, 1, 100, Coordinate()) {}
    SomeEnemy(Coordinate position) : Enemy(0, 100, 1, 1, 100, position) {}
    void attack(std::shared_ptr<Attackable> &target,
                unsigned int current_time) override{};
    bool canAttack(const std::shared_ptr<Attackable> &target) override {
        return true;
    };
    std::shared_ptr<Attackable> findTarget(
        std::vector<std::shared_ptr<Attackable>> &possible_targets) override {
        return nullptr;
    };
};