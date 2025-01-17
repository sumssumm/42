#include <iostream>

#include "whatever.hpp"

int main(void) {
  int a = 2;
  int b = 3;
  std::cout << "before: " << "a = " << a << ", b = " << b << std::endl;

  ::swap(a, b);
  std::cout << "after: " << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";
  std::cout << "before: " << "c = " << c << ", d = " << d << std::endl;

  ::swap(c, d);
  std::cout << "after: " << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  return 0;
}

// #include "whatever.hpp"
// #include <iostream>
// class Awesome {
// public:
//   Awesome(void) : _n(0) {}
//   Awesome(int n) : _n(n) {}
//   Awesome &operator=(Awesome &a) {
//     _n = a._n;
//     return *this;
//   }
//   bool operator==(Awesome &rhs) const { return (this->_n == rhs._n); }
//   bool operator!=(Awesome &rhs) const { return (this->_n != rhs._n); }
//   bool operator>(Awesome &rhs) const { return (this->_n > rhs._n); }
//   bool operator<(Awesome &rhs) const { return (this->_n < rhs._n); }
//   bool operator>=(Awesome &rhs) const { return (this->_n >= rhs._n); }
//   bool operator<=(Awesome &rhs) const { return (this->_n <= rhs._n); }
//   int get_n() const { return _n; }

// private:
//   int _n;
// };
// std::ostream &operator<<(std::ostream &o, const Awesome &a) {
//   o << a.get_n();
//   return o;
// }
// int main(void) {
//   Awesome a(2), b(4);
//   swap(a, b);
//   std::cout << a << " " << b << std::endl;
//   std::cout << max(a, b) << std::endl;
//   std::cout << min(a, b) << std::endl;
//   return 0;
// }