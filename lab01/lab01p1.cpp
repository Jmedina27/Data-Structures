#include "Clock.h"

using namespace std;

int main()
{
    Time start = Time(12, 0);
    Time end = Time(1, 15);
    for (int i = 0; i < 75; i++) {
        sleep(1); //sleep 60 seconds
        --end;  //subtract a minute to end 
    }
    if (end == start) {
        cout << "class dismissed"; // displays class dismissed when end is equal to start
    }
}