#ifndef EXAMPLE_H
#define EXAMPLE_H

//namespace example {
//  int multiply(float a, float b);
//}

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

using namespace facebook;

void installCryptography(jsi::Runtime &rt);

void cleanUpCryptography();

#endif /* EXAMPLE_H */
