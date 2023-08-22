//
// Created by nastya on 05.06.2022.
//

#ifndef RUBIK_CSIMPLECUBE_H
#define RUBIK_CSIMPLECUBE_H


#include <unordered_map>

#include "../ICubeModel.h"


class CSimpleCube : public ICubeModel {
private:
    std::unordered_map<colour_t, std::array<std::array<colour_t, 3>, 3>> sides;

    static void fill_array(colour_t colour, std::array<std::array<colour_t, 3>, 3> &array);

    static void rotate_array(direction_t direction, std::array<std::array<colour_t, 3>, 3> &a);

public:
    CSimpleCube();

    void rotate(colour_t side_colour, direction_t direction) final;

    const std::array<std::array<colour_t, 3>, 3> &operator[](colour_t side) const final;
};


#endif //RUBIK_CSIMPLECUBE_H
