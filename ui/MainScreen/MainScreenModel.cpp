#include "MainScreenModel.h"

MainScreenModel::MainScreenModel(GameStatusStore* model) : _model(model) {}

void MainScreenModel::update() {
    notifyUpdate();
}

BoardModel& MainScreenModel::GetBoard() {
    return _model->mboard;
}

size_t MainScreenModel::GetWhiteScore() {
    return _model->mWhiteScore;
}

size_t MainScreenModel::GetBlackScore() {
    return _model->mBlackScore;
}

bool MainScreenModel::GetSurrender() {
    return _model->bIsSurrender;
}

std::string MainScreenModel::GetCurrentPlayer() const {
    std::string player;
    if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
    player = "Black";
    }
    else {
    player = "White";
    }
    return std::move(player);
}

GameStatusStore::Player MainScreenModel::GetWinner() const {
    GameStatusStore::Player winner(GameStatusStore::Player::NONE);
    if (_model->bIsSurrender) {
    if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
        winner = GameStatusStore::Player::BLACK;
    }
    else if (_model->mLastPlayer == GameStatusStore::Player::BLACK) {
        winner = GameStatusStore::Player::WHITE;
    }
    }
    else {
    if (_model->mWhiteScore == 12) {
        winner = GameStatusStore::Player::WHITE;
    }
    else if (_model->mBlackScore == 12) {
        winner = GameStatusStore::Player::BLACK;
    }
    }
    return winner;
}

bool MainScreenModel::GetDirection() const {
    bool direction;
    switch(_model->mLastPlayer) {
    case GameStatusStore::Player::WHITE:
    direction = false;
    break;
    default:
    direction = true;
    break;
    }
    return direction;
}

movePos MainScreenModel::GetMove(std::string line1, std::string line2) {
    movePos position;
    size_t p1, p2;
    bool isLine1Number = true, isLine2Number = true;
    std::for_each(line1.cbegin(), line1.cend(), [&](char c) { if (!isdigit(c)) isLine1Number = false; });
    std::for_each(line2.cbegin(), line2.cend(), [&](char c) { if (!isdigit(c)) isLine2Number = false; });
    if (!isLine1Number || !isLine2Number) {
    if (line1 == "ff") {
        position.first.first = 0;
        position.first.second = 0;
        position.second.first = 0;
        position.second.second = 0;
    }
    else {
        position.first.first = 1;
        position.first.second = 1;
        position.second.first = 1;
        position.second.second = 1;
    }
    }
    else {
    p1 = static_cast<size_t>(std::stoi(line1));
    p2 = static_cast<size_t>(std::stoi(line2));
    position.first.first = p1 / 10;
    position.first.second = p1 - 10 * position.first.first;
    position.second.first = p2 / 10;
    position.second.second = p2 - 10 * position.second.first;
    }
    return std::move(position);
}

void MainScreenModel::UpdateScore() {
    if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
    _model->mBlackScore++;
    }
    else {
    _model->mWhiteScore++;
    }
}

void MainScreenModel::SwitchPlayer() {
    if (_model->mLastPlayer == GameStatusStore::Player::WHITE) {
    _model->mLastPlayer = GameStatusStore::Player::BLACK;
    }
    else {
    _model->mLastPlayer = GameStatusStore::Player::WHITE;
    }
}

std::string MainScreenModel::CastPlayer(GameStatusStore::Player player) const {
    std::string playerStr;
    switch (player) {
    case GameStatusStore::Player::WHITE:
    playerStr = "White player";
    break;
    default:
    playerStr = "Black player";
    break;
    }
    return playerStr;
}

void MainScreenModel::ChangeSurrender() {
    _model->bIsSurrender = true;
}
