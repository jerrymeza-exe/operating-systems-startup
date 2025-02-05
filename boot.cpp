#include <iostream>
#include "boot.h"

using namespace std;

void systemBoot() {
    cout << "System Booting Up..." << endl;
    int i = 0;
    while(i <= 100) {
        cout << "Loading: " << i << "%" << endl;

        for (long j = 0; j < 1000000000; j++) {
            // waiting time
        }

        i = i + 20;
    }
    cout << "Boot Complete!" << endl;
}