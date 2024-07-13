#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif