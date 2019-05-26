/* See https://www.youtube.com/watch?v=bGC2fNALbNU&list=PLBZBJbE_rGRVnpitdvpdY9952IsKMDuev&index=8 */
#include <iostream>
#include <array>
using namespace std;

array<int, 3> target_set = {1, 2, 3};

typedef unsigned int uint;

int main() {
    uint x = (1L<<target_set.size()) - 1; // 00000111

    for (uint mask = 0; mask <= x; ++mask) {
        cout << "Subset: ";
        for (int i = 0; i < target_set.size(); ++i) {
            if ((1<<i) & mask) {
                cout << target_set[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}