//
//  main.cpp
//  Code
//
//  Created by ChuangLiu on 2018/12/23.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

using namespace std;

//使用hash
bool duplicate1(int number[], int length, int *duplication){
    //检查输入合法性
    if (number == nullptr || length <= 0){
        return false;
    }
    for (int i=0; i<length;){
        if ( number[i]<0 || number[i]>length-1 ){
            return false;
        }
    }
    int *hash = new int[length+1];
    memset(hash, -1, sizeof(int) * length);
    
    for(int i=0; i<length; i++){
        if (hash[number[i]]==-1){
            hash[number[i]] = number[i];
        }
        else{
            *duplication = number[i];
            return true;
        }
    }
    return false;
}

//交换方法
bool duplicate2(int number[], int length, int *duplication){
    //检查输入合法性
    if (number == nullptr || length <= 0){
        return false;
    }
    for (int i=0; i<length;){
        if ( number[i]<0 || number[i]>length-1 ){
            return false;
        }
    }
    for (int i=0; i<length;){
        int num = number[i];
        if (num != i){
            if (num == number[num]){
                *duplication = number[i];
                return true;
            }
            number[i] = number[num];
            number[num] = num;
        }
        else if(num == i){
            i++;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int number[] = {2,3,1,0,2,5,3};
    int duplication;
    int length = 7;
    if(duplicate1(number,length,&duplication)){
        cout<<duplication<<"\n";
    }
    if(duplicate2(number,length,&duplication)){
        cout<<duplication<<"\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}
