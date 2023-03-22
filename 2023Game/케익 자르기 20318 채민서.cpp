#include <iostream>
using namespace std;

int main() {
#pragma region 내 코드
    int numa, numb, numc, numd;
    cin >> numa >> numb >> numc >> numd;

    if (numa > numb) {
        int t = numa;
        numa = numb;
        numb = t;
    }

    if (numc > numd) {
        int t = numc;
        numc = numd;
        numd = t;
    }

    if ((numc < numa && (numd > numa && numd < numb)) || ((numc > numa && numc < numb) && numd > numb)) {

        cout << "cross";
        return 0;
    }

    cout << "not cross";
#pragma endregion

#pragma region 선생님 코드
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int cnt = 0;
    for (int i = a; i < b; i++) {
        if (i == c || i == d) {
            cnt++;
        }
    }
    if (cnt == 0 || cnt == 2)
        cout << "not cross";
    else
        cout << "cross";
#pragma endregion

}