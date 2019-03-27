# Golang概念题

- [Go概念](#Go概念)
- [Go语法](#Go语法)
- [Go优点](#Go优点)
- [Go运行时](#Go运行时)
- [golang与java的差异](#golang与java的差异)
- [Goroutines并发与协程](#Goroutines并发与协程)
- [函数多返回值](#函数多返回值)
- [基于消息传递的通信方式channel](#基于消息传递的通信方式channel)
- [丰富实用的内置数据类型](#丰富实用的内置数据类型)
- [defer机制](#defer机制)
- [反射](#反射)
- [高性能HTTPServer](#高性能HTTPServer)
- [工程管理与编程规范](#工程管理与编程规范)
- [在一行语句中定义多个不同类型变量](#在一行语句中定义多个不同类型变量)
- [Go的指针](#Go的指针)
- [Go需要显式类型转换](#Go需要显式类型转换)
- [Go没有异常](#Go没有异常)
- [Go变量声明语法](#Go变量声明语法)
- [Go是不是面向对象语言](#Go是不是面向对象语言)
- [Go2特性](#Go2特性)
- [Go中的rune](#Go中的rune)
- [Go常量](#Go常量)
- [golangmap的实现](#golangmap的实现)
- [golang方法method](#golang方法method)
- [new跟make](#new跟make)
- [切片](#切片)
- [go程序调试](#go程序调试)
- [如何写单元测试和基准测试](#如何写单元测试和基准测试)
- [go读写锁](#go读写锁)
- [go互斥锁](#go互斥锁)
- [cap和len](#cap和len)
- [golang垃圾回收](#golang垃圾回收)
- [interface](#interface)
- [断言判断interface类型](#断言判断interface类型)
- [生产者消费者](#生产者消费者)
- [给以后的同学攒点golang的面经](https://www.nowcoder.com/discuss/145338)


---

- [深入Go语言网络库的基础实现](http://skoo.me/go/2014/04/21/go-net-core)
- [Go并发调度器解析之实现一个协程池](https://juejin.im/entry/5b1e31f0e51d45067c6305a3)
- [Goroutine并发调度模型深度解析之手撸一个协程池](http://blog.taohuawu.club/article/42)

---

golang 的协程 说一下你的理解

https://www.cnblogs.com/liang1101/p/7285955.html

golang当中的协程是占用一个cpu还是会被调度到不同的cpu？
- 10，golang怎么进行垃圾回收的？什么对象会进老年代？垃圾回收算法有哪些？为什么新生代使用复制算法？

---

## Go概念

- 是Google开发的一种静态强类型、编译型、并发型，并具有垃圾回收功能的编程语言
- 强类型指的是程序中表达的任何对象所从属的类型都必须能在编译时刻确定。强类型是针对类型检查的严格程度而言的，它指任何变量在使用的时候必须要指定这个变量的类型，而且在程序的运行过程中这个变量只能存储这个类型的数据。
- 静态类型语言是编译期间做检查数据类型的语言，即写程序时要声明所有变量的数据类型，是固定的。使用数据之前，必须先声明数据类型（int ,float,double等）。相当于使用之前，首先要为它们分配好内存空间。
- Go是强类型的，因此声明属于一种类型的变量不能赋予另一种类型的值。
- Go程序使用包构建
- 使用传统编译和模型链接来生成可执行的二进制文件
- Go有 Package runtime ，包含与 Go 的运行时系统交互的操作，不包含虚拟机，在运行前编译
- Go 编译器产生的是本地可执行代码，这些代码仍旧运行在 Go 的 runtime

## Go语法

### go中的取反操作

对x取反：^x

### golang中大多数数据类型都可以转化为有效的JSON文本，下面几种类型除外（）
正确答案: B C D   你的答案: 空 (错误)

指针

channel

complex

函数

## Go优点

- 一种解释的动态类型语言
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
- 部署简单。Go 编译生成的是一个静态可执行文件，除了 glibc 外没有其他外部依赖。这让部署变得异常方便：目标机器上只需要一个基础的系统和必要的管理、监控工具，完全不需要操心应用所需的各种包、库的依赖关系，大大减轻了维护的负担。这和 Python 有着巨大的区别。由于历史的原因，Python 的部署工具生态相当混乱【比如 setuptools, distutils, pip, buildout 的不同适用场合以及兼容性问题】。官方 PyPI 源又经常出问题，需要搭建私有镜像，而维护这个镜像又要花费不少时间和精力。
- 并发性好。Goroutine 和 channel 使得编写高并发的服务端软件变得相当容易，很多情况下完全不需要考虑锁机制以及由此带来的各种问题。单个 Go 应用也能有效的利用多个 CPU 核，并行执行的性能好。这和 Python 也是天壤之比。多线程和多进程的服务端程序编写起来并不简单，而且由于全局锁 GIL 的原因，多线程的 Python 程序并不能有效利用多核，只能用多进程的方式部署；如果用标准库里的 multiprocessing 包又会对监控和管理造成不少的挑战【我们用的 supervisor 管理进程，对 fork 支持不好】。部署 Python 应用的时候通常是每个 CPU 核部署一个应用，这会造成不少资源的浪费，比如假设某个 Python 应用启动后需要占用 100MB 内存，而服务器有 32 个 CPU 核，那么留一个核给系统、运行 31 个应用副本就要浪费 3GB 的内存资源。
- 良好的语言设计。从学术的角度讲 Go 语言其实非常平庸，不支持许多高级的语言特性；但从工程的角度讲，Go 的设计是非常优秀的：规范足够简单灵活，有其他语言基础的程序员都能迅速上手。更重要的是 Go 自带完善的工具链，大大提高了团队协作的一致性。比如 gofmt 自动排版 Go 代码，很大程度上杜绝了不同人写的代码排版风格不一致的问题。把编辑器配置成在编辑存档的时候自动运行 gofmt，这样在编写代码的时候可以随意摆放位置，存档的时候自动变成正确排版的代码。此外还有 gofix, govet 等非常有用的工具。
- 执行性能好。虽然不如 C 和 Java，但通常比原生 Python 应用还是高一个数量级的，适合编写一些瓶颈业务。内存占用也非常省。

可直接编译成机器码，不依赖其他库，glibc的版本有一定要求，部署就是扔一个文件上去就完成了。
静态类型语言，但是有动态语言的感觉，静态类型的语言就是可以在编译的时候检查出来隐藏的大多数问题，动态语言的感觉就是有很多的包可以使用，写起来的效率很高。
语言层面支持并发，这个就是Go最大的特色，天生的支持并发，我曾经说过一句话，天生的基因和整容是有区别的，大家一样美丽，但是你喜欢整容的还是天生基因的美丽呢？Go就是基因里面支持的并发，可以充分的利用多核，很容易的使用并发。
内置runtime，支持垃圾回收，这属于动态语言的特性之一吧，虽然目前来说GC不算完美，但是足以应付我们所能遇到的大多数情况，特别是Go1.1之后的GC。
简单易学，Go语言的作者都有C的基因，那么Go自然而然就有了C的基因，那么Go关键字是25个，但是表达能力很强大，几乎支持大多数你在其他语言见过的特性：继承、重载、对象等。
丰富的标准库，Go目前已经内置了大量的库，特别是网络库非常强大，我最爱的也是这部分。
内置强大的工具，Go语言里面内置了很多工具链，最好的应该是gofmt工具，自动化格式化代码，能够让团队review变得如此的简单，代码格式一模一样，想不一样都很困难。
跨平台编译，如果你写的Go代码不包含cgo，那么就可以做到window系统编译linux的应用，如何做到的呢？Go引用了plan9的代码，这就是不依赖系统的信息。内嵌C支持，前面说了作者是C的作者，所以Go里面也可以直接包含c代码，利用现有的丰富的C库。

## Go运行时

尽管Go编译器产生的是本地可执行代码，这些代码仍旧运行在Go的runtime（这部分的代码可以在runtime包中找到）当中，这个runtime类似虚拟机，它负责管理包括内存分配、垃圾回收、栈处理、goroutine、channel、slice、map和reflection等等。

 runtime 调度器是个非常有用的东西，关于 runtime 包几个方法:

    Gosched：让当前线程让出 cpu 以让其它线程运行,它不会挂起当前线程，因此当前线程未来会继续执行

    NumCPU：返回当前系统的 CPU 核数量

    GOMAXPROCS：设置最大的可同时使用的 CPU 核数

    Goexit：退出当前 goroutine(但是defer语句会照常执行)

    NumGoroutine：返回正在执行和排队的任务总数

    GOOS：目标操作系统

NumCPU

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

## golang与java的差异

http://baijiahao.baidu.com/s?id=1604482531243718742&wfr=spider&for=pc

## Goroutines并发与协程

**Goroutines**是与其他函数或方法同时运行的函数或方法。 Goroutines可以被认为是轻量级线程。 与线程相比，创建Goroutine的成本很小。 Go应用程序通常会同时运行数千个Goroutines。

Golang会使用现有的线程来调度协程。也就是说，从程序员的角度，协程是并发执行的

通过关键字go来实现协程并发（协程又称微线程，比线程更轻量、开销更小，性能更高）

- 与线程相比，Goroutines创建非常便宜。 它们的堆栈大小只有几kb，堆栈可以根据应用程序的需要增长和缩小，而在线程的情况下，堆栈大小必须指定并固定。
- Goroutines **被多路复用** 到更少数量的OS线程。 程序中可能只有一个线程有数千个Goroutines。 如果该线程中的任何Goroutine阻塞说等待用户输入，则创建另一个OS线程，并将剩余的Goroutines移动到新的OS线程。
- Goroutines使用**频道进行通信**。 当使用Goroutines访问共享内存时，通过设计的通道**防止竞争条件**（当两个或多个线程可以访问共享数据并且他们试图同时更改它时发生竞争条件）。 通道可以被认为是Goroutines通信的管道。

所以goroutine是按照抢占式调度的，一个goroutine最多执行10ms就会换作下一个

这个和目前主流系统的的cpu调度类似（按照时间分片）

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

## 函数多返回值

```go
package main
import "fmt"

func swap(x, y string) (string, string) {
   return y, x
}
func main() {
   a, b := swap("Mahesh", "Kumar")
   fmt.Println(a, b)
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

## 丰富实用的内置数据类型

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

## 高性能HTTPServer

GO在语言级别自带HTTP/TCP/UDP高性能服务器，基于协程并发，为业务开发提供最直接有效的能力支持。要在GO语言中实现一个高性能的HTTP Server，只需要几行代码即可完成，非常简单。

## 工程管理与编程规范

在GO语言中，有一套标准的工程管理规范，只要按照这个规范进行项目开发，之后的事情（比如包管理、编译等等）都将变得非常的简单。

在GO项目下，存在两个关键目录，一个是src目录，用于存放所有的.go源码文件；一个是bin目录，用于存在编译后的二进制文件。在src目录下，除了main主包所在的目录外，其它所有的目录名称与直接目录下所对应的包名保持对应，否则编译无法通过。这样，GO编译器就可以从main包所在的目录开始，完全使用目录结构和包名来推导工程结构以及构建顺序，避免像C++一样，引入一个额外的Makefile文件。

在GO的编译过程中，我们唯一要做的就是将GO项目路径赋值给一个叫GOPATH的环境变量，让编译器知道将要编译的GO项目所在的位置。然后进入bin目录下，执行go build {主包所在的目录名}，即可秒级完成工程编译。编译后的二进制文件，可以推到同类OS上直接运行，没有任何环境依赖。

GO语言的编程规范强制集成在语言中，比如明确规定花括号摆放位置，强制要求一行一句，不允许导入没有使用的包，不允许定义没有使用的变量，提供gofmt工具强制格式化代码等等。

## 在一行语句中定义多个不同类型变量

```go
var a, b, c =  3,  4,  "foo"  
```

## Go的指针

**指针变量** 保存变量的地址

```go
var x =  5
var p *int =  &x
fmt.Printf("x = %d",  *p)
```

## Go需要显式类型转换

```go
i := 55      //int
j := 67.8    //float64
sum := i + int(j) //j is converted to int
```

## Go没有异常

Go代码使用错误值来指示异常状态。

```go
func Open(name string) (file *File, err error)
```

```go
f, err := os.Open("filename.ext")
if err != nil {
    log.Fatal(err)
}
// do something with the open *File f
```

## Go变量声明语法

```go
// 1 - variable declaration, then assignment
var age int
age = 29

// 2 - variable declaration with initial value
var age2 int = 29

// 3 - Type inference
var age3 = 29

// 4 - declaring multiple variables
var width, height int = 100, 50

// 5 - declare variables belonging to different types in a single statement
var (  
      name1 = initialvalue1,
      name2 = initialvalue2
)
// 6 - short hand declaration
name, age4 := "naveen", 29 //short hand declaration
```

如果没有为变量赋值，则使用变量类型的零值自动初始化它。

## Go是不是面向对象语言

- Go有面向对象的特性，但是没有类的继承

### Go Object-Oriented Language Features

- **Structs** - 结构是用户定义的类型。结构类型（使用方法）与其他语言中的类具有相似的用途。大写是包外可见的，小写的struct或函数只能在包内使用。
- **Methods** - 方法是对特定类型进行操作的函数
- **Embedding** - golang 中没有继承，但是其结构体内联的方式和继承很像
- **Interfaces** - 接口是声明方法集的类型。与其他语言的接口类似，它们没有实现。实现所有接口方法的对象自动实现接口。没有继承或子类或“implements”关键字。

### The Go way to implement

- **Encapsulation** - Go封装了包级别的东西。以小写字母开头的名称仅在该包中可见。您可以隐藏私有包中的任何内容，只显示特定类型，接口和工厂函数。
- **Inheritance** - 由*embedding*组成的匿名类型等同于实现继承。
- **Polymorphism** - 接口类型的变量可以包含实现接口的任何值。接口的这个属性用于在Go中实现多态。

```go
package main

import (  
    "fmt"
)

// interface declaration
type Income interface {  
    calculate() int
    source() string
}

// struct declaration
type FixedBilling struct {  
    projectName string
    biddedAmount int
}

type TimeAndMaterial struct {  
    projectName string
    noOfHours  int
    hourlyRate int
}

// interface implementation for FixedBilling
func (fb FixedBilling) calculate() int {  
    return fb.biddedAmount
}

func (fb FixedBilling) source() string {  
    return fb.projectName
}

// interface implementation for TimeAndMaterial
func (tm TimeAndMaterial) calculate() int {  
    return tm.noOfHours * tm.hourlyRate
}

func (tm TimeAndMaterial) source() string {  
    return tm.projectName
}

// using Polymorphism for calculation based 
// on the array of variables of interface type 
func calculateNetIncome(ic []Income) {  
    var netincome int = 0
    for _, income := range ic {
        fmt.Printf("Income From %s = $%d\n", income.source(), income.calculate())
        netincome += income.calculate()
    }
    fmt.Printf("Net income of organisation = $%d", netincome)
}

func main() {  
    project1 := FixedBilling{projectName: "Project 1", biddedAmount: 5000}
    project2 := FixedBilling{projectName: "Project 2", biddedAmount: 10000}
    project3 := TimeAndMaterial{projectName: "Project 3", noOfHours: 160, hourlyRate: 25}
    incomeStreams := []Income{project1, project2, project3}
    calculateNetIncome(incomeStreams)
}
```

## Go2特性

- 修复Go无法扩展的最重要方式
- 提供向后兼容性
- Go 2不得拆分Go生态系统

## Go中的rune

- 除了数字，还有其他字符，需要用32位表示他们，比如中文是utf8编码，占三个字节
- rune 英文占一个字节，中文占三个字节
- string底层是用byte数组存的，并且是不可以改变的。
- 在 Go 中，字符串是以 UTF-8 为格式进行存储的，在字符串上调用 len 函数，取得的是字符串包含的 byte 的个数
- /通过rune类型处理unicode字符
- fmt.Println("rune:", len([]rune(str)))
- golang中还有一个byte数据类型与rune相似，它们都是用来表示字符类型的变量类型。它们的不同在于：
- byte 等同于int8，常用来处理ascii字符
- rune 等同于int32,常用来处理unicode或utf-8字符

## Go常量

- 除非明确指定类型，否则golang中的任何常量（无名或无名）都是无类型的。

```go
const a = 1
var myFloat32 float32 = 4.5
var myComplex64 complex64 = 4.5
```

- 常量声明

```go
const typedInt int = 1  
```

## golangmap的实现

由于go语言是一个强类型的语言，因此hashmap也是有类型的，具体体现在key和value都必须指定类型，比如声明一个key为string，value也是string的map，
需要这样做

var m map[string]string // 声明一个hashmap，还不能直接使用，必须使用make来初始化
m = make(map[string]string) // 初始化一个map
m = make(map[string]string, 3) // 初始化一个map并附带一个可选的初始bucket（非准确值，只是有提示意义）

m := map[string]string{} // 声明并初始化

m := make(map[string]string) // 使用make来初始化

大部分类型都能做key，某些类型是不能的，共同的特点是：不能使用==来比较，包括: slice, map, function

golang的map是hash结构的，意味着平均访问时间是O(1)的。同传统的hashmap一样，由一个个bucket组成

### golang如何实现一个HashMap

- go语言是一个强类型的语言，因此hashmap也是有类型的，具体体现在key和value都必须指定类型
- m := make(map[string]string) // 使用make来初始化

```
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
- 方法其实就是一个最基本的面向对象的雏形

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

func new(Type) *Type
分配空间，参数一个类型，返回值指向这个新分配的零值的指针
func make(Type,size IntegerType)
分配并且初始化一个slice，或者map或者chan对象，并且只能是这三种对象。
第一个参数为类型，第二个参数为长度
返回值是这个类型.

make也是用于内存分配的，但是和new不同，它只用于chan、map以及切片的内存创建，而且它返回的类型就是这三个类型本身，而不是他们的指针类型，因为这三种类型就是引用类型，所以就没有必要返回他们的指针了。

而new用于类型的内存分配，并且内存置为零。

make返回的还是这三个引用类型本身；而new返回的是指向类型的指针。

## 切片

    make([]int,l,c) ，l为长度，c为容量，不传c则容量等于长度底层还是数组，通过len()获取长度，cap()获取容量append之后返回的是一个新的切片扩容：
        capacity小于1000时，两倍扩容capacity大于1000时，增长因子为1.25，25%扩容nil切片的数组指针为nil，而空切片的数组指针指向一个没有分配任何内存空间的地址，即底层元素包含0个元素。不管nil切片还是空切片，对其调用append，len和cap的效果都是一样的。
切片，是引用类型

    赋值：将一个切片赋值给另一个切片可指定索引
        第一个索引：指定切片的头部第二个索引：指定切片长度的尾部第三个索引：限制切片的容量

参考下面代码：

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

for-range返回的是每个元素的副本，而不是引用切片在函数件传递还是以值传递的方式传递，由于切片的尺寸很小，在函数间复制和传递切片的成本也很低。在64位结构的机器上，一个切片需要24个字节，指针字段8字节，长度和容量分别需要8字节，由于与切片关联的数据包含在底层数组里面，不属于切片本身，所以将切片复制给人以数组时对底层数组大小都不会有影响。

## go读写锁

读写锁实际是一种特殊的自旋锁，它把对共享资源的访问者划分成读者和写者，读者只对共享资源进行读访问，写者则需要对共享资源进行写操作。这种锁相对于自旋锁而言，能提高并发性，因为在多处理器系统中，它允许同时有多个读者来访问共享资源，最大可能的读者数为实际的逻辑CPU数。写者是排他性的，一个读写锁同时只能有一个写者或多个读者（与CPU数相关），但不能同时既有读者又有写者。

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

其中Mutex为互斥锁，Lock()加锁，Unlock()解锁，使用Lock()加锁后，便不能再次对其进行加锁，直到利用Unlock()解锁对其解锁后，才能再次加锁．适用于读写不确定场景，即读写次数没有明显的区别，并且只允许只有一个读或者写的场景，所以该锁也叫做全局锁。

我们一般会在锁定互斥锁之后紧接着就用defer语句来保证该互斥锁的及时解锁。请看下面这个函数：

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

几乎所有新语言（java，python，php等等）都引入了语言层面的自动内存管理 – 也就是语言的使用者只用关注内存的申请而不必关心内存的释放，内存释放由虚拟机（virtual machine）或运行时（runtime）来自动进行管理。而这种对不再使用的内存资源进行自动回收的行为就被称为垃圾回收。

- go语言垃圾回收总体采用的是经典的标记-清理（Mark-and-Sweep）算法，就是先标记出需要回收的内存对象快，然后在清理掉；

- 该方法分为两步，标记从根变量开始迭代得遍历所有被引用的对象，对能够通过应用遍历访问到的对象都进行标记为“被引用”；标记完成后进行清除操作，对没有标记过的内存进行回收（回收同时可能伴有碎片整理操作）。

- 每次启动垃圾回收都会暂停当前所有的正常代码执行，回收是系统响应能力大大降低
- 会导致 stw (stop the world)的问题，中断用户逻辑

- GC的优化方式原则就是尽可能少的声明临时变量：
- 局部变量尽量复用；
- 如果局部变量过多，可以把这些变量放到一个大结构体里面，这样扫描的时候可以只扫描一个变量，回收掉它包含的很多内存；

触发GC机制

- 1.在申请内存的时候，检查当前当前已分配的内存是否大于上次GC后的内存的2倍，若是则触发（主GC线程为当前M）
- 2.监控线程发现上次GC的时间已经超过两分钟了，触发；将一个G任务放到全局G队列中去。（主GC线程为执行这个G任务的M）

### golang什么时候执行STOP THE WORLD？

go语言垃圾回收总体采用的是经典的标记-清理（Mark-and-Sweep）算法，就是先标记出需要回收的内存对象快，然后在清理掉；

- 该方法分为两步，标记从根变量开始迭代得遍历所有被引用的对象，对能够通过应用遍历访问到的对象都进行标记为“被引用”；标记完成后进行清除操作，对没有标记过的内存进行回收（回收同时可能伴有碎片整理操作）。

- 每次启动垃圾回收都会暂停当前所有的正常代码执行，回收是系统响应能力大大降低
- 会导致 stw (stop the world)的问题，中断用户逻辑

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

- interface{} 类型没有声明任何一个方法，俗称空接口。interface{} 在我们需要存储任意类型的数值的时候相当有用，有点类似于C语言的void*类型。

```go
func PrintAll(vals []interface{}) {
    for _, val := range vals {
        fmt.Println(val)
    }
}

func main() {
    names := []string{"stanley", "david", "oscar"}
    vals := make([]interface{}, len(names))
    for i, v := range names {
        vals[i] = v
    }
    PrintAll(vals)
}
```

## 断言判断interface类型

https://www.cnblogs.com/xiaopipi/p/4889212.html
https://www.jianshu.com/p/3ced36523c8c

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