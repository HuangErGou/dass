#include "p16.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char const *argv[]) {
  Currency currenty1, currenty2;

  currenty1.setValue(1.23);
  currenty2.setValue(2.34);

  currenty1.add(currenty2).output();
  currenty1.increment(currenty2);
  currenty1.output();
  return 0;
}

Currency::Currency(signType sign, unsigned long dollars, unsigned int cents) {
  setValue(sign, dollars, cents);
}

void Currency::setValue(signType sign, unsigned long dollars,
                        unsigned int cents) {
  if (cents > 99) throw std::invalid_argument("Cents should be < 100");

  _sign = sign;
  _dollars = dollars;
  _cents = cents;
}

void Currency::setValue(double amount) {
  signType sign = amount < 0 ? minus : plus;
  unsigned long dollars = (unsigned long)amount;
  unsigned int cents = ((unsigned long)(amount * 100)) % 100;

  setValue(sign, dollars, cents);
}

Currency Currency::add(const Currency &value) const {
  long a3 = castToLong() + value.castToLong();

  signType result_sign = a3 >= 0 ? plus : minus;
  if (minus == result_sign) a3 = -a3;

  unsigned long result_dollars = a3 / 100;
  unsigned int result_cents = a3 - result_dollars * 100;
  return Currency(result_sign, result_dollars, result_cents);
}

Currency &Currency::increment(const Currency &value) {
  *this = add(value);
  return *this;
}

Currency Currency::subtract(const Currency &value) const { return Currency(); }

void Currency::output() const {
  if (_sign == minus) std::cout << "-";
  std::cout << "$" << _dollars << ".";
  if (_cents < 10) std::cout << "0";
  std::cout << _cents << std::endl;
}

long Currency::castToLong() const {
  long value = _dollars * 100 + _cents;
  value = _sign == plus ? value : value;
  return value;
}
