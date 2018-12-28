//
//  main.cpp
//  Code
//
//  Created by ChuangLiu.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

using namespace std;

void ReplaceBank(char string[], int length){
    //检查输入合法性
    if (string == nullptr || length <= 0){
        return;
    }
    
    int i = 0;
    int stringlength = 0;
    int banknumber = 0;
    while(string[i]!='\0'){
        stringlength++;
        if(string[i]==' '){
            banknumber++;
        }
        i++;
    }
    
    int p1 = stringlength;
    int p2 = stringlength + banknumber*2;
    if(p2>length){
        return;
    }
    while(p1>=0 && p2>p1){
        if(string[p1]==' '){
            string[p2--] = '0';
            string[p2--] = '2';
            string[p2--] = '%';
            p1--;
        }
        else{
            string[p2] = string[p1];
            p1--;
            p2--;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    char str[20] = "we are happy";
    int length = 20;
    ReplaceBank(str,length);
    cout<<str<<"\n";
    return 0;
}