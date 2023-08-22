cmake_minimum_required(VERSION 3.21)
project(Rubik)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubik
        main.cpp

        Model/ICubeModel.h
            Model/SimpleCube/CSimpleCube.h
            Model/SimpleCube/CSimpleCube.cpp

        View/ICubeView.h
            View/ConsoleView/CConsoleView.h
            View/ConsoleView/CConsoleView.cpp

        Controller/ICubeController.h
            Controller/SimpleController/CSimpleController.h
            Controller/SimpleController/CSimpleController.cpp

        cube.h
        )