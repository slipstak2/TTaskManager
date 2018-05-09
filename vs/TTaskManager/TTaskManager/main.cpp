#include <iostream>
#include "Task.h"

using namespace std;

int main() {
   cout << sizeof(time_t);

   Project game;
   BaseTask* task =  game.rootTasks[0];
   Meeting meeting;
   meeting._participants = new Person[10] ;

   return 0;
}