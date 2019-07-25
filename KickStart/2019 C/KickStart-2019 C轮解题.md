---
title: "KickStart-2019 C轮解题"
catalog: true
toc_nav_num: true
date: 2019/7/25 10:56:00
header-img: "/img/article_header/article_header.jpg"
tags:
- KickStart
- 算法
catagories:
- KickStart
---

### Wiggie Walk
之前在leetcode上面做过一道类似的题目，但是那道题目只要求最终截至的点，还是比较简单的。这个题目个人感觉比较复杂。

[github](https://github.com/CrowFea/CodeRepo/tree/master/KickStart/2019%20C)


### Circuit Board
这道题感觉比第一道题简单。主要的意思是找到极值差最小的一块子数组。

![img](https://s2.ax1x.com/2019/07/25/eez31e.png)

我们使用一个相同大小的数组dp，dp[i][j]用来记录当前pixel可以向右侧延伸多少个块满足题意。最后从上到下每一列每一列的查询，找到每一个数组对应的最大最小值。

时间复杂度为O(N^3)。

[github](https://github.com/CrowFea/CodeRepo/tree/master/KickStart/2019%20C)

### Catch Some
贪心可知Bundle每种颜色的衣服最多只会换一次。所以问题便转化为对于每种颜色，看多少只狗狗，可以令总路程最小。这可以用DP来解决。
我们把每种颜色的狗离散化成一个前缀, 看成一个物品，相当于每一类物品最多取一个的背包，额外考虑一维0/1表示是否返回原地即可。

[github](https://github.com/CrowFea/CodeRepo/tree/master/KickStart/2019%20C)