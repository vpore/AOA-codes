#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int p[50]; // LPS table

void calc_LPS(string pattern, int m){
    int k = 0; // stores length of previous longest pattern
    p[0] = 0;
    int i = 1; // iterator of pattern string
    while(i<m){
        if(pattern[k] == pattern[i]){
            k++;
            p[i]=k;
            i++;
        }
        else{
            if(k!=0)
                k=p[k-1];
            else{
                p[i]=0;
                i++;
            }
        }
    }
}

void KMP_Matcher(string pattern, string text){
    int m = pattern.size();
    int n = text.size();
    calc_LPS(pattern, m);
    int i = 0; // iterator on text string
    int j = 0; // iterator on pattern string
    while(i < n){
        if(pattern[j] == text[i])
            i++, j++;
        if(j == m){
            cout<<"Pattern Found at index : "<<i-m<<endl;
            j = p[j-1];
        }
        else if(i<n && pattern[j]!=text[i]){
            if(j!=0)
                j=p[j-1];
            else
                i++;
        }
    }
}

int main(){
    string pattern;
    string text;
    cout<<"Enter the text"<<endl;
    cin>>text;
    cout<<"Enter the pattern"<<endl;
    cin>>pattern;
    KMP_Matcher(pattern, text);
    return 0;
}