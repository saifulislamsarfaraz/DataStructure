#include "functions.h"
#include <bits/stdc++.h>
#define XX first
#define YY second
using namespace std;
char sample[5][25]={"7+(7/7)+(7+7)*2-4", "4/2+2+2+(4/(8-6))", "1*(3-2)-3*2", "2*7+4/2-(2*2+3)", "(6+2)*(6+7-1)+2*9"};

char operators[]={'-', '+', '*'};
string digits[]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

string concat(pair <string, int> p1, int ind, pair <string, int> p2){
    return "("+p1.XX+")"+operators[ind]+"("+p2.XX+")";
}

pair <string, int> generate_infix(int lim){
    if(lim<=6){
        int ind1=rand()%10;
        int ind2=rand()%10;
        int ind3=rand()%10;
        int ind4=1;
        int val=0;
        bool toSwap=false;
        if(ind4==0){
            val=(digits[ind1][0]-'0')-(digits[ind2][0]-'0')*(digits[ind3][0]-'0');
            if(val<0){
                toSwap=true;
                val*=-1;
            }
        }
        else{
            val=(digits[ind1][0]-'0')+(digits[ind2][0]-'0')*(digits[ind3][0]-'0');
        }
        if(toSwap) return {digits[ind2]+operators[2]+digits[ind3]+operators[ind4]+digits[ind1], val};
        return {digits[ind1]+operators[ind4]+digits[ind2]+operators[2]+digits[ind3], val};
    }
    pair <string, int> p1=generate_infix((lim-5)/2-1);
    pair <string, int> p2=generate_infix(lim-5-((lim-5)/2-2));
    int ind;
    if(p1.YY<100 && p2.YY<100)ind=rand()%3;
    else ind=rand()%2;
    if(ind==0){
        if(p1.YY>p2.YY) return {concat(p1, ind, p2), p1.YY-p2.YY};
        return {concat(p2, ind, p1), p2.YY-p1.YY};
    }
    if(ind==1){
        return {concat(p1, ind, p2), p1.YY+p2.YY};
    }
    return {concat(p1, ind, p2), p1.YY*p2.YY};
}


char infix[100105];
char postfix[100105];
void string_to_char_array(string str){
    int len=0;
    for(int i=0; i<str.size(); i++){
        infix[i]=str[i];
        len++;
    }
    infix[len]=0;
}



int evaluate(){
    printf("The tester has not been implemented yet, it will be updated soon");
}
