#include "node.h"
#include "poolOfNodes.h"
#include <cmath>
#include <cstdio>
#include <sstream>
#include <iomanip>

class Literal : public Node {
public:
  virtual ~Literal() {}

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

  virtual const Literal* opMin() const = 0;
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
    long double res = static_cast<long double>(static_cast<long long>(lhs / val));
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* op2Div(long long lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    long double res = static_cast<long double>(static_cast<long long>(lhs / val));
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
  virtual const Literal* opMod(long long lhs) const  {
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

  virtual const Literal* opPow(long long lhs) const {
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
     if  (fmod(val, 1.0) == 0) {
          std::cout << val << ".0" << std::endl;
      } else {
	//std::cout << std::setprecision(16) << val << std::endl;
        printf("%.16Lg\n", val);
      }
  }
  virtual void printStmt() const {
    //std::cout << "FLOAT: ";
     if  (fmod(val, 1.0) == 0) {
          std::cout << val << ".0" << std::endl;
     } else {
       int n = 12;
       int d = (int)::ceil(::log10(val < 0 ? -val : val)); /*digits before decimal point*/
       //long double order = ::pow(10., n - d);
       //std::cout << "n-->" << n << "d-->" << d << std::endl;
       //std::stringstream ss;
       //ss << std::setprecision(n - d) << std::round(val * order) / order;
       //std::cout << ss.str() << std::endl;
       //std::cout << std::setprecision(9) << val << std::endl;
       printf("%.12Lg\n", val);
     }
  }
private:
  long double val;
};

class IntLiteral: public Literal {
public:
 IntLiteral(long long _val): val(_val) {}

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
    long double res = static_cast<long double>(static_cast<long long>(lhs / val));
    long double m = fmod(lhs, val);
    if (((lhs < 0) ^ (val < 0)) && m != 0)
	res -= 1;
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
    const Literal* node = new FloatLiteral(fmod(lhs, val));
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
    long double res = 0.0;
    if (lhs != 0) {
      res = pow(lhs, val);
    }
    const Literal* node = new FloatLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPow(long long lhs) const {
    long long res = 0;
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
  virtual void printStmt() const {
    //std::cout << "INT: " << val << std::endl;
    std::cout << val << std::endl;
  }
private:
  long long val;
};

