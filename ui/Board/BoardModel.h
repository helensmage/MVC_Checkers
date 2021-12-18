#pragma once

#include "../Cell/CellModel.h"
#include "../../common/IModel.h"

#include <map>

using map1 = std::map<pos, CellModel>;

class BoardModel : public IModel
{
public:
  enum class MoveResult { SUCCESSFUL_MOVE, SUCCESSFUL_COMBAT, PROHIBITED, FF };
  BoardModel();
  ~BoardModel();
  void ResetMap();
  MoveResult MakeMove(const pos& startPos, const pos& endPos, bool direction, bool forceCombat = false);
  map1& GetMap() { return mCells; }
  void update() { notifyUpdate(); }

private:
  MoveResult CheckMove(const pos& startPos, const pos& endPos, bool direction);
  const size_t mBoardSize;
  map1 mCells;
};
