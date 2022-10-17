#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector <int> coinRow(vector <int>& arr){
    vector <int> F (arr.size(), -1);
    F[0] = 0;
    F[1] =  arr[0];
    for (int i =1; i < arr.size(); i++){
        F[i + 1] = max(arr[i] + F[i - 1], F[i]);
    }
    return F;

}

int main (){

    string input = "1 2 21 12 48 20 10 ";
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
    answer = coinRow(arr);
    for (int i = 0; i < answer.size(); i ++){
        cout << answer[i] << "\n";
    }
    

    return 0;
}