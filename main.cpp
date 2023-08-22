#include "Model/SimpleCube/CSimpleCube.h"
#include "Controller/SimpleController/CSimpleController.h"
#include "View/ConsoleView/CConsoleView.h"

int main() {
    std::shared_ptr<ICubeModel> cube = std::make_shared<CSimpleCube>();
    std::shared_ptr<ICubeController> controller = std::make_shared<CSimpleController>();
    std::shared_ptr<ICubeView> view = std::make_shared<CConsoleView>();

    cube->setView(view);
    view->setController(controller);
    controller->setCube(cube);

    view->run();

    return 0;
}
