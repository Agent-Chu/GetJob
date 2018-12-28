//
//  main.cpp
//  Code
//
//  Created by ChuangLiu on 2018/12/23.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

using namespace std;

int countRange(const int* number,int length,int start,int end){
    int count = 0;
    for (int i = 0; i < length ; i++){
        if(number[i]<=end && number[i]>=start){
            count++;
        }
    }
    return count;
}

//const int* number表示指向数组的指针，不会改变
int duplicate(const int* number, int length){
    //检查输入合法性
    if (number == nullptr || length <= 0){
        return -1;
    }
    
    //二分的标准写法
    int start = 1;
    int end = length - 1;
    while(end >= start){
        int middle = (end + start) / 2;
        int count = countRange(number,length,start,middle);
        if (end == start){
            if (count>1){
                return start;
            }
            else{
                break;
            }
        }
        if(count > (middle-start+1) ){//非左即右
            end = middle;
        }
        else{
            start = middle+1;
        }
        
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int number[] = {2,3,5,4,3,2,6,7};
    int n = 7;
    int length = n+1;
    int f = duplicate(number,length);
    if(f != -1){
        cout<<f<<"\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}
