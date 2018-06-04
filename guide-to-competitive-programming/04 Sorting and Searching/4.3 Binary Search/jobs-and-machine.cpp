#include <bits/stdc++.h>

using namespace std;

const int n = 3;//#machines
const int jobs = 8;//#jobs
int p[3] = {2,3,7};//time to process jobs for each machine

//#jobs done at time unit 't'
int jobsDone(int t){
    int ans = t/p[0] + t/p[1] + t/p[2];
    return ans;
}

//(one value that we know is enough for processing all jobs)
int z = 8*p[0];//best we can do if we only use the fastest machine //one easy upperbound :)

int solution(){
    int k = -1;
    for(int b=z; b>=1; b/=2){
        while(jobsDone(b+k) < jobs) k+=b;
    }
    return k+1;
}

int main(){
    cout << solution() << endl;
    
    return 0;
}