//
// Created by nastya on 06.06.2022.
//

#include "CSimpleController.h"


void CSimpleController::rotate(colour_t side_colour, direction_t direction) {
    cube_->rotate(side_colour, direction);
}

std::string CSimpleController::shuffle(int seed) {
    std::srand(seed != 0 ? seed : time(nullptr));

    int count = std::rand() % 100;
    colour_t colour;
    direction_t direction;
    std::stringstream ss;

    for (int i = 0; i < count; ++i) {
        direction = static_cast<direction_t>(std::rand() % 2);
        colour = static_cast<colour_t>(std::rand() % 6);
        cube_->rotate(colour, direction);

        switch (colour) {
            case WHITE:
                direction == CLOCKWISE ? ss << 'w' : ss << 'W';
                break;
            case RED:
                direction == CLOCKWISE ? ss << 'r' : ss << 'R';
                break;
            case BLUE:
                direction == CLOCKWISE ? ss << 'b' : ss << 'B';
                break;
            case GREEN:
                direction == CLOCKWISE ? ss << 'g' : ss << 'G';
                break;
            case ORANGE:
                direction == CLOCKWISE ? ss << 'o' : ss << 'O';
                break;
            case YELLOW:
                direction == CLOCKWISE ? ss << 'y' : ss << 'Y';
                break;
        }
    }

    return ss.str();
}

void CSimpleController::solve(const std::string& commands) {
    for (const auto &command: commands) {
        switch (command) {
            case 'w':
                cube_->rotate(WHITE, CLOCKWISE);
                break;
            case 'W':
                cube_->rotate(WHITE, COUNTER_CLOCKWISE);
                break;

            case 'r':
                cube_->rotate(RED, CLOCKWISE);
                break;
            case 'R':
                cube_->rotate(RED, COUNTER_CLOCKWISE);
                break;

            case 'b':
                cube_->rotate(BLUE, CLOCKWISE); break;
            case 'B':
                cube_->rotate(BLUE, COUNTER_CLOCKWISE); break;

            case 'g':
                cube_->rotate(GREEN, CLOCKWISE); break;
            case 'G':
                cube_->rotate(GREEN, COUNTER_CLOCKWISE); break;

            case 'o':
                cube_->rotate(ORANGE, CLOCKWISE); break;
            case 'O':
                cube_->rotate(ORANGE, COUNTER_CLOCKWISE); break;

            case 'y':
                cube_->rotate(YELLOW, CLOCKWISE); break;
            case 'Y':
                cube_->rotate(YELLOW, COUNTER_CLOCKWISE); break;

            default:
                throw std::runtime_error("Unknown command" + std::to_string(command));
        }
    }
}
