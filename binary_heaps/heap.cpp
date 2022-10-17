#include <iostream>
using namespace std;


class Top_Down{
    public:
    int size = 2;
    int count = 0;
    int* arr = NULL;

    Top_Down();
    void insert(int value);
    void going_up(int value, int pos);
};

Top_Down :: Top_Down(){
    arr = new int[size];
}

void Top_Down :: going_up(int value, int pos){
    arr[pos] = value;

    int father_pos = (int) pos/2;

    if(pos == 1){
        return;
    }
    else if (arr[pos] > arr[father_pos]){
        arr[pos] = arr[father_pos];
        going_up(value, father_pos);
    }
    else{
        return;
    }

}

void Top_Down :: insert(int value){
    if (count < size - 1){
        going_up(value, count + 1);
        count ++;
    }
    else{
        int* aux_arr = new int[size*2];

        for (int i =0; i < size; i ++){
            aux_arr[i] = arr[i];
        }
        size = size * 2;
    }

}

void bottom_up(int* &arr, int size){
    int k, v;
    bool heap;
    for (int i = (int) size/2; i >= 1; i--){
        heap = false;
        k = i;
        v = arr[i];

        while(!heap && 2*k <= size){
            int j = 2* k;

            if (j < size){
                if (arr[j] < arr[j+1]){
                    j ++;
                }
            }

            if (v >= arr[j]){
                heap = true;
            }
            else{
                arr[k] = arr[j];
                k = j;
            }
        }

        arr[k] = v;
    }
}

int main(){
    int* arr = new int[5];
    arr[0] = 9;
    arr[1] = 1;
    arr[2] = 4;
    arr[3] = 2;
    arr[4] = 10;

    bottom_up(arr, 5);

    for (int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
    cout << "------------------------\n";

    Top_Down heap;
    heap.insert(2);
    heap.insert(1);
    cout << heap.size << "-" << heap.count;
    for (int i = 1; i < heap.size; i++){
        cout << heap.arr[1] << endl;
    }

}