# 剑指 Offer

- [剑指 Offer 题解](https://github.com/CyC2018/CS-Notes/blob/master/docs/notes/%E5%89%91%E6%8C%87%20offer%20%E9%A2%98%E8%A7%A3.md)
- [1 赋值运算符函数](#1-赋值运算符函数)
- [2 实现Singleton模式](#2-实现Singleton模式)
- [3 数组中的重复数字](#3-数组中的重复数字)
- [4 二维数组中的查找](#4-二维数组中的查找)
- [5 替换空格](#5-替换空格)
- [6 从尾到头打印链表](#6-从尾到头打印链表)
- [7 重建二叉树](#7-重建二叉树)
- [8 二叉树的下一个结点](#8-二叉树的下一个结点)
- [9 用两个栈实现队列](#9-用两个栈实现队列)
- [10 斐波那契数列](#10-斐波那契数列)
- [11 旋转数组的最小数字](#11-旋转数组的最小数字)
- [16 数值的整数次方](#16-数值的整数次方)

## 1 赋值运算符函数

## 2 实现Singleton模式

## 3 数组中的重复数字

**数组：**
数组特点：

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

## 4 二维数组中的查找

**题目：**
有一个二维数组，每一行从左到右递增，每一列从上到下递增，实现输入一个二维数组和一个数，判断是否存在。

思路1:从右上开始，当前数小于目标数则向下，大->左

思路2:从左下开始，小->右，大->上

- [4.二维数组中的查找代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/4.二维数组中的查找.cpp)

## 5 替换空格

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

## 6 从尾到头打印链表

**栈：**
c++中栈的使用方法：

```c++
#include <stack>

using namespace std;

stack<类型> name;

name.push();
name.empty();
name.top();
name.pop();
```

**题目：**
输入一个链表的头结点，从尾到头反过来打印每个节点的值

思路1：栈
思路2：由于递归也是栈，用递归

- [6.从尾到头打印链表代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/6.从尾到头打印链表.cpp)

## 7 重建二叉树

**树：**
除根节点外，每个节点只有一个父节点，根节点没有

除叶子节点外，每个节点有一个或者多个子节点，叶子节点没有子节点。

二叉树，每个节点最多有两个子节点。

前序遍历：先根，再左，再右

中序遍历：左，根，右

后序遍历：左，右，根

每种可以用递归和循环两种方法，需要掌握三种遍历的六种实现方法

**题目：**
输入前序遍历和中序遍历的结果，重建二叉树，例：{1,2,4,7,3,5,6,8}和{4,7,2,1,5,3,8,6}

- [7.重建二叉树](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/7.重建二叉树.cpp)

## 8 二叉树的下一个结点

**题目：**
给定一个二叉树和其中一个结点，如何找出中序遍历序列中这个结点的下一个结点。树的结点有左子树，右子树和父节点的指针

分三种情况：

- 如果该节点有右子树，则该节点的下一个结点是这个结点的右子树中最左子节点
- 如果该结点没有右子树，并且这个结点是左孩子，则这个结点的下一个结点是它的父节点
- 如果该结点既没有右子树，并且这个结点是右孩子，则需要沿着父节点的指针一直向上遍历，直到找到一个结点，这个结点是左孩子，则这个结点的父节点是我们需要的，也就是该结点在中序中的下一个结点
- 后两种情况可以合并成一种，第二种不需要向上遍历而已

- [8.二叉树的下一个结点](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offercode/8.二叉树的下一个结点.cpp)

## 9 用两个栈实现队列

- 入栈元素压入栈1
- 出栈时，如果栈2有则直接出
- 如果栈2没有，则把栈1元素逐个弹出并压入栈2
- 入栈判满，出栈判空

```c++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()<=0){
            while(stack1.size()>0){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int a;
        a = stack2.top();
        stack2.pop();
        return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

## 10 斐波那契数列

- 递归需要时间和空间消耗。每次调用都需要在内存的栈中分配空间保存参数、返回地址和临时变量。
- 递归可能存在很多重复计算
- 递归可能引起调用栈溢出，当调用层数太多时会超出栈的容量

### 求斐波那契数列的第n项的值

- 传统递归解法（效率低）

```c++
long long fibonacci(unsigned int n){
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
```

- 循环解法
- 从f(0),f(1)算出f(2)，一直算到f(n)

```c++
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        if(n == 1)
            return 1;
        int fa = 1;
        int fb = 0;
        int fn = 0;
        for(int i=2; i<=n;i++){
            fn = fa+fb;
            fb = fa;//这两行位置不能换
            fa = fn;
        }
        return fn;
    }
};
```

### 青蛙跳台阶

- 一只青蛙一次可以跳上1级台阶，或者2级，求这个青蛙跳上n级台阶有几种跳法
- 可以转化成斐波那契数列
- 当只有1级的时候只有一种跳法
- 有2级的时候有两种，1+1和2
- 当n级的时候，设为f(n)种跳法，当n>2时，针对第一次跳，可以跳1级，此时的跳法数目为后面n-1的跳法数，为f(n-1)
- 同理，第一次跳也能跳2级，跳法数目为f(n-2)
- 所以n级的跳法总数f(n) = f(n-1)+f(n-2)

## 11 旋转数组的最小数字

- 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
- 如果直接遍历，时间复杂度为O(n)
- 记录首位指针，最小的数把这个数组分为递增的两半
- 直接取数组中间的数，如果这个数位于前面的递增数组，则这个数应该大于等于首指针指向的数，移动前面的
- 如果这个数位于后面的递增数组，则这个数应该小于等于尾指针指向的数，移动后面的
- 当这两个指针相遇（距离为1）则说明第二个指针已经指向了最小的数

```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()){
            return 0;
        }
        int start = 0;
        int end = rotateArray.size()-1;
        int mid = start;
        while(rotateArray[start]>=rotateArray[end]){
            if(end - start == 1){
                mid = end;
                break;
            }
            mid = (start+end)/2;
            if(rotateArray[mid]>=rotateArray[start]){
                start = mid;
            }
            else if(rotateArray[mid]<=rotateArray[end]){
                end = mid;
            }
        }
        return rotateArray[mid];
    }
};
```

## 16 数值的整数次方

- 实现函数 double Power(double base, int exponent) 求base的ex次方，不能用库函数，不用考虑大数问题
- 需要考虑指数为负数时，对指数先求绝对值，然后算出次方后再取倒数
- 当底数为0并且指数为负数时，抛出异常
- 当底数指数都为0时，数学上没有意义，返回0或者1

- 当ex为偶数时，结果为 base的ex/2次方 乘 base的ex/2次方
- 当ex为奇数时，结果为 base的(ex-1)/2次方 乘 base的(ex-1)/2次方 乘 base

```c++
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0){
            return 1;
        }
        if(exponent == 1){
            return base;
        }
        double result = Power(base,exponent>>2);//用位运算代替除2
        result *= result;
        if(exponent&0x1 == 1){//用位与运算符代替求余运算符
            result *= base;
        }
        return result;
    }
};
```

循环做法：

```c++
class Solution {
public:
    double Power(double base, int exponent) {
        long long p = abs((long long)exponent);
        double r = 1.0;
        while(p){
            if(p & 1) r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/ r : r;
    }
};
```