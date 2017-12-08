#include "node.h"
#include "poolOfNodes.h"
#include <cmath>
#include <cstdio>
#include <iomanip>

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual bool operator==(const Literal& rhs) const = 0;
  virtual bool opEqual(long double) const = 0;
  virtual bool opEqual(long long) const = 0;

  virtual bool operator<(const Literal& rhs) const = 0;
  virtual bool opLess(long double) const = 0;
  virtual bool opLess(long long) const = 0;

  virtual bool operator>(const Literal& rhs) const = 0;
  virtual bool opGreater(long double) const = 0;
  virtual bool opGreater(long long) const = 0;

  virtual bool operator>=(const Literal& rhs) const = 0;
  virtual bool opGreaterEqual(long double) const = 0;
  virtual bool opGreaterEqual(long long) const = 0;

  virtual bool operator<=(const Literal& rhs) const = 0;
  virtual bool opLessEqual(long double) const = 0;
  virtual bool opLessEqual(long long) const = 0;

  virtual bool operator!=(const Literal& rhs) const = 0;
  virtual bool opNotEqual(long double) const = 0;
  virtual bool opNotEqual(long long) const = 0;

  virtual const Literal* operator+(const Literal& rhs) const = 0;
  virtual const Literal* opPlus(long double) const = 0;
  virtual const Literal* opPlus(long long) const = 0;

  virtual const Literal* operator*(const Literal& rhs) const = 0;
  virtual const Literal* opMult(long double) const = 0;
  virtual const Literal* opMult(long long) const = 0;

  virtual const Literal* operator-(const Literal& rhs) const = 0;
  virtual const Literal* opSubt(long double) const = 0;
  virtual const Literal* opSubt(long long) const = 0;

  virtual const Literal* operator/(const Literal& rhs) const = 0;
  virtual const Literal* opDiv(long double) const = 0;
  virtual const Literal* opDiv(long long) const = 0;
 
  virtual const Literal* opDoubleDiv(const Literal& rhs) const = 0;
  virtual const Literal* op2Div(long double) const = 0;
  virtual const Literal* op2Div(long long) const = 0;

  virtual const Literal* operator%(const Literal& rhs) const = 0;
  virtual const Literal* opMod(long double) const = 0;
  virtual const Literal* opMod(long long) const = 0;

  virtual const Literal* opPower(const Literal& rhs) const = 0;
  virtual const Literal* opPow(long double) const = 0;
  virtual const Literal* opPow(long long) const = 0;

  virtual const Literal* operator<<(const Literal& rhs) const = 0;
  virtual const Literal* opLShift(long double) const = 0;
  virtual const Literal* opLShift(long long) const = 0;

  virtual const Literal* operator>>(const Literal& rhs) const = 0;
  virtual const Literal* opRShift(long double) const = 0;
  virtual const Literal* opRShift(long long) const = 0;

  virtual const Literal* operator&(const Literal& rhs) const = 0;
  virtual const Literal* opAmpersand(long double) const = 0;
  virtual const Literal* opAmpersand(long long) const = 0;

  virtual const Literal* operator|(const Literal& rhs) const = 0;
  virtual const Literal* opBar(long double) const = 0;
  virtual const Literal* opBar(long long) const = 0;

  virtual const Literal* operator^(const Literal& rhs) const = 0;
  virtual const Literal* opCircumflex(long double) const = 0;
  virtual const Literal* opCircumflex(long long) const = 0;

  virtual const Literal* opMin() const = 0;
  virtual const Literal* operator~() const = 0;
  virtual const Literal* eval() const = 0;
  virtual void print() const {
    std::cout << "No Way" << std::endl;
  }
  virtual void printStmt() const {
    std::cout << "No Way 2" << std::endl;
  }
};


class FloatLiteral: public Literal {
public:
  FloatLiteral(long double _val): val(_val) {}

  virtual bool operator==(const Literal& rhs) const {
    return rhs.opEqual(val);
  }
  virtual bool opEqual(long double lhs) const {
    return std::abs(val - lhs) < 1e-6;
  }
  virtual bool opEqual(long long lhs) const {
    return std::abs(val - lhs) < 1e-6;
  }

  virtual bool operator<(const Literal& rhs) const {
    return rhs.opLess(val);
  }
  virtual bool opLess(long double lhs) const {
    return lhs < val;
  }
  virtual bool opLess(long long lhs) const {
    return lhs < val;
  }

  virtual bool operator>(const Literal& rhs) const {
    return rhs.opGreater(val);
  }
  virtual bool opGreater(long double lhs) const {
    return lhs > val;
  }
  virtual bool opGreater(long long lhs) const {
    return lhs > val;
  }

  virtual bool operator>=(const Literal& rhs) const {
    return rhs.opGreaterEqual(val);
  }
  virtual bool opGreaterEqual(long double lhs) const {
    return lhs >= val;
  }
  virtual bool opGreaterEqual(long long lhs) const {
    return lhs >= val;
  }

