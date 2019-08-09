#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> build_counter(vector<int> & data, int size){
    vector<int> counter(201,0);
    for(int i = 0; i < size; i++){
        counter[data[i]]++;
    }
    return counter;
}

double getMedian(vector<int> &counter, int mid_element, bool isEven){
    for(int i = 0; i < 201; i++){
        mid_element-=counter[i];
        if(mid_element < 0){
            return i;
        }else{
            if(mid_element == 0){
                if(!isEven){
                    return i;
                }else{
                    for(int j = i+1; j < 201; j++){
                        if(counter[j]>0){
                            return (i+j)/2.0;
                        }
                    }
                }
            }
        }
    }
    cout << "something goes wrong" << endl;
    return -1;
}
/*
double getMedian(vector<int> &counter, int mid_element, bool isEven){
    double answer = 0;
    if(!isEven){
        for(int i = 0; i < 201; i++){
            mid_element-=counter[i];
            if(mid_element <= 0){
                return i;
            }
        }
    }
    else{
        int answer = 0;
        for(int i = 0; i < 201; i++){
            mid_element-=counter[i];
            if(mid_element < 0){
                return i;
            }else if(mid_element == 0){
                answer = i;
                for(int j = i+1; j < 201; j++){
                    if(counter[j] > 0){
                        answer +=j;
                        return answer/2.0;
                    }
                }
            }
        }
    }
    return -1;
}*/



// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int n = expenditure.size();
    int answer = 0;
    bool isEven = (d % 2) == 0;
    int mid_position = d / 2; // size_window / 2
    if(!isEven){
        mid_position++;
    }
    vector<int> counter = build_counter(expenditure, d);
    for(int i = 0; i < n-d; i++){
        double median = getMedian(counter,mid_position,isEven);
        int current_expenditure = expenditure[i+d];
        if(current_expenditure >= 2*median){
            answer++;
        }
        counter[expenditure[i]]--;
        counter[expenditure[i+d]]++;
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

