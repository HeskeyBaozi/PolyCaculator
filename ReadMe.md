# 背景
你上初中的表弟刚刚学了多项式计算。在最近的作业中，他经常会遇到多项式的题目。包括进行多项式加、减、乘，求值等计算。对此他感到十分苦恼。然而，他突然想起他亲爱的表哥（表姐）是学计算机的！于是，他想拜托你为他设计一款处理多项式的软件。
    以下是你俩的一次通话：

> 表弟：我的好表哥（姐），你救救我呗>_<<br>
你：又怎么啦<br>
表弟：能不能帮我弄一个处理多项式的小软件呀。你知道，我老是有多项式加、减、乘和求值等计算作业要做。<br>
你：我没问题呀，我正好用这个问题练练手。<br>
表弟：听说计算机能听懂人的语言。我能不能把我要计算的两个多项式写下来，然后让计算机帮我做加法？<br>
你：这个简单，我可以帮你设计一个程序。你只要把你想计算的式子通过键盘敲进计算机，计算机就能帮你算出两条式子相加的结果。<br>
表弟：好呀好呀，你具体给我说说呗<br>
你：你听好咯，我可以给你设计一个这样的软件。你可以输入多项式，为了方便起见，你可以将多项式表示成数对的形式。如x^2+1可表示成(1,2)(1,0)，5x^6-4x^3+2可表示成(5,6)(-4,3)(1,0)，以降序的方式排列。当然，你的输入必须得合法，否则，我的程序会告诉你输入错误。不过为了让软件记住这个多项式，你可以输入p=(2,1)(1,0)，q=(5,6)(-4,3)(1,0)的形式，那么以后你就可以用p、q表示多项式了。当你想进行加减法运算时，只需要输入p、q就可以了。<br>
表弟：好厉害！那如果我想保存相加结果呢？<br>
你：我的程序会询问你是否保存此多项式，如果你想保存，只需要输入多项式的名字就可以了，如r。<br>
表弟：那我输入式子以后，我要怎样才能进行加减法计算呢？<br>
你：我会提供几个按键给你的。比如说输入“1”表示做加法运算，我的程序会提醒你输入两个多项式，然后告诉你结果。像这样，系统提示你输入第一个多项式：p，输入第二个多项式q，输入完毕后，会告诉你其结果为……，然后询问你是否保存结果。<br>
以此类推，比如输入“2”做减法运算，输入“3”做乘法运算，输入“4”做求值运算等等<br>
表弟：好厉害~那你的程序会怎样告诉我结果呢？还是(2,1)(1,0)这样的形式吗，这样好像不太好看耶，你知道我们平时习惯都不是这样的……<br>
你：好啦好啦，要求真多，在输出多项式时，我会以x^5-3x^3+5之类的样子显示结果的。<br>
表弟：那太好啦，那我能查看目前保存了多少条多项式吗<br>
你：对哦，差点忘了。我还会给你增加一个功能，就是显示目前多项式。比如当你输入“6”，就能把计算机中目前储存的多项式都显示给你看。还有一点我跟你强调一下，如果你在做加减法时，输入了不存在的多项式，我的程序会告诉你输入不合法哦。当然，我的程序也是支持用新输入的多项式的，比如输入第一个多项式为：(1,1)(2,0)，第二个多项式为：p。程序照样能计算出结果。<br>
表弟：耶~我还有一个要求，就是能对多项式求值<br>
你：别急嘛，我刚想说。我还会给你加一个功能，当你输入“5”，就可以进行求值啦。我的程序会让你选择一条多项式，然后输入变量的值，程序就会告诉你这条多项式的值。如多项式为(2,1)(1,0)，即x^2+1，输入变量的值2，即x=2，系统就会返回一个5给你。<br>
表弟：谢谢表哥（姐）！你今晚做一个给我吧~<br>
你：哪有这么快小屁孩。这样吧，给我叁周时间，我把做好的软件发给你使用。<br>


# 要求：
计算器的功能菜单如下：
1. 输入多项式
2. 多项式相加
3. 多项式相减
4. 多项式与常数的乘法运算
5. 求多项式代入某点的值
6. 显示所有储存多项式
9. 帮助（查看功能列表）
0. 退出系统

使用面向对象的程序设计思想，通过创建多项式类实现以上功能。

## 输入要求
输入必须合法，任何如(2,1)(3,4))、(3,3)(5)、(1,2,3)(4,5)、(1,2)(3,4 等都是不合法输入
## 输出要求
多项式以降幂的形式输出，输出需友好，任何如1x^2+ -3x、0x^4+7、 x+x^5+x^3等都是不合法输出.用户在任何时候都能退回到主菜单

## 扩展功能
在基本要求基础上，实现以下功能可进行加分
1. 多项式与多项式相乘
2. 判断两个多项式是否相等
3. 对某个多项式求导


# 实验报告
![tushu](/images/ts14.jpg)
# 一. 实验目的
未知目的
# 二. 实验环境
本实验可基于Visual Studio 或Eclipse 或Devc++平台开发，参考主流的编码规范，如Google C++Style Guide（中文版）
## 2.1 编程语言和开发工具
编程语言： ANSI C/C++
开发工具： 可自行选择
## 2.2 编码规范
要求遵循良好的程序设计风格来设计和编写程序。基本编码规范：
1. 标识符的命名要到达顾名思义的程度；
2. 关键代码提供清晰、准确的注释；
3. 程序版面要求：
> a) 不同功能块用空行分隔；
b) 一般一个语句一行；
c) 语句缩进整齐、层次分明。

# 三．实验内容




# 四.分析与设计

简要描述程序设计的过程，包括设计思路，设计要点及特色；程序的不足与改进等。要求画出程序的简单流程图。

## 4.1 、需求分析：
 

系统功能图



## 4.2、类结构设计


类关系图：






## 4.3、细节设计

### 接口设计：

### 数据成员设计：

### 成员函数：

### 数据成员：

# 五、实验结果

设计有代表性的输入数据，并分析测试结果以及针对测试中发现的问题所进行的

修正与改进。



## 说明：


# 六、设计心得
进行总结，描述所获得的经验和心得体会等。









 注： 提示信息
1. 可发挥想象力，提高系统的交互体验，可用性和可靠性。
2. 请独立完成，但允许和鼓励相互讨论后自己写程序。由于题目具有开放性，很容易从程序看出是否抄袭。若发现抄袭，将导致抄袭双方或多方大副扣分或直接零分。

#程序测试
1. 请自行测试类的功能。
2. 界面交互时，请检测用户输入的正确性，保证程序的健壮性。（在用户做出操作后最好打印出提示语句。）
3. 在实验报告中分析测试意图和测试结果。如果通过测试发现程序错误，也分析错误原因、改正方法等，并在实验报告中体现。


