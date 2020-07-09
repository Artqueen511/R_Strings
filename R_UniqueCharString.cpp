//works aA-zZ strings-case insensitive
//E(Space) = O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool uniqStr_atoz(string str)
{
    int bitset=0,finder=0; //4 bytes
    //cout<< sizeof(bitset); int i=0;
	for(int i=0;i<str.length();i++)
	{
	   bitset = str[i]-'a';
	   //cout<<bitset<<" ";
	   if((finder & (1 << bitset)) >0)
	   {
	       return false;
	   }
	   finder= finder | (1 << bitset);
	}
	return true;
}
bool uniqStr_any(string str)
{
    int bitset=0,finder1=0,finder2=0,finder3=0; //4 bytes
    //cout<< sizeof(bitset); int i=0;
	for(int i=0;i<str.length();i++)
	{
	   bitset = str[i]-' ';
	   if(bitset<=31)
	   {
	   if((finder1 & (1 << bitset)) >0)
	   {
	       return false;
	   }
	   finder1= finder1 | (1 << bitset);
	   }
	   if (bitset>31 && bitset<=63){
	       bitset-=32;
	       if((finder2 & (1 << bitset)) >0)
	   {
	       return false;
	   }
	   finder2= finder2 | (1 << bitset);
	   }
	   if (bitset>63 && bitset<=127){
	       bitset-=64;
	       if((finder3 & (1 << bitset)) >0)
	   {
	       return false;
	   }
	   finder3= finder3 | (1 << bitset);
	   }
	   
	}
	return true;
}
/*bool uniqStr_any(string str0)
{
    bitset<96>strbit(0);
    bitset<96>strcheck(0);
    cout<<strcheck;
    cout<<strbit.size();
    for(int i=0;i<str0.length();i++)
	{
	    int bitpos = str0[i]-' ';
    if(strcheck & strbit.set(bitpos)) 
	   {
	       return false;
	   }
	   strcheck= strcheck | strbit.set(bitpos);
	}
	return true;
}
*/
int main() {
    string str1;
    cin>>str1;
    cout<<"-----method 1 | a to z case-insensitive------"<<endl;
    if(uniqStr_atoz(str1)){
        cout<<str1<<" has all unique characters!!"<<endl;}
    else{
    cout<<str1<<" doesn't have all unique characters"<<endl;}
    cout<<"-----method 2 | All characters case-sensitive------"<<endl;
    if(uniqStr_any(str1)){
        cout<<str1<<" has all unique characters!!"<<endl;}
    else{
    cout<<str1<<" doesn't have all unique characters"<<endl;}
    return 0;
   
}


//input1 - #Ccode{]+%
/*output1 
-----method 1 | a to z case-insensitive------
#Ccode{]+% doesn't have all unique characters
-----method 2 | All characters case-sensitive------
#Ccode{]+% has all unique characters!!*/
//GfGlink - https://ide.geeksforgeeks.org/4Km1fh49Ln