# 剑指 Offer

- [剑指 Offer 题解](https://github.com/CyC2018/CS-Notes/blob/master/docs/notes/%E5%89%91%E6%8C%87%20Offer%20%E9%A2%98%E8%A7%A3%20-%20%E7%9B%AE%E5%BD%95.md)
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
- [17 打印从1到最大的n位数](#17-打印从1到最大的n位数)
- [18 删除链表中重复的结点](#18-删除链表中重复的结点)
- [19 正则表达式匹配](#19-正则表达式匹配)

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

```c++
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
```

思路3:由于数的范围是0-n-1，所以从头到尾扫描，当前数i和位置m不等，则i换到m位置，相等则继续，与hash方法相比，不用新开辟一个数组。

注意代码健壮性，检查传入数组是否为空，检查length是否小于等于0，检查每个数是够在0-n-1之间

**题目二：不修改数组找出重复数字**
数组长度为n+1，所有数字都在1-n的范围，所以至少有一个数字是重复的。找出任意一个数字，但是不能修改数组。

思路1:hash

思路2：对范围进行二分，因为数组长度为n+1，所有数字都在1-n的范围，所以至少有一个数字是重复的。尝试缩小范围，确定最终结果

```c++
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
```

## 4 二维数组中的查找

**题目：**
有一个二维数组，每一行从左到右递增，每一列从上到下递增，实现输入一个二维数组和一个数，判断是否存在。

思路1:从右上开始，当前数小于目标数则向下，大->左

思路2:从左下开始，小->右，大->上

- [4.二维数组中的查找代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offer/code/4.二维数组中的查找.cpp)

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

- [5.替换空格代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offer/code/5.替换空格.cpp)

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

- [6.从尾到头打印链表代码](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offer/code/6.从尾到头打印链表.cpp)

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

```c++
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int inlen = vin.size();
        if (inlen == 0){
            return NULL;
        }
        vector<int> leftin,leftpre,rightin,rightpre;
        TreeNode* head = new TreeNode(pre[0]);
        int index = 0;
        for(int i = 0; i<inlen;i++){
            if(vin[i] == pre[0]){
                index = i;
                break;
            }
        }
        for(int i=0;i<index;i++){
            leftin.push_back(vin[i]);
            leftpre.push_back(pre[i+1]);
        }
        for(int i=index+1;i<inlen;i++){
            rightin.push_back(vin[i]);
            rightpre.push_back(pre[i]);
        }
        head->left=reConstructBinaryTree(leftpre,leftin);
        head->right=reConstructBinaryTree(rightpre,rightin);
        return head;
    }
};
```

## 8 二叉树的下一个结点

**题目：**
给定一个二叉树和其中一个结点，如何找出中序遍历序列中这个结点的下一个结点。树的结点有左子树，右子树和父节点的指针

分三种情况：

- 如果该节点有右子树，则该节点的下一个结点是这个结点的右子树中最左子节点
- 如果该结点没有右子树，并且这个结点是左孩子，则这个结点的下一个结点是它的父节点
- 如果该结点既没有右子树，并且这个结点是右孩子，则需要沿着父节点的指针一直向上遍历，直到找到一个结点，这个结点是左孩子，则这个结点的父节点是我们需要的，也就是该结点在中序中的下一个结点
- 后两种情况可以合并成一种，第二种不需要向上遍历而已

- [8.二叉树的下一个结点](https://github.com/ChuangLiu727/GetJob/blob/master/剑指offer/code/8.二叉树的下一个结点.cpp)

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

## 17 打印从1到最大的n位数

输入数字n，按顺序打印出1到最大的n位十进制数

## 18 删除链表中重复的结点

- 普通删除结点：从头结点开始遍历到要删除的节点，再操作指针，此时需要删除结点的前一个结点
- 如果给定了要删除结点的指针，则不需要前一个结点，可以直接把后一个结点的值赋给要删除的结点，再删除后一个结点即可

时间复杂度O(1)删除：

```c++
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    if(!pListHead||!pToBeDeleted){
        return ;
    }
    //要删除的节点不是尾结点，O(1)
    if(pToBeDeleted->next!=nullptr){
        ListNode* pNext = pToBeDeleted->next;
        pToBeDeleted->value = pNext->value;
        pToBeDeleted->next = pNext->next;

        delete pNext;
        pNext = nullptr;
    }
    //链表中只有一个结点，删除头结点，也就是删除尾结点
    else if(*pListHead == pToBeDeleted){
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    //多个结点删除尾结点，因为尾结点没有下一个结点，所以只能遍历，找到前一个结点，时间复杂度为O(n)
    else{
        ListNode* pNode = *pListHead;
        while(pNode->next!=pToBeDeleted){
            pNode = pNode->next;
        }
        pNode->next = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
```

题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

```c++
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        //如果为0个结点或者1个结点
        if(pHead==NULL||pHead->next==NULL){
            return pHead;
        }
        //设置三个指针
        else{
            //使用构造函数，设置一个头结点，防止头结点要被删除,用于返回整个链表
            ListNode* newHead = new ListNode(-1);
            newHead->next = pHead;

            ListNode* pre = newHead;
            ListNode* p = pHead;
            ListNode* next = NULL;
            while(p!=NULL&&p->next!=NULL){
                next = p->next;
                if(p->val == next->val){//如果当前节点的值和下一个节点的值相等
                    while(next!=NULL&&next->val==p->val){//向后重复查找
                        next = next->next;
                    }
                    pre->next = next;//因为不保留重复结点，所以需要pre结点
                    p = next;
                }
                else{//如果当前节点和下一个节点值不等，则向后移动一位
                    pre = p;
                    p = p->next;
                }
            }
            return newHead->next;
        }
    }
};
```

## 19 正则表达式匹配

- 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

```c++
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(*str == '\0'&&*pattern == '\0'){//两个字符串都为空，返回true
            return true;
        }
        if(*str != '\0'&&*pattern == '\0'){//当第一个字符串不空，而第二个字符串空了，返回false
            return false;
        }
        if(*(pattern+1) == '*'){//pattern下一个字符为‘*’,‘*’可以代表0个或多个
            if((*str == *pattern)||(*str != '\0'&&*pattern == '.')){
                //当匹配多于一个字符时，相当于从str的下一个字符继续开始匹配
                //当‘*’匹配1个或多个时，str当前字符移向下一个，pattern当前字符不变。
                return match(str,pattern+2)||match(str+1,pattern);
            }
            else{
                //当‘*’匹配0个字符时，str当前字符不变，pattern当前字符后移两位，跳过这个‘*’符号；
                return match(str,pattern+2);
            }
        }
        else{//pattern下一个字符不为‘*’
            if((*str == *pattern)||(*str != '\0'&&*pattern == '.')){
                //直接匹配当前字符。如果匹配成功，继续匹配下一个
                return match(str+1,pattern+1);
            }
            else{
                return false;
            }
        }
    }
};
```