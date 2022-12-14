#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include "AvlTree.h"

using namespace std;

int main() {
    
    clock_t start, end;
    double time = 0;

    AvlTree<int> T;
    vector<int> list {-1, 829, -200, 500};
    for(int i = 0; i < list.size(); ++i)
    {
        T.insert(list[i]);
        cout << list[i] << " ";
    }
    cout << endl;
    T.printTree();
    cout << endl;

    AvlTree<int> T1;
    vector<int> list1 {2000, 20000, 200000, 2000000};

    int count = 0;
    while(count < list1.size())
    {
        int n = list1[count];
        int k = n;

        T1.makeEmpty();
        for(size_t j{1}; j <= n; ++j)
        {
            T1.insert(j);
        }
        start = clock();
        T1.printElement(1,k);
        end = clock();

        time = double(end-start) / CLOCKS_PER_SEC;
        cout << "The run time of " << n << "\tin test 1 cost: " << time << " s." << endl;

        count++;
    }

    AvlTree<int> T2;
    vector<int> list2 {int(pow(2,16)), int(pow(2,18)), int(pow(2,20)), int(pow(2,22))};

    int count2 = 0;
    while(count2 < list2.size())
    {
        int n = list2[count2];
        int k = log2(n);

	    T2.makeEmpty();
        for(size_t j{0}; j <= n; ++j)
        {
            T2.insert(j);
        }

        start = clock();
        T2.printElement(n,n + k - 1);
        end = clock();

        time = double(end-start) / CLOCKS_PER_SEC;
        cout << "The run time of " << n << "\tin test 2 cost: " << time << " s." << endl;

        count2++;
    }

    return 0;
}
