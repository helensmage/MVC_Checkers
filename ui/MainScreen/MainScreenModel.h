#pragma once

#include "../../common/IModel.h"
#include "../Cell/CellModel.h"
#include "../../store/GameStatusStore.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

using movePos = std::pair<pos, pos>;

class MainScreenModel : public IModel { 
public:
   MainScreenModel(GameStatusStore* model);
   void update();
   BoardModel& GetBoard();
   size_t GetWhiteScore();
   size_t GetBlackScore();
   bool GetSurrender();
   std::string GetCurrentPlayer() const;
   GameStatusStore::Player GetWinner() const;
   bool GetDirection() const;
   movePos GetMove(std::string line1, std::string line2);
   void UpdateScore();
   void SwitchPlayer();
   std::string CastPlayer(GameStatusStore::Player player) const;
   void ChangeSurrender();

private:
   GameStatusStore* _model;
};
