#ifndef NNP_H
#define NNP_H

#include <iostream>
#include <utility>
#include <queue>
#include<map>

using namespace std;
typedef pair<pair<float, int>, pair<int, float>> pi;
typedef pair<pair<int, float>, pair<int, float>> pi1;
typedef pair<int, float> g;

priority_queue<pi1, vector<pi1>, greater<pi1>> same_arrival_time(priority_queue<pi1, vector<pi1>,
	greater<pi1>>& proc2, priority_queue<pi, vector<pi>, greater<pi>>& proc, int current_time);

bool is_found(priority_queue<pi, vector<pi>, greater<pi>> proc, float current_time);

void Priority_NonPreemptive(vector<int> ID, vector<float> arrivalTime, vector<float> burstTime, vector<int> priority, float r_time, float& av_waiting_time,
	priority_queue< g, vector<g>, greater<g>>& process_waiting_time, vector<pair<int, pair<float, float>>>& gant_chart);

#endif