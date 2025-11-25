#include <cstring>
#include <iostream>

using namespace std;
#define LOG(x) cout << x << endl

int main() {
    int var = 12;
    void* ptr = &var;
    LOG(var);

    char* buffer = new char[8];
    LOG(memset(buffer, 0, 8));
    char** ptr1 = &buffer;
    delete[] buffer;

    cin.get();
}