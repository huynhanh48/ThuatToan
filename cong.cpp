#include <iostream>
using namespace std;
bool foud=false;
int giatri = 10;
int x[3] = {7,2,5};

void print() {
    for (int i = 0; i < 3; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void attemp(int k, int sum) {
    if (k == 3) {
        if (sum == giatri) {
        	foud=true;
            print();
        }
        return;
    }

    if (sum <= giatri) {
        for (int i = 1; i >= 0; i--) {
            if (i == 1) {
                attemp(k + 1, sum + x[k]);
            } else {
                attemp(k + 1, sum - x[k]);
            }
        }
    }
}

int main() {
    attemp(0, 0);
    if(!foud) cout<<"khong co phep cong hoac tru nao ca!";
    return 0;
}

