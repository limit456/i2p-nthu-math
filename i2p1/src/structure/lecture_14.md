# Lecture 14: Structure (2)

## Structure example: Floating point number

``` c++
{{#include lecture_14_ex1.cpp}}
```

``` console
$ g++ -g test.cpp && ./a.out
Input a float number (a) in (-)xxx.xxx(e|E)(-)(xxx): -123.456e3
(a) = -123456
Input a float number (b) in (-)xxx.xxx(e|E)(-)(xxx): 456.789e4
(b) = 456789e1
(a) + (b) = 444444e1
(a) - (b) = 469134e1
(a) * (b) = -563933427e3
(a) / (b) = 0
$ 
```

## Structure example: Polynomial Equation

``` c++
{{#include lecture_14_ex2.cpp}}
```

``` console
$ g++ -g test.cpp && ./a.out
Enter polynomial a: -30x^3+20x^1
Polynomial a: -30x^3+20x^1
Enter polynomial b: 50x^3-20
Polynomial b: 50x^3-20
Polynomial c = a + b: 20x^3+20x^1-20
$ 
```

## Structure example: Geometry Object

Ref: [Computational geometry - Wikipedia](https://en.wikipedia.org/wiki/Computational_geometry)

``` c++
{{#include lecture_14_ex3.cpp}}
```

``` console
$ g++ -g test.cpp && ./a.out
Enter the type of geometry (t|q|p) with points (x,y): t((0,0),(1,1),(0,4))
Triangle: 
(0, 0)
(1, 1)
(0, 4)
Area: 2
$ g++ -g test.cpp && ./a.out
Enter the type of geometry (t|q|p) with points (x,y): q((0,0),(1,1),(3,4),(0,4))
Quadrilateral: 
(0, 0)
(1, 1)
(3, 4)
(0, 4)
Area: 6
$ g++ -g test.cpp && ./a.out
Enter the type of geometry (t|q|p) with points (x,y): p((0,0),(1,1),(3,4),(4,4),(0,4))
Polygon: 
(0, 0)
(1, 1)
(3, 4)
(4, 4)
(0, 4)
Area: 6
$
```

## Structure example: Vector & Matrix (Mathmatical)

``` c++
{{#include lecture_14_ex4.cpp}}
```

``` console
$ g++ -g test.cpp && ./a.out
Enter a vector: [9,10,11,12]
Vector v: 
[9, 10, 11, 12]
Length: 21.1187

Enter a matrix: [[1,2,3,4][5,6,7,8][9,10,11,12]]
Matrix m: 
[[1, 2, 3, 4]
[5, 6, 7, 8]
[9, 10, 11, 12]
]
$ 
```
