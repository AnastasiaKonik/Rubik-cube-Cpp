//
// Created by nastya on 09.06.2022.
//

#ifndef RUBIK_CCONSOLEVIEW_H
#define RUBIK_CCONSOLEVIEW_H


#include "../ICubeView.h"


class CConsoleView : public ICubeView {
private:
    static void print(colour_t colour);
public:
    CConsoleView() = default;

    void display(colour_t side_colour, direction_t direction, const ICubeModel &cube) final;

    void run() final;
};


#endif //RUBIK_CCONSOLEVIEW_H
