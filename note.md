# 语言基础

## C++ Snippets

* class & ostream

``` c++
class Foo {
public:
    Foo() { this->a = 1; }
    int a;
    friend ostream &operator<<(ostream &ostream, Foo &f);
private:
    int _b;
}

ostream &operator<<(ostream &ostream, Foo &f) {
    ostream << f._b;;
}
```

* file input/output

``` c++
#include <cstdio>
#include <iostream>
freopen("data.in", "r", stdin);
freopen("data.out", "w", stdout);
fclose(stdin);
fclose(stdout);
```

* iostresm

``` c++
while (!cin.eof);
```

* 浮点数比较: `<cmath> fabs(a - b) < 1e-6`;

* stl algorithm

* stl container
  
  * `utility`: `pair`  
  * `bitset`

* range mid `begin + (end - begin) / 2`

# 数学

## 位运算

* `n &= n - 1`: 敲除最右边的1 (Brian Kernighan)

## 数论

* GCD(a, b), a > b 最大公约数, (`C++ <numeric> std::gcd`)

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
* LCM(a, b), 最小公倍数 (`C++ <numeric> std::lcm`)

* `a%p`的逆元`x`: `ax % p = 1` `x`最小解
  * `x, _ = exgcd(a, p)`
  * 若`p`为素数: `x = a^(p - 2) % p` (费马小定理)
  * `(n/a) % p = nx % p`

## 组合数学

* 排列 Permutation
  ```
  P(n, k) = n! / (n - k)!
  ```

* 组合 Combination
  
  ```
  C(n, k) = n! / (n - k)! / k!
          = C(n - 1, k - 1) + C(n - 1, k)
          = C(n - 1, k) * n / (n - k)
  C(n, 0) = C(n, n) = 1
  ```

# Platform

## acm.ecnu.edu.cn

* `std::cin.eof()` not work?