#include "MainScreenView.h"

MainScreenView::MainScreenView(MainScreenModel* model) : _model(model) {
    _model->addObserver(this);
}

void MainScreenView::draw() {
    if (_model->GetSurrender()) {
    std::cout << std::endl << "Game Over!" << std::endl;
    std::cout << _model->CastPlayer(_model->GetWinner()) << " wins!" << std::endl;
    }
    else {
    system("cls");

    std::cout << "White Player score: " << _model->GetWhiteScore() << std::endl;
    std::cout << "Black Player score: " << _model->GetBlackScore() << std::endl << std::endl;
    
    _model->GetBoard().update();
    
    std::cout << _model->GetCurrentPlayer() << " move:" << std::endl;
    }
}
