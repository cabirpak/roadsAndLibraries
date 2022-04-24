#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool comparef(vector<int> a, vector<int> b){
    return (a[0] < b[0]);
}

vector<vector<int>> solution(vector<vector<int>> a) {
    vector<vector<int>> r;
    vector<int> avgs;
    map<int, vector<int>> s;
    int i=0;
    for(vector<int> v : a){
        float avg = 0;
        for(int x : v)
            avg += x;
        avg /= (float)v.size();
        s[(int)(avg * 1000)].push_back(i);
        i++;
    }
    //sort(s.begin(), s.end());
    for(map<int,vector<int>>::iterator i = s.begin(); i!=s.end(); i++){
        r.push_back(i->second);
    }
    sort(r.begin(), r.end(), comparef);
    return r;
}

int main(){
vector<vector<int>> a = {{3,3,4,2}, 
 {4,4}, 
 {4,0,3,3}, 
 {2,3}, 
 {3,3,3}};
 vector<vector<int>> b = solution(a);
 for(vector<int> v:b){
    for(int x:v){
        cout << x<< ", ";
    }
    cout << endl;
 }
}

