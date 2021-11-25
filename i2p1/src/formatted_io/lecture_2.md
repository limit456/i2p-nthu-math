# Lecture 2: Data Type & Formatted Input/Output (2)

## 細部拆解一個 C++ 程式碼

Debugger 逐行解釋

``` c++
#include <iostream>

int main(void)
{
    int a = 0, b = 0, c = 0;
    std::cout << "input a:";
    std::cin >> a;
    std::cout << "input b:";
    std::cin >> b;
    c = a + b;
    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "a + b = " << c << std::endl;
    return 0;
}
```

### 為何要寫 `#include <>` ?

Include 了許多已經先寫好的 function，有些是跟系統有關，我們看不到原始碼的，我們只要拿來用就好。
可以打開 `/usr/include/c++/9/iostream` 看原始碼。

### 為何 `int main(void)` ?

`main` 的定義
1. `int main () { body }`
2. `int main (int argc, char *argv[]) { body }`

> The main function is called at program startup after initialization of the non-local objects with static storage duration.
> It is the designated entry point to a program that is executed in hosted environment (that is, with an operating system).
> The entry points to freestanding programs (boot loaders, OS kernels, etc) are implementation-defined.

Another example:

``` c++
#include <iostream>
#include <sstream>

int main(int argc, char *argv[])
{
    int a = 0, b = 0, c = 0;
    std::stringstream char_array_to_int;
    std::cout << argc << std::endl;
    char_array_to_int << argv[1] << ' ' << argv[2];
    char_array_to_int >> a;
    char_array_to_int >> b;
    c = a + b;
    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "a + b = " << c << std::endl;
    return 0;
}
```

## Coding Style & 變數名稱規則

好的 coding style 很重要

Bad example:

``` c++
#include <iostream>
#include <sstream>
int main(int argc, char *argv[]){int a = 0, b = 0, c = 0;std::stringstream char_array_to_int;std::cout << argc << std::endl;char_array_to_int << argv[1] << ' ' << argv[2];char_array_to_int >> a;char_array_to_int >> b;c = a + b;std::cout << "a: " << a << std::endl << "b: " << b << std::endl << "a + b = " << c << std::endl;return 0;}
```

### intend & spacing

Bad example:

``` c++
#include <iostream>
#include <sstream>
int main(int argc, char *argv[]){int a = 0, b = 0, c = 0;
  std::stringstream char_array_to_int;
    std::cout<<argc<<std::endl;
    char_array_to_int<<argv[1]<<' '<<argv[2];
char_array_to_int>>a;
    char_array_to_int>>b;
 c=a+b;
    std::cout<<"a: "<<a<<std::endl
              <<    "b: "      << b <<      std::endl
    << "a + b = "<< c << std::endl;
    return 0;
}
```

### fomatter

In vscode:
* Windows: <kbd>Shift</kbd> <kbd>Alt</kbd> <kbd>F</kbd>
* macOS: <kbd>Shift</kbd> <kbd>Option</kbd> <kbd>F</kbd>
* Linux: <kbd>Ctrl</kbd> <kbd>Shift</kbd> <kbd>I</kbd>

Demo

### 變數名稱規則

GNU

``` c++
#include <iostream>
#include <sstream>
int main(int argc, char *argv[])
{
  int a = 0, b = 0, c = 0;
  std::stringstream char_array_to_int;
  std::cout << argc << std::endl;
  char_array_to_int << argv[1] << ' ' << argv[2];
  char_array_to_int >> a;
  char_array_to_int >> b;
  c = a + b;
  std::cout << "a: " << a << std::endl
            << "b: " << b << std::endl
            << "a + b = " << c << std::endl;
  return 0;
}
```

Hungarian notation

``` c++
#include <iostream>
#include <sstream>
int main(int argc, char *argv[])
{
  int a = 0, b = 0, c = 0;
  std::stringstream charArrayToInt;
  std::cout << argc << std::endl;
  charArrayToInt << argv[1] << ' ' << argv[2];
  charArrayToInt >> a;
  charArrayToInt >> b;
  c = a + b;
  std::cout << "a: " << a << std::endl
            << "b: " << b << std::endl
            << "a + b = " << c << std::endl;
  return 0;
}
```

## 變數格式 & 型態轉換

### int, long, long long

|   Type    | Size in bits |  Format  |                             Value range                             |
| :-------: | :----------: | :------: | :-----------------------------------------------------------------: |
|    int    |      16      |  signed  |                     \\(-32768\\) to \\(32767\\)                     |
|           |              | unsigned |                       \\(0\\) to \\(65535\\)                        |
|   long    |      32      |  signed  |             \\(-2,147,483,648\\) to \\(2,147,483,647\\)             |
|           |              | unsigned |                   \\(0\\) to \\(4,294,967,295\\)                    |
| long long |      64      |  signed  | \\(-9,223,372,036,854,775,808\\) to \\(9,223,372,036,854,775,807\\) |
|           |              | unsigned |             \\(0\\) to \\(18,446,744,073,709,551,615\\)             |

