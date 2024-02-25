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
            Bankomat atm(12345, 50, 1000);
            atm.loadMoney(500, 10);
            atm.loadMoney(200, 20); 


            bool result = atm.withdrawMoney(700);
            Assert::IsTrue(result);

            result = atm.withdrawMoney(600);
            Assert::IsFalse(result);
        }
    };
}