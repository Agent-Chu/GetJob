# Golang笔试题

## go中的取反操作

对x取反：^x

## delete

删除map

## goconvey

- goconvey是一个支持golang的单元测试框架

- goconvey能够自动监控文件修改并启动测试，并可以将测试结果实时输出到web界面

- goconvey提供了丰富的断言简化测试用例的编写

- goconvey可以与go test集成

golang中大多数数据类型都可以转化为有效的JSON文本，下面几种类型除外（）
正确答案: B C D   你的答案: 空 (错误)

指针

channel

complex

函数

### golang什么时候执行STOP THE WORLD？

go语言垃圾回收总体采用的是经典的标记-清理（Mark-and-Sweep）算法，就是先标记出需要回收的内存对象快，然后在清理掉；

- 该方法分为两步，标记从根变量开始迭代得遍历所有被引用的对象，对能够通过应用遍历访问到的对象都进行标记为“被引用”；标记完成后进行清除操作，对没有标记过的内存进行回收（回收同时可能伴有碎片整理操作）。

- 每次启动垃圾回收都会暂停当前所有的正常代码执行，回收是系统响应能力大大降低
- 会导致 stw (stop the world)的问题，中断用户逻辑

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