### unsigned int & overflow

``` c++
#include <iostream>
int main(void)
{
  int i = 2147483647;
  unsigned int j = 4294967295U;
  std::cout << i << ' ' << i + 1 << ' ' << i + 2 << std::endl;
  std::cout << j << ' ' << j + 1 << ' ' << j + 2 << std::endl;
  return 0;
}
```

### float, double, double double

|    Type     | Size in bits |  Format  |                            Value range                            |
| :---------: | :----------: | :------: | :---------------------------------------------------------------: |
|    float    |      32      | IEEE-754 |      min subnormal: \\( \pm 1.401,298,4 \times 10^{-45} \\)       |
|             |              |          |        min normal: \\( \pm 1.175,494,3 \times 10^{-38} \\)        |
|             |              |          |            max: \\( \pm 3.402,823,4 \times 10^{38} \\)            |
|   double    |      64      | IEEE-754 |   min subnormal: \\( \pm 4.940,656,458,412 \times 10^{-324} \\)   |
|             |              |          | min normal: \\( \pm  2.225,073,858,507,201,4 \times 10^{-308} \\) |
|             |              |          |     max: \\( \pm 1.797,693,134,862,315,7 \times 10^{308} \\)      |
| long double |      80      |   x86    |          min subnormal: \\( \pm  3.645,199,531,882, \\)           |
|             |              |          |               \\( 474,602,528 \times 10^{-4951} \\)               |
|             |              |          |            min normal: \\( \pm 3.362,103,143,112, \\)             |
|             |              |          |               \\( 093,506,263 \times 10^{-4932} \\)               |
|             |              |          |                max: \\( \pm 1.189,731,495,357, \\)                |
|             |              |          |               \\( 231,765,021 \times 10^{4932} \\)                |
| __float128  |     128      | IEEE-754 |        min subnormal: \\( \pm  6.475,175,119,438,025, \\)         |
|             |              |          |      \\( 110,924,438,958,227,646,552,5 \times 10^{-4966} \\)      |
|             |              |          |          min normal: \\( \pm 3.362,103,143,112,093, \\)           |
|             |              |          |      \\( 506,262,677,817,321,752,602,6 \times 10^{-4932} \\)      |
|             |              |          |              max: \\( \pm 1.189,731,495,357,231, \\)              |
|             |              |          |      \\( 765,085,759,326,628,007,016,2 \times 10^{4932} \\)       |


### floating point precision

``` c++
#include <iostream>
#include <iomanip>
int main(void)
{
  float x = 1.23456789;
  std::cout << std::setprecision(3) << x << std::endl;
  std::cout << std::setprecision(4) << x << std::endl;
  std::cout << std::fixed;
  std::cout << std::setprecision(5) << x << std::endl;
  std::cout << std::setprecision(9) << x << std::endl;
  return 0;
}
```

### cast

``` c++
#include <iostream>
int main(void)
{
  double f = 3.14;
  unsigned int n1 = (unsigned int)f; // C-style cast
  std::cout << f << std::endl;
  std::cout << n1 << std::endl;
  return 0;
}
```

### char

|   Type    | Size in bits |  Format  |               Value range               |
| :-------: | :----------: | :------: | :-------------------------------------: |
| character |      8       |  signed  |         \\( -128 \\) to \\( 127 \\)         |
|           |              | unsigned |          \\( 0 \\) to \\( 255 \\)           |
|           |      16      |  UTF-16  |         \\( 0 \\) to \\( 65535 \\)          |
|           |      32      |  UTF-32  | \\( 0 \\) to \\( 1,114,111 \\) (`0x10ffff`) |

#### ASCII

**Hex**  = Hexdecimal Value, **Char** = Character

