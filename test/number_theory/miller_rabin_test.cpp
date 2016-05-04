//          Copyright Diego Ramirez 2015
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cpl/number_theory/miller_rabin.hpp>
#include <gtest/gtest.h>

#include <cstdint>          // uint64_t, UINT64_C
#include <initializer_list> // initializer_list

using cpl::miller_rabin_primality_test;
using std::uint64_t;

template <typename T>
static void test_prime(const T x) {
  EXPECT_TRUE(miller_rabin_primality_test(x))
      << x << " is an expected prime number but Miller-Rabin tells it is not.";
}

template <typename T>
static void test_composite(const T x) {
  EXPECT_FALSE(miller_rabin_primality_test(x))
      << x
      << " is an expected composite number but Miller-Rabin tells it is not.";
}

static void test_prime_numbers(const std::initializer_list<uint64_t> ilist) {
  for (const auto x : ilist)
    test_prime(x);
}

static void
test_composite_numbers(const std::initializer_list<uint64_t> ilist) {
  for (const auto x : ilist)
    test_composite(x);
}

TEST(MillerRabinTest, DegenerateNumbersTest) {
  test_composite(1u);
  test_prime(2u);
}

TEST(MillerRabinTest, PrimesUnder2147Test) {
  test_prime_numbers(
      {2,    3,    5,    7,    11,   13,   17,   19,   23,   29,   31,   37,
       41,   43,   47,   53,   59,   61,   67,   71,   73,   79,   83,   89,
       97,   101,  103,  107,  109,  113,  127,  131,  137,  139,  149,  151,
       157,  163,  167,  173,  179,  181,  191,  193,  197,  199,  211,  223,
       227,  229,  233,  239,  241,  251,  257,  263,  269,  271,  277,  281,
       283,  293,  307,  311,  313,  317,  331,  337,  347,  349,  353,  359,
       367,  373,  379,  383,  389,  397,  401,  409,  419,  421,  431,  433,
       439,  443,  449,  457,  461,  463,  467,  479,  487,  491,  499,  503,
       509,  521,  523,  541,  547,  557,  563,  569,  571,  577,  587,  593,
       599,  601,  607,  613,  617,  619,  631,  641,  643,  647,  653,  659,
       661,  673,  677,  683,  691,  701,  709,  719,  727,  733,  739,  743,
       751,  757,  761,  769,  773,  787,  797,  809,  811,  821,  823,  827,
       829,  839,  853,  857,  859,  863,  877,  881,  883,  887,  907,  911,
       919,  929,  937,  941,  947,  953,  967,  971,  977,  983,  991,  997,
       1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
       1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163,
       1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249,
       1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321,
       1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439,
       1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511,
       1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601,
       1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693,
       1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783,
       1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877,
       1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987,
       1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069,
       2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143});
}

TEST(MillerRabinTest, StrongPseudoprimesTest) {
  // Strong pseudoprimes used in the implementation.
  test_composite_numbers({2147, 9080191, 4759123141, 1122004669633,
                          2152302898747, 3474749660383, 341550071728321,
                          3825123056546413051});

  // Other significative strong pseudoprimes
  test_composite_numbers({1373653, 25326001, 3215031751});

  // Strong pseudoprimes to base 2.
  test_composite_numbers(
      {2047,   3277,   4033,   4681,   8321,   15841,  29341,  42799,
       49141,  52633,  65281,  74665,  80581,  85489,  88357,  90751,
       104653, 130561, 196093, 220729, 233017, 252601, 253241, 256999,
       271951, 280601, 314821, 357761, 390937, 458989, 476971, 486737});

  // Strong pseudoprimes to base 3.
  test_composite_numbers(
      {121,    703,    1891,   3281,   8401,   8911,   10585,  12403,  16531,
       18721,  19345,  23521,  31621,  44287,  47197,  55969,  63139,  74593,
       79003,  82513,  87913,  88573,  97567,  105163, 111361, 112141, 148417,
       152551, 182527, 188191, 211411, 218791, 221761, 226801});

  // Strong pseudoprimes to base 4.
  test_composite_numbers(
      {341,   1387,  2047,  3277,  4033,   4371,   4681,   5461,   8321,
       8911,  10261, 13747, 14491, 15709,  15841,  19951,  29341,  31621,
       42799, 49141, 49981, 52633, 60787,  65077,  65281,  74665,  80581,
       83333, 85489, 88357, 90751, 104653, 123251, 129921, 130561, 137149});
}

