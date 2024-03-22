#ifndef S21_MATH_TEST_H
#define S21_MATH_TEST_H

#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  for (int x = -1000; x < 1000; x += 100) {
    int abs_res = abs(x);
    int s21_abs_res = s21_abs(x);
    ck_assert_int_eq(abs_res, s21_abs_res);
  }
}
END_TEST

START_TEST(test_acos) {
  for (double x = -1; x <= 1; x += 0.015) {
    long double acos_res = acos(x);
    long double s21_acos_res = s21_acos(x);
    ck_assert_ldouble_eq_tol(acos_res, s21_acos_res, 1e-6);
  }
  ck_assert_ldouble_nan(s21_acos(-1.1));
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq(s21_acos(1), +0);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);

  ck_assert_ldouble_nan(acos(-1.1));
  ck_assert_ldouble_nan(acos(1.1));
  ck_assert_ldouble_eq(acos(1), +0);
}
END_TEST

START_TEST(test_asin) {
  for (double x = -1.0; x <= 1; x += 0.015) {
    long double asin_res = asin(x);
    long double s21_asin_res = s21_asin(x);
    ck_assert_ldouble_eq_tol(asin_res, s21_asin_res, 1e-6);
  }
  ck_assert_ldouble_nan(s21_asin(-1.1));
  ck_assert_ldouble_nan(s21_asin(1.1));
  ck_assert_ldouble_eq(s21_asin(0), +0);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);

  ck_assert_ldouble_nan(asin(-1.1));
  ck_assert_ldouble_nan(asin(1.1));
  ck_assert_ldouble_eq(asin(0), +0);
}
END_TEST
#endif
