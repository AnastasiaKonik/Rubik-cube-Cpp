//
// Created by nastya on 05.06.2022.
//

#include "CSimpleCube.h"


CSimpleCube::CSimpleCube(){
    std::array<std::array<colour_t, 3>, 3> arr{};

    fill_array(WHITE, arr);
    sides.insert({WHITE, arr});

    fill_array(RED, arr);
    sides.insert({RED, arr});

    fill_array(BLUE, arr);
    sides.insert({BLUE, arr});

    fill_array(GREEN, arr);
    sides.insert({GREEN, arr});

    fill_array(ORANGE, arr);
    sides.insert({ORANGE, arr});

    fill_array(YELLOW, arr);
    sides.insert({YELLOW, arr});
}

void CSimpleCube::fill_array(colour_t colour, std::array<std::array<colour_t, 3>, 3> &array) {
    for (auto &a : array) {
        for (auto &e : a) {
            e = colour;
        }
    }
}

const std::array<std::array<colour_t, 3>, 3> &CSimpleCube::operator[](colour_t side) const {
    return sides.at(side);
}

void CSimpleCube::rotate_array(direction_t direction, std::array<std::array<colour_t, 3>, 3> &a) {
    colour_t tmp;
    if (direction == CLOCKWISE) {
        // corners
        tmp = a[0][0];
        a[0][0] = a[2][0];
        a[2][0] = a[2][2];
        a[2][2] = a[0][2];
        a[0][2] = tmp;

        // edges
        tmp = a[0][1];
        a[0][1] = a[1][0];
        a[1][0] = a[2][1];
        a[2][1] = a[1][2];
        a[1][2] = tmp;
    } else {
        // corners
        tmp = a[0][0];
        a[0][0] = a[0][2];
        a[0][2] = a[2][2];
        a[2][2] = a[2][0];
        a[2][0] = tmp;

        // edges
        tmp = a[0][1];
        a[0][1] = a[1][2];
        a[1][2] = a[2][1];
        a[2][1] = a[1][0];
        a[1][0] = tmp;
    }
}

