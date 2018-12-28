# 剑指 Offer

- [剑指 Offer 题解](https://github.com/CyC2018/CS-Notes/blob/master/docs/notes/%E5%89%91%E6%8C%87%20offer%20%E9%A2%98%E8%A7%A3.md)
- [1.赋值运算符函数](#1.赋值运算符函数)
- [2.实现Singleton模式](#2.实现Singleton模式)
- [3.数组中的重复数字](#3.数组中的重复数字)
- [4.二维数组中的查找](#4.二维数组中的查找)
- [5.替换空格](#5.替换空格)

## 1.赋值运算符函数

## 2.实现Singleton模式

## 3.数组中的重复数字

**数组：**

- 连续内存
- STL 的 vector 每次扩充容量时，新的容量是之前一次的两倍
- 数组作为函数的参数传递时，数组退化成同类型的指针

```c++
int Getsize(int data[]){
    return sizeof(data);
}

int main(){
    int data1[] = {1,2,3,4,5};
    printf("%d\n",sizeof(data1));
    //输出20，5个int

    int* data2 = data1;
    printf("%d\n",sizeof(data2));
    //输出4，因为是对一个指针求sizeof

    printf("%d\n",Getsize(data1));
    //输出4，虽然传递的是数组，但是数组作为参数传递时，退化成了int指针
}
```

**题目一：找出数组中重复数字**
在长度为n的数组中有n个数字，数字大小在0-n-1的范围中，输出重复数字。

思路1:先排序后扫描

思路2:扫描，构建hash表

思路3:由于数的范围是0-n-1，所以从头到尾扫描，当前数i和位置m不等，则i换到m位置，相等则继续，与hash方法相比，不用新开辟一个数组。

注意代码健壮性，检查传入数组是否为空，检查length是否小于等于0，检查每个数是够在0-n-1之间

- [3.数组中的重复数字题目一代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/3.数组中的重复数字题目一.cpp)

**题目二：不修改数组找出重复数字**
数组长度为n+1，所有数字都在1-n的范围，所以至少有一个数字是重复的。找出任意一个数字，但是不能修改数组。

思路1:hash

思路2：对范围进行二分，因为数组长度为n+1，所有数字都在1-n的范围，所以至少有一个数字是重复的。尝试缩小范围，确定最终结果

- [3.数组中的重复数字题目二代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/3.数组中的重复数字题目二.cpp)

## 4.二维数组中的查找

**题目：**
有一个二维数组，每一行从左到右递增，每一列从上到下递增，实现输入一个二维数组和一个数，判断是否存在。

思路1:从右上开始，当前数小于目标数则向下，大->左

思路2:从左下开始，小->右，大->上

- [4.二维数组中的查找代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/4.二维数组中的查找.cpp)

## 5.替换空格

**字符串：**
以字符'\0'结尾，有额外开销，注意防止越界。

C/C++把常量字符串放在一个单独的内存区域

```c++
char str1[] = "helloworld";
char str2[] = "helloworld";
//(str1==str2)为false
char* str3 = "helloworld";
char* str4 = "helloworld";
//(str3==str4)为true
```

**题目：**
把字符串的空格替换为"%20"

思路：从后向前移动，时间复杂度为O(n)，如果从前向后遍历，则遇到一个空格后，剩下的都要移动，时间复杂度为O(n^2)。

首先遍历，确定有几个空格，然后设置两个指针，间隔为需要新增的长度，默认输入字符串后面有空余空间。

- [5.替换空格代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/5.替换空格.cpp)