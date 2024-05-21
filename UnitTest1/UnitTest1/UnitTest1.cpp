#include "pch.h"
#include "CppUnitTest.h"
#include "main-project/book_subscription.h"
#include "main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestProcess)
        {
            int result = process();
            Assert::AreNotEqual(0, result, L"Process function should not return 0 by default.");
        }
    };
}
