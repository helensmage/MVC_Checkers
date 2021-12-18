#pragma once

#include <utility>
#include <string>
#include "../../common/IModel.h"

using pos = std::pair<std::size_t, std::size_t>;

class CellModel : public IModel
{
public:
  enum class State {BLACK, WHITE, BLANK};
  CellModel(State state);
  State GetState() const { return mState; }
  void SetState(State state) { mState = state; }
  std::string CastState();
  void update() { notifyUpdate(); }

private:
  State mState;
};
