
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
    /**
     * @brief Виртуальный метод, описывающий поведение объекта на каждый тик игры
     */
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

    //! @brief метод, описывающий получение урона персонажем
    virtual void TakeDamage(const int &damage) = 0;

    /**
     * @brief устанавливает статическое свойство Character.signal_upd_pos , по которому должна обновляться позиция <br>
     * @param signal сигнал, по которому все персонажи на карте должны обновить позицию.
     */
    static void setSignalUpdPos(SignalForUpdateObjectPositionOnMap *signal){
        signal_upd_pos = signal;
    };

    /**
     * @brief изменяет текущую позицию персонажа по заданным отступам <br>
     * внутри метод имеет проверку на корректность изменения позиции.
     * @param x_offset отступ по x
     * @param y_offset отступ по y
     */
    void movePosWithOffset(const int &x_offset, const int &y_offset);

protected:
    int hp;
    //! Сигнал, по которому персонаж должен обновить свою позицию на карте.
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