//
// Created by nastya on 09.06.2022.
//

#ifndef RUBIK_ICUBEMODEL_H
#define RUBIK_ICUBEMODEL_H


#include <array>
#include <memory>

#include "../cube.h"
#include "../View/ICubeView.h"


class ICubeModel {
protected:
    std::shared_ptr<ICubeView> view_;

public:
    void setView(const std::shared_ptr<ICubeView> &view) {
        view_ = view;
    }

    virtual void rotate(colour_t side_colour, direction_t direction) = 0;

    virtual const std::array<std::array<colour_t, 3>, 3> &operator[](colour_t side) const = 0;
};

#endif //RUBIK_ICUBEMODEL_H
