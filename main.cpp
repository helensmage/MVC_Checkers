#include "store/GameStatusStore.h"
#include "ui/MainScreen/MainScreenModel.h"
#include "ui/MainScreen/MainScreenModel.cpp"
#include "ui/MainScreen/MainScreenView.h"
#include "ui/MainScreen/MainScreenView.cpp"
#include "ui/Cell/CellView.h"
#include "ui/MainScreen/MainScreenController.h"
#include "ui/MainScreen/MainScreenController.cpp"
#include "ui/Board/BoardView.cpp"
#include "ui/Board/BoardModel.cpp"
#include "ui/Cell/CellView.cpp"
#include "ui/Cell/CellModel.cpp"

#include <iostream>

int main() {
  GameStatusStore store;
  MainScreenModel model(&store);
  MainScreenView view(&model);
  MainScreenController controller(&model);
  controller.start();
}
