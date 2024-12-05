#include<bits/stdc++.h>
using namespace std;

class josAR{

    unordered_set<int>s;
    char characters[95]={' ','!','"','#','$','%','&', '\'' , '(' ,')','*','+',',','-','.', '/' , '0' ,'1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\', ']' ,'^','_' ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~'};
    char primary_arr[95];
    map<int,string>patterns;
    public:
    string key="";
    josAR(){
    patterns[0]="0";patterns[1]="01";patterns[2]="00";patterns[3]="011";patterns[4]="010";patterns[5]="001";patterns[6]="000";patterns[7]="0111";patterns[8]="0110";patterns[9]="0101";patterns[10]="0100";patterns[11]="0011";patterns[12]="0010";patterns[13]="0001";patterns[14]="0000";patterns[15]="01111";patterns[16]="01110";patterns[17]="01101";patterns[18]="01100";patterns[19]="01011";patterns[20]="01010";patterns[21]="01001";patterns[22]="01000";patterns[23]="00111";patterns[24]="00110";patterns[25]="00101";patterns[26]="00100";patterns[27]="00011";patterns[28]="00010";patterns[29]="00001";patterns[30]="00000";patterns[31]="011111";patterns[32]="011110";patterns[33]="011101";patterns[34]="011100";patterns[35]="011011";patterns[36]="011010";patterns[37]="011001";patterns[38]="011000";patterns[39]="010111";patterns[40]="010110";patterns[41]="010101";patterns[42]="010100";patterns[43]="010011";patterns[44]="010010";patterns[45]="010001";patterns[46]="010000";patterns[47]="001111";patterns[48]="001110";patterns[49]="001101";patterns[50]="001100";patterns[51]="001011";patterns[52]="001010";patterns[53]="001001";patterns[54]="001000";patterns[55]="000111";patterns[56]="000110";patterns[57]="000101";patterns[58]="000100";patterns[59]="000011";patterns[60]="000010";patterns[61]="000001";patterns[62]="000000";patterns[63]="0111111";patterns[64]="0111110";patterns[65]="0111101";patterns[66]="0111100";patterns[67]="0111011";patterns[68]="0111010";patterns[69]="0111001";patterns[70]="0111000";patterns[71]="0110111";patterns[72]="0110110";patterns[73]="0110101";patterns[74]="0110100";patterns[75]="0110011";patterns[76]="0110010";patterns[77]="0110001";patterns[78]="0110000";patterns[79]="0101111";patterns[80]="0101110";patterns[81]="0101101";patterns[82]="0101100";patterns[83]="0101011";patterns[84]="0101010";patterns[85]="0101001";patterns[86]="0101000";patterns[87]="0100111";patterns[88]="0100110";patterns[89]="0100101";patterns[90]="0100100";patterns[91]="0100011";patterns[92]="0100010";patterns[93]="0100001";patterns[94]="0100000";patterns[95]="0011111";
    }

    void keyGenerator(){
    while(s.size()!=96){
        int x=rand()%96;
        s.insert(x);
        }
    int k=0;
    for(auto i:s){
        primary_arr[k++]=characters[i];
    }
    }
    
    string decrypt(string key,string txt){
    string dtxt="";int s=0;
    for(auto i:key){
        string temp=txt.substr(s,int(i-'0'));
        s+=i-'0';
        for(auto j:patterns){
            if(j.second==temp){dtxt+=primary_arr[j.first];}
        }
    }
    // cout<<"dcrypted txt:"<<dtxt;
    return dtxt;
    }

    string encrypt(string txt){
        string ans="";
        for(auto i:txt){
        for(int j=0;j<=95;j++){
            if(primary_arr[j]==i){ans+=patterns[j];
            int n=patterns[j].length();
            key+=to_string(n);}
        }
    }
    // cout<<"encrypted text:"<<endl;
    // cout<<ans<<endl;
    // cout<<key<<endl;
    return ans;
    }
};


int main(){
    josAR obj1=josAR();
    obj1.keyGenerator();
    string s=obj1.encrypt("akshay");
    string key=obj1.key;
    string d=obj1.decrypt(key,s);
    cout<<d;
    josAR obj2=josAR();
    obj2.keyGenerator();
    obj2.encrypt("akshay");
    string key2=obj2.key;
    cout<<key<<" "<<key2;
    return 0;
}