/*
 * Copyright (c) 2018, Michael Feathers, James Grenning, Bas Vodde
                       and Paul Bussmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef INC_MS_CPP_UNITTEST_WITH_CPPUTEST

#include "CppUnitTest.h"

/* pre-define CppUTest macros */
#define FAIL(message)\
    { Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail(L""#message); }

#include "../../CppUTest/TestHarness.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/TestOutput.h"

void CppUnitTestTestMethodInitialize(UtestShell* pShell);

#define INVOKE_CPPUTEST_TEST(testGroup, testName) \
TEST_METHOD(##testGroup##_##testName##) {\
    TEST_##testGroup##_##testName##_Test oTest; \
	oTest.run(); /* includes setup(), teardown() */ \
}

#undef TEST
#define TEST(testGroup, testName) \
  /* External declarations for strict compilers */ \
  class TEST_##testGroup##_##testName##_TestShell; \
  extern TEST_##testGroup##_##testName##_TestShell TEST_##testGroup##_##testName##_TestShell_instance; \
  \
  class TEST_##testGroup##_##testName##_Test : public TEST_GROUP_##CppUTestGroup##testGroup \
{ public: TEST_##testGroup##_##testName##_Test () : TEST_GROUP_##CppUTestGroup##testGroup () {} \
       void testBody(); }; \
  class TEST_##testGroup##_##testName##_TestShell : public UtestShell { \
      virtual Utest* createTest() _override { return new TEST_##testGroup##_##testName##_Test; } \
  } TEST_##testGroup##_##testName##_TestShell_instance; \
  TEST_CLASS(TEST_CLASS_##testGroup##_##testName##) { public:\
    TEST_METHOD_INITIALIZE(TestInitialize) {CppUnitTestTestMethodInitialize(&TEST_##testGroup##_##testName##_TestShell_instance);}\
    INVOKE_CPPUTEST_TEST(##testGroup##,##testName##); \
  }; \
  static TestInstaller TEST_##testGroup##_##testName##_Installer(TEST_##testGroup##_##testName##_TestShell_instance, #testGroup, #testName, __FILE__,__LINE__); \
    void TEST_##testGroup##_##testName##_Test::testBody()

/* CppUTest / VsCppUnit extension */
#undef  CHECK_TRUE_LOCATION
#define CHECK_TRUE_LOCATION(condition, checkString, conditionString, text, file, line)\
    { if (!(condition))Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail(L""#checkString #conditionString); }

#undef  CHECK
#define CHECK(condition)\
  CHECK_TRUE_LOCATION(condition, "CHECK", #condition, NULL, __FILE__, __LINE__)

#undef CHECK_LOCATION_TEXT
#define CHECK_LOCATION_TEXT(condition, checkString, conditionString, text, file, line) \
    { CHECK_TRUE_LOCATION(condition, checkString, conditionString, text, file, line) }

#undef  CHECK_EQUAL_LOCATION
#define CHECK_EQUAL_LOCATION(expected,actual,file,line)\
	CHECK_LOCATION_TEXT(((expected) == (actual)), #expected " == ", #actual, NULL, file, line)

#undef  CHECK_EQUAL
#define CHECK_EQUAL(expected, actual)\
  CHECK_EQUAL_LOCATION(expected, actual, __FILE__, __LINE__)

#undef  LONGS_EQUAL
#define LONGS_EQUAL(expected, actual)\
  CHECK_EQUAL_LOCATION(expected, actual, __FILE__, __LINE__)

#undef MEMCMP_EQUAL_LOCATION
#define MEMCMP_EQUAL_LOCATION(expected,actual,size,fileName,lineNumber)\
  { UtestShell::getCurrent()->assertBinaryEqual(expected, actual, size, NULL, fileName, lineNumber, TestTerminatorWithoutExceptions()); }

#undef MEMCMP_EQUAL
#define MEMCMP_EQUAL(expected,actual,size) MEMCMP_EQUAL_LOCATION((expected),(actual),(size),(__FILE__),(__LINE__))

#endif /* INC_MS_CPP_UNITTEST_WITH_CPPUTEST */
