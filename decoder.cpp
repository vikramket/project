#include<bits/stdC++.h>
using namespace std;
//Decoding without tree 
//input format:
/* 1.no. of elements in key charts
   2.character stringcode(encoded)
   3.encoded string */
void decoder(unordered_map<string,char> huffmanCode,string encodedstring){
    string ans;
    string str="";
    for(int i=0;i<encodedstring.size();i++){
      if(huffmanCode.find(str) != huffmanCode.end()){
            auto k=huffmanCode.find(str);
            char chh=k->second;
            ans.push_back(chh);
            str="";
      }
      str.push_back(encodedstring[i]);
    }
    cout<<ans;

}
int main(){
    int n;
    cin>>n;
    unordered_map<string,char> huffmanCode;
    while(n--){
        string s;
        char ch;
        cin>>ch>>s;
        huffmanCode.insert({s,ch});
            }
    string encodedstring;
    cin>>encodedstring;
  decoder(huffmanCode,encodedstring);
  return 0;
}