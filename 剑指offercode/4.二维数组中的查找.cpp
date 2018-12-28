//
//  main.cpp
//  Code
//
//  Created by ChuangLiu on 2018/12/23.
//  Copyright © 2018 ChuangLiu. All rights reserved.
//

#include <iostream>

using namespace std;

//右上开始
bool Find1(int* matrix, int rows, int columns, int number){
    //检查输入合法性
    if (matrix == nullptr || rows == 0 || columns == 0){
        return false;
    }
    
    int rows_point = 0;
    int columns_point = columns-1;
    
    while(rows_point<rows && columns_point>=0){
        //因为传递的是指针，所以只能用这种形式
        if(matrix[rows_point * columns + columns_point]>number){
            columns_point--;
        }
        if(matrix[rows_point * columns + columns_point]<number){
            rows_point++;
        }
        else{
            return true;
        }
    }
    
    return false;
}

//左下开始
bool Find2(int* matrix, int rows, int columns, int number){
    //检查输入合法性
    if (matrix == nullptr || rows == 0 || columns == 0){
        return false;
    }
    
    int rows_point = rows - 1;
    int columns_point = 0;
    
    while(rows_point>=0 && columns_point<columns){
        //因为传递的是指针，所以只能用这种形式
        if(matrix[rows_point * columns + columns_point]>number){
            rows_point--;
        }
        if(matrix[rows_point * columns + columns_point]<number){
            columns_point++;
        }
        else{
            return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    int matrix[4][4] = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}
    };
    int rows = 4;
    int columns = 4;
    if(Find1((int*)matrix,rows,columns,7)){
        cout<<"yes1\n";
    }
    if(Find2((int*)matrix,rows,columns,7)){
        cout<<"yes2\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}
