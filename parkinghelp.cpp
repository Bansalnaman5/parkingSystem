// code by naman bansal
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#define spot pair<string,pair<string,long long int> >
using namespace std;
class Parking{
    spot spots[101];
    int currcars;
    int lastpark;
    ifstream myfileread;
    ofstream myfilewrite;
    public:
        Parking(){
            currcars=0;
            lastpark=1;
            myfileread.open("parking.txt");
            string temp;
            while(getline(myfileread,temp)){
                vector<string> t;
                string da="";
                split(temp,t);
                if(t[0]=="") continue;
                for(int i=3;i<t.size();i++) da+=" "+t[i];
                // cout<<t[1]<<" "<<t[2]<<" "<<da<<endl;
                spot o;
                o.first=t[1];
                o.second.first=da;
                o.second.second=stoll(t[2]);
                spots[stoi(t[0])]=o;
                currcars++;
                lastpark=stoi(t[0]);
            }
            myfileread.close();
        }
        void split(string s,vector<string> &temp){
            string curr="";
            for(int i=0;i<s.size();i++){
                if(s[i]!=' '){
                    curr+=s[i];
                }
                else{
                    temp.push_back(curr);
                    curr="";
                }
            }
            temp.push_back(curr);
        }
        int getSize(){
            return currcars;
        }
        int parkCar(string number){
            if(lastpark==101) return -1;
            spot curr;
            curr.first=number;
            time_t now=time(0);
            string d=ctime(&now);
            d=d.substr(0,d.size()-1);
            curr.second.first=d;
            curr.second.second=static_cast<long long int>(now);
            int find=-1;
            for(int i=1;i<lastpark;i++){
                if(spots[i].first==""){
                    find=i;
                    break;
                }
            }
            if(find==-1){
                spots[lastpark]=curr;
                lastpark++;
            }
            else{
                spots[find]=curr;
            }
            currcars++;
            return find==-1?lastpark-1:find;
        }
        int removeCar(string number){
            bool f=false;
            int curr=-1;
            for(int i=1;i<=lastpark;i++){
                if(spots[i].first==number){
                    f=true;
                    curr=i;
                    break;
                }
            }
            if(!f) return -1;
            spots[curr].first="";
            currcars--;
            long long int now=static_cast<long long int>(time(0));
            cout<<endl<<"Parked "<<number<<" at "<<spots[curr].second.first<<" ";
            return (int)(now-spots[curr].second.second);
        }
        void status(){
            if(getSize()==100) cout<<"Parking is Full !!"<<endl;
            else{
                for(int i=1;i<101;i++){
                    if(spots[i].first!=""){
                        spot temp=spots[i];
                        cout<<"Registration number : "<<temp.first<<" parked at spot "<<i<<" from "<<temp.second.first<<endl;
                    }
                }
                cout<<"Total "<<getSize()<<" cars are currently parked "<<endl;
            }
            return;
        }
        void out(){
            myfilewrite.open("parking.txt");
            for(int i=1;i<101;i++){
                if(spots[i].first!=""){
                    spot o=spots[i];
                    string k=o.second.first;
                    myfilewrite<<i<<" "<<o.first<<" "<<to_string(o.second.second)<<" "<<k.substr(0,k.size()-1)<<'\n';
                }
            }
            myfilewrite.close();
        }
};
int main(){
    Parking parking;
    ifstream inpfile("input.txt");
    while(1){
    int t;
    cout<<"1 . To park car "<<endl;
    cout<<"2 . To remove car"<<endl;
    cout<<"3 . To get Status of parking"<<endl;
    cout<<"4 . To exit"<<endl;
    inpfile>>t;
    if(t==1){
        cout<<endl<<"Enter registration number :";
        string g;
        inpfile>>g;
        cout<<endl;
        int p=parking.parkCar(g);
        if(p==-1) cout<<"Sorry car parking is FULL !!"<<endl;
        else cout<<"You can park your car at spot "<<p<<endl;
    }
    else if(t==2){
        string g;
        cout<<endl<<"Enter registration number of car : ";
        cin>>g;
        cout<<endl;
        int y=parking.removeCar(g);
        if(y==-1) cout<<"No car with registration "<<g<<" parked here !!"<<endl;
        else{
            string ans="";
            if(y/60>=60){
                ans+=to_string(y/3600)+" Hrs "+to_string(y%60)+" min ";
            }
            if(y/60<60){
                ans+=to_string(y/60)+" min "+to_string(y%60)+" seconds";
            }
            cout<<"You can take your car after paying for duration "<<ans<<endl;
        }
    }
    else if(t==3) parking.status();
    else if(t==4) {
        parking.out();
        break;
    }
    else{
        parking.out();
        break;
    }
    }
    return 0;
}