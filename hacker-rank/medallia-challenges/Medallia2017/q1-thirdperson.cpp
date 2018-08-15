#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

enum CivilStatus{
    divorced,
    single,
    widowed
};

CivilStatus getStatus(string status){
    if(status == "divorced") return divorced;
    if(status == "single") return single;
    return widowed;
}

struct Person{
    int id;
    double salary;
    int number_of_children;
    CivilStatus civilStatus;
    int age;
};

struct idSalary{
    int id;
    double salary;
};

bool constraintsOK(Person p){
    if(p.civilStatus != single) return false;
    if(p.number_of_children == 0 || p.number_of_children > 3) return false;
    if(p.age < 30 || p.age > 40) return false;
    return true;
}

idSalary getClosestSalaryLessThan(idSalary max_e, vector<Person> & ps){
    int n = ps.size();
    idSalary closestOK;
    closestOK.salary = INT_MIN;
    closestOK.id = -1;
    for(int i = 0; i < n; i++){
        Person p = ps[i];
        if(max_e.id == p.id) continue;
        //no hace falta descontar el 15% a todos, solo importa el ID
        double salary = p.salary*(100-(4-p.number_of_children))/100;
        if(salary <= max_e.salary && salary > closestOK.salary){
            closestOK.salary = salary;
            closestOK.id = p.id;
        }
    }
    return closestOK;
}

int getThirdPerson(Person * ps, int n){
    vector<Person> psOK;
    for(int i = 0; i < n; i++){
        Person p = ps[i];
        if(constraintsOK(p)){
            psOK.push_back(p);
        }
    }
    idSalary answer;
    answer.salary = INT_MAX;
    answer.id = -1;
    answer = getClosestSalaryLessThan(answer, psOK);
    cout << answer.id << " " << answer.salary << endl;
    answer = getClosestSalaryLessThan(answer, psOK);
    cout << answer.id << " " << answer.salary << endl;
    answer = getClosestSalaryLessThan(answer, psOK);
    cout << answer.id << " " << answer.salary << endl;
    return answer.id;
}

int main(){
    int n; cin >> n;
    Person ps[n];
    for(int i = 0; i < n; i++){
        Person p;
        cin >> p.id;
        cin >> p.salary;
        cin >> p.number_of_children;
        string status; cin >> status;
        p.civilStatus = getStatus(status);
        cin >> p.age;
        ps[i] = p;
    }

    cout << "The person with ID = " << getThirdPerson(ps, n);//id 2
    cout << " has the third best salary that fulfill the given conditions.\n";
    return 0;
}