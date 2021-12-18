#include "CellView.h"

CellView::CellView(CellModel* model) : _model(model) {
  _model->addObserver(this);
}

void CellView::draw() {
  std::cout << _model->CastState();
  std::cout << "|";
}
