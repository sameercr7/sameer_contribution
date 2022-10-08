// RABIN KARP ALGORITHM + question


#include <bits/stdc++.h> 
using namespace std;
// ismein semicoloumn ni hoga
// q smjha diya kyn lgya h
// d jo h rolling hash ke concept keliye lgya hua h




#define d 256
const int q=101;
int rabinkarpi(string pat,string txt){
    int M=pat.size();
    int N=txt.size();
    
    //for calculating hash (d^(M-1))%q 
    int h=1;
    for(int i=1;i<=M-1;i++)
    // we can use for like this also for(int i=0;i<M-1;i++)
        h=(h*d)%q;
    
     // Calculate the hash value of pattern and first 
    // window of text 
    int p=0,t=0;
    for(int i=0;i<M;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
      //   now check krna h ki p aur t khna equal h
    // loop (n-m) tk chalega
    for(int i=0;i<=(N-M);i++){
       
       if(p==t){
           bool flag=true;
           for(int j=0;j<M;j++)
                if(txt[i+j]!=pat[j]){flag=false;break;}
            if(flag==true)
              return 1;
       }
       // if p==t ke ni hua to hum slide krenge ab
        // mtlb t nikalenge kynki p to same hi rhega
       if(i<N-M){
         // abdul bari ka ss dkhlena smjh aajayega
            // we are doing  modulo taaki overflow na ho

           t=((d*(t-txt[i]*h))+txt[i+M])%q;
        if(t<0)t=t+q;
       }
    }
    return 0;
    
}
 
int rabinkarp(string A,string B) 
{ 
    // string a = "aaac",b="aac";
    // cout<<"All index numbers where pattern found:"<<" ";
    // RBSearch(b,a,3,4);
    // edge cases
        if(A == B) return 1;
        
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            source+=A;
            count++;
        }
        
        // edge cases
        if(source == B) 
            return count;
        
        if(rabinkarpi(B,source) == 1) 
            return count;
        
        if(rabinkarpi(B,source+A) == 1) 
            return count+1;
        return -1;
    }

    int main(){
        string a="a",b="aa";
        cout<<rabinkarp(a,b);
        return 0;
    }
    
      

























    




