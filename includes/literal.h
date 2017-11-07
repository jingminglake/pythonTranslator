#include "node.h"
#include "poolOfNodes.h"
#include <cmath>
#include <cstdio>
#include <iomanip>

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const = 0;
  virtual const Literal* opPlus(long double) const = 0;
  virtual const Literal* opPlus(int) const = 0;

  virtual const Literal* operator*(const Literal& rhs) const = 0;
  virtual const Literal* opMult(long double) const = 0;
  virtual const Literal* opMult(int) const = 0;

  virtual const Literal* operator-(const Literal& rhs) const = 0;
  virtual const Literal* opSubt(long double) const = 0;
  virtual const Literal* opSubt(int) const = 0;

  virtual const Literal* operator/(const Literal& rhs) const = 0;
  virtual const Literal* opDiv(long double) const = 0;
  virtual const Literal* opDiv(int) const = 0;
 
  virtual const Literal* opDoubleDiv(const Literal& rhs) const = 0;
  virtual const Literal* op2Div(long double) const = 0;
  virtual const Literal* op2Div(int) const = 0;

  virtual const Literal* operator%(const Literal& rhs) const = 0;
  virtual const Literal* opMod(long double) const = 0;
  virtual const Literal* opMod(int) const = 0;

  virtual const Literal* opPower(const Literal& rhs) const = 0;
  virtual const Literal* opPow(long double) const = 0;
  virtual const Literal* opPow(int) const = 0;

  virtual const Literal* opMin() const = 0;
  virtual const Literal* eval() const = 0;
  virtual void print() const {
    std::cout << "No Way" << std::endl;
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(long double _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
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
  virtual const Literal* opSubt(int lhs) const  {
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
  virtual const Literal* opMult(int lhs) const  {
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
  virtual const Literal* opDiv(int lhs) const  {
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
    long double res = static_cast<long double>(static_cast<int>(lhs / val));
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* op2Div(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    long double res = static_cast<long double>(static_cast<int>(lhs / val));
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(long double lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPow(val);
  }

  virtual const Literal* opPow(long double lhs) const {
    long double res = 0.0;
    if (lhs != 0) {
      res = pow(lhs, val);
    }
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opPow(int lhs) const {
    long double res = 0.0;
    if (lhs != 0) {
      res = pow(lhs, val);
    }
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* opMin() const {
    const Literal* node = new FloatLiteral(-val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const {
    //std::cout << "FLOAT: ";
      if  (val == (int)val) {
          std::cout << val << ".0" << std::endl;
      } else {
	//std::cout << std::setprecision(16) << val << std::endl;
        printf("%.16Lg\n", val);
      }
  }
private:
  long double val;
};

class IntLiteral: public Literal {
public:
 IntLiteral(int _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(long double lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<long double>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
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
  virtual const Literal* opSubt(int lhs) const {
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
  virtual const Literal* opMult(int lhs) const  {
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
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    int res = lhs / val;
    int m = lhs % val;
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
    long double res = static_cast<long double>(static_cast<int>(lhs / val));
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* op2Div(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    int res = lhs / val;
    int m = lhs % val;
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
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Mod Error");
    const Literal* node = new IntLiteral(((lhs % val) + val) % val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  
  virtual const Literal* opPower(const Literal& rhs) const {
    return rhs.opPow(val);
  }
  virtual const Literal* opPow(long double lhs) const {
    long double res = 0.0;
    if (lhs != 0) {
      res = pow(lhs, val);
    }
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(int lhs) const {
    int res = 0;
    if (lhs != 0) {
        res = pow(lhs, val);
    }
    const Literal* node = new IntLiteral(res);
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
private:
  int val;
};

