# kafka

## kafka核心概念

Kafka是一个分布式的、可分区的、可复制的消息系统。它提供了普通消息系统的功能，但具有自己独特的设计。

这个独特的设计是什么样的呢？

首先让我们看几个基本的消息系统术语：
Kafka将消息以topic为单位进行归纳。
将向Kafka topic发布消息的程序成为producers.
将预订topics并消费消息的程序成为consumer.
Kafka以集群的方式运行，可以由一个或多个服务组成，每个服务叫做一个broker.
producers通过网络将消息发送到Kafka集群，集群向消费者提供消息，

kafka是消息中间件的一种，是一种分布式流平台，是用于构建实时数据管道和流应用程序。具有横向扩展，容错，wicked fast（变态快）等优点。
Kafka简介

Kafka是一种分布式的，基于发布/订阅的消息系统。主要设计目标如下：

    以时间复杂度为O(1)的方式提供消息持久化能力，并保证即使对TB级以上数据也能保证常数时间的访问性能
    高吞吐率。即使在非常廉价的商用机器上也能做到单机支持每秒100K条消息的传输
    支持Kafka Server间的消息分区，及分布式消息消费，同时保证每个partition内的消息顺序传输
    同时支持离线数据处理和实时数据处理

## kafka名词解释

    消息记录(record): 由一个key，一个value和一个时间戳构成，消息最终存储在主题下的分区中, 记录在生产者中称为生产者记录(ProducerRecord), 在消费者中称为消费者记录(ConsumerRecord)，Kafka集群保持所有的消息，直到它们过期， 无论消息是否被消费了，在一个可配置的时间段内，Kafka集群保留所有发布的消息，不管这些消息有没有被消费。比如，如果消息的保存策略被设置为2天，那么在一个消息被发布的两天时间内，它都是可以被消费的。之后它将被丢弃以释放空间。Kafka的性能是和数据量无关的常量级的，所以保留太多的数据并不是问题。
    生产者(producer): 生产者用于发布(send)消息，负责发布消息到Kafka broker，Producer将消息发布到它指定的topic中,并负责决定发布到哪个分区。通常简单的由负载均衡机制随机选择分区，但也可以通过特定的分区函数选择分区。使用的更多的是第二种。
    消费者(consumer): 消费者用于订阅(subscribe)消息，消费消息。每个consumer属于一个特定的consuer group（可为每个consumer指定group name，若不指定group name则属于默认的group）。使用consumer high level API时，同一topic的一条消息只能被同一个consumer group内的一个consumer消费，但多个consumer group可同时消费这一消息。发布消息通常有两种模式：队列模式（queuing）和发布-订阅模式(publish-subscribe)。队列模式中，consumers可以同时从服务端读取消息，每个消息只被其中一个consumer读到；发布-订阅模式中消息被广播到所有的consumer中。Consumers可以加入一个consumer 组，共同竞争一个topic，topic中的消息将被分发到组中的一个成员中。同一组中的consumer可以在不同的程序中，也可以在不同的机器上。如果所有的consumer都在一个组中，这就成为了传统的队列模式，在各consumer中实现负载均衡。如果所有的consumer都不在不同的组中，这就成为了发布-订阅模式，所有的消息都被分发到所有的consumer中。更常见的是，每个topic都有若干数量的consumer组，每个组都是一个逻辑上的“订阅者”，为了容错和更好的稳定性，每个组由若干consumer组成。这其实就是一个发布-订阅模式，只不过订阅者是个组而不是单个consumer。
    消费者组(consumer group): 相同的group.id的消费者将视为同一个消费者组, 每个消费者都需要设置一个组id, 每条消息只能被 consumer group 中的一个 Consumer 消费,但可以被多个 consumer group 消费
    主题(topic): 消息的一种逻辑分组，用于对消息分门别类，每一类消息称之为一个主题，相同主题的消息放在一个队列中，每条发布到Kafka集群的消息都有一个类别，这个类别被称为topic。（物理上不同topic的消息分开存储，逻辑上一个topic的消息虽然保存于一个或多个broker上但用户只需指定消息的topic即可生产或消费数据而不必关心数据存于何处）
    分区(partition): 消息的一种物理分组， 一个主题被拆成多个分区，每一个分区就是一个顺序的、不可变的消息队列，并且可以持续添加，分区中的每个消息都被分配了一个唯一的id，称之为偏移量(offset),在每个分区中偏移量都是唯一的。每个分区对应一个逻辑log，有多个segment组成。parition是物理上的概念，每个topic包含一个或多个partition，创建topic时可指定parition数量。每个partition对应于一个文件夹，该文件夹下存储该partition的数据和索引文件
    偏移量(offset): 分区中的每个消息都一个一个唯一id，称之为偏移量，它代表已经消费的位置。可以自动或者手动提交偏移量(即自动或者手动控制一条消息是否已经被成功消费)
    代理(broker): 一台kafka服务器称之为一个broker，Kafka集群包含一个或多个服务器，这种服务器被称为broker
    副本(replica)：副本只是一个分区(partition)的备份。 副本从不读取或写入数据。 它们用于防止数据丢失。
    领导者(leader)：Leader 是负责给定分区的所有读取和写入的节点。 每个分区都有一个服务器充当Leader， producer 和 consumer 只跟 leader 交互
    追随者(follower)：跟随领导者指令的节点被称为Follower。 如果领导失败，一个追随者将自动成为新的领导者。 跟随者作为正常消费者，拉取消息并更新其自己的数据存储。replica 中的一个角色，从 leader 中复制数据。
    zookeeper：Kafka代理是无状态的，所以他们使用ZooKeeper来维护它们的集群状态。ZooKeeper用于管理和协调Kafka代理

