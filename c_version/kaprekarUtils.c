#include<math.h>
#include<stdio.h>
#include "kaprekarUtils.h"
#include<stdlib.h>

/**
 * <p>This function tests whether the given input <code>n</code>
 * is a Kaprekar Number or not.  A Kaprekar Number is a non-negative
 * integer n whose square can be split into two positive integers 
 * whose sum is equal to the original number.  For the purposes of 
 * this method, we restrict our consideration to base-10 representations.</p>
 * 
 * For example, 45 is a Kaprekar number, because 
 *   45<sup>2</sup> = 2025 
 * and 
 *   20 + 25 = 45. 
 * 
 * <p>See Wikipedia's  
 * <a href="https://en.wikipedia.org/wiki/Kaprekar_number">Kaprekar Number</a>
 * article for more information.</p>
 * 
 * @param n
 * @return <code>true</code> if <code>n</code> is a Kaprekar Number, 
 * <code>false</code> otherwise.
 *
 * Bug fixes by Daniel Andrews
 * Fixed bug in line 41.  Previous version didn't have the (long) n squared.
 * Fixed spelling of modulus
 * Fixed the value of i, was previously zero, but that caused a divide by zero error.
 * Fixed the log10 (square) in line 42.
 *
 *
 */
int isKaprekar(int n) {

  if(n < 1) {
    return 0;
  }

  int i;
  long square = (long) n * (long) n;
  int numberofDigits = (int) log10(square) + 1;
  long modulus = 1;
  long first, second;
  for(i=1; i<=numberofDigits; i++) {
    modulus *= 10;
    first = square / modulus;
    second = square % modulus;
    if(second > 0 &&
       first + second == n) {
      return 1;
    }
  }
  return 0;
  
}
