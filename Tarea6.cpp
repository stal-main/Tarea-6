
#include <iostream>

#include"LinkedList.h"    

using std::cout;
using std::endl;
using std::cin;

void radixSort(LinkedList<int>& list, int maxDigits) {

    LinkedList<int> buckets[10];

    int divisor = 1;

    for (int d = 0; d < maxDigits; d++) {

        while (!list.atEnd()) {

            int digit = (list.getElement() / divisor) % 10;

            buckets[digit].append(list.getElement());

            list.next();
        }

        list.clear();

        for (int i = 0; i < 10; i++) {

            while (!buckets[i].atEnd()) {

                list.append(buckets[i].getElement());

                buckets[i].next();
            }

            buckets[i].clear();
        }

        divisor *= 10;
    }
}

int main() {

    int listSize;

    int numericBase;

    cout << "Introduce the size of the list to be sorted: " << endl;

	cin >> listSize;

    cout << "Introduce the numeric base to be used: " << endl;

	cin >> numericBase;


}
