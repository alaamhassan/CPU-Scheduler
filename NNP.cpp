#include "NNP.H"

priority_queue<pi1, vector<pi1>, greater<pi1>> same_arrival_time(priority_queue<pi1, vector<pi1>, greater<pi1>>& proc2, priority_queue<pi, vector<pi>, greater<pi>>& proc, int current_time) {


	int priority = 0;
	float arrival_time = 0;
	float burst_time = 0;
	int process_num = 0;

	if (current_time == 5) {
		int a = 0;
	}
	for (int i = 0; i < proc.size(); i++) {
		if (proc.top().first.first <= current_time) {
			arrival_time = proc.top().first.first;
			priority = proc.top().first.second;
			process_num = proc.top().second.first;
			burst_time = proc.top().second.second;
			proc2.push(make_pair(make_pair(priority, arrival_time), make_pair(process_num, burst_time)));
			proc.pop();
		}

	}
	return proc2;
}
bool is_found(priority_queue<pi, vector<pi>, greater<pi>> proc, float current_time) {

	for (int i = 0; i < proc.size(); i++) {
		if (proc.top().first.first <= current_time)return 1;
	}
	return 0;
}

void Priority_NonPreemptive(vector<int> ID, vector<float> arrivalTime, vector<float> burstTime, vector<int> priority, float r_time, float& av_waiting_time,
	priority_queue< g, vector<g>, greater<g>>& process_waiting_time, vector<pair<int, pair<float, float>>>& gant_chart) {

	int no = ID.size();
	float current_time = 0;
	float waiting_time = 0;
	float p_waiting_time = 0;
	priority_queue<pi, vector<pi>, greater<pi>> proc;
	priority_queue<pi1, vector<pi1>, greater<pi1>> proc2;


	for (int i = 0; i < ID.size(); i++) {
		proc.push(make_pair(make_pair(arrivalTime.at(i), priority.at(i)), make_pair(ID.at(i), burstTime.at(i))));
	}
	current_time = proc.top().first.first;
	while (!proc.empty()) {
		proc2 = same_arrival_time(proc2, proc, current_time);
		while ((!proc2.empty()) && (!is_found(proc, current_time))) {

			pi1 current_proc = proc2.top();
			proc2.pop();

			waiting_time += (current_time - current_proc.first.second);
			gant_chart.push_back(make_pair(current_proc.second.first, make_pair(current_time, current_proc.second.second + current_time)));
			p_waiting_time = (current_proc.second.second + current_time - current_proc.first.second - current_proc.second.second);
			process_waiting_time.push(make_pair(current_proc.second.first, p_waiting_time));
			current_time = current_proc.second.second + current_time;

		}

	}



}