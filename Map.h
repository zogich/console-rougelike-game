#ifndef CONSOLE_ROUGELIKE_GAME_MAP_H
#define CONSOLE_ROUGELIKE_GAME_MAP_H
#include <vector>
#include <memory>
#include "objects/structures.h"
#include "Factory.h"


typedef std::map<char, std::vector<std::unique_ptr<GameObject>>> objectPool;

//! @brief Карта игрового мира.
class Map {
private:
    //! @brief Двумерный вектор "плиток". Сама карта, на которой расположены объекты.
    std::vector<std::vector<Tile>> tiles;

    //! @brief Фабрика, заполняющая карту.
    std::unique_ptr<Factory> factory;

    //! @brief Объекты, расположенные на карте.
    objectPool pool;
public:
    //! @param path_to_config_file Путь к файлу, в котором записана конфигурация карты.
    Map(const std::string &path_to_config_file);

    //! @brief Возвращает двумерный массив "плиток" карты.
    std::vector<std::vector<Tile>> getTiles() const;

    //! @brief Возвращает список объектов расположенных на карте.
    objectPool* getPool();

    //! @brief Отрисовка карты.
    void drawMap();

    void updateObjectsPosTiles();

    //! @brief Метод, выполняющий изменение положения символа объекта на карте.
    //! @param sym Символ который надо переместить.
    //! @param old_pos Прежняя позиция символа.
    //! @param new_pos Новая позиция символа.
    void moveObjectSym(const Point &old_pos, const Point &new_pos, const char &sym);
};

//! @brief Перегрузка оператора ввода из файла.
std::ostream& operator << (std::ostream &os, const Map &map);

#endif //CONSOLE_ROUGELIKE_GAME_MAP_H
