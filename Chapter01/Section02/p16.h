#ifndef _P16_H
#define _P16_H

enum signType { plus, minus };

class Currency {
 public:
  Currency(signType sign = plus, unsigned long dollars = 0,
           unsigned int cents = 0);
  void setValue(signType, unsigned long, unsigned int);
  void setValue(double);
  signType getSign() const { return _sign; }
  unsigned long getDollars() const { return _dollars; }
  unsigned int getCents() const { return _cents; }
  Currency add(const Currency&) const;
  Currency& increment(const Currency&);
  Currency subtract(const Currency&) const;
  void output() const;
  ~Currency() {}

 private:
  long castToLong() const;

 private:
  signType _sign;
  unsigned long _dollars;
  unsigned int _cents;
};

#endif