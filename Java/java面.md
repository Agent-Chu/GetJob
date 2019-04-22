https://github.com/h2pl/Java-Tutorial

https://www.nowcoder.com/discuss/161991

https://zhuanlan.zhihu.com/p/61049063?utm_source=wechat_session&utm_medium=social&utm_oi=642159079888392192

https://www.cnblogs.com/heyonggang/p/9112731.html

https://snailclimb.top/JavaGuide/#/

https://mp.weixin.qq.com/s/I7uohI6Mbqz8--Ird2kmmw

https://zhengjianglong.gitbooks.io/note-of-interview/content/java/base.html

https://github.com/CyC2018/CS-Notes#coffee-java

https://www.nowcoder.com/discuss/160806

https://www.nowcoder.com/discuss/147097

https://www.nowcoder.com/discuss/161611

https://www.nowcoder.com/discuss/160187

https://www.nowcoder.com/discuss/162234


最基本的语言基础：语法，关键字含义，面向对象
2. 集合类(ArrayList, HashMap, ConcurrentHashmap…等等)
3. 多线程(锁，CAS，线程池，concurrent 包下的类)
4. 语言特性：反射，动态代理，泛型，Java 8 新特性
5. IO (装饰器模式，NIO)
6. JVM：内存模型，垃圾回收，类加载机制

三、 Java Web

1. Tomcat，Servlet，JSP，Cookie/Session 等基本概念
2. 框架使用和原理：Spring(AOP，IoC)，MyBatis 等


Java的内存模型是什么样的呢？
Java字节码模型可以详细讲一下嘛？
Java类加载机制了解吗，可以讲一下嘛？（追问：Tomcat类加载机制？）
List和Set了解吗？他们主要是什么区别？
HashMap了解吗？大体的讲一下？
Spring这边，IOC和AOP可以讲一下嘛？
Java 虚拟机老生代垃圾回收机制怎么做的？
新生代呢？
Java 是引用传递还是按值传递？为什么？
Java有哪些粒度的锁？
在方法上加锁和对对象加锁有哪些底层实现上的区别？
HashMap和HashTable的区别？
HashTable如何实现线程安全？
HashMap的实现是怎样的？
ConcurrentHashMap如何保证线程安全？
Java 的有序的数据集合有了解过吗？
TreeSet 底层实现是怎样的呢？
为什么使用红黑树而非 AVL 树？
堆和二叉树又有什么区别？
你对 Java 中延迟执行的库有了解嘛？如果让你去实现，你怎么实现？（我说在操作系统中注册回调函数，类似 epoll ）
你对 Spring 的 AOP 如何看待？
（我说2种实现方式，JDK 动态代理和 CGLIB）为什么 JDK 动态代理需要被代理的类要实现一个接口呢？
如果让你实现动态代理，你会如何去实现呢？
Spring Bean 循环依赖问题如何解决？
Spring Bean 被 AOP 代理大概发生在什么时候呢？
JVM 的 GC Root 了解吗？有哪些 GC Root 对象？
Java 运行时候，栈空间可能很大，如何快速的枚举出 GC Root 呢？
volatile 关键字有哪些作用？能够做哪些事？举例？
WebApplicationContext 的初始化流程？
Spring MVC 如何解析到请求对应哪个 RequestHandler？

Spring 的事务你了解吗？大概讲一下？

JPA 和 Hibernate 之间的关系？

Hibernate 底层是如何实现到数据库表的映射的？

8. Java相关：线程池、HashMap、CopyOnWriteArrayList
5. Java相关： 线程池



 java基础知识

² Java异常处理

² Java数据结构

² Java并发包使用

² Java并发处理

2. JVM知识

² JVM存储区

² JVM内存回收算法

² JVM性能调优

² JVM调参 

Spring

2. springMVC

3. SpringBoot

4. Mybatis

5. Dubbo 



6、ArrayList与LinkedList的区别

7、线程安全与非线程安全集合说一下，底层怎么实现的（hashmap，concurrenthashmap）

8、Java内存模型，方法区存什么

1、说一下Spring的IOC和AOP，底层什么原理

2、动态代理有几种，Jdk与Cglib区别

7、若hashcode方法永远返回1会产生什么结果

8、Error与RuntimeException的区别

9、引用计数法与GC Root可达性分析法区别

10、双亲委派机制说一下

1、volatile关键字作用

5、NIO说一下你的理解

6、AtomicInteger底层原理

Java 程序的运行原理普通可执行程序的运行原理缓存行与伪共享。两个面试官都问，可见十分重要，还好都答出来了从浏览器发出请求开始，到服务端应用接受到请求为止的过程HashMap ，hash 碰撞，hash 算法的优化单点登录正向代理与反向代理反爬机制，爬虫模拟浏览器行为cglib 方法拦截动态代理依赖注入Servlet 的本质TCP 长连接。心跳包，websocketNetty 百万级长连接优化DSL 解析到 AST 。lexer 和 parserJVM 相关。（你读过 GC 相关源码吗？）代码规范，包命名规范


7 hashmap的实现讲一下吧，讲的很详细了。讲一下红黑树的结构，查询性能等。
8 Java中的垃圾回收讲一下，讲了分代，gc算法，gc root可达性分析等


5 hashmap的实现，hashtable，concurrenthashmap实现。


13 多线程用过哪些，chm和countdownlatch在实习用过

2 Java的集合类哪些是线程安全
3 分别说说这些集合类，hashmap怎么实现的，扯了很多

2 你谈到的并发技术，chm和countdownlatch怎么使用的
3 为什么要这么处理，使用线程池是不是也可以。我说也可以


1 Java的hashmap
2 Java的多线程技术，线程池
3 Java的jvm讲一下，内存模型，垃圾回收



2 jvm的内存模型和垃圾回收
3 Java并发技术讲一下

4 jvm了解么
5 jvm加载类是在什么时候
6 如果有重复类加载会发生什么


什么对象会进老年代？垃圾回收算法有哪些？为什么新生代使用复制算法？


60.说一下 jvm 的主要组成部分？及其作用？

61.说一下 jvm 运行时数据区？

62.说一下堆栈的区别？

63.队列和栈是什么？有什么区别？

64.什么是双亲委派模型？

65.说一下类加载的执行过程？

66.怎么判断对象是否可以被回收？

67.java 中都有哪些引用类型？

68.说一下 jvm 有哪些垃圾回收算法？

69.说一下 jvm 有哪些垃圾回收器？

70.详细介绍一下 CMS 垃圾回收器？

71.新生代垃圾回收器和老生代垃圾回收器都有哪些？有什么区别？

72.简述分代垃圾回收器是怎么工作的？

73.说一下 jvm 调优的工具？

74.常用的 jvm 调优的参数都有哪些？