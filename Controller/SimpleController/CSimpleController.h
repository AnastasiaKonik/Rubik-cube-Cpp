//
// Created by nastya on 06.06.2022.
//

#ifndef RUBIK_CSIMPLECONTROLLER_H
#define RUBIK_CSIMPLECONTROLLER_H


#include <sstream>

#include "../ICubeController.h"


class CSimpleController : public ICubeController {
public:
    CSimpleController() = default;

    void rotate(colour_t side_colour, direction_t direction) final;

    std::string shuffle(int seed) final;

    void solve(const std::string& commands) override;
};


#endif //RUBIK_CSIMPLECONTROLLER_H