  virtual bool operator<=(const Literal& rhs) const {
    return rhs.opLessEqual(val);
  }
  virtual bool opLessEqual(long double lhs) const {
    return lhs <= val;
  }
  virtual bool opLessEqual(long long lhs) const {
    return lhs <= val;
  }

  virtual bool operator!=(const Literal& rhs) const {
    return rhs.opNotEqual(val);
  }
  virtual bool opNotEqual(long double lhs) const {
    return lhs != val;
  }
  virtual bool opNotEqual(long long lhs) const {
    return lhs != val;
  }

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(long long lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(long long lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(long long lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<long double>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opDoubleDiv(const Literal& rhs) const  {
    return rhs.op2Div(val);
  }
  virtual const Literal* op2Div(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* op2Div(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    long double res = static_cast<long double>(static_cast<long long>(lhs / val));
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    if (res == 0 && ((lhs < 0) ^ (val < 0)))
        res *= -1.0;
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new FloatLiteral(fmod((fmod(lhs, val) + val) , val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new FloatLiteral(fmod((fmod(lhs, val) + val) , val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPow(val);
  }

  virtual const Literal* opPow(long double lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opPow(long long lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<<(const Literal& rhs) const  {
    return rhs.opLShift(val);
  }
  virtual const Literal* opLShift(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for <<: 'float' and 'float'");
    return nullptr;
  }
  virtual const Literal* opLShift(long long lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for <<: 'int' and 'float'");
    return nullptr;
  }

  virtual const Literal* operator>>(const Literal& rhs) const  {
    return rhs.opRShift(val);
  }
  virtual const Literal* opRShift(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for >>: 'float' and 'float'");
    return nullptr;
  }
  virtual const Literal* opRShift(long long lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for >>: 'int' and 'float'");
    return nullptr;
  }

  virtual const Literal* operator&(const Literal& rhs) const  {
    return rhs.opAmpersand(val);
  }
  virtual const Literal* opAmpersand(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for &: 'float' and 'float'");
    return nullptr;
  }
  virtual const Literal* opAmpersand(long long lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for &: 'int' and 'float'");
    return nullptr;
  }

  virtual const Literal* operator|(const Literal& rhs) const  {
    return rhs.opBar(val);
  }
  virtual const Literal* opBar(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for |: 'float' and 'float'");
    return nullptr;
  }
  virtual const Literal* opBar(long long lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for |: 'int' and 'float'");
    return nullptr;
  }

  virtual const Literal* operator^(const Literal& rhs) const  {
    return rhs.opCircumflex(val);
  }
  virtual const Literal* opCircumflex(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for ^: 'float' and 'float'");
    return nullptr;
  }
  virtual const Literal* opCircumflex(long long lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for ^: 'int' and 'float'");
    return nullptr;
  }

  virtual const Literal* opMin() const {
    const Literal* node = new FloatLiteral(-val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator~() const  {
    throw std::string("TypeError: bad operand type for unary ~: 'float'");
     return nullptr;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    //std::cout << "FLOAT: ";
    if  (fmod(val, 1.0) == 0) {
      std::cout << val << ".0" << std::endl;
    } else {
      std::cout << std::setprecision(16) << val << std::endl;
      //printf("%.16Lg\n", val);
    }
  }
  virtual void printStmt() const {
    //std::cout << "FLOAT: ";
    if  (fmod(val, 1.0) == 0 && val < 1e+16) {
      std::cout << val << ".0" << std::endl;
    } else {
      std::cout << std::setprecision(12) << val << std::endl;
    }
  }

private:
  long double val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(long long _val): val(_val) {}
  
  virtual bool operator==(const Literal& rhs) const {
    return rhs.opEqual(val);
  }
  virtual bool opEqual(long double lhs) const {
    return std::abs(val - lhs) < 1e-6;
  }
  virtual bool opEqual(long long lhs) const {
    return val == lhs;
  }

  virtual bool operator<(const Literal& rhs) const {
    return rhs.opLess(val);
  }
  virtual bool opLess(long double lhs) const {
    return lhs < val;
  }
  virtual bool opLess(long long lhs) const {
    return lhs < val;
  }

  virtual bool operator>(const Literal& rhs) const {
    return rhs.opGreater(val);
  }
  virtual bool opGreater(long double lhs) const {
    return lhs > val;
  }
  virtual bool opGreater(long long lhs) const {
    return lhs > val;
  }

  virtual bool operator>=(const Literal& rhs) const {
    return rhs.opGreaterEqual(val);
  }
  virtual bool opGreaterEqual(long double lhs) const {
    return lhs >= val;
  }
  virtual bool opGreaterEqual(long long lhs) const {
    return lhs >= val;
  }

  virtual bool operator<=(const Literal& rhs) const {
    return rhs.opLessEqual(val);
  }
  virtual bool opLessEqual(long double lhs) const {
    return lhs <= val;
  }
  virtual bool opLessEqual(long long lhs) const {
    return lhs <= val;
  }

  virtual bool operator!=(const Literal& rhs) const {
    return rhs.opNotEqual(val);
  }
  virtual bool opNotEqual(long double lhs) const {
    return lhs != val;
  }
  virtual bool opNotEqual(long long lhs) const {
    return lhs != val;
  }

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<long double>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(long long lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(long long lhs) const {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(long long lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    //char buf[100];
    // sprintf(buf, "%.16Lf", (long double)lhs /(long double)val);
    //std::cout << "SUccessfully parsed111: " << buf << std::endl;
    //char * e;
    //errno = 0;
    //long double res = std::strtold(buf, &e);
    //if (*e != '\0' || errno != 0) { /* error */ std::abort(); }

    //std::cout << "Successfully parsed: " << res << std::endl;
    //std::cout << "-=-=-=-2=-=-=-=-=--" << res << std::endl;
    //long double x = 1.0;
    //long double y = 3.0;
    //printf("%.16Lf\n", x / y);
    //std::cout << "-=-=-=-=-=-=" << x / y << std::endl;
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    long long res = lhs / val;
    long long m = lhs % val;
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    const Literal* node = new IntLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opDoubleDiv(const Literal& rhs) const  {
    return rhs.op2Div(val);
  }
  virtual const Literal* op2Div(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    long double res = static_cast<long long>(lhs / val);
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    if (res == 0 && ((lhs < 0) ^ (val < 0)))
        res *= -1.0;
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* op2Div(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    long long res = lhs / val;
    long long m = lhs % val;
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    const Literal* node = new IntLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new FloatLiteral(fmod((fmod(lhs, val) + val) , val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new IntLiteral(((lhs % val) + val) % val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(long double lhs) const {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(long long lhs) const {
    const Literal* node = new IntLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator<<(const Literal& rhs) const  {
    return rhs.opLShift(val);
  }
  virtual const Literal* opLShift(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for <<: 'float' and 'int'");
    return nullptr;
  }
  virtual const Literal* opLShift(long long lhs) const  {
    if (val < 0)
      throw std::string("ValueError: negative shift count");
    const Literal* node = new IntLiteral(lhs << val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator>>(const Literal& rhs) const  {
    return rhs.opRShift(val);
  }
  virtual const Literal* opRShift(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for >>: 'float' and 'int'");
    return nullptr;
  }
  virtual const Literal* opRShift(long long lhs) const  {
    if (val < 0)
      throw std::string("ValueError: negative shift count");
    const Literal* node = new IntLiteral(lhs >> val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator&(const Literal& rhs) const  {
    return rhs.opAmpersand(val);
  }
  virtual const Literal* opAmpersand(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for &: 'float' and 'int'");
    return nullptr;
  }
  virtual const Literal* opAmpersand(long long lhs) const  {
    const Literal* node = new IntLiteral(lhs & val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator|(const Literal& rhs) const  {
    return rhs.opBar(val);
  }
  virtual const Literal* opBar(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for |: 'float' and 'int'");
    return nullptr;
  }
  virtual const Literal* opBar(long long lhs) const  {
    const Literal* node = new IntLiteral(lhs | val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator^(const Literal& rhs) const  {
    return rhs.opCircumflex(val);
  }
  virtual const Literal* opCircumflex(long double lhs) const  {
    lhs = 0;
    throw std::string("TypeError: unsupported operand type(s) for ^: 'float' and 'int'");
    return nullptr;
  }
  virtual const Literal* opCircumflex(long long lhs) const  {
    const Literal* node = new IntLiteral(lhs ^ val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator~() const  {
    const Literal* node = new IntLiteral(~val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opMin() const {
    const Literal* node = new IntLiteral(-val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    //std::cout << "INT: " << val << std::endl;
    std::cout << val << std::endl;
  }
  virtual void printStmt() const {
    //std::cout << "INT: " << val << std::endl;
    std::cout << val << std::endl;
  }
protected:
  long long val;
};

class BoolLiteral: public IntLiteral {
public:
  BoolLiteral(int _val): IntLiteral(_val) {}

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    if (val)
      std::cout << "True" << std::endl;
    else
      std::cout << "False" << std::endl;
  }
  virtual void printStmt() const {
    if (val)
      std::cout << "True" << std::endl;
    else
      std::cout << "False" << std::endl;
  }
};

class NullLiteral : public IntLiteral {
public:
  NullLiteral(): IntLiteral(0) {}
  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    std::cout << "None" << std::endl;
  }
  virtual void printStmt() const {
    std::cout << "None" << std::endl;
  }
};
