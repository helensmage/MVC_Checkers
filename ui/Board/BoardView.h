#pragma once

#include "BoardModel.h"
#include "../../common/IView.h"
#include "../../ui/Cell/CellView.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

using pos = std::pair<std::size_t, std::size_t>;
using movePos = std::pair<pos, pos>;

class BoardView: public IView
{
public:
   BoardView(BoardModel* model);
   void draw();

private:
   BoardModel* _model;
};