TEST(MillerRabinTest, DifferentBitsNumberTest) {
  // Thanks to https://primes.utm.edu/lists/2small/0bit.html

  auto test_set = [](const size_t n, std::initializer_list<uint64_t> ilist) {
    const uint64_t two_pow_n = (n == 64) ? 0 : (UINT64_C(1) << n);
    for (const uint64_t k : ilist) {
      const auto p = two_pow_n - k;
      test_prime(p);
    }
  };

  test_set(8, {5, 15, 17, 23, 27, 29, 33, 45, 57, 59});
  test_set(9, {3, 9, 13, 21, 25, 33, 45, 49, 51, 55});
  test_set(10, {3, 5, 11, 15, 27, 33, 41, 47, 53, 57});
  test_set(11, {9, 19, 21, 31, 37, 45, 49, 51, 55, 61});
  test_set(12, {3, 5, 17, 23, 39, 45, 47, 69, 75, 77});
  test_set(13, {1, 13, 21, 25, 31, 45, 69, 75, 81, 91});
  test_set(14, {3, 15, 21, 23, 35, 45, 51, 65, 83, 111});
  test_set(15, {19, 49, 51, 55, 61, 75, 81, 115, 121, 135});
  test_set(16, {15, 17, 39, 57, 87, 89, 99, 113, 117, 123});
  test_set(17, {1, 9, 13, 31, 49, 61, 63, 85, 91, 99});
  test_set(18, {5, 11, 17, 23, 33, 35, 41, 65, 75, 93});
  test_set(19, {1, 19, 27, 31, 45, 57, 67, 69, 85, 87});
  test_set(20, {3, 5, 17, 27, 59, 69, 129, 143, 153, 185});
  test_set(21, {9, 19, 21, 55, 61, 69, 105, 111, 121, 129});
  test_set(22, {3, 17, 27, 33, 57, 87, 105, 113, 117, 123});
  test_set(23, {15, 21, 27, 37, 61, 69, 135, 147, 157, 159});
  test_set(24, {3, 17, 33, 63, 75, 77, 89, 95, 117, 167});
  test_set(25, {39, 49, 61, 85, 91, 115, 141, 159, 165, 183});
  test_set(26, {5, 27, 45, 87, 101, 107, 111, 117, 125, 135});
  test_set(27, {39, 79, 111, 115, 135, 187, 199, 219, 231, 235});
  test_set(28, {57, 89, 95, 119, 125, 143, 165, 183, 213, 273});
  test_set(29, {3, 33, 43, 63, 73, 75, 93, 99, 121, 133});
  test_set(30, {35, 41, 83, 101, 105, 107, 135, 153, 161, 173});
  test_set(31, {1, 19, 61, 69, 85, 99, 105, 151, 159, 171});
  test_set(32, {5, 17, 65, 99, 107, 135, 153, 185, 209, 267});
  test_set(33, {9, 25, 49, 79, 105, 285, 301, 303, 321, 355});
  test_set(34, {41, 77, 113, 131, 143, 165, 185, 207, 227, 281});
  test_set(35, {31, 49, 61, 69, 79, 121, 141, 247, 309, 325});
  test_set(36, {5, 17, 23, 65, 117, 137, 159, 173, 189, 233});
  test_set(37, {25, 31, 45, 69, 123, 141, 199, 201, 351, 375});
  test_set(38, {45, 87, 107, 131, 153, 185, 191, 227, 231, 257});
  test_set(39, {7, 19, 67, 91, 135, 165, 219, 231, 241, 301});
  test_set(40, {87, 167, 195, 203, 213, 285, 293, 299, 389, 437});
  test_set(41, {21, 31, 55, 63, 73, 75, 91, 111, 133, 139});
  test_set(42, {11, 17, 33, 53, 65, 143, 161, 165, 215, 227});
  test_set(43, {57, 67, 117, 175, 255, 267, 291, 309, 319, 369});
  test_set(44, {17, 117, 119, 129, 143, 149, 287, 327, 359, 377});
  test_set(45, {55, 69, 81, 93, 121, 133, 139, 159, 193, 229});
  test_set(46, {21, 57, 63, 77, 167, 197, 237, 287, 305, 311});
  test_set(47, {115, 127, 147, 279, 297, 339, 435, 541, 619, 649});
  test_set(48, {59, 65, 89, 93, 147, 165, 189, 233, 243, 257});
  test_set(49, {81, 111, 123, 139, 181, 201, 213, 265, 283, 339});
  test_set(50, {27, 35, 51, 71, 113, 117, 131, 161, 195, 233});
  test_set(51, {129, 139, 165, 231, 237, 247, 355, 391, 397, 439});
  test_set(52, {47, 143, 173, 183, 197, 209, 269, 285, 335, 395});
  test_set(53, {111, 145, 231, 265, 315, 339, 343, 369, 379, 421});
  test_set(54, {33, 53, 131, 165, 195, 245, 255, 257, 315, 327});
  test_set(55, {55, 67, 99, 127, 147, 169, 171, 199, 207, 267});
  test_set(56, {5, 27, 47, 57, 89, 93, 147, 177, 189, 195});
  test_set(57, {13, 25, 49, 61, 69, 111, 195, 273, 363, 423});
  test_set(58, {27, 57, 63, 137, 141, 147, 161, 203, 213, 251});
  test_set(59, {55, 99, 225, 427, 517, 607, 649, 687, 861, 871});
  test_set(60, {93, 107, 173, 179, 257, 279, 369, 395, 399, 453});
  test_set(61, {1, 31, 45, 229, 259, 283, 339, 391, 403, 465});
  test_set(62, {57, 87, 117, 143, 153, 167, 171, 195, 203, 273});
  test_set(63, {25, 165, 259, 301, 375, 387, 391, 409, 457, 471});
  test_set(64, {59, 83, 95, 179, 189, 257, 279, 323, 353, 363});
}

//#include <chrono>
//#include <random>
//#include <vector>
// TEST(MillerRabinTest, Benchmark) {
//  std::vector<uint_fast64_t> values(50000);
//  std::mt19937 engine(234362);
//  std::uniform_int_distribution<uint_fast64_t> gen_value;
//  for (auto &elem : values)
//    elem = gen_value(engine);
//
//  using namespace std::chrono;
//  auto start = steady_clock::now();
//  size_t checksum = 0;
//  for (const auto x : values)
//    checksum += miller_rabin_primality_test(x);
//  auto end = steady_clock::now();
//  auto elapsed = duration_cast<milliseconds>(end - start);
//  std::cout << "Elapsed time: " << elapsed.count() << " ms\n";
//  std::cout << "Checksum: " << checksum << '\n';
//}