void CSimpleCube::rotate(colour_t side_colour, direction_t direction) {
    rotate_array(direction, sides[side_colour]);
   
    auto &y = sides[YELLOW];
    auto &b = sides[BLUE];
    auto &g = sides[GREEN];
    auto &w = sides[WHITE];
    auto &r = sides[RED];
    auto &o = sides[ORANGE];
    
    switch (side_colour) {
        case WHITE:
            if (direction == CLOCKWISE) {
                std::array<colour_t, 3> tmp = sides[BLUE][2];
                sides[BLUE][2] = sides[ORANGE][2];
                sides[ORANGE][2] = sides[GREEN][2];
                sides[GREEN][2] = sides[RED][2];
                sides[RED][2] = tmp;
            } else {
                std::array<colour_t, 3> tmp = sides[BLUE][2];
                sides[BLUE][2] = sides[RED][2];
                sides[RED][2] = sides[GREEN][2];
                sides[GREEN][2] = sides[ORANGE][2];
                sides[ORANGE][2] = tmp;
            }
            break;
        case RED:
            if (direction == CLOCKWISE) {
                std::array<colour_t, 3> t{y[2][2], y[1][2], y[0][2]};
                y[2][2] = b[2][2]; y[1][2] = b[1][2]; y[0][2] = b[0][2];
                b[2][2] = w[2][2]; b[1][2] = w[1][2]; b[0][2] = w[0][2];
                w[2][2] = g[0][0]; w[1][2] = g[1][0]; w[0][2] = g[2][0];
                g[0][0] = t[0]   ; g[1][0] = t[1]   ; g[2][0] = t[2];
            } else {
                std::array<colour_t, 3> t{y[0][2], y[1][2], y[2][2]};
                y[0][2] = g[2][0]; y[1][2] = g[1][0]; y[2][2] = g[0][0];
                g[2][0] = w[0][2]; g[1][0] = w[1][2]; g[0][0] = w[2][2];
                w[0][2] = b[0][2]; w[1][2] = b[1][2]; w[2][2] = b[2][2];
                b[0][2] = t[0]   ; b[1][2] = t[1]   ; b[2][2] = t[2];
            }
            break;
        case BLUE:
            if (direction == CLOCKWISE) {
                std::array<colour_t, 3> t{y[2][0], y[2][1], y[2][2]};
                y[2][0] = o[2][2]; y[2][1] = o[1][2]; y[2][2] = o[0][2];
                o[2][2] = w[0][2]; o[1][2] = w[0][1]; o[0][2] = w[0][0];
                w[0][2] = r[0][0]; w[0][1] = r[1][0]; w[0][0] = r[2][0];
                r[0][0] = t[0]   ; r[1][0] = t[1]   ; r[2][0] = t[2];
            } else {
                std::array<colour_t, 3> t{y[2][2], y[2][1], y[2][0]};
                y[2][2] = r[2][0]; y[2][1] = r[1][0]; y[2][0] = r[0][0];
                r[2][0] = w[0][0]; r[1][0] = w[0][1]; r[0][0] = w[0][2];
                w[0][0] = o[0][2]; w[0][1] = o[1][2]; w[0][2] = o[2][2];
                o[0][2] = t[0]   ; o[1][2] = t[1]   ; o[2][2] = t[2];
            }
            break;
        case GREEN:
            if (direction == CLOCKWISE) {
                std::array<colour_t, 3> t{y[0][2], y[0][1], y[0][0]};
                y[0][2] = r[2][2]; y[0][1] = r[1][2]; y[0][0] = r[0][2];
                r[2][2] = w[2][0]; r[1][2] = w[2][1]; r[0][2] = w[2][2];
                w[2][0] = o[0][0]; w[2][1] = o[1][0]; w[2][2] = o[2][0];
                o[0][0] = t[0]   ; o[1][0] = t[1]   ; o[2][0] = t[2];
            } else {
                std::array<colour_t, 3> t{y[0][0], y[0][1], y[0][2]};
                y[0][0] = o[2][0]; y[0][1] = o[1][0]; y[0][2] = o[0][0];
                o[2][0] = w[2][2]; o[1][0] = w[2][1]; o[0][0] = w[2][0];
                w[2][2] = r[0][2]; w[2][1] = r[1][2]; w[2][0] = r[2][2];
                r[0][2] = t[0]   ; r[1][2] = t[1]   ; r[2][2] = t[2];
            }
            break;
        case ORANGE:
            if (direction == CLOCKWISE) {
                std::array<colour_t, 3> t{y[0][0], y[1][0], y[2][0]};
                y[0][0] = g[2][2]; y[1][0] = g[1][2]; y[2][0] = g[0][2];
                g[2][2] = w[0][0]; g[1][2] = w[1][0]; g[0][2] = w[2][0];
                w[0][0] = b[0][0]; w[1][0] = b[1][0]; w[2][0] = b[2][0];
                b[0][0] = t[0]   ; b[1][0] = t[1]   ; b[2][0] = t[2];
            } else {
                std::array<colour_t, 3> t{y[2][0], y[1][0], y[0][0]};
                y[2][0] = b[2][0]; y[1][0] = b[1][0]; y[0][0] = b[0][0];
                b[2][0] = w[2][0]; b[1][0] = w[1][0]; b[0][0] = w[0][0];
                w[2][0] = g[0][2]; w[1][0] = g[1][2]; w[0][0] = g[2][2];
                g[0][2] = t[0]   ; g[1][2] = t[1]   ; g[2][2] = t[2];
            }
            break;
        case YELLOW:
            if (direction == CLOCKWISE) {
                std::array<colour_t, 3> tmp = sides[GREEN][0];
                sides[GREEN][0] = sides[ORANGE][0];
                sides[ORANGE][0] = sides[BLUE][0];
                sides[BLUE][0] = sides[RED][0];
                sides[RED][0] = tmp;
            } else {
                std::array<colour_t, 3> tmp = sides[GREEN][0];
                sides[GREEN][0] = sides[RED][0];
                sides[RED][0] = sides[BLUE][0];
                sides[BLUE][0] = sides[ORANGE][0];
                sides[ORANGE][0] = tmp;
            }
            break;
    }

    view_->display(side_colour, direction, *this);
}
