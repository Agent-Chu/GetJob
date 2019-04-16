# Zookeeper

## 基本概念

ZooKeeper是一个开源的分布式协调服务，他为分布式应用提供了高效且可靠的分布式协调服务，提供了诸如统一命名空间服务，配置服务和分布式锁等分布式基础服务。

分布式应用程序可以基于 ZooKeeper 实现诸如数据发布/订阅、负载均衡、命名服务、分布式协调/通知、集群管理、Master 选举、配置维护，名字服务、分布式同步、分布式锁和分布式队列等功能。

## Zookeeper 集群的角色

ZooKeeper中包含Leader、Follower和Observer三个角色；

通过一次选举过程，被选举的机器节点被称为Leader，Leader机器为客户端提供读和写服务；

Follower和Observer是集群中的其他机器节点，唯一的区别就是：Observer不参与Leader的选举过程，也不参与写操作的过半写成功策略。

## Zookeeper 节点类型

- 持久化节点（永久节点）（PERSISTENT）：不会因为会话结束或者超时而消失；

- 有序节点（PERSISTENT_SEQUENTIAL）：会在节点名的后面加一个数字后缀，并且是有序的，这种节点会根据当前已存在的节点数自动加 1，例如生成的有序节点为 /lock/node-0000000000，它的下一个有序节点则为 /lock/node-0000000001，以此类推。
- 临时节点（EPHEMERAL）：如果会话结束或者超时就会消失，客户端session超时这类节点就会被自动删除；
- 临时自动编号节点（EPHEMERAL_SEQUENTIAL）

节点在ZeeKeeper中包含两层含义：

    集群中的一台机器，我们成为机器节点；
    ZooKeeper数据模型中的数据单元，我们成为数据节点（ZNode）。

ZooKeeper的数据模型是内存中的一个ZNode数，由斜杠(/)进行分割的路径，就是一个ZNode，每个ZNode上除了保存自己的数据内容，还保存一系列属性信息；

ZooKeeper中的数据节点分为两种：持久节点和临时节点。

所谓的持久节点是指一旦这个ZNode创建成功，除非主动进行ZNode的移除操作，节点会一直保存在ZooKeeper上；而临时节点的生命周期是跟客户端的会话相关联的，一旦客户端会话失效，这个会话上的所有临时节点都会被自动移除。

## Zookeeper 监听器 Watcher

- 为一个节点注册监听器，在节点状态发生改变时，会给客户端发送消息。
- ZooKeeper允许用户在指定节点上注册一些Watcher，并且在一些特定事件触发的时候，ZooKeeper会通过事件通知到感兴趣的客户端上。

## Zookeeper 会话

会话就是一个客户端与服务器之间的一个TCP长连接。客户端和服务器的一切交互都是通过这个长连接进行的；

会话会在客户端与服务器断开链接后，如果经过了设点的sessionTimeout时间内没有重新链接后失效。

如果一个已经获得锁的会话超时了，因为创建的是临时节点，所以该会话对应的临时节点会被删除，其它会话就可以获得锁了。可以看到，Zookeeper 分布式锁不会出现数据库的唯一索引实现的分布式锁释放锁失败问题。

## Zookeeper 版本

ZooKeeper为每一个ZNode节点维护一个叫做Stat的数据结构，在Stat中维护了节点相关的三个版本：

    当前ZNode的版本 version
    当前ZNode子节点的版本 cversion
    当前ZNode的ACL(Access Control Lists)版本 aversion

## Zookeeper ACL（Access Control Lists）

ZooKeeper中定义了5中控制权限：

    CREATE：创建子节点的权限
    READ：获取节点数据和子节点列表的权限
    WRITE：跟新节点数据的权限
    DELETE：删除子节点的权限
    ADMIN：设置节点ACL的权限。

其中CREATE和DELETE这两种权限都是针对子节点的权限控制。

## Zookeeper 都有哪些功能？

1.配置中心
2.命名服务
3.Master选举
4.分布式锁 -------------------redis锁、数据库锁
5.服务注册与推送

## Zookeeper 有几种部署模式？

单机模式，集群模式，伪集群模式

## Zookeeper 怎么保证主从节点的状态同步？

Zookeeper的核心是原子广播机制，这个机制保证了各个server之间的同步。实现这个机制的协议叫做Zab协议。Zab协议有两种模式，它们分别是恢复模式和广播模式。
(1) 恢复模式
当服务启动或者在领导者崩溃后，Zab就进入了恢复模式，当领导者被选举出来，且大多数server完成了和leader的状态同步以后，恢复模式就结束了。状态同步保证了leader和server具有相同的系统状态。
(2) 广播模式
一旦Leader已经和多数的Follower进行了状态同步后，他就可以开始广播消息了，即进入广播状态。这时候当一个Server加入ZooKeeper服务中，它会在恢复模式下启动，发现Leader，并和Leader进行状态同步。待到同步结束，它也参与消息广播。ZooKeeper服务一直维持在Broadcast状态，直到Leader崩溃了或者Leader失去了大部分的Followers支持。

## 集群中为什么要有主节点？

## 集群中有 3 台服务器，其中一个节点宕机，这个时候 zookeeper 还可以使用吗？

## Zookeeper 通知机制？

客户端在向 ZooKeeper 服务器注册 Watcher 的同时，会将 Watcher 对象存储在客户端的 WatchManager 中。当ZooKeeper 服务器触发 Watcher 事件后，会向客户端发送通知，客户端线程从 WatchManager 的实现类中取出对应的 Watcher 对象来执行回调逻辑。

## Zookeeper 抽象模型

Zookeeper 提供了一种树形结构级的命名空间，/app1/p_1 节点的父节点为 /app1。

## 分布式锁实现

- 创建一个锁目录 /lock；
- 当一个客户端需要获取锁时，在 /lock 下创建临时的且有序的子节点；
- 客户端获取 /lock 下的子节点列表，判断自己创建的子节点是否为当前子节点列表中序号最小的子节点，如果是则认为获得锁；否则监听自己的前一个子节点，获得子节点的变更通知后重复此步骤直至获得锁；
- 执行业务代码，完成后，删除对应的子节点。

## 羊群效应

一个节点未获得锁，只需要监听自己的前一个子节点，这是因为如果监听所有的子节点，那么任意一个子节点状态改变，其它所有子节点都会收到通知（羊群效应），而我们只希望它的后一个子节点收到通知。