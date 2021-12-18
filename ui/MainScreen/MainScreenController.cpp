#include "MainScreenController.h"

MainScreenController::MainScreenController(MainScreenModel* model) : _model(model) {}

void MainScreenController::start() {
    _model->GetBoard().ResetMap();
    while (_model->GetWinner() == GameStatusStore::Player::NONE) {
    BoardModel::MoveResult moveResult(BoardModel::MoveResult::PROHIBITED);
    std::string line1, line2;
    while (moveResult == BoardModel::MoveResult::PROHIBITED) {
        bool direction = _model->GetDirection();
        _model->update();
        std::cin >> line1;
        std::cin >> line2;
        auto newMove = std::move(_model->GetMove(line1, line2));
        moveResult = _model->GetBoard().MakeMove(newMove.first, newMove.second, direction);
    }
    if (moveResult == BoardModel::MoveResult::FF) {
        _model->ChangeSurrender();
        break;
    }
    if (moveResult == BoardModel::MoveResult::SUCCESSFUL_COMBAT) {
        _model->UpdateScore();
    }
    _model->SwitchPlayer();
    }
    _model->update();
}
