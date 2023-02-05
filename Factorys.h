

#ifndef CONSOLE_ROUGELIKE_GAME_FACTORYS_H
#define CONSOLE_ROUGELIKE_GAME_FACTORYS_H
#include <memory>
#include "objects/GameObject.h"

class AbstractFactory {
    virtual std::unique_ptr<GameObject> createProduct() = 0;
};

class KnightFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos);
};

class ZombieFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos);
};

class DragonFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos);
};

class PrincessFactory : public AbstractFactory {
    std::unique_ptr<GameObject> createProduct(const Point &pos) ;
};

#endif //CONSOLE_ROUGELIKE_GAME_FACTORYS_H
