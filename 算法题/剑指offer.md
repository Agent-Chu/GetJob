# 剑指 Offer

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
- [12 矩阵中的路径](#12-矩阵中的路径)
- [13 机器人的运动范围](#13-机器人的运动范围)
- [16 数值的整数次方](#16-数值的整数次方)
- [17 打印从1到最大的n位数](#17-打印从1到最大的n位数)
- [18 删除链表中重复的结点](#18-删除链表中重复的结点)
- [19 正则表达式匹配](#19-正则表达式匹配)
- [29 顺时针打印矩阵](#29-顺时针打印矩阵)
- [30 包含min函数的栈](#30-包含min函数的栈)
- [36 二叉搜索树与双向链表](#36-二叉搜索树与双向链表)
- [37 序列化二叉树](#37-序列化二叉树)
- [38 字符串的排列](#38-字符串的排列)
- [40 最小的k个数](#40-最小的k个数)
- [41 数据流中的中位数](#41-数据流中的中位数)
- [49 丑数](#49-丑数)
- [51 数组中的逆序对](#51-数组中的逆序对)
- [60 n个骰子点数和及各自出现的概率](#60-n个骰子点数和及各自出现的概率)
- [65 不用加减乘除做加法](#65-不用加减乘除做加法)
- [67 把字符串转换为整数](#67-把字符串转换为整数)
- [68 树中两个节点的最低公共祖先](#68-树中两个节点的最低公共祖先)

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

## 12 矩阵中的路径

- 题目描述 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

- 分析：回溯算法
  - 首先，在矩阵中任选一个格子作为路径的起点。如果路径上的第i个字符不是ch，那么这个格子不可能处在路径上的第i个位置。如果路径上的第i个字符正好是ch，那么往相邻的格子寻找路径上的第i+1个字符。除在矩阵边界上的格子之外，其他格子都有4个相邻的格子。
重复这个过程直到路径上的所有字符都在矩阵中找到相应的位置。
  - 由于回朔法的递归特性，路径可以被开成一个栈。当在矩阵中定位了路径中前n个字符的位置之后，在与第n个字符对应的格子的周围都没有找到第n+1个字符，这个时候只要在路径上回到第n-1个字符，重新定位第n个字符。
  - 由于路径不能重复进入矩阵的格子，还需要定义和字符矩阵大小一样的布尔值矩阵，用来标识路径是否已经进入每个格子。 当矩阵中坐标为（row,col）的格子和路径字符串中相应的字符一样时，从4个相邻的格子(row,col-1),(row-1,col),(row,col+1)以及(row+1,col)中去定位路径字符串中下一个字符
  - 如果4个相邻的格子都没有匹配字符串中下一个的字符，表明当前路径字符串中字符在矩阵中的定位不正确，我们需要回到前一个，然后重新定位。
  - 一直重复这个过程，直到路径字符串上所有字符都在矩阵中找到合适的位置

```c++
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str==NULL||rows<=0||cols<=0)
           return false;
        bool *isOk=new bool[rows*cols]();
        for(int i=0;i<rows;i++)//用矩阵种所有点当起点
        {
             for(int j=0;j<cols;j++)
                 if(isHsaPath(matrix,rows,cols,str,isOk,i,j))
                     return true;
        }
        return false;
    }
    bool isHsaPath(char *matrix,int rows,int cols,char *str,bool *isOk,int curx,int cury)
    {
        if(*str=='\0')//找到这个路径
           return true;
        //防止越界，越界则移到另一端
        if(cury==cols){
             curx++;
             cury=0;
        }
        if(cury==-1){
             curx--;
             cury=cols-1;
        }
        //但是去掉后也ac
        if(curx<0||curx>=rows)//越界
             return false;
        if(isOk[curx*cols+cury])//已经走过
            return false;
        if(*str!=matrix[curx*cols+cury])//路径不对
           return false;
        isOk[curx*cols+cury]=true;//已经进入这个格子
        //路径的下一个，矩阵中向四个方向各走一步
        bool sign=isHsaPath(matrix,rows,cols,str+1,isOk,curx-1,cury)
                ||isHsaPath(matrix,rows,cols,str+1,isOk,curx+1,cury)
                ||isHsaPath(matrix,rows,cols,str+1,isOk,curx,cury-1)
                ||isHsaPath(matrix,rows,cols,str+1,isOk,curx,cury+1);
        isOk[curx*cols+cury]=false;//回到前一个
        return sign;
    }
};
```

## 13 机器人的运动范围

- 题目描述：地上有一个 m 行和 n 列的方格。一个机器人从坐标 (0, 0) 的格子开始移动，每一次只能向左右上下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于 k 的格子。例如，当 k 为 18 时，机器人能够进入方格 (35,37)，因为 3+5+3+7=18。但是，它不能进入方格 (35,38)，因为 3+5+3+8=19。请问该机器人能够达到多少个格子？

- 这是一个可达性问题，使用dfs方法，走到的每一格标记为走过，走到无路可走时就是最终的结果。每次都有四个方向可以选择，所以写四个递归即可。
- 核心思路：
  - 1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，返回1 + 4 个方向的探索值之和。
  - 2.探索时，判断当前节点是否可达的标准为：
  - 1）当前节点在矩阵内；
  - 2）当前节点未被访问过；
  - 3）当前节点满足limit限制。

```c++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int* flag=new int[rows*cols];//辅助数组
        for(int i=0;i<rows*cols;i++)//初始化辅助数组
            flag[i]=0;
        return helper(0, 0, rows, cols, flag, threshold);
    }
    int helper(int i, int j, int rows, int cols, int* flag, int threshold) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)//出界
            return 0;
        //不能进入行坐标和列坐标的数位之和大于threshold的格子
        if(numSum(i) + numSum(j)  > threshold)
            return 0;
        if(*(flag + i*cols + j) == 1)//已经走过
            return 0;
        *(flag + i*cols + j) = 1;//走过
        return helper(i - 1, j, rows, cols, flag, threshold)
            + helper(i + 1, j, rows, cols, flag, threshold)
            + helper(i, j - 1, rows, cols, flag, threshold)
            + helper(i, j + 1, rows, cols, flag, threshold)
            + 1;//格子数+1
    }
    int numSum(int i) {
        int sum = 0;
        do{
            sum += i%10;
        }while((i = i/10) > 0);
        return sum;
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

- 输入数字n，按顺序打印出1到最大的n位十进制数

- 需要考虑大数问题，这是题目设置的陷阱。可以把问题转换成数字排列问题，用递归让代码更简洁。我们把数字的每一位都从0到9排列一遍，得到全部的十进制数，打印时，前面的零不打印出来

```c++
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void PrintNum(char* number){
    //此处的number为一个str类型的数组，每个数组元素是一个0-9之间数字的字符串形式
    bool isbegin = true;
    int len = strlen(number);
    //printf("长度：%d",len);
    for(int i=0;i<len;i++){
        if(isbegin&&number[i]!='0'){//只输出非零项
            isbegin = false;
        }
        if(!isbegin){
            printf("%c",number[i]);
        }
    }
    printf("\t");
}

void Print1Ton(char* number,int length,int index){
    //第一次调用时，index==0，所以只有第一位是0
    //直到9，调用PrintNum输出1-9
    if(index == length - 1){//index表示变换位数
        PrintNum(number);
        return;
    }
    for(int i=0;i<10;i++){
        number[index+1] = i+'0';//改变下一位
        //改变下一位后，第一位是1
        //第二位从0-9，输出第一位和第二位的组合，也就是全排列
        Print1Ton(number,length,index+1);
    }
}

int main(){
    int n;
    cin >> n;
    if(n<=0){
        return 1;
    }
    char* number = new char[n+1];
    number[n] = '\0';
    for(int i=0;i<10;i++){//依次取0-9的值
        number[0] = i+'0';//第一位0
        Print1Ton(number,n,0);
    }
    delete[] number;
    return 0;
}
```

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

## 29 顺时针打印矩阵

- 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

- 四个循环中的分界点设置。
- 一圈一圈打印，边界条件是`up <= down && left <= right`

```c++
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int hight = matrix.size();
        int length = matrix[0].size();
        vector<int> res;
        if(hight == 0||length == 0){
            return res;
        }
        int up = 0;
        int down = hight-1;
        int left = 0;
        int right = length-1;
        int i;
        while(up <= down && left <= right){
            for(i=left;i<=right;i++){
                res.push_back(matrix[up][i]);
            }
            for(i=up+1;i<=down;i++){
                res.push_back(matrix[i][right]);
            }
            if(up!=down){
                for(i=right-1;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
            }
            if(left!=right){
                for(i=down-1;i>up;i--){
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};
```

## 30 包含min函数的栈

```c++
class Solution {
public:
    stack<int> stk,stkmin;
    void push(int value) {
        stk.push(value);
        if(stkmin.empty()){
            stkmin.push(value);
        }
        else if(value<=stkmin.top()){
            stkmin.push(value);
        }
    }
    void pop() {
        if(stk.top()==stkmin.top()){
            stkmin.pop();
        }
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return stkmin.top();
    }
};
```

## 36 二叉搜索树与双向链表

- 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
- 二叉搜索树要转换成有序的双向链表，实际上就是使用中序遍历把节点连入链表中，并且题目要求在原来节点上进行操作，也就是使用左指针和右指针表示链表的前置节点和后置节点。
- 使用栈实现中序遍历的非递归算法，便可以找出节点的先后关系，依次连接即可。

- [牛客](https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5)

## 37 序列化二叉树

- 请实现两个函数，分别用来序列化和反序列化二叉树。
- 比如 1 2 3 4 5，使用先序遍历 序列化结果是1,2,4,###3,#5,##，反序列化先让根节点指向第一位字符，然后左子树递归进行连接，右子树
- 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点不为空时，在转化val所得的字符之后添加一个' ， '作为分割。对于空节点则以 '#' 代替。
- 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会随着递归的进行而移动！！！)

```c++
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {
       if(root == NULL)
           return NULL;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){
        if(root == NULL){
            str += '#';
            return ;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
     
    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        TreeNode *ret = Deserialize(&str);
 
        return ret;
    }
    TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
        if(**str == '#'){  //所以一定要用**str,
            ++(*str);         //以保证得到递归后指针str指向未被读取的字符
            return NULL;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};
```

## 38 字符串的排列

- [解题思路及思路图](http://www.cnblogs.com/cxjchen/p/3932949.html)

- 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。输入可能有重复

- 对于无重复值的情况
  - 固定第一个字符，递归取得首位后面的各种字符串组合；
  - 再把第一个字符与后面每一个字符交换，并同样递归获得首位后面的字符串组合；
  - 递归的出口，就是只剩一个字符的时候，递归的循环过程，就是从每个子串的第二个字符开始依次与第一个字符交换，然后继续处理子串。

- 有重复值
  - 由于全排列就是从第一个数字起，每个数分别与它后面的数字交换，我们先尝试加个这样的判断——如果一个数与后面的数字相同那么这两个数就不交换了。
  - 例如abb，第一个数与后面两个数交换得bab，bba。然后abb中第二个数和第三个数相同，就不用交换了。
  - 但是对bab，第二个数和第三个数不 同，则需要交换，得到bba。
  - 由于这里的bba和开始第一个数与第三个数交换的结果相同了，因此这个方法不行。
  - 换种思维，对abb，第一个数a与第二个数b交换得到bab，然后考虑第一个数与第三个数交换，此时由于第三个数等于第二个数，
  - 所以第一个数就不再用与第三个数交换了。再考虑bab，它的第二个数与第三个数交换可以解决bba。此时全排列生成完毕！
  - 去重的全排列就是从第一个数字起，每个数分别与它后面非重复出现的数字交换。

```c++
class Solution {
public:
    vector<string> Permutation(string str)
    {
        vector<string> result;
        if(str.empty())
            return result;
        Permutation(str,result,0);//从第一个字符开始
        //此时得到的result中排列并不是字典顺序，可以单独再排下序
        sort(result.begin(),result.end());
        return result;
    }

    void Permutation(string str,vector<string> &result,int begin){
        // 递归结束条件：索引已经指向str最后一个元素时
        if(begin == str.size()-1){
            if(find(result.begin(),result.end(),str) == result.end()){
                // 如果result中不存在str，才添加；避免aa和aa重复添加的情况
                result.push_back(str);
            }
        }
        else{
            // 第一次循环i与begin相等，相当于第一个位置自身交换，关键在于之后的循环，
            // 之后i != begin，则会交换两个不同位置上的字符，直到begin==str.size()-1，进行输出；
            for(int i=begin;i<str.size();++i){
                swap(str[i],str[begin]);
                Permutation(str,result,begin+1);//范围不断缩小，直到最后一个的时候，输出
                swap(str[i],str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
            }
        }
    }

    void swap(char &fir,char &sec){
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};
```

## 40 最小的k个数

- 思路一：利用快速排序中的获取分割（中轴）点位置函数getPartitiion。
  - 基于数组的第k个数字来调整，使得比第k个数字小的所有数字都位于数组的左边，比第k个数字大的所有数字都位于数组的右边。调整之后，位于数组左边的k个数字就是最小的k个数字（这k个数字不一定是排序的）。O(N)

```c++
class Solution {
public:
    int partion(vector<int>& input, int beg, int end)
    {
        int key = input[beg];
        while (beg < end)
        {
            while (beg < end && input[end] >= key)end--;
            input[beg] = input[end];
            while (beg < end && input[beg] <= key)beg++;
            input[end] = input[beg];
        }
        input[beg] = key;
        return beg;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() == 0 || input.size() < k || k <= 0)
            return {};
        int pos = partion(input, 0, input.size() - 1);
        while (pos != k - 1)
        {
            if (pos > k - 1)
                pos = partion(input, 0, pos - 1);
            else
                pos = partion(input, pos + 1, input.size() - 1);
        }
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
};
```

- 思路二：利用堆排序，O(N logK)，适合处理海量数据
  - (1) 遍历输入数组，将前k个数插入到推中；（利用multiset来做为堆的实现）
  - (2) 继续从输入数组中读入元素做为待插入整数，并将它与堆中最大值比较：如果待插入的值比当前已有的最大值小，则用这个数替换当前已有的最大值；如果待插入的值比当前已有的最大值还大，则抛弃这个数，继续读下一个数。
  - 这样动态维护堆中这k个数，以保证它只储存输入数组中的前k个最小的数，最后输出堆即可。

```c++
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int len = input.size();
        if(input.empty()||k<=0||len<k){
            return res;
        }

        multiset<int, greater<int>> Num;
        multiset<int, greater<int>>::iterator iterNum;

        vector<int>::iterator iter = input.begin();
        for(;iter!=input.end();iter++){
            if(Num.size()<k){
                Num.insert(*iter);
            }
            else{
                iterNum = Num.begin();
                if(*iter<*iterNum){
                    Num.erase(iterNum);
                    Num.insert(*iter);
                }
            }
        }
        for(iterNum = Num.end();iterNum!=Num.begin();iterNum--){
            res.push_back(*iterNum);
        }
        return res;
    }
};
```

## 41 数据流中的中位数

```c++
class Solution {
public:
    priority_queue<int, vector<int>, less<int> > right;//右边是最小堆
    priority_queue<int, vector<int>, greater<int> > left;//左边是最大堆
    void Insert(int num)
    {
        //先插右边，再去调整
        if(right.empty() || num <= right.top())
            right.push(num);
        else
            left.push(num);
        //插入完成后总数为偶数时，始终保持右边和左边个数相等
        if(right.size() == left.size() + 2){
            left.push(right.top());
            right.pop();
        }
        //插入完成后总数为奇数时，始终保持右边比左边个数多1
        if(right.size() + 1 == left.size()){
            right.push(left.top());
            left.pop();
        }
    }

    double GetMedian()
    {
        //偶数情况
        if(right.size() == left.size())
            return (right.top() + left.top()) / 2.0;
        //奇数情况
        return right.top();
    }

};
```

## 49 丑数

- 思路：按顺序把每个丑数放在数组中，求下一个丑数
- 下一个丑数必定由有数组中的某一个丑数A * 2， B * 3， C * 5 的中的最小值得来。
- 在数组中必定有一个丑数M2， 在它之前的数 * 2 都小于当前最大丑数， 在它之后的数 * 2都大于当前最大丑数， 同样有M3, M5

```
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7){
            return index;
        }
        vector<int> res(index);
        res[0] = 1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<index;i++){
            res[i] = min(res[t2]*2,min(res[t3]*3,res[t5]*5));
            if(res[i]==res[t2]*2)t2++;
            if(res[i]==res[t3]*3)t3++;
            if(res[i]==res[t5]*5)t5++;
        }
        return res[index-1];
    }
};
```

## 51 数组中的逆序对

https://www.cnblogs.com/buxizhizhou/p/4727810.html

https://www.nowcoder.com/questionTerminal/96bd6684e04a44eb80e6a68efc0ec6c5

## 59 滑动窗口最大值

题目：滑动窗口的最大值

- 思路：滑动窗口应当是队列，但为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队列。
- 原则：
  - 对新来的元素k，将其与双端队列中的元素相比较
  - 1）前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,
  - 2）前面比k大的X，比较两者下标，判断X是否已不在窗口之内，不在了，直接移出队列
  - 队列的第一个元素是滑动窗口中的最大值

```c++
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;//s.front()存储的是最大值的下标
        for(int i=0;i<num.size();i++){
            while(s.size()&&num[s.back()]<=num[i]){//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
                s.pop_back();
            }
            while(s.size()&&i-s.front()+1>size){//移动窗口，把下标不在窗口范围的下标都从前面移除
                s.pop_front();
            }
            s.push_back(i);//当前下标存入，当前下标可能成为以后的最大值
            if(size&&i+1>=size){//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
                res.push_back(num[s.front()]);
            }
        }
        return res;
    }
};
```

## 60 n个骰子点数和及各自出现的概率

- 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入n，打印出S的所有可能的值出现的概率。

- 解题思路：
- 第一步，确定问题解的表达式。可将f(n, s) 表示n个骰子点数的和为s的排列情况总数。
- 第二步，确定状态转移方程。n个骰子点数和为s的种类数只与n-1个骰子的和有关。因为一个骰子有六个点数，那么第n个骰子可能出现1到6的点数。所以第n个骰子点数为1的话，f(n,s)=f(n-1,s-1)，当第n个骰子点数为2的话，f(n,s)=f(n-1,s-2)，…，依次类推。在n-1个骰子的基础上，再增加一个骰子出现点数和为s的结果只有这6种情况！那么有：

- f(n,s)=f(n-1,s-1)+f(n-1,s-2)+f(n-1,s-3)+f(n-1,s-4)+f(n-1,s-5)+f(n-1,s-6) ，0< n<=6n
- f(n,s)=0, s< n or s>6n

- 上面就是状态转移方程，已知初始阶段的解为：
- 当n=1时, f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1。

```
int getNSumCount(int n, int sum){
    if(n<1||sum<n||sum>6*n){
        return 0;
    }
    if(n==1){
        return  1;
    }
    int resCount=0;
    resCount=getNSumCount(n-1,sum-1)+getNSumCount(n-1,sum-2)+
             getNSumCount(n-1,sum-3)+getNSumCount(n-1,sum-4)+
             getNSumCount(n-1,sum-5)+getNSumCount(n-1,sum-6);
    return resCount;
}
```

## 65 不用加减乘除做加法

- 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

```
class Solution {
public:
    int Add(int num1, int num2)
    {
        while( num2!=0 ){
            int sum = num1 ^ num2;
            int carray = (num1 & num2) << 1;
            num1 = sum;
            num2 = carray;
        }
        return num1;
    }
};
```

- 两个数异或：相当于每一位相加，而不考虑进位；
- 两个数相与，并左移一位：相当于求得进位；
- 将上述两步的结果相加

---

- 三步走的方式计算二进制值相加： 5-101，7-111
- 第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111。
- 第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。
- 第三步重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。
- 继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。

```
(a&b)<<1  ->   1 0 0 1 0         -----d        18
a^b       ->     0 1 1 0         -----e         6

(d&e) <<1  ->   0 0 1 0 0        -----f         4
d^e        ->   1 0 1 0 0        -----g        20

(f&g) <<1  ->   0 1 0 0 0        -----h        8
f^g        ->   1 0 0 0 0        -----i        16

(h&i) <<1  ->   0 0 0 0 0        -----h        0 -----退出循环
h^i        ->   1 1 0 0 0        -----i        24
```

## 67 把字符串转换为整数

题目描述 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

```
Iuput:
+2147483647
1a33

Output:
2147483647
0
```

解析：首先需要判断正负号，然后判断每一位是否是数字，然后判断是否溢出，判断溢出可以通过加完第n位的和与未加第n位的和进行比较。最后可以得出结果。所以需要3-4步判断。

```c++
class Solution {
public:
    int StrToInt(string str) {
        int n = str.size();
        int s = 1;
        long long res = 0;
        if(!n)
            return 0;
        if(str[0] == '-')
            s = -1;
        int i;
        if(str[0] ==  '-' || str[0] == '+')
            i=1;
        else
            i=0;
        for(; i < n; ++i){
            if(!('0' <= str[i] && str[i] <= '9'))
                return 0;
            res=res*10+str[i]-'0';
        }
        return res * s;
    }
};
```

## 68 树中两个节点的最低公共祖先

### 二叉查找树

[Leetcode : 235. Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

二叉查找树中，两个节点 p, q 的公共祖先 root 满足 root.val >= p.val && root.val <= q.val。

```java
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null)
        return root;
    if (root.val > p.val && root.val > q.val)
        return lowestCommonAncestor(root.left, p, q);
    if (root.val < p.val && root.val < q.val)
        return lowestCommonAncestor(root.right, p, q);
    return root;
}
```

### 普通二叉树

[Leetcode : 236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)

在左右子树中查找是否存在 p 或者 q，如果 p 和 q 分别在两个子树中，那么就说明根节点就是最低公共祖先。

```java
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null || root == p || root == q)
        return root;
    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);
    return left == null ? right : right == null ? left : root;
}
```