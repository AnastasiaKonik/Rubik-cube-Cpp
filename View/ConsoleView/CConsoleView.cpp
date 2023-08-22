//
// Created by nastya on 09.06.2022.
//

#include <iostream>
#include <algorithm>
#include <sstream>

#include "CConsoleView.h"

#define SPACE std::cout << "      ";
#define NEW_LINE std::cout << std::endl;


void CConsoleView::display(colour_t side_colour, direction_t direction, const ICubeModel &cube) {
    system("clear");
    for (const auto &line: cube[YELLOW]) {
        SPACE
        for (const auto &mini_cube: line) {
            print(mini_cube);
        }
        NEW_LINE
    }
    for (int i = 0; i < 3; ++i) {
        for (const auto &mini_cube: cube[ORANGE][i]) {
            print(mini_cube);
        }
        for (const auto &mini_cube: cube[BLUE][i]) {
            print(mini_cube);
        }
        for (const auto &mini_cube: cube[RED][i]) {
            print(mini_cube);
        }
        for (const auto &mini_cube: cube[GREEN][i]) {
            print(mini_cube);
        }
        NEW_LINE
    }
    for (const auto &line: cube[WHITE]) {
        SPACE
        for (const auto &mini_cube: line) {
            print(mini_cube);
        }
        NEW_LINE
    }
}

void CConsoleView::print(colour_t colour) {
    switch (colour) {
        case WHITE:
            std::cout << "\033[38;5;255m\u25A0 \033[0;m";
            break;
        case RED:
            std::cout << "\033[38;5;124m\u25A0 \033[0;m";
            break;
        case BLUE:
            std::cout << "\033[38;5;27m\u25A0 \033[0;m";
            break;
        case GREEN:
            std::cout << "\033[38;5;46m\u25A0 \033[0;m";
            break;
        case ORANGE:
            std::cout << "\033[38;5;202m\u25A0 \033[0;m";
            break;
        case YELLOW:
            std::cout << "\033[38;5;226m\u25A0 \033[0;m";
            break;
    }
}

void CConsoleView::run() {
    std::cout << "Welcome to cube!" << std::endl;
    std::string line;
    std::stringstream commands_ss;
    while (true) {
        std::cout << "Enter command (to ask for help type h): ";
        std::getline(std::cin, line);

        if (line == "e") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        if (line == "h") {
            std::cout << "Usage: \n\tr[+|-][w|y|b|r|g|o] - rotate the cube(+ clockwise; - counterclockwise)\n"
                         "\tq - Shuffle\n\tw - Solve\n\th - Show this message\n\te - Exit\n";
            continue;
        }
        if (line == "q") {
            commands_ss << controller_->shuffle(0);
            std::cout << "Shuffle sequence:\n" << commands_ss.str() << std::endl;
            continue;
        }
        if (line == "w") {
            std::string commands = commands_ss.str();
            if (commands.empty()) {
                std::cout << "Cube is solved!!!" << std::endl;
                continue;
            }

            std::transform(commands.begin(), commands.end(), commands.begin(), [](char c) {
                return std::isupper(c) ? std::tolower(c) : std::toupper(c);
            });
            std::reverse(commands.begin(), commands.end());

            controller_->solve(commands);
            std::cout << "Solved! Solution: " << commands << std::endl;
            commands_ss.str("");

            continue;
        }
        if (line.size() == 3 && line[0] == 'r'
            && (line[1] == '+' || line[1] == '-')
            && (line[2] == 'w' || line[2] == 'y' || line[2] == 'b'
                || line[2] == 'o' || line[2] == 'g' || line[2] == 'r')) {

            switch (line[2]) {
                case 'w':
                    controller_->rotate(WHITE, line[1] == '+' ? CLOCKWISE : COUNTER_CLOCKWISE);
                    commands_ss << (line[1] == '+' ? 'w' : 'W');
                    break;
                case 'y':
                    controller_->rotate(YELLOW, line[1] == '+' ? CLOCKWISE : COUNTER_CLOCKWISE);
                    commands_ss << (line[1] == '+' ? 'y' : 'Y');
                    break;
                case 'b':
                    controller_->rotate(BLUE, line[1] == '+' ? CLOCKWISE : COUNTER_CLOCKWISE);
                    commands_ss << (line[1] == '+' ? 'b' : 'B');
                    break;
                case 'o':
                    controller_->rotate(ORANGE, line[1] == '+' ? CLOCKWISE : COUNTER_CLOCKWISE);
                    commands_ss << (line[1] == '+' ? 'o' : 'O');
                    break;
                case 'g':
                    controller_->rotate(GREEN, line[1] == '+' ? CLOCKWISE : COUNTER_CLOCKWISE);
                    commands_ss << (line[1] == '+' ? 'g' : 'G');
                    break;
                case 'r':
                    controller_->rotate(RED, line[1] == '+' ? CLOCKWISE : COUNTER_CLOCKWISE);
                    commands_ss << (line[1] == '+' ? 'r' : 'R');
                    break;
            }

            continue;
        }

        std::cout << "Error! Try again! (to ask for help type h)" << std::endl;
    }
}

