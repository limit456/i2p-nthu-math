#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Fp_Calc; // forward declaration

// Fixed point class declaration
class Fixed_Point
{
private:
    long long int m_int_part;
    long long int m_frac_part;
    unsigned int m_precision;

    // utility functions
    // set fixed point without checking
    void _set(const string &arg_str);
    // normalize to m_precision
    void _normalize(const unsigned int arg_precision = 0);

public:
    Fixed_Point(const long long int &arg_int_part = 0,
                const unsigned long long int &arg_frac_part = 0,
                const unsigned int &arg_precision = 9);
    Fixed_Point(const string &arg_str);

    ~Fixed_Point();

    // getter & setter
    void set_int_part(const long long int arg_int_part);
    void set_frac_part(const unsigned long long int arg_frac_part);
    void set_precision(const unsigned int arg_precision);
    void set(const long long int &arg_int_part,
             const unsigned long long int &arg_frac_part,
             const unsigned int &arg_precision);
    void set(const string &arg_str);
    void set(const double &arg_double);
    void set(const float &arg_float);
    long long int get_int_part() const;
    unsigned long long int get_frac_part() const;
    unsigned int get_precision() const;
    double get_double_value() const;
    float get_float_value() const;
    string get_string_value() const;

    // formatted output
    void print() const;

    // arithmetic operation
    Fixed_Point add(const Fixed_Point &arg_fp) const;
    Fixed_Point sub(const Fixed_Point &arg_fp) const;

    // friend class
    friend class Fp_Calc;
};

// Fixed point calculator class declaration
class Fp_Calc
{
private:
    // define current value
    Fixed_Point m_curr_val;
    // define input value
    Fixed_Point m_input_val;
    // define operation
    // `+`, `-`, `*`, `/`, and ` ` for none
    char m_op;
    // calculate result
    void _calc_result();

public:
    // Constructor
    Fp_Calc();
    // Copy constructor
    Fp_Calc(const Fp_Calc &arg_int_calc);

    // Destructor
    ~Fp_Calc(){}; // no need to do anything

    // clear the input value
    void clear();
    // set the input value
    void set_input(const string &arg_input);
    // add the input value to the current value
    void add();
    // subtract the input value from the current value
    void sub();
    // multiply the input value with the current value
    void mul();
    // divide the current value by the input value
    void div();
    // assign the input value to the current value
    void assign();
    // get the current value
    Fixed_Point get_curr_val();
    // get the current operation
    char get_op();
    // get the input value
    Fixed_Point get_input_val();
};

// Fixed point class implementation

// utility functions

// set fixed point without checking
void Fixed_Point::_set(const string &arg_str)
{
    // set integer part
    m_int_part = stoll(arg_str.substr(0, arg_str.find('.')));
    // set fractional part
    m_frac_part = stoull(arg_str.substr(arg_str.find('.') + 1));
    // set precision
    m_precision = arg_str.length() - arg_str.find('.') - 1;
}

// normalize to precision
void Fixed_Point::_normalize(const unsigned int arg_precision)
{
    unsigned int temp_precision = arg_precision;
    // if precision is not specified, use the current precision
    if (arg_precision == 0)
    {
        temp_precision = m_precision;
    }
    // if precision is over the maximum, use the maximum
    else if (arg_precision > 9)
    {
        temp_precision = 9;
    }
    else
    {
        temp_precision = arg_precision;
    }

    // update fractional part
    int precision_diff = temp_precision - m_precision;
    if (precision_diff > 0)
    {
        m_frac_part *= pow(10, precision_diff);
    }
    else if (precision_diff < 0)
    {
        m_frac_part /= pow(10, -precision_diff);
    }

    // update m_precision
    m_precision = temp_precision;

    // handle fractional part overflow

    // update integer part
    if (m_frac_part >= pow(10, m_precision))
    {
        m_int_part += m_frac_part / pow(10, m_precision);
        m_frac_part %= (int)pow(10, m_precision);
    }

    // handle fractional part underflow

    // update integer part
    if (m_frac_part < 0)
    {
        m_int_part -= 1;
        m_frac_part += pow(10, m_precision);
    }
}

