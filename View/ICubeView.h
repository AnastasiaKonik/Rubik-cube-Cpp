//
// Created by nastya on 09.06.2022.
//


#ifndef RUBIK_ICUBEVIEW_H
#define RUBIK_ICUBEVIEW_H


#include <memory>

#include "../cube.h"
#include "../Model/ICubeModel.h"
#include "../Controller/ICubeController.h"


class ICubeView {
protected:
    std::shared_ptr<ICubeController> controller_;

public:
    void setController(const std::shared_ptr<ICubeController> &controller) {
        controller_ = controller;
    }

    virtual void display(colour_t side_colour, direction_t direction, const ICubeModel &cube) = 0;

    virtual void run() = 0;
};

#endif //RUBIK_ICUBEVIEW_H
