#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP Lab 1.2/OOP Lab 1.2.cpp"
#include "../OOP Lab 1.2/Bankomat.cpp"
#include "../OOP Lab 1.2/Bankomat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankomatTest
{
    TEST_CLASS(BankomatTest)
    {
    public:
        TEST_METHOD(TestWithdrawMoney)
        {
            int x = 5000;
            Bankomat atm;
            atm.loadMoney(500, 10);
            int a = atm.getCurrentMoney();
            
            Assert::AreEqual(a, x);
        }
    };
}