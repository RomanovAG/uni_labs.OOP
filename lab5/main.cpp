#include <iostream>
#include <thread>

using namespace std;

int func(const char *str)
{
    //while (true) {}
    cout << str;
    return 0;
}

int main()
{
    thread t(func, "t");
    thread h(func, "h");
    thread r(func, "r");
    thread e(func, "e");
    thread a(func, "a");
    thread d(func, "d");
    t.join();
    h.join();
    r.join();
    e.join();
    a.join();
    d.join();
//    t.detach();
//    h.detach();
//    r.detach();
//    e.detach();
//    a.detach();
//    d.detach();
    return 0;
}
