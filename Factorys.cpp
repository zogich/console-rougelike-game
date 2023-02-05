//
// Created by иван on 02.02.2023.
//

#include "Factorys.h"
#include "objects/Knight.h"
#include "objects/Zombie.h"
#include "objects/Dragon.h"
#include "objects/Princess.h"


std::unique_ptr<GameObject> KnightFactory::createProduct(const Point &pos) {
    return std::make_unique<Knight>(pos);
}

std::unique_ptr<GameObject> ZombieFactory::createProduct(const Point &pos) {
    return std::make_unique<Zombie>(pos);
}

std::unique_ptr<GameObject> DragonFactory::createProduct(const Point &pos) {
    return std::make_unique<Dragon>(pos);
}

std::unique_ptr<GameObject> PrincessFactory::createProduct(const Point &pos) {
    return std::make_unique<Princess>(pos);
}