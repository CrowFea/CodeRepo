---
title: "KickStart-2019 A轮解题"
catalog: true
toc_nav_num: true
date: 2019/7/11 0:43:00
header-img: "/img/article_header/article_header.jpg"
tags:
- KickStart
- 算法
catagories:
- KickStart
---

### Training
先排序，因为每次挑选之后一定是选取连在一起的几个最划算。所以排完序之后就直接在一轮遍历里面选择差最小的。
代码[github](https://github.com/CrowFea/CodeRepo/tree/master/KickStart/2019%20A)

### Parcels
这道题还是很有意思的，看了别人的做法学到了很多东西。

首先求出整个gird里面每个方格的代价，这里我一开始的做法是非常低级的，就是遍历每一个存在deliver的方格，再遍历一遍所有的grid。这个复杂度是O((RC)^2)。但实际上我们可以通过BFS，通过点到整网格的扩散完成。这个复杂度是O(RC)。这样一来可以求出所有代价中最大的代价。

接下来是一个技巧，我们可以将这个最优问题转化为满足性问题。对于可以找到的的一个整数K，满足所有的代价均小于代价。上面求出来的最大代价就是如此。这里我们需要找到0到K中满足这个条件的最小值，可以采用二分的思想来寻找。

这里的一个思路是将 曼哈顿距离 转化为 切比雪夫距离。[SGColin's Space](https://www.cnblogs.com/SGCollin/p/9636955.html)

```c++
dist((x1, y1), (x2, y2)) = max(abs(x1 + y1 - (x2 + y2)), abs(x1 - y1 - (x2 - y2)))
```

这个复杂度是O(RC)

加上二分的复杂度

O(RClog(R+C))

代码[github](https://github.com/CrowFea/CodeRepo/tree/master/KickStart/2019%20A)

### Contenion
这个题比较困难，看别人的做法也是看了很久。官方答案给出的解答是线段树，但是基本上使用的都是二分。这里值得注意的是解决最大最小问题的时候一般用的都是二分法。

我们可以给定一个k，看当前的这些数满不满足所有的订单都能够至少有K个解，如果不满足，二分向下；否则向上。对于两个预定，它们只有两种执行顺序，a先b后，或b先a后。

现在判断的思路是首先根据区间左右端点排序，第一关键字为起始点，第二关键字为终止点，
要使得这些预定尽可能满足最小值k的需求，每次求得第i ii个区间满足需求后，最后一个座位后一个座位，设为ed eded
对于两个区间，进行以下讨论：

- 两个区间相离，无需要进行特别讨论；
- 两个区间相交，
    - 如果后一个区间起始点在ed eded之后，那么则可以在执行的时候，让后者先执行；
    - 如果后一个区间起始点在ed eded之前，那么只能先将后者起始点偏移到ri+1 r_i +1r 
    i+1，否则第i ii个区间就满足不了了；
- 如果前者包含了后者，那么，后者必须先执行，因此在计算前者有效位置的时候，需要跳过后者；

根据上述规则，可以在O(Q^2)的时间内完成判断，算法总复杂度为 O(Q^2logN)。

代码[github](https://github.com/CrowFea/CodeRepo/tree/master/KickStart/2019%20A)