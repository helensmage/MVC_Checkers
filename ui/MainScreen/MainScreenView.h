#pragma once

#include "MainScreenModel.h"
#include "../../store/GameStatusStore.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

using movePos = std::pair<pos, pos>;

class MainScreenView: public IView {
public:
   MainScreenView(MainScreenModel* model);
   void draw();

private:
   MainScreenModel* _model;
};
