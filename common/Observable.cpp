#include "IView.h"

#include <vector>

class Observable
{
public:
    void addObserver(IView* observer) {
      _observers.push_back(observer);
    }
    void notifyUpdate() {
      int size = _observers.size();
      for (int i = 0; i < size; i++)
      {
         _observers[i]->draw();
      }
   }
private:
   std::vector<IView*> _observers;
};
