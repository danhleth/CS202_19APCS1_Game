#include "includePath.h"
#include "thread.cpp"

int main() {
    thread t1(ThreadFunc1);
    while (1) {
        system("PAUSE");
        /*int temp = toupper(cin.get());
        if (temp == 27) {
            exitGame(&t1); 
            return 0;
        }*/
    }
    return 0;
}