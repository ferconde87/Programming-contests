#include <bits/stdc++.h>

using namespace std;

#define cn(x) cout << #x << " = " << x << endl;

/*
Constraints
1 ≤ n ≤ 5 * 10 4
0 ≤ phone call durations ≤ 10 4
Cities names are in { Buenos Aires, Rosario, Viedma, Cusco,
Lima, Ayacucho, Rio de Janeiro, Belo Horizonte, Recife }
Buenos Aires, Rosario and Viedma are cities in Argentina.
Cusco, Lima and Ayacucho are cities in Peru.
Rio de Janeiro, Belo Horizonte and Recife are cities in Brazil.
All calls are measured in seconds
*/

enum City { BuenosAires, Rosario, Viedma, Cusco, Lima, Ayacucho, RioDeJaneiro, BeloHorizonte, Recife };
enum Country { Argentina, Brazil, Peru };
enum PhoneCallType { LocalPhoneCall, NationalPhoneCall, InternationalPhoneCall };

map<City, Country> cityToCountry;

struct PhoneCall{
    City from;
    City to;
    int durationInSeconds;
};


int phoneCallCost(PhoneCallType type, int durationInSeconds){
    if(type == LocalPhoneCall) return durationInSeconds;
    else if(type == NationalPhoneCall ){
        if(durationInSeconds <= 60) return 10;
        return 10 + durationInSeconds - 60;// = 10 + 1 per second after first minute
    }else{
        if(durationInSeconds <= 600) return 20*durationInSeconds;
        else return 15*durationInSeconds; //discont made after 10 minutes
    }
}

PhoneCallType getType(PhoneCall phoneCall){
    if(phoneCall.from == phoneCall.to) return LocalPhoneCall;
    if(cityToCountry[phoneCall.from] == cityToCountry[phoneCall.to]) return NationalPhoneCall;
    return InternationalPhoneCall;
}

int CalculateCost(PhoneCall phoneCall){
    PhoneCallType type = getType(phoneCall);
    return phoneCallCost(type, phoneCall.durationInSeconds);
}


int main(){
    cityToCountry[BuenosAires] = Argentina;
    cityToCountry[Rosario] = Argentina;
    cityToCountry[Viedma] = Argentina;
    cityToCountry[Cusco] = Peru;
    cityToCountry[Lima] = Peru;
    cityToCountry[Ayacucho] = Peru;
    cityToCountry[RioDeJaneiro] = Brazil;
    cityToCountry[BeloHorizonte] = Brazil;
    cityToCountry[Recife] = Brazil;

    map<string, City> stringToCity;
    stringToCity["Buenos Aires"] = BuenosAires;
    stringToCity["Rosario"] = Rosario;
    stringToCity["Viedma"] = Viedma;
    stringToCity["Cusco"] = Cusco;
    stringToCity["Lima"] = Lima;
    stringToCity["Ayacucho"] = Ayacucho;
    stringToCity["Rio de Janeiro"] = RioDeJaneiro;
    stringToCity["Belo Horizonte"] = BeloHorizonte;
    stringToCity["Recife"] = Recife;

    map<string, PhoneCallType> stringToPhoneCall;
    stringToPhoneCall["LocalPhoneCall"] = LocalPhoneCall;
    stringToPhoneCall["NationalPhoneCall"] = NationalPhoneCall;
    stringToPhoneCall["InternationalPhoneCall"] = InternationalPhoneCall;

    int t; cin >> t;//test cases
    cin.ignore();
    for(int k = 0; k < t; k++){
        int n; cin >> n; cin.ignore();
        PhoneCall phoneCall[n];
        for(int i = 0; i < n; i++){
            string from; getline(cin, from);
            phoneCall[i].from = stringToCity[from];
        }
        for(int i = 0; i < n; i++){
            string to; getline(cin, to);
            phoneCall[i].to = stringToCity[to];
        }

        for(int i = 0; i < n; i++){
            cin >> phoneCall[i].durationInSeconds;
        }

        for(int i = 0; i < n; i++){        
            cout << CalculateCost(phoneCall[i]) << endl;
        }
    }

    return 0;
}