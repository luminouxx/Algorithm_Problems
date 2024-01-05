#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000000

int N, M;
int arr[MAX] = {0,};

void binarySearch(int key) {
    int start = 0;
    int end = N-1;
    int pivot = 0;

    while (start <= end) {
        pivot = (start + end) / 2;

        if (arr[pivot] == key) {
            cout << 1 << "\n";
            return;
        } else if (arr[pivot] > key) {
            end = pivot-1;
        } else if (arr[pivot] < key) {
            start = pivot+1;
        }
    }
    cout << 0 << "\n";
    return;
}

void setInput() {
    cin >> N;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    sort(arr, arr + N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    setInput();

    cin >> M;

    int temp;

    for (int j=0; j<M; j++) {
        cin >> temp;
        binarySearch(temp);
    }

    return 0;
}
