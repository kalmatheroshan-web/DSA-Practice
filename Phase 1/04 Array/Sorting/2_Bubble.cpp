#include <iostream>
#include <vector>
using namespace std;

void bubble_asc(vector<int> &ar) {
    int n = ar.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (ar[j] > ar[j + 1]) {
                swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

void bubble_des(vector<int> &ar) {
    int n = ar.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (ar[j] < ar[j + 1]) {
                swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

void bubble_last(vector<int> &ar) {
    int n = ar.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = n - 1; j > i; j--) {
            if (ar[j - 1] > ar[j]) {
                swap(ar[j - 1], ar[j]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

/*
        time : O(N*N)
        space : O(1)
        stable : yes
*/

int main() {
    vector<int> ar = {7, 4, 2, 3, 5};

    bubble_last(ar);

    cout << "Printing array " << endl;
    for (int val : ar)
        cout << val << " ";
    cout << endl;

    return 0;
}
