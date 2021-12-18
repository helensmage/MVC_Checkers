#pragma once

#include "CellModel.h"
#include "../../common/IView.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <algorithm>

class CellView: public IView
{
public:
   CellView(CellModel* model);
   void draw();

private:
   CellModel* _model;
};
