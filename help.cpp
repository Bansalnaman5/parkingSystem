#include<iostream>
#include<fstream>
using namespace std;

string pre="DL1ABC";
ofstream myfile("input.txt",ios_base::app);
void getperm(string inp,string out){
    if(inp.size()==0){
        myfile<<1<<'\n';
        myfile<<pre+out<<'\n';
        return;
    }
    for(int i=0;i<inp.size();i++){
        char c=inp[i];
        getperm(inp.substr(0,i)+inp.substr(i+1),out+c);
    }
    return;
}
int main(){
    getperm("1234","");
    getperm("9870","");
    getperm("5678","");
    getperm("4907","");
    myfile<<3;
    return 0;
}