// Constructor
Fixed_Point::Fixed_Point(const long long int &arg_int_part,
                         const unsigned long long int &arg_frac_part,
                         const unsigned int &arg_precision)
    : m_int_part(arg_int_part),
      m_frac_part(arg_frac_part),
      m_precision(arg_precision)
{
}

Fixed_Point::Fixed_Point(const string &arg_string)
{
    _set(arg_string);
    _normalize();
}

Fixed_Point::~Fixed_Point()
{
    // do nothing
}

// getter & setter
void Fixed_Point::set_int_part(const long long int arg_int_part)
{
    m_int_part = arg_int_part;
}
void Fixed_Point::set_frac_part(const unsigned long long int arg_frac_part)
{
    m_frac_part = arg_frac_part;
    _normalize();
}
void Fixed_Point::set_precision(const unsigned int arg_precision)
{
    _normalize(arg_precision);
}
void Fixed_Point::set(const long long int &arg_int_part,
                      const unsigned long long int &arg_frac_part,
                      const unsigned int &arg_precision)
{
    m_int_part = arg_int_part;
    m_frac_part = arg_frac_part;
    m_precision = arg_precision;
    _normalize();
}
void Fixed_Point::set(const string &arg_str)
{
    _set(arg_str);
    _normalize();
}
void Fixed_Point::set(const double &arg_double)
{
    _set(to_string(arg_double));
    _normalize();
}
void Fixed_Point::set(const float &arg_float)
{
    _set(to_string(arg_float));
    _normalize();
}
long long int Fixed_Point::get_int_part() const
{
    return m_int_part;
}
unsigned long long int Fixed_Point::get_frac_part() const
{
    return m_frac_part;
}
unsigned int Fixed_Point::get_precision() const
{
    return m_precision;
}
double Fixed_Point::get_double_value() const
{
    return double(m_int_part) + double(m_frac_part) / pow(10, m_precision);
}
float Fixed_Point::get_float_value() const
{
    return float(m_int_part) + float(m_frac_part) / pow(10, m_precision);
}
string Fixed_Point::get_string_value() const
{
    string str_int_part = to_string(m_int_part);
    string str_frac_part = to_string(m_frac_part);
    // if precision is not specified, use the current precision
    if (m_precision == 0)
    {
        return str_int_part;
    }
    // if precision is 1, return integer part and fractional part
    else if (m_precision == 1)
    {
        return str_int_part + "." + str_frac_part;
    }
    // if precision is over 1, return integer part and fractional part with
    // specified precision
    else
    {
        // if fractional part is 0, return integer part
        if (str_frac_part == "0")
        {
            return str_int_part;
        }
        // if fractional part is not 0, return integer part and fractional part
        else
        {
            // if fractional part is less than precision, add 0 to the front
            if (str_frac_part.length() < m_precision)
            {
                str_frac_part = string(m_precision - str_frac_part.length(), '0') + str_frac_part;
            }
            // if fractional part is more than precision, remove the end
            else if (str_frac_part.length() > m_precision)
            {
                str_frac_part = str_frac_part.substr(0, m_precision);
            }
            return str_int_part + "." + str_frac_part;
        }
    }
}

void Fixed_Point::print() const
{
    cout << get_string_value();
}

Fixed_Point Fixed_Point::add(const Fixed_Point &arg_fixed_point) const
{
    Fixed_Point result;
    Fixed_Point normalized_this(*this);
    Fixed_Point normalized_arg(arg_fixed_point);
    unsigned int max_precision = max(normalized_this.m_precision,
                                     normalized_arg.m_precision);
    normalized_this.set_precision(max_precision);
    normalized_arg.set_precision(max_precision);
    result.m_precision = max_precision;
    result.m_int_part = normalized_this.m_int_part + normalized_arg.m_int_part;
    result.m_frac_part = normalized_this.m_frac_part + normalized_arg.m_frac_part;
    result._normalize();
    return result;
}

