# 语言基础

## C++ Snippets

### define class

``` c++
class Foo {
public:
    Foo() { this->a = 1; }
    int a;
private:
};
```

### io

#### \<iostream\>

``` c++
ostream &operator<<(ostream &o, Foo &f);
istream &operator>>(istream &i, Foo &f);
```

#### \<cstdio\>

``` c++
freopen("data.in", "r", stdin);
freopen("data.out", "w", stdout);
fclose(stdin);
fclose(stdout);
```

### random

#### C++ 11 \<random\>

``` c++
mt19937 rng{random_device{}()};
uniform_int_distribution<int> uni(0, MAX); // [0, MAX]
int r = uni(rng);
```

#### C \<cstdlib\>

``` c
srand(time(NULL));
int r = rand() % MAX; // [0, MAX)
```

### other utilities
  
* `<utility>`: `pair`
* `<bitset>`

### useful snippets

* mid of $[begin, end]$: $begin + (end - begin) / 2$
* $float = float$: $\underline{cmath}.fabs(a - b) < 1e-6$

# DP

背包类.
`w`: 背包大小, `w_n`: `n`的重量, `v_n`: `n`的价值,
  
``` c++
// 最大价值
f(/* 0.. */ n, w) = max(
  /* 全选 */ f(n - 1, w - w_n) + v_n,
  /* 部分 */ ...,
  /* 不选 */ f(n - 1, w)
)
```

# 数学

## 位运算

* `n &= n - 1`: 敲除最右边的1 (Brian Kernighan)
* `a + b = a^b + (a&b)<<1`: 加法 ($b \not= 0$)

## 数论

### 最大公约数 GCD

  $gcd(a, b) a > b$
  (`c++`: `<numeric>gcd`)

  ``` go
  func gcd(int a, b) int {
      if b == 1 {
          return a
      }
      return gcd(b, a % b)
  }

  // ax + by = gcd(a, b)
  func exgcd(int a, b) (int x, y) {
    if b == 0 {
        x = 1; y = 0;
        return
    }
    y, x = exgcd(b, a % b)
    y -= x * (a / b)
    return
  }
  ```

### 最小公倍数 LCM

$lcm(a, b)$
(`c++`: `<numeric>lcm`)

### 逆元

$a \% p$的逆元$x$: $a x \% p = 1$

* $x, \_ = exgcd(a, p)$
* 若$p$为素数: $x = a^{(p - 2)} \% p$ (费马小定理)

应用场景

* $\textbf{(n/a) \% p = nx \% p}$

## 组合数学

### 排列 Permutation

```
P(n, k) = n! / (n - k)!
```

### 组合 Combination
  
```
C(n, k) = n! / (n - k)! / k!
        = C(n - 1, k - 1) + C(n - 1, k)
        = C(n - 1, k) * n / (n - k)
C(n, 0) = C(n, n) = 1
```

# 图论

## 桥

`b - f`是桥

```
a - b - f - g
|   |   |   |
c - d   h - i
```

## 欧拉图

即一笔画, 半欧拉图(欧拉通路) 欧拉图(欧拉回路)

### 判断

``` c++
if (无向图) {
  if (没有奇度节点) 欧拉图;
  if (2个奇数节点) 半欧拉图;
}
if (有向图 & 强连通) {
  if (all(入度 == 出度)) 欧拉图;
  if (
    only_one(abs(入度 - 出度) == 1)
    && other(入度 == 出度)
  ) 半欧拉图;
}
```

### 寻找欧拉路

* Fleury: 最后走桥
* Hierholzer
  \[[LC 332](https://leetcode-cn.com/problems/reconstruct-itinerary/solution/zhong-xin-an-pai-xing-cheng-by-leetcode-solution/),
  [OI Wiki Euler](https://oi-wiki.org/graph/euler/)\]
  1. dfs
  2. 走过后删除边
  3. 不可移动后推入栈


# Platform

## acm.ecnu.edu.cn

* `std::cin.eof()` not work?