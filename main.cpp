#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double resGoodForA = 0.0;
int k;


inline int numbersInNimber(unsigned int n){
    if ( n < 10 ) return 1;
    else return (1 + numbersInNimber(n/10));
}


inline long fact(int n){
    if (n <= 1) return n;
    else return(n * fact(n-1));
}




inline long countAllVariants(unsigned int n, int k){
    long C;
    int numb = numbersInNimber(n);
    if((numb - 2) > 0)
        C = fact(numb)/(2 * fact(numb - 2));
    else
        C = fact(numb)/(2);
    return pow(C, k);
}


inline void swap(int *a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}


inline void isGoodForAs(unsigned int res){
  cout << res << endl;
}

inline void Test(int *a, int k, int ttt){
    unsigned int res = 0;

    for (int i = 0; i < ttt; ++i){
        int pptr = a[ttt - 1 - i];
        res = res + pptr*pow(10, i);
    }

    if(k == 0) {cout << res << endl;;
    }
    else {
        for(int m = 0; m <ttt; ++m){
            for(int n = m+1; n <ttt; ++n){
                swap(a, m, n);
                Test(a, k - 1, ttt);
                swap(a, n, m);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cout << "Enter N and k:" << endl;
    unsigned int n;
    cin >> n;
    cin >> k;

    int numb = numbersInNimber(n);

    int ptrK = k;
    int ttt =numb;
    int *a = new int[numb];
    unsigned int ptr = n;
    for (int i = numb - 1; i >= 0; --i){
        a[i] = ptr%10;
        ptr = ptr / 10;
    }

    Test(a, ptrK, ttt);

    cout << endl << "Total number of permutations: " << countAllVariants(n, k) << endl;
    return 0;
}
