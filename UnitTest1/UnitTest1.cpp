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
        TEST_METHOD(Test_Difference)//Тоніццо Сімоне
        {
            Set<int> e;
            e.add(1);
            e.add(2);

            Set<int> e2;
            e2.add(2);
            e2.add(3);

            Set<int> difference = e.difference(e2);
            Assert::AreEqual(1, difference.getSize());
            Assert::IsTrue(difference.contains(1));
        }
        TEST_METHOD(TestIntersection)//Тоніццо Сімоне
        {
            Set<int> f;
            f.add(1);
            f.add(2);
            Set<int> f2;
            f2.add(2);
            f2.add(3);

            Set<int> intersected = f.intersection(f2);


            Assert::AreEqual(1, intersected.getSize());
            Assert::IsTrue(intersected.contains(2));
        }
        TEST_METHOD(Test_Constructor)//Тоніццо Сімоне
        {
            Set<int> g;

            Assert::AreEqual(0, g.getSize());
        }

      
    };

}
