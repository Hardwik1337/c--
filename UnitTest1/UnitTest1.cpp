#include "pch.h"
#include "CppUnitTest.h"
#include "set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetTests
{
    TEST_CLASS(SetTest)
    {
    public:

        TEST_METHOD(Test_Add)//Андрій Прядко
        {
            Set<int> a;
            a.add(1);
            Assert::IsTrue(a.contains(1));
            Assert::AreEqual(1, a.getSize());
        }
        TEST_METHOD(Test_Remove)//Андрій Прядко
        {
            Set<int> b;
            b.add(1);
            b.add(2);
            b.add(3);
            b.remove(2);
            Assert::IsTrue(b.contains(1));
            Assert::IsFalse(b.contains(2));
            Assert::IsTrue(b.contains(3));
            Assert::AreEqual(2, b.getSize());
        }
        TEST_METHOD(Test_Clear)//Андрій Прядко
        {
            Set<int> c;
            c.add(1);
            c.clear();
            Assert::AreEqual(0, c.getSize());
            Assert::IsFalse(c.contains(1));
         
        }
        TEST_METHOD(Test_Connect)//Андрій Прядко
        {
            Set<int> d;
            d.add(1);
            Set<int> d2;
            d2.add(2);
            Set<int> connected = d.connectSet(d2);
            Assert::AreEqual(2, connected.getSize());
            Assert::IsTrue(connected.contains(1));
            Assert::IsTrue(connected.contains(2));
        }

      
    };

}
