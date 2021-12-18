#pragma once

#include "../ui/Board/BoardModel.h"
#include "../ui/Board/BoardView.h"

class GameStatusStore
{
public:
  GameStatusStore() : mWhiteScore(0), mBlackScore(0), mLastPlayer(Player::NONE), bIsSurrender(false) {}
  enum class Player { NONE, BLACK, WHITE };
  bool bIsSurrender;
  BoardModel mboard;
  BoardView* v = new BoardView(&mboard);
  size_t mWhiteScore;
  size_t mBlackScore;
  Player mLastPlayer;
};
