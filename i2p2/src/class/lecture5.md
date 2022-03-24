<!--
marp: true
author: Yi-Wen Hung
theme: default
headingDivider: 2
paginate: true
-->

# Collaborate with Other Classes 

> Slides version: [lecture5_slides.html](./lecture5_slides.html)
> Website version: [lecture5.html](./lecture5.html)

* Interaction in other classes
* How to use a class with another class
  - as an argument
  - use member functions
  - use `friend` class
* How to use a class in another function
  - use getter and setter
  - use `friend` function
---
* `friend` function
  - syntax & example
* Example
  - Example: Triangle (again)
  - Example: Vector (again)
  - Example: Integer Calculator (again)
  - Example: Fixed Point Number
* Practices

## Interaction with other classes

User can use multiple classes to process data.
- use `std::vector` to store multiple `std::string` data
- compute the intersection of a line and a point in a 2D plane with user-defined `line` and `point` classes
- etc.

## How to use a class in another class

To use a class with another class:
  - as an argument
  - use member functions
  - `friend` class

---
### Use a class as an argument

Example: `Point_2D` and `Line_2D` (v1, partial)

```c++
#include <iostream>

using namespace std;

class Point_2D // a point on a 2D plane
{
private:
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;
public:
    // Constructor
    Point_2D(const int &arg_x = 0, const int &arg_y = 0);
    Point_2D(const Point_2D &arg_point);
   
    // Member functions
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    int get_x() const;
    int get_y() const;
};
```
---
``` c++
class Line_2D // a line on a 2D plane
{
private:
    // record the start point
    Point_2D m_start;
    // record the end point
    Point_2D m_end;
public:
    // Constructor
    Line_2D(const Point_2D &arg_start, const Point_2D &arg_end);
    Line_2D(const Line_2D &arg_line);
   
    // Member functions
    void set_start(const Point_2D &arg_start);
    void set_end(const Point_2D &arg_end);
    void set(const Point_2D &arg_start, const Point_2D &arg_end);
    Point_2D get_start() const;
    Point_2D get_end() const;
};
```

---
### Use member functions of a class

Example: `Point_2D` and `Line_2D` (v2, partial)

``` c++
class Line_2D // a line on a 2D plane
{
private:
    // record the start point
    Point_2D m_start;
    // record the end point
    Point_2D m_end;
public:
    // Constructor
    Line_2D(const Point_2D &arg_start, const Point_2D &arg_end);
    Line_2D(const Line_2D &arg_line);
    // use Point_2D's constructor to set the start and end point
    Line_2D(int arg_start_x = 0, int arg_start_y = 0,
            int arg_end_x = 0, int arg_end_y = 0);
```
---
``` c++   
    // Member functions
    void set_start(const Point_2D &arg_start);
    void set_end(const Point_2D &arg_end);
    void set(const Point_2D &arg_start, const Point_2D &arg_end);
    // use member function to set the x and y coordinates
    void set_start(int arg_x, int arg_y)
    {
        m_start.set_x(arg_x);
        m_start.set_y(arg_y);
    }
    void set_end(int arg_x, int arg_y)
    {
        m_end.set_x(arg_x);
        m_end.set_y(arg_y);
    }
    void set(int arg_start_x, int arg_start_y,
             int arg_end_x, int arg_end_y)
    {
        m_start.set_x(arg_start_x);
        m_start.set_y(arg_start_y);
        m_end.set_x(arg_end_x);
        m_end.set_y(arg_end_y);
    }
```
---
``` c++
    Point_2D get_start() const;
    Point_2D get_end() const;
    // use member function to get the x and y coordinates
    int get_start_x() const { return m_start.get_x(); }
    int get_start_y() const { return m_start.get_y(); }
    int get_end_x() const { return m_end.get_x(); }
    int get_end_y() const { return m_end.get_y(); }
};
```

---
### Use `friend` class

Example: `Point_2D` and `Line_2D` (v3, partial)

```c++
#include <iostream>

using namespace std;

class Point_2D // a point on a 2D plane
{
private:
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;
public:
    // Constructor
    Point_2D(const int &arg_x = 0, const int &arg_y = 0);
    Point_2D(const Point_2D &arg_point);
   
    // Member functions
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    int get_x() const;
    int get_y() const;

    // Friend class, can access private members
    friend class Line_2D;
};
```
---
``` c++
class Line_2D // a line on a 2D plane
{
private:
    // record the start point
    Point_2D m_start;
    // record the end point
    Point_2D m_end;
public:
    // Constructor
    Line_2D(const Point_2D &arg_start, const Point_2D &arg_end);
    Line_2D(const Line_2D &arg_line);
    // use Point_2D's constructor to set the start and end point
    Line_2D(int arg_start_x = 0, int arg_start_y = 0,
            int arg_end_x = 0, int arg_end_y = 0);
```
---
``` c++   
    // Member functions
    void set_start(const Point_2D &arg_start);
    void set_end(const Point_2D &arg_end);
    void set(const Point_2D &arg_start, const Point_2D &arg_end);
    // set the x and y coordinates directly because of friend class
    void set_start(int arg_x, int arg_y) 
    { 
        m_start.m_x = arg_x; m_start.m_y = arg_y; 
    }
    void set_end(int arg_x, int arg_y)
    {
        m_end.m_x = arg_x; m_end.m_y = arg_y;
    }
    void set(int arg_start_x, int arg_start_y,
             int arg_end_x, int arg_end_y)
    {
        m_start.m_x = arg_start_x; m_start.m_y = arg_start_y;
        m_end.m_x = arg_end_x; m_end.m_y = arg_end_y;
    }
```
---
``` c++
    Point_2D get_start() const;
    Point_2D get_end() const;
    // get the x and y coordinates directly because of friend class
    int get_start_x() const { return m_start.m_x; }
    int get_start_y() const { return m_start.m_y; }
    int get_end_x() const { return m_end.m_x; }
    int get_end_y() const { return m_end.m_y; }
};
```

