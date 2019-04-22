## makefile

- 对于大的工程通常涉及很多头文件和源文件，编译起来很很麻烦，makefile正是为了自动化编译产生的，makefile像是编译说明书，指示编译的步骤和条件，之后被make命令解释。
- Makefile 主要的 5个部分 (显示规则, 隐晦规则, 变量定义, 文件指示, 注释)
  - 显示规则 :: 说明如何生成一个或多个目标文件(包括 生成的文件, 文件的依赖文件, 生成的命令)
  - 隐晦规则 :: make的自动推导功能所执行的规则
  - 变量定义 :: Makefile中定义的变量
  - 文件指示 :: Makefile中引用其他Makefile; 指定Makefile中有效部分; 定义一个多行命令
  - 注释     :: Makefile只有行注释 "#", 如果要使用或者输出"#"字符, 需要进行转义, "\#"

- Makefile基本格式如下:

```makefile
target ... : prerequisites ...
    command
    ...
    ...
```

- target        - 目标文件, 可以是 Object File, 也可以是可执行文件
- prerequisites - 生成 target 所需要的文件或者目标
- command       - make需要执行的命令 (任意的shell命令), Makefile中的命令必须以 [tab] 开头

## make 的工作方式

- 读入主Makefile (主Makefile中可以引用其他Makefile)
- 读入被include的其他Makefile
- 初始化文件中的变量
- 推导隐晦规则, 并分析所有规则
- 为所有的目标文件创建依赖关系链
- 根据依赖关系, 决定哪些目标要重新生成
- 执行生成命令