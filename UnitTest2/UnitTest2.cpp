#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/ADMIN/source/repos/HW3/HW3/HashTable2D.h"
#include "/Users/ADMIN/source/repos/HW3/HW3/HashTable2D.cpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(TestInsert)
        {
            HashTable2D ht(100);
            int spotsChecked = ht.insert(10);
            Assert::AreEqual(1, spotsChecked, L"Insert should check 1 spot when no collision.");
        }

        TEST_METHOD(TestInsertCollision)
        {
            HashTable2D ht(100);
            ht.insert(10);
            int spotsChecked = ht.insert(510);
            Assert::AreEqual(2, spotsChecked, L"Insert should check 2 spots due to collision.");
        }

        TEST_METHOD(TestInsertFull)
        {
            std::string expected = "The value 1 cannot be inserted.\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            HashTable2D ht(100, 5);
            for (int i = 1; i <= 500; i++) {
                ht.insert(i);
            }
            ht.insert(1);

            std::cout.rdbuf(sbuf);

            Assert::AreEqual(expected, buffer.str(), L"Insert should return a statement when it's full");
        }

        TEST_METHOD(TestSearchFound)
        {
            std::string expected = "The value 10 can be found.\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            HashTable2D ht(100);
            ht.insert(10);
            ht.search(10);

            std::cout.rdbuf(sbuf);

            Assert::AreEqual(expected, buffer.str(), L"Value should be found.");
        }

        TEST_METHOD(TestSearchNotFound)
        {
            std::string expected = "The value 10 cannot be found.\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            HashTable2D ht(100);
            ht.search(10);

            std::cout.rdbuf(sbuf);

            Assert::AreEqual(expected, buffer.str(), L"Value should not be found or there should be a message outputted.");
        }

        TEST_METHOD(TestRemove)
        {
            std::string expected = "The value 10 was removed.\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            HashTable2D ht(100);
            ht.insert(10);
            ht.remove(10);

            std::cout.rdbuf(sbuf);

            Assert::AreEqual(expected, buffer.str(), L"Value should be removed.");
        }

        TEST_METHOD(TestRemoveNotFound)
        {
            std::string expected = "The value 10 cannot be removed.\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());

            HashTable2D ht(100);
            ht.remove(10);

            std::cout.rdbuf(sbuf);

            Assert::AreEqual(expected, buffer.str(), L"Value cannot be removed or there should be a message outputted.");
        }
    };
}