Fixed_Point Fixed_Point::sub(const Fixed_Point &arg_fixed_point) const
{
    Fixed_Point result;
    Fixed_Point normalized_this(*this);
    Fixed_Point normalized_arg(arg_fixed_point);
    unsigned int max_precision = max(normalized_this.m_precision,
                                     normalized_arg.m_precision);
    normalized_this.set_precision(max_precision);
    normalized_arg.set_precision(max_precision);
    result.m_precision = max_precision;
    result.m_int_part = normalized_this.m_int_part - normalized_arg.m_int_part;
    result.m_frac_part = normalized_this.m_frac_part - normalized_arg.m_frac_part;
    result._normalize();
    return result;
}

// Fp_Calc class implementation

// Constructor
Fp_Calc::Fp_Calc()
    : m_curr_val(), m_input_val(), m_op(' ')
{
}

// Copy constructor
Fp_Calc::Fp_Calc(const Fp_Calc &arg_int_calc)
    : m_curr_val(arg_int_calc.m_curr_val),
      m_input_val(arg_int_calc.m_input_val),
      m_op(arg_int_calc.m_op)
{
}

// calculate the result
void Fp_Calc::_calc_result()
{
    switch (m_op)
    {
    case '+':
        m_curr_val = m_curr_val.add(m_input_val);
        break;
    case '-':
        m_curr_val = m_curr_val.sub(m_input_val);
        break;
    case ' ':
        m_curr_val = m_input_val;
        break;
    default:
        break;
    }
}

// clear the input value
void Fp_Calc::clear()
{
    m_input_val = Fixed_Point();
}

// set the input value
void Fp_Calc::set_input(const string &arg_input_val)
{
    m_input_val = Fixed_Point(arg_input_val);
}

// add the input value to the current value
void Fp_Calc::add()
{
    _calc_result();
    m_op = '+';
}

// subtract the input value from the current value
void Fp_Calc::sub()
{
    _calc_result();
    m_op = '-';
}

// multiply the input value with the current value
void Fp_Calc::mul()
{
    _calc_result();
    m_op = '*';
}

// divide the current value by the input value
void Fp_Calc::div()
{
    _calc_result();
    m_op = '/';
}

// assign the input value to the current value
void Fp_Calc::assign()
{
    _calc_result();
    m_op = ' ';
}

// get the current value
Fixed_Point Fp_Calc::get_curr_val()
{
    return m_curr_val;
}

// get the current operation
char Fp_Calc::get_op()
{
    return m_op;
}

// get the input value
Fixed_Point Fp_Calc::get_input_val()
{
    return m_input_val;
}

// main function

int main()
{
    // create an instance of the class
    Fp_Calc calc;
    // set the input value
    calc.set_input("10.0");
    // get the input value
    calc.get_input_val().print();
    cout << endl;
    // add the input value to the current value
    calc.add();
    // get current op
    cout << '\'' << calc.get_op() << '\'' << endl;
    // set another input value
    calc.set_input("20.0123");
    // get the input value
    calc.get_input_val().print();
    cout << endl;
    // clear the input value
    calc.clear();
    cout << "clear" << endl;
    // set the input value
    calc.set_input("30.000456");
    // get the input value
    calc.get_input_val().print();
    cout << endl;
    // subtract the input value from the current value
    calc.sub();
    // get current op
    cout << '\'' << calc.get_op() << '\'' << endl;
    // print the result
    calc.get_curr_val().print();
    cout << endl;
    // set another input value
    calc.set_input("20.0123");
    // get the input value
    calc.get_input_val().print();
    cout << endl;
    // compute the result
    calc.assign();
    // print the result
    calc.get_curr_val().print();
    cout << endl;
}