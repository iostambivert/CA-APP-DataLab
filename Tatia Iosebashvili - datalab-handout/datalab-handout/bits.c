/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only3 ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  //firstly we should negate both x and y, flip all the bits of each integer.
  /*bitwise OR operation results in a value where all the bits that were originally 0 in both x and y 
  are set to 1, and all other bits are cleared.*/
  //final negation flips flips all the bits of the result back, naturally means AND operation.
  return ~(~x|~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/* shifting by 3 buts computes the number of bits to shift x to reach the desired byte.
right shiftx by computed one aligns the byte of the interest to LSB.
bitwise AND operation with 0xFF extracting the byte from the shifted value.*/
return (x >> (n << 3)) & 0xFF;

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // Create a mask to clear the leftmost n bits
    int mask = ~(((1 << 31) >> n) << 1);

  // Perform logical right shift and clear the leftmost bits
    return (x >> n) & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int sum=0,mask;
	mask=0x11|(0x11<<8);//Now mask equals to 0x1111
	mask=mask|(mask<<16);//Now mask equals to 0x11111111
	sum+=x&mask;
	sum+=(x>>1)&mask;
	sum+=(x>>2)&mask;
	sum+=(x>>3)&mask;
	//4 bits a group
	mask=0xff|(0xff<<8);//Now mask equals to 0xffff
	sum=(sum&mask)+((sum>>16)&mask);
	mask=(0xf<<8)+0xf;//Now mask equals to 0x0f0f
	sum=(sum&mask)+((sum>>4)&mask);
	mask=0xff;
	sum=(sum&mask)+((sum>>8)&mask);
	return sum;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  //The given code implements the bang function, which takes an integer x as input and returns 1 if x is zero, and returns 0 otherwise.
  /*the first step is negate x to get -x and make bitwise or operation between x and -x,
   resulting in a value with all bits set if x is non-zero, and all bits cleared if x is zero. 
   Next, it right-shifts this result by 31 bits, extracting the sign bit. 
   If x is non-zero, the sign bit will be 0; if x is zero, the sign bit will be 1.
   finally, we add 1 in order to make sure the final result becomes 1, if x is zero, otherwise 0. */
  return (((~x + 1) | x) >> 31) + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* we can just simply shift it by 31 bits,which resulting in the binary representation 
  of the minimum value for a 32-bit signed integer.In two's complement representation, the leftmost bit (most significant bit)
  represents the sign of the number. For the minimum value, this bit is set to 1, indicating a negative number.
  All other bits are set to 0 to minimize the value represented.*/
  
    return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  // shifts out all but the n least significant bits.
  x=x>>(n+~0);
	//(x==0)||(x==-1)
  //checks if x is either 0 or -1. If x is 0, it returns 1 (true) because 0 can be represented by any number of bits.
  // If x is -1, it returns 1 (true) because -1 can be represented by all 1s, regardless of the number of bits.
	return (!x)|(!(x+1));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int bias,flag;//bias is the bias needed for negative number
	//flag is the MSB of x
    flag=(x>>31);
    bias=(1<<n)+(~0);
    bias&=flag;//Only negative numbers need bias
    x+=bias;
    return x>>n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2 
 */
int negate(int x) {
  /* if we want to return -x, we can just use this negation, wich always returns the opposite of given x. )) */
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
/*the first right shift operation on x by 31 bits extracts the sign bit of 'x'.
If x is negative, the sign bit will be 1; if x is non-negative (including zero), the sign bit will be 0.
The logical OR operation effectively combines the sign bit and the logical negation of x. 
If x is negative, the result will be all 1s; if x is non-negative (including zero), the result will be all 0s.
finally it applies logical negation (!) which stands for getting zero if x is negative, otherwise 1*/

  return !(((x >> 31) | (!x)));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*implementation basically starts from the XOR operation and then right shift by 31 bits, which extracts the sign bit.
   If x is less than y, the result will be 1; otherwise, it will be 0.logical OR operation with y effectively replaces the sign bit with 
   the value of y if x is less than y. next step is to negate previous one to return 0 if  x is less than y, otherwise 1. adding result to x
   stands for determining whether x is less than or equal to y or not. the right shift extracts the sign bit.  If the result is less than or equal to x, 
   the sign bit will be 0; otherwise, it will be 1. finally and operations provides the result is either 0 or 1 , according to the 'x' is less or equal to y or not.*/
  return ((x + ~(((x ^ y) >> 31) | y)) >> 31) & 1;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  //checks if the upper half of x (bits 16-31) is all zeroes.then shift by 4to obtain the most significant bit of the logarithm.
  int ans = (!(x >> 16)) << 4; 
  // checks if remaining bits are zeros, ans is obtained previously  If it is, it returns 1, otherwise 0.
  // This result is XORed with ans left-shifted by 3, which sets the next bit of the logarithm.
  ans ^= (!(x << ans >> 24)) << 3;
  //sets ans to XOR with 28, which adds a fixed offset to the logarithm.
  ans ^= 28;
  //checks if the remaining lower bits of x (bits 0 through ans - 1) are all zeroes. If it is, it returns 1, otherwise 0. 
  //This result is left-shifted by 2 and XORed with ans, setting another bit of the logarithm.
  ans ^= (!(x >> ans)) << 2;
  //It updates x by right-shifting it by ans bits.
  x = x >> ans;
  // extracts the bits of x (after the right shift) in positions 1-30 and uses them to index into a predefined table (0x5B),
  //returning a value between 0 and 3. This result is XORed with ans to set the last two bits of the logarithm.
  ans ^= ((~0x5B) >> (x & 30)) & 3;
  // The function returns the computed logarithm of x.
  return ans;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 //check whether uf is NaN
	unsigned mask;
	int temp;
  //mask is used to extract the sign bit of the float.
	mask=1U<<31;
  //Then, it combines the sign bit of the float with the exponent bits by performing a bitwise OR operation.
	temp=uf | mask;
  // It then right-shifts this combined value by 23 bits to isolate the exponent part (temp >>= 23).
	temp >>= 23;
  //It checks if the exponent part consists of all 1s (NaN) and if the fraction part is not all zeroes. 
  //If both conditions are met, indicating that the float is NaN, it returns the input float uf unchanged.
	if((!(~ temp)) && (!!(uf<<9))  )
		return uf;
  //If the float is not NaN, it performs a bitwise XOR operation between uf and the mask.
  // This operation flips the sign bit of the float, effectively negating it
	return uf ^ mask;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int flag = (x & 0x80000000), i, val1, val2, len, tempp, temp;//flag equals to (1 << 31) or 0,indicating the sign bit of x
	if(x == 0x80000000)//if x equals to INT_MIN
		return 0xcf000000;//Then we can not take -x, so just return the answer
	if(flag)//flag equals to (1 << 31) or 0, and flag is considered true when flag equals to (1 << 31)
		x = -x;//x now equals to abs(x)
	i = 31;//initialization of i, i will be the first bit of 1(from left to right, except the sign bit)
	do
	{
		if( x >> (--i) & 0x1)
			break;
	}
	while(i);
	if(x == 0)//x equals to zero
		return 0;
	temp = i + 127;//This temp is exp, 127 is the bias
	len = i - 23;//if i is greater than 23, than len is the number of bits that needed to be rounded
	if(len > 0)
	{
		val2 = x & ((0xffffffffU) >> (32 - len) );//Save the bits that will be rounded in val2
		val1 = (x >> len) & 0x007fffff;//val1 is the frac domain
		tempp = 1 << (len - 1);//set tempp to justify the round stat
		if((val2 > tempp) || ((val2 == tempp) && ((val1 & 0x1))))//There is a carry '1' here
			val1++;
	}
	else
		val1 = (x << (-len)) & 0x007fffff;//if len <= 0, which means the 23 bit of frac is enough, we do not need to consider val2

	if(val1 == 0x00800000 )//corner case, special judge
	{
		val1 = 0;
		temp++;
	}
	return flag  | ((temp << 23)) | (val1);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned s, exp, frac;
	s = uf & 0x80000000;//s is the sign bit
	exp = (uf >> 23) & 0x000000ff;//exp is the exponent domain
	frac = uf & 0x007fffff;//get the lowest 23 bits of uf
	if(exp == 255)//NaN or INF
		return uf;
	if(exp == 0)//denormalized floating point number
	{
		if(frac & 0x00400000)//if the first bit of frac is 1
			exp++;
		frac = (frac << 1) & 0x007fffff;
	}
	else
	{
		exp++;
		if(exp == 255)//If 2*uf is INF
			frac = 0;
	}
	return s | (exp << 23) | frac;
}
