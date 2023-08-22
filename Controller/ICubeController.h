//
// Created by nastya on 09.06.2022.
//

#ifndef RUBIK_ICUBECONTROLLER_H
#define RUBIK_ICUBECONTROLLER_H


#include <memory>

#include "../cube.h"
#include "../Model/ICubeModel.h"


class ICubeController {
protected:
    std::shared_ptr<ICubeModel> cube_;

public:
    void setCube(const std::shared_ptr<ICubeModel> &cube) {
        cube_ = cube;
    }

    virtual void rotate(colour_t side_colour, direction_t direction) = 0;

    virtual std::string shuffle(int seed) = 0;

    virtual void solve(const std::string& commands) = 0;
};


#endif //RUBIK_ICUBECONTROLLER_H
