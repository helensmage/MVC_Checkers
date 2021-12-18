#include "BoardView.h"

BoardView::BoardView(BoardModel* model) : _model(model) {
      _model->addObserver(this);
   }

void BoardView::draw() {
  size_t boardSize = static_cast<size_t>(sqrt(_model->GetMap().size()));
  for (size_t i = 0; i < boardSize; i++) {
    std::cout << "|";
    for (size_t j = 0; j < boardSize; j++) {
      CellModel cw(_model->GetMap().at(pos(i, j)));
      CellView* bw = new CellView(&cw);
      cw.update();
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
}
