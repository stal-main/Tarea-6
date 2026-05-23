
#include <iostream>
#include <cstdlib>
#include <time.h>
#include"LinkedList.h"    

using std::cout;
using std::endl;
using std::cin;

int getMax(LinkedList<int>& list) {

    list.goToStart();

    int max = 0;

    while (!list.atEnd()) {

        if (list.getElement() > max) {

            max = list.getElement();
        }

        list.next();
    }

    return max;
}

void radixSort(LinkedList<int>& list, int base) {

    if (list.getSize() == 0) {
        return;
	}

	int max = getMax(list);

    int numPass = 1;

	int tempMax = max;

    while (tempMax >= base) {

        numPass++;

        tempMax /= base;
	}

    LinkedList<int>* buckets = new LinkedList<int>[base];

    int divisor = 1;

    for (int d = 0; d < numPass; d++) {

        list.goToStart();

        while (!list.atEnd()) {

            int digit = (list.getElement() / divisor) % base;

            buckets[digit].append(list.getElement());

            list.next();
        }

		list.clear();

        for (int i = 0; i < base; i++) {

			buckets[i].goToStart();

            while (!buckets[i].atEnd()) {

                list.append(buckets[i].getElement());

                buckets[i].next();
            }

            buckets[i].clear();
        }

        divisor *= base;
    }

    delete[] buckets;
}

int main() {

    srand(time(nullptr));

    bool continuate = true;

    while (continuate) {

        int listSize;

        int numericBase;

        cout << "Introduce the size of the list to be sorted: " << endl;

        cin >> listSize;

        cout << "Introduce the numeric base to be used: " << endl;

        cin >> numericBase;

        if (numericBase < 2) {

            cout << "Numeric base must be at least 2. Try again" << endl;
		}

        else {

            LinkedList<int> list;

            for (int i = 0; i < listSize; i++) {

                list.append(rand() % 100000);
            }

            if (listSize <= 20) {

                cout << "Original list: ";

                list.print();

            }  

            clock_t start = clock();

			radixSort(list, numericBase);

            clock_t end = clock();

			double seconds = double(end - start) / CLOCKS_PER_SEC;
       
            if (listSize <= 20) {

                cout << "Sorted list: ";

                list.print();
            }         

			cout << "Sorted " << listSize << " elements in " << seconds << " seconds." << endl;

        }

		cout << "Do you want to sort another list? (y/n)" << endl;

		char response;

		cin >> response;

		continuate = (response == 'y' || response == 'Y');
    }

    return 0;

}
