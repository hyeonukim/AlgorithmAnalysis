/*
Question from: https://school.programmers.co.kr/learn/courses/30/lessons/42891?language=python3
*/

#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k){
    long long sum_val = 0;
    //if total food_time is smaller than k, return -1
    for (int i = 0; i < food_times.size(); i++){
        sum_val += food_times[i];
    }
    if (sum_val <= k) return -1;

    //use priority queue so we can get rid of the food with least time
    priority_queue< pair<int, int> > pq;
    for (int i = 0; i < food_times.size(); i++){
        //push how long each food takes to eat, and food number
        pq.push({-food_times[i], i+1});
    }

    long long previous;
    long long length = food_times.size();

    //sum_val + (curr food time - previous food time) * number of food left
    while (sum_val + ((-pq.top().first - previous) * length) <= k){
        int curr = -pq.top().first;
        pq.pop();
        sum_val += (curr - previous) * length;
        length--; //remove the food that's done
        previous = curr;
    }

    //check what food we're on
    vector<pair<int, int>> res;
    while (!pq.empty()){
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        res.push_back({food_time, num});
    }
    sort(res.begin(), res.end(), compare);
    return res[(k-sum_val) % length].second;
}
