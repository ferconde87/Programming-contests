#include <fstream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using std::getline;
using std::string;

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

int distance(pair<int, int> x, pair<int, int> y){
    return max(abs(x.first-y.first),abs(x.second-y.second));
}


int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int H, W;
    fin >> W >> H;
    unordered_map<char, pair<int, int> > map;
    for(int i = H; i >= 1; i--){
        for(int j = 1; j <= W; j++){
            char c;
            fin >> c;
            map.insert(make_pair(c, (make_pair(i,j))));
        }
    }

    // for(auto it = map.begin(); it != map.end(); it++){
    //     pair<int, int> p = it->second;
    //     cout << it->first << " (" << p.first << ", " << p.second << ") " << endl;
    // }
    // cout << endl;
    fin.ignore();//esto hace que consuma el "\n" (porque al usar >> el 'cursor' queda en el "\n")
    string best_language = "";
    int min_cost = 10000000;//is better using max_int possible
    for(int L = 0; L < 3; L++){
        string language;
        getline(fin, language);
        string line;
        getline(fin, line);//%TEMPLATE-START%
        //getline(fin, line);
        int cost = 0;
        char y = ' ';//necesito guardarme la última tecla de cada línea del template
        pair<int, int> posy;
        while(getline(fin, line)){
            if(line.compare("%TEMPLATE-END%") == 0) break;
            // cn(line)
            size_t found = line.find_first_not_of(" ");
            if(found == string::npos) found = 0;
            char x = line[found];
            auto posx = map.find(x)->second;
            if(!isblank(y)) cost += distance(posx,posy);
            if(found + 1 >= line.size()) y = x;//no entra al for => y no tiene el último char
            for(int i = found+1; i < line.size(); i++){
                // cn(line)
                if(line[i]==' ') continue;
                y = line[i];
                posy = map.find(y)->second;
                cost += distance(posx,posy);
                x = y;
                posx = posy;
            }
        }

        if(cost < min_cost){
            best_language = language;
            min_cost = cost;
        }
    }

    fout << best_language << endl;
    fout << min_cost;

    return 0;
}