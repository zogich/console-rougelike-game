
#ifndef CONSOLE_ROUGELIKE_GAME_OBJECTS_H
#define CONSOLE_ROUGELIKE_GAME_OBJECTS_H
#include "objects/structures.h"

class SignalForUpdateObjectPositionOnMap;


class GameObject {
private:
    char sym;
    Point coordinates;
public:
    Point GetPos() { return coordinates; };
    char GetSym() const { return sym; };
    virtual ~GameObject() = default;
    virtual void OnGameTick() = 0;
protected:
    void SetPos(Point pos){
        this->coordinates = pos;
    };
    void SetSym(char symbol){
        this->sym = symbol;
    }
};

class Wall : public GameObject{
public:
    Wall(const Point &pos);
    void OnGameTick() override;
};

class Character : public GameObject{
public:
    int GetHp() const{ return this->hp; };
    virtual void TakeDamage(const int &damage) = 0;
    static void setSignalUpdPos(SignalForUpdateObjectPositionOnMap *signal){
        signal_upd_pos = signal;
    };

protected:
    int hp;
    static SignalForUpdateObjectPositionOnMap *signal_upd_pos;

};

class Knight : public Character{
private:
    int damage;
public:
    Knight(const Point &pos);
    int GetSelfDamage();
    void TakeDamage(const int &damage) override;
    void OnGameTick() override;
};

class Zombie : public Character {
private:
    int damage;
public:
    Zombie(const Point &pos);
    int GetDamage();
    void TakeDamage(const int &dmg) override;
    void OnGameTick() override;
};

class Dragon : public Character{
private:
    int damage;
public:
    Dragon(const Point &pos);
    int GetDamage();
    void TakeDamage(const int &dmg) override;
    void OnGameTick() override;
};

class Princess : public Character{
public:
    Princess(const Point &pos);
    void TakeDamage(const int &damage) override;
    void OnGameTick() override;
};
#endif