## 分布式

每个分区在Kafka集群的若干服务中都有副本，这样这些持有副本的服务可以共同处理数据和请求，副本数量是可以配置的。副本使Kafka具备了容错能力。
每个分区都由一个服务器作为“leader”，零或若干服务器作为“followers”,leader负责处理消息的读和写，followers则去复制leader.如果leader down了，followers中的一台则会自动成为leader。集群中的每个服务都会同时扮演两个角色：作为它所持有的一部分分区的leader，同时作为其他分区的followers，这样集群就会据有较好的负载均衡。

## kafka功能

    发布订阅：生产者(producer)生产消息(数据流), 将消息发送到到kafka指定的主题队列(topic)中，也可以发送到topic中的指定分区(partition)中，消费者(consumer)从kafka的指定队列中获取消息，然后来处理消息。
    流处理(Stream Process): 将输入topic转换数据流到输出topic
    连接器(Connector) : 将数据从应用程序(源系统)中导入到kafka，或者从kafka导出数据到应用程序(宿主系统sink system), 例如：将文件中的数据导入到kafka，从kafka中将数据导出到文件中

## kafka中的消息模型

    队列：同名的消费者组员瓜分消息
    发布订阅：广播消息给多个消费者组(不同名)

 

生产者(producer)将消息记录(record)发送到kafka中的主题中(topic), 一个主题可以有多个分区(partition), 消息最终存储在分区中，消费者(consumer)最终从主题的分区中获取消息。

## 相比传统的消息系统，Kafka可以很好的保证有序性。
传统的队列在服务器上保存有序的消息，如果多个consumers同时从这个服务器消费消息，服务器就会以消息存储的顺序向consumer分发消息。虽然服务器按顺序发布消息，但是消息是被异步的分发到各consumer上，所以当消息到达时可能已经失去了原来的顺序，这意味着并发消费将导致顺序错乱。为了避免故障，这样的消息系统通常使用“专用consumer”的概念，其实就是只允许一个消费者消费消息，当然这就意味着失去了并发性。

在这方面Kafka做的更好，通过分区的概念，Kafka可以在多个consumer组并发的情况下提供较好的有序性和负载均衡。将每个分区分只分发给一个consumer组，这样一个分区就只被这个组的一个consumer消费，就可以顺序的消费这个分区的消息。因为有多个分区，依然可以在多个consumer组之间进行负载均衡。注意consumer组的数量不能多于分区的数量，也就是有多少分区就允许多少并发消费。

Kafka只能保证一个分区之内消息的有序性，在不同的分区之间是不可以的，这已经可以满足大部分应用的需求。如果需要topic中所有消息的有序性，那就只能让这个topic只有一个分区，当然也就只有一个consumer组消费它。

## kafka 可以脱离 zookeeper 单独使用吗？为什么？

安装kafka是需要依赖于zookeeper的，所以安装kafka的时候也会包含zookeeper 

## kafka 有几种数据保留的策略？

## kafka 同时设置了 7 天和 10G 清除数据，到第五天的时候消息达到了 10G，这个时候 kafka 将如何处理？

## 什么情况会导致 kafka 运行变慢？

## 使用 kafka 集群需要注意什么？