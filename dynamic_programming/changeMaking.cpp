#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> changeMaking(vector <int>& arr, int given_money){
    vector <int> F (given_money +1, -1);
    F[0] = 0;


    for (int i = 1; i <= given_money ; i++){
        int temp = 429496295,  j = 0;
        while(j < arr.size() and i >= arr[j]){
            temp = min(F[i - arr[j]], temp);
            j += 1;
        }
        F[i] = temp + 1;
    }
    return F;

}

int main (){
    string input = "1 5 25 50 100 200 500 ";

    string a= "";
    vector <int> arr;
    vector <int> answer;
    for (auto i: input){
        if (i == ' '){

            arr.push_back(stoi(a));
            a = "";
            continue;
        }
        
        else{
            a += i;
        }
    }
    answer = changeMaking(arr, 20);
    for (int i = 0; i < answer.size(); i++){
        cout <<"Para " << i << " Reais: " << answer[i] << endl;
    }
}