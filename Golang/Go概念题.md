# Golang概念题

- [Go概念](#Go概念)
- [Go优点](#Go优点)
- [Go语法特点](#Go语法特点)
- [Go运行时](#Go运行时)
- [Goroutines协程](#Goroutines协程)
- [基于消息传递的通信方式channel](#基于消息传递的通信方式channel)
- [内置数据类型](#内置数据类型)
- [defer机制](#defer机制)
- [反射](#反射)
- [Go是不是面向对象语言](#Go是不是面向对象语言)
- [Go中的rune](#Go中的rune)
- [Go中Map的实现](#Go中Map的实现)
- [golang方法method](#golang方法method)
- [new跟make](#new跟make)
- [切片](#切片)
- [go读写锁](#go读写锁)
- [go互斥锁](#go互斥锁)
- [cap和len](#cap和len)
- [golang垃圾回收](#golang垃圾回收)
- [interface](#interface)
- [interface存储任意类型和断言](#interface存储任意类型和断言)
- [生产者消费者](#生产者消费者)
- [给以后的同学攒点golang的面经](https://www.nowcoder.com/discuss/145338)

---

- [深入Go语言网络库的基础实现](http://skoo.me/go/2014/04/21/go-net-core)
- [Go并发调度器解析之实现一个协程池](https://juejin.im/entry/5b1e31f0e51d45067c6305a3)
- [Goroutine并发调度模型深度解析之手撸一个协程池](http://blog.taohuawu.club/article/42)

---


- 10，golang怎么进行垃圾回收的？什么对象会进老年代？垃圾回收算法有哪些？为什么新生代使用复制算法？

---

## Go概念

- 是Google开发的一种静态强类型、编译型、并发型，并具有垃圾回收功能的编程语言
- 强类型指的是程序中表达的任何对象所从属的类型都必须能在编译时刻确定。强类型是针对类型检查的严格程度而言的，它指任何变量在使用的时候必须要指定这个变量的类型，而且在程序的运行过程中这个变量只能存储这个类型的数据。
- 静态类型语言是编译期间做检查数据类型的语言，即写程序时要声明所有变量的数据类型，是固定的。使用数据之前，必须先声明数据类型（int ,float,double等）。相当于使用之前，首先要为它们分配好内存空间。
- Go程序使用包构建
- 使用传统编译和模型链接来生成可执行的二进制文件
- Go有 Package runtime ，包含与 Go 的运行时系统交互的操作，不包含虚拟机，在运行前编译
- Go 编译器产生的是本地可执行代码，这些代码仍旧运行在 Go 的 runtime

## Go优点

- 静态类型编译语言的效率和安全性
- 支持网络和多核计算
- 支持：轻量级进程（通过goroutines），channels，select语句。
- 简洁、安全。
- 支持接口和类型嵌入
- go编译器支持静态链接。 所有go代码都可以静态链接到一个大的二进制文件中，并且可以轻松地部署在云服务器中，而不必担心依赖性。
- 编译时间很快，可以在一台计算机上在几秒钟内编译一个大型Go程序。
- Go提供了一个软件构建模型，使依赖性分析变得简单，并避免了包含文件和库的大量开销。
- Go的类型系统没有层次结构
- Go提供垃圾收集，并为并发执行和通信的基本支持。
- Go提出了一种在多核机器上构建系统软件的方法。
- 部署简单。Go 编译生成的是一个静态可执行文件，除了 glibc 外没有其他外部依赖。这让部署变得异常方便：目标机器上只需要一个基础的系统和必要的管理、监控工具，完全不需要操心应用所需的各种包、库的依赖关系，大大减轻了维护的负担。
- 并发性好。Goroutine 和 channel 使得编写高并发的服务端软件变得相当容易，很多情况下完全不需要考虑锁机制以及由此带来的各种问题。单个 Go 应用也能有效的利用多个 CPU 核，并行执行的性能好。
- 执行性能好。虽然不如 C 和 Java，但通常比原生 Python 应用还是高一个数量级的，适合编写一些瓶颈业务。内存占用也非常省。
- 可直接编译成机器码，不依赖其他库，glibc的版本有一定要求，部署就是扔一个文件上去就完成了。
- 静态类型语言，但是有动态语言的感觉，静态类型的语言就是可以在编译的时候检查出来隐藏的大多数问题，动态语言的感觉就是有很多的包可以使用，写起来的效率很高。
- 语言层面支持并发，可以充分的利用多核，很容易的使用并发。
- 内置runtime，支持垃圾回收
- 丰富的标准库，Go目前已经内置了大量的库，特别是网络库非常强大，我最爱的也是这部分。
- 内置强大的工具，Go语言里面内置了很多工具链，最好的应该是gofmt工具，自动化格式化代码，能够让团队review变得如此的简单，代码格式一模一样，想不一样都很困难。
- 跨平台编译

## Go语法特点

- Go需要显式类型转换
- Go没有异常，Go代码使用错误值来指示异常状态。
- 如果没有为变量赋值，则使用变量类型的零值自动初始化它。
- 除非明确指定类型，否则golang中的任何常量（const）都是无类型的。

## Go运行时

- Go编译器产生的是本地可执行代码，这些代码运行在Go的runtime（这部分的代码可以在runtime包中找到）当中
- runtime类似虚拟机，它负责管理包括内存分配、垃圾回收、栈处理、goroutine、channel、slice、map和reflection等等。

- runtime 包几个方法:
  - Gosched：让当前线程让出 cpu 以让其它线程运行,它不会挂起当前线程，因此当前线程未来会继续执行
  - NumCPU：返回当前系统的 CPU 核数量
  - GOMAXPROCS：设置最大的可同时使用的 CPU 核数
  - Goexit：退出当前 goroutine(但是defer语句会照常执行)
  - NumGoroutine：返回正在执行和排队的任务总数
  - GOOS：目标操作系统

```go
package main

import (
    "fmt"
    "runtime"
)

func main() {
    fmt.Println("cpus:", runtime.NumCPU())
    fmt.Println("goroot:", runtime.GOROOT())
    fmt.Println("archive:", runtime.GOOS)
}
```

## Goroutines协程

- 协程（coroutine）是Go语言中的轻量级线程实现，由Go运行时（runtime）管理。
- 协程是在应用层模拟的线程，他避免了上下文切换的额外耗费，兼顾了多线程的优点。简化了高并发程序的复杂度。举个例子，一个高并发的网络服务器，每一个socket连接进来，服务器用一个协程来对他进行服务。代码非常清晰。而且兼顾了性能。
- Goroutines是与其他函数或方法同时运行的函数或方法。
- Goroutines可以被认为是轻量级线程。与线程相比，创建Goroutine的成本很小。Go应用程序通常会同时运行数千个Goroutines。
- Golang会使用现有的线程来调度协程。也就是说，从程序员的角度，协程是并发执行的
- 通过关键字go来实现协程并发（协程又称微线程，比线程更轻量、开销更小，性能更高）
- 与线程相比，Goroutines创建非常便宜。 它们的堆栈大小只有几kb，堆栈可以根据应用程序的需要增长和缩小，而在线程的情况下，堆栈大小必须指定并固定。

### 网络编程

1. 高并发（每秒钟上千数万的单机访问量）
2. Request/Response。程序生命期端（毫秒，秒级）
3. 高IO，低计算（连接数据库，请求API）。

### goroutine 和协程区别

- 本质上，goroutine 就是协程。
- 不同的是，Golang 在 runtime、系统调用等多方面对 goroutine 调度进行了封装和处理，当遇到长时间执行或者进行系统调用时，会主动把当前 goroutine 的CPU (P) 转让出去，让其他 goroutine 能被调度并执行，也就是 Golang 从语言层面支持了协程。Golang 的一大特色就是从语言层面原生支持协程，在函数或者方法前面加 go关键字就可创建一个协程。
- 每个 goroutine (协程) 默认占用内存远比 Java 、C 的线程少。
- 切换开销方面，goroutine 远比线程小
  - 线程：涉及模式切换(从用户态切换到内核态)、16个寄存器、PC、SP...等寄存器的刷新等。
  - goroutine：只有三个寄存器的值修改 - PC / SP / DX.

### Goroutines调度方式

- Goroutines **被多路复用** 到更少数量的OS线程。 程序中可能只有一个线程有数千个Goroutines。 如果该线程中的任何Goroutine阻塞说等待用户输入，则创建另一个OS线程，并将剩余的Goroutines移动到新的OS线程。
- Goroutines使用**频道进行通信**。 当使用Goroutines访问共享内存时，通过设计的通道**防止竞争条件**（当两个或多个线程可以访问共享数据并且他们试图同时更改它时发生竞争条件）。 通道可以被认为是Goroutines通信的管道。
- 所以goroutine是按照抢占式调度的，一个goroutine最多执行10ms就会换作下一个
- 这个和目前主流系统的的cpu调度类似（按照时间分片）

### Goroutines使用

```go
func run(arg string){
    //...
}
func main(){
    go run("test")
}
```

```go
func main() {
    log.Println("Hello, world")

    netListen, err := net.Listen("tcp", "localhost:4000")
    if err != nil {
        fmt.Fprintf(os.Stderr, "Fatal error: %s", err.Error())
        os.Exit(1)
    }

    defer netListen.Close()

    log.Println("Waiting for clients")

    for {
        conn, err := netListen.Accept()
        if err != nil {
            continue
    }

        log.Println(conn.RemoteAddr().String(), " tcp connect success")
        go handleConnection(conn)
    }
}

func handleConnection(conn net.Conn) {
    ...
}
```

## 基于消息传递的通信方式channel

channel是语言级别的进程内的协程间的通信方式，是线程安全的

使用基于消息传递的通信方式（而不是大多数语言所使用的基于共享内存的通信方式）进行协程间通信，并且将消息管道(channel)作为基本的数据类型，使用类型关键字(chan)进行定义，并发操作时线程安全。

channel是协程不是线程。channel不会产生新的线程，所以线程安全

```go
func main(){
    const taskNum int = 10
    chs := make(chan int, taskNum)
    for i:=0; i<taskNum; i++{
        go func(){
            fmt.Println("abc")
            chs <- 1
        }()
    }
    for i:=0; i<taskNum; i++{
        <-chs
    }
}
```

## 内置数据类型

- 传统的整型、浮点型、字符型、数组、结构等类型。
- string 字符串类型
- slice 切片类型(可变长数组)
- map 字典类型
- complex64 complex128 复数类型
- error 错误类型
- chan 管道类型
- 任意类型(Interface{})

## defer机制

通过该关键字指定需要延迟执行的逻辑体，即在函数体return前或出现panic时执行。这种机制非常适合善后逻辑处理，比如可以尽早避免可能出现的资源泄漏问题。

```go
func main() {
    c := make(chan int)
    go func() {
        defer fmt.Println("子协程结束")
        fmt.Println("子协程正在运行……")
        c <- 666 //666发送到c
    }()
    fmt.Println("程序开始")
    num := <-c //从c中接收数据，并赋值给num
    fmt.Println("num = ", num)
    fmt.Println("main协程结束")
}
```

运行结果：

```bash
程序开始
子协程正在运行……
子协程结束
num =  666
main协程结束
```

## 反射

```go
import "reflect"
```

- reflect包有两个数据类型我们必须知道，一个是Type，一个是Value。
- Type就是定义的类型的一个数据类型，Value是值的类型
- Type类型用来表示一个go类型。

```go
str := "this is string"
type := reflect.TypeOf(str)
```

## Go是不是面向对象语言

- Go有面向对象的特性，但是没有类的继承

- **结构体 Structs** - 结构是用户定义的类型。结构类型（使用方法）与其他语言中的类具有相似的用途。大写是包外可见的，小写的struct或函数只能在包内使用。
- **方法 Methods** - 方法是对特定类型进行操作的函数
- **内联 Embedding** - golang 中没有继承，但是其结构体内联的方式和继承很像
- **接口 Interfaces** - 接口是声明方法集的类型。与其他语言的接口类似，它们没有实现。实现所有接口方法的对象自动实现接口。没有继承或子类或“implements”关键字。

---

- **封装 Encapsulation** - Go封装了包级别的东西。以小写字母开头的名称仅在该包中可见。您可以隐藏私有包中的任何内容，只显示特定类型，接口和工厂函数。
- **继承 Inheritance** - 由*embedding*组成的匿名类型等同于实现继承。
- **多态 Polymorphism** - 接口类型的变量可以包含实现接口的任何值。接口的这个属性用于在Go中实现多态。

```go
// 声明一个接口
type Income interface {  
    calculate() int
    source() string
}

// 声明一个结构体
type FixedBilling struct {  
    projectName string
    biddedAmount int
}

type TimeAndMaterial struct {  
    projectName string
    noOfHours  int
    hourlyRate int
}

// FixedBilling 中实现接口
func (fb FixedBilling) calculate() int {  
    return fb.biddedAmount
}

func (fb FixedBilling) source() string {  
    return fb.projectName
}

// TimeAndMaterial 中实现接口
func (tm TimeAndMaterial) calculate() int {  
    return tm.noOfHours * tm.hourlyRate
}

func (tm TimeAndMaterial) source() string {  
    return tm.projectName
}

//使用
func main() {  
    project1 := FixedBilling{projectName: "Project 1", biddedAmount: 5000}
    project2 := FixedBilling{projectName: "Project 2", biddedAmount: 10000}
    project3 := TimeAndMaterial{projectName: "Project 3", noOfHours: 160, hourlyRate: 25}
}
```

## Go中的rune

- 除了数字，还有其他字符，需要用32位表示他们，比如中文是utf8编码，占三个字节
- rune 英文占一个字节，中文占三个字节
- string底层是用byte数组存的，并且是不可以改变的。
- 在 Go 中，字符串是以 UTF-8 为格式进行存储的，在字符串上调用 len 函数，取得的是字符串包含的 byte 的个数
- golang中还有一个byte数据类型与rune相似，它们都是用来表示字符类型的变量类型。它们的不同在于：
  - byte 等同于int8，常用来处理ascii字符
  - rune 等同于int32,常用来处理unicode或utf-8字符

```go
func main() {
    s := "你好" // UTF-8
    fmt.Println(len(s))    //结果：6

    st := []rune(s)
    fmt.Println(len(st))    //结果：2
}
```

## Go中Map的实现

- 由于go语言是一个强类型的语言，因此hashmap也是有类型的
- 具体体现在key和value都必须指定类型，比如声明一个key为string，value也是string的map
- 大部分类型都能做key，某些类型是不能的，共同的特点是：不能使用==来比较，包括: slice, map, function

```go
var m map[string]string // 声明一个hashmap，还不能直接使用，必须使用make来初始化
m = make(map[string]string) // 初始化一个map
m = make(map[string]string, 3) // 初始化一个map并附带一个可选的初始bucket（非准确值，只是有提示意义）

m := map[string]string{} // 声明并初始化

m := make(map[string]string) // 使用make来初始化
```

```go
// 测试key是否存在
v, ok := m["b"]
if ok {
    ...
}

// 删除一个key
delete(m, "a")
```

## golang方法method

- GO的方法是定义在一个接收者上的一个函数，接收者是某种类型的变量；
- GO的方法其实就是一个变种的函数

```go
package main
import (
    "fmt"
)
type T struct {
    Name string
    Age  int
}
func main() {
    t := T{}
    fmt.Println(t)
    t.Name = "astar"
    t.Age = 10
    fmt.Println(t)
    t.Add()
}
func (t *T) Add() {
    fmt.Println(t.Age, t.Name)
}
```

- 调用t.Add()以及输出
- 新增了一个变种函数(其实是方法)，(t *T) 这就是给这个结构体绑定函数，然后在结构体中就可以直接调用Add这个方法
- GO就是以这种形式来实现面像对象的思想
- 虽然method的名字一模一样，但是如果接受者不一样，那么method就不一样
- method里面可以访问接收者的字段
- 调用method通过.访问，就像struct里面访问字段一样

## new跟make

- new用于类型的内存分配，并且内存置为零。
- new(Type) *Type
- 分配空间，参数一个类型，返回值指向这个新分配的零值的指针
- new返回的是指向类型的指针

---

- 用于内存分配
- make(Type,size IntegerType)
- 分配并且初始化一个slice，或者map或者chan对象，并且只能是这三种对象。
- 第一个参数为类型，第二个参数为长度
- 返回的类型就是这三个类型本身，而不是他们的指针类型，因为这三种类型就是引用类型，所以就没有必要返回他们的指针了。

## 切片

- 切片是引用类型
- make([]int,l,c)
- l为长度，c为容量，不传c则容量等于长度底层还是数组
- 通过len()获取长度，cap()获取容量append之后返回的是一个新的切片扩容：
- for-range返回的是每个元素的副本

---

- 1.切片每次新增个数不超过原来的1倍，且每次增加数不超过1024个，且增加后总长度小于1024个，这种情况下扩容后为原来的2倍
- 2.切片一次新增个数超过原来1倍，但不超过1024个，且增加后总长度小于1024个，这种情况下扩容后的容量比实际长度略大一些。
- 3.原切片长度超过1024时，一次增加容量不是2倍而是0.25倍，每次超过预定的都是0.25累乘

```go
a := []int{1, 2, 3, 4, 5}
b := a[1:]
c := a[:4]
d := a[1:4]
e := a[2:3:4]
fmt.Println("a", len(a), cap(a))
fmt.Println("b", len(b), cap(b))
fmt.Println("c", len(c), cap(c))
fmt.Println("d", len(d), cap(d))
fmt.Println("e", len(e), cap(e))

//打印结果
a 5 5
b 4 4
c 4 5
d 3 4
e 1 2
```

## go读写锁

- 读写锁实际是一种特殊的自旋锁，它把对共享资源的访问者划分成读者和写者，读者只对共享资源进行读访问，写者则需要对共享资源进行写操作。
- 这种锁相对于自旋锁而言，能提高并发性，因为在多处理器系统中，它允许同时有多个读者来访问共享资源，最大可能的读者数为实际的逻辑CPU数。
- 写者是排他性的，一个读写锁同时只能有一个写者或多个读者（与CPU数相关），但不能同时既有读者又有写者。

```go
package main

import (
    // "fmt"
    "sync"
    "time"
)

var m *sync.RWMutex

func main() {
    m = new(sync.RWMutex)

    // 多个同时读
    go read(1)
    go read(2)

    time.Sleep(2 * time.Second)
}

func read(i int) {
    println(i, "read start")

    m.RLock()
    println(i, "reading")
    time.Sleep(1 * time.Second)
    m.RUnlock()

    println(i, "read over")
}

```

输出：可以看出1 读还没有结束，2已经在读

```
1 read start
1 reading
2 read start
2 reading
1 read over
2 read over
```

## go互斥锁

- 其中Mutex为互斥锁，Lock()加锁，Unlock()解锁
- 使用Lock()加锁后，便不能再次对其进行加锁，直到利用Unlock()解锁对其解锁后，才能再次加锁
- 适用于读写不确定场景，即读写次数没有明显的区别，并且只允许只有一个读或者写的场景，所以该锁也叫做全局锁。
- 一般会在锁定互斥锁之后紧接着就用defer语句来保证该互斥锁的及时解锁。

```go
var mutex sync.Mutex
func write() {
    mutex.Lock()
    defer mutex.Unlock()
    // 省略若干条语句
}
```

### cap和len

len() 可以用来查看数组或slice的长度

cap()可以用来查看数组或slice的容量

在数组中由于长度固定不可变，因此len(arr)和cap(arr)的输出永远相同

在slice中，len(sli)表示可见元素有几个（也即直接打印元素看到的元素个数），而cap(sli)表示所有元素有几个

```go
arr := []int{2, 3, 5, 7, 11, 13}
sli := arr[1:4]
fmt.Println(sli)
fmt.Println(len(sli))
fmt.Println(cap(sli))
```

```
[3 5 7]
3
5
```

## golang垃圾回收

- 使用者只用关注内存的申请而不必关心内存的释放，对不再使用的内存资源进行自动回收
- 内存释放由虚拟机（virtual machine）或运行时（runtime）来自动进行管理。
- go语言垃圾回收总体采用的是经典的标记-清理（Mark-and-Sweep）算法，就是先标记出需要回收的内存对象快，然后在清理掉；
  - （1）标记从根变量开始迭代得遍历所有被引用的对象，对能够通过应用遍历访问到的对象都进行标记为“被引用”；
  - （2）标记完成后进行清除操作，对没有标记过的内存进行回收（回收同时可能伴有碎片整理操作）。
- 每次启动垃圾回收都会暂停当前所有的正常代码执行，回收是系统响应能力大大降低
- 会导致 stw (stop the world)的问题，中断用户逻辑

- GC的优化方式原则就是尽可能少的声明临时变量：
- 局部变量尽量复用；
- 如果局部变量过多，可以把这些变量放到一个大结构体里面，这样扫描的时候可以只扫描一个变量，回收掉它包含的很多内存；

触发GC机制

- 1.在申请内存的时候，检查当前当前已分配的内存是否大于上次GC后的内存的2倍，若是则触发（主GC线程为当前M）
- 2.监控线程发现上次GC的时间已经超过两分钟了，触发；将一个G任务放到全局G队列中去。（主GC线程为执行这个G任务的M）

## interface

- interface 是方法声明的集合
- 任何类型的对象实现了在interface 接口中声明的全部方法，则表明该类型实现了该接口。
- interface 可以作为一种数据类型，实现了该接口的任何对象都可以给对应的接口类型变量赋值。

```go
type Phone interface {
    call()
}

type NokiaPhone struct {
}

func (nokiaPhone NokiaPhone) call() {
    fmt.Println("I am Nokia, I can call you!")
}

type ApplePhone struct {
}

func (iPhone ApplePhone) call() {
    fmt.Println("I am Apple Phone, I can call you!")
}

func main() {
    var phone Phone
    phone = new(NokiaPhone)
    phone.call()

    phone = new(ApplePhone)
    phone.call()
}
```

## interface存储任意类型和断言

- interface{} 类型没有声明任何一个方法，俗称空接口类型。
- interface{} 在我们需要存储任意类型的数值的时候相当有用，有点类似于C语言的void*类型。
- 对于函数内部，该变量仍然为interface{}类型（空接口类型），所以给函数传值的时候形参也需要是interface{}类型
- 可以通过断言来将接口类型转换成其他类型

```go
func PrintAll(vals []interface{}) {
    for _, val := range vals {
        fmt.Println(val)
    }
}

func echoString(content interface{}) {
    result, err := content.(string)  
    if err != nil {  // 断言失败
        fmt.Println(err .Error())  // 输出失败原因
        return
    }
    fmt.Println(result)
}

func main() {
    names := []string{"stanley", "david", "oscar"}
    vals := make([]interface{}, len(names))//声明一个interface{}的切片
    echoString(vals[0]);
    for i, v := range names {
        vals[i] = v
    }
    PrintAll(vals)
}
```

## 生产者消费者

```go
package main

import (
    "fmt"
    "math/rand"
    "time"
)

func productor(channel chan string) {
    for {
        channel <- fmt.Sprintf("%v", rand.Float64())
        time.Sleep(time.Second * time.Duration(1))
    }
}

func customer(channel chan string) {
    for {
        message := <-channel // 此处会阻塞, 如果信道中没有数据的话
        fmt.Println(message)
    }
}

func main() {
    channel := make(chan string, 5) // 定义带有5个缓冲区的信道(当然可以是其他数字)
    go productor(channel)           // 将 productor 函数交给协程处理, 产生的结果传入信道中
    customer(channel)               // 主线程从信道中取数据
}
```