|  Hex  |               Char                |  Hex  |  Char  |  Hex  |  Char  |  Hex  | Char  |
| :---: | :-------------------------------: | :---: | :----: | :---: | :----: | :---: | :---: |
|   0   |            NUL (null)             |  20   | SPACE  |  40   |   @    |  60   |   `   |
|   1   |      SOH (start of heading)       |  21   |   !    |  41   |   A    |  61   |   a   |
|   2   |        STX (start of text)        |  22   | " `\"` |  42   |   B    |  62   |   b   |
|   3   |         ETX (end of text)         |  23   |   #    |  43   |   C    |  63   |   c   |
|   4   |     EOT (end of transmission)     |  24   |   $    |  44   |   D    |  64   |   d   |
|   5   |           ENQ (enquiry)           |  25   |   %    |  45   |   E    |  65   |   e   |
|   6   |         ACK (acknowledge)         |  26   |   &    |  46   |   F    |  66   |   f   |
|   7   |          BEL (bell `\a`)          |  27   | ' `\'` |  47   |   G    |  67   |   g   |
|   8   |       BS  (backspace `\b`)        |  28   |   (    |  48   |   H    |  68   |   h   |
|   9   |     TAB (horizontal tab `\t`)     |  29   |   )    |  49   |   I    |  69   |   i   |
|   A   | LF  (NL line feed, new line `\n`) |  2A   |   *    |  4A   |   J    |  6A   |   j   |
|   B   |      VT  (vertical tab `\v`)      |  2B   |   +    |  4B   |   K    |  6B   |   k   |
|   C   | FF  (NP form feed, new page `\f`) |  2C   |   ,    |  4C   |   L    |  6C   |   l   |
|   D   |    CR  (carriage return `\r`)     |  2D   |   -    |  4D   |   M    |  6D   |   m   |
|   E   |          SO  (shift out)          |  2E   |   .    |  4E   |   N    |  6E   |   n   |
|   F   |          SI  (shift in)           |  2F   |   /    |  4F   |   O    |  6F   |   o   |
|  10   |      DLE (data link escape)       |  30   |   0    |  50   |   P    |  70   |   p   |
|  11   |      DC1 (device control 1)       |  31   |   1    |  51   |   Q    |  71   |   q   |
|  12   |      DC2 (device control 2)       |  32   |   2    |  52   |   R    |  72   |   r   |
|  13   |      DC3 (device control 3)       |  33   |   3    |  53   |   S    |  73   |   s   |
|  14   |      DC4 (device control 4)       |  34   |   4    |  54   |   T    |  74   |   t   |
|  15   |    NAK (negative acknowledge)     |  35   |   5    |  55   |   U    |  75   |   u   |
|  16   |      SYN (synchronous idle)       |  36   |   6    |  56   |   V    |  76   |   v   |
|  17   |     ETB (end of trans. block)     |  37   |   7    |  57   |   W    |  77   |   w   |
|  18   |           CAN (cancel)            |  38   |   8    |  58   |   X    |  78   |   x   |
|  19   |        EM  (end of medium)        |  39   |   9    |  59   |   Y    |  79   |   y   |
|  1A   |         SUB (substitute)          |  3A   |   :    |  5A   |   Z    |  7A   |   z   |
|  1B   |         ESC (escape `\e`)         |  3B   |   ;    |  5B   |   [    |  7B   |   {   |
|  1C   |       FS  (file separator)        |  3C   |   <    |  5C   | \ `\\` |  7C   |  \|   |
|  1D   |       GS  (group separator)       |  3D   |   =    |  5D   |   ]    |  7D   |   }   |
|  1E   |      RS  (record separator)       |  3E   |   >    |  5E   |   ^    |  7E   |   ~   |
|  1F   |       US  (unit separator)        |  3F   | ? `\?` |  5F   |   _    |  7F   |  DEL  |

``` c++
#include <iostream>
int main(void)
{
  char char_five = '5';       // char_five = 53
  char char_diff = '5' - '0'; // char_diff = 53-48 = 5
  char c = 'B' + 32;          // c = 98 = 'b'
  std::cout << char_five << std::endl;
  std::cout << (int)char_five << std::endl;
  std::cout << (int)char_diff << std::endl;
  std::cout << c << std::endl;
  return 0;
}
```

#### others

[UTF-8](https://zh.wikipedia.org/wiki/UTF-8), [UTF-16](https://zh.wikipedia.org/wiki/UTF-16),
[Big5](https://zh.wikipedia.org/wiki/%E5%A4%A7%E4%BA%94%E7%A2%BC), [Shift_JIS](https://zh.wikipedia.org/wiki/Shift_JIS), etc.

Reference:
* [htchen/i2p-nthu by 陳煥宗老師](https://github.com/htchen/i2p-nthu/tree/master/程式設計一)
* [Main function - cppreference.com](https://en.cppreference.com/w/cpp/language/main_function)
* [【VSCode】如何在 VSCode 上自定義 C++ 的 coding style | by Zam Huang | Medium](https://zamhuang.medium.com/vscode-%E5%A6%82%E4%BD%95%E5%9C%A8-vscode-%E4%B8%8A%E8%87%AA%E5%AE%9A%E7%BE%A9-c-%E7%9A%84-coding-style-c8eb199c57ce)
* [Naming convention (programming) - Wikipedia](https://en.wikipedia.org/wiki/Naming_convention_(programming))
* [GNU Coding Standards](https://www.gnu.org/prep/standards/standards.html)
* [Fundamental types - cppreference.com](https://en.cppreference.com/w/cpp/language/types)
* [setprecision - C++ Reference](https://www.cplusplus.com/reference/iomanip/setprecision/)
* [Explicit type conversion - cppreference.com](https://en.cppreference.com/w/cpp/language/explicit_cast)
* [ASCII Table](https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)
* [What is a buffer in C?](https://www.educative.io/edpresso/what-is-a-buffer-in-c)