## What is a `friend` class & `friend` function?

Ref: [Friend class and function in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/friend-class-function-cpp/)

> A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class.

### Friend Class Example

``` c++
#include <iostream>
class A {
private:
    int a;

public:
    A() { a = 0; }
    friend class B; // Friend Class
};
```
---
``` c++
class B {
private:
    int b;

public:
    void showA(A& x)
    {
        // Since B is friend of A, it can access
        // private members of A
        std::cout << "A::a=" << x.a;
    }
};

int main()
{
    A a;
    B b;
    b.showA(a);
    return 0;
}
```
---
### Friend Function Example

``` c++
#include <iostream>

class B; // Forward declaration, used in class A

class A {
public:
	void showB(B&);
};

class B {
private:
	int b;

public:
	B() { b = 0; }
	friend void A::showB(B& x); // Friend function
};
```
---
``` c++
void A::showB(B& x)
{
	// Since showB() is friend of B, it can
	// access private members of B
	std::cout << "B::b = " << x.b;
}

int main()
{
	A a;
	B x;
	a.showB(x);
	return 0;
}
```
---
### Friend Function Example (global)

``` c++
#include <iostream>

class A {
	int a;

public:
	A() { a = 0; }

	// global friend function
	friend void showA(A&);
};

void showA(A& x)
{
	// Since showA() is a friend, it can access
	// private members of A
	std::cout << "A::a=" << x.a;
}

int main()
{
	A a;
	showA(a);
	return 0;
}

```

## How to use a class in another function

To use a class with another function:
  - use getter and setter
  - use `friend` function

---
### Use getter and setter of a class

Example: compare two `Point_2D` objects

``` c++
int compare(const Point_2D &arg_point1, const Point_2D &arg_point2)
{
    // compare the x coordinates
    if (arg_point1.get_x() < arg_point2.get_x())
    {
        return -1;
    }
    else if (arg_point1.get_x() > arg_point2.get_x())
    {
        return 1;
    }
    else
    {
        // compare the y coordinates
        if (arg_point1.get_y() < arg_point2.get_y())
        {
            return -1;
        }
        else if (arg_point1.get_y() > arg_point2.get_y())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
```

---
### Use `friend` function

Example: compare two `Point_2D` objects with `friend` function

```c++
#include <iostream>

using namespace std;

class Point_2D // a point on a 2D plane
{
private:
    // record the x coordinate
    int m_x;
    // record the y coordinate
    int m_y;
public:
    // Constructor
    Point_2D(const int &arg_x = 0, const int &arg_y = 0);
    Point_2D(const Point_2D &arg_point);
   
    // Member functions
    void set_x(const int &arg_x);
    void set_y(const int &arg_y);
    void set(const int &arg_x, const int &arg_y);
    int get_x() const;
    int get_y() const;

    // Friend function, can access private members
    friend int compare(const Point_2D &arg_point1, const Point_2D &arg_point2);
};
```
---
``` c++
int compare(const Point_2D &arg_point1, const Point_2D &arg_point2)
{
    // compare the x coordinates
    if (arg_point1.m_x < arg_point2.m_x)
    {
        return -1;
    }
    else if (arg_point1.m_x > arg_point2.m_x)
    {
        return 1;
    }
    else
    {
        // compare the y coordinates
        if (arg_point1.m_y < arg_point2.m_y)
        {
            return -1;
        }
        else if (arg_point1.m_y > arg_point2.m_y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
```

## Example 1: Triangle (again) [[Source](./lecture5_ex1.html)]

A Triangle:
- contains 3 points
- on the 2D plane
- need to be able to calculate the area
- need to be initialized, printed, and modified

## Example 2: Vector (again) [[Source](./lecture5_ex2.html)]

A Vector:
- contains 3 factors of the 3 basis $\bold{i}$, $\bold{j}$, $\bold{k}$
- need to be able to calculate the length
- need to be able to calculate the dot, cross product
- need to be initialized, printed, and modified

## Example 3: Fixed Point Number & Fixed Point Number Calculator [[Source](./lecture5_ex3.html)]

A Fixed Point Number:
- contains a integer part, a fractional part, and a precision
- need to be able to calculate the sum, difference
- need to be able to convert to/from string, `float`, and `double`
- need to be initialized, printed, and modified
---
A Fixed Point Number Calculator:
- contains current value, input value, and operation
- need to be able to set the input value
- need to be able to set the operation
- need to be able to calculate the result
- need to be able to clear the input value
- need to be initialized
- need to be able to get all information

## Practices

- Practice 1: 參考 `Triangle` class, 如果需要支援多維度的座標系以及四邊形等其他圖形需要如何修改?
- Practice 2: 參考 `Vector` class, 如果需要支援多維度的座標系上、或是轉換 basis 為其他 vector 要如何修改?
- Practice 3: 參考 `Fp_Calc` class, 如果需要支援乘除法、超過 `Fixed_Point` 可儲存的範圍要如何設計相關的 member function?
