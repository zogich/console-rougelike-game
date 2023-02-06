

#ifndef CONSOLE_ROUGELIKE_GAME_FACTORYS_H
#define CONSOLE_ROUGELIKE_GAME_FACTORYS_H
#include <memory>
#include "objects/Objects.h"

class AbstractFactory {
    virtual std::unique_ptr<GameObject> createProduct(const Point &pos) = 0;
};

class KnightFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos) override;
};

class ZombieFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos) override;
};

class DragonFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos) override;
};

class PrincessFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos) override ;
};

class WallFactory: public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos) override;
};
#endif //CONSOLE_ROUGELIKE_GAME_FACTORYS_H
