#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer - Size")
{
    MagicalContainer container;
    CHECK(container.size() == 0);

    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    CHECK_EQ(container.size(), 3);
}

TEST_CASE("MagicalContainer - Add and Remove Elements")
{
    MagicalContainer container;

    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    CHECK_EQ(container.size(), 3);

    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    CHECK_EQ(container.removeElement(20), true);
    CHECK_EQ(container.size(), 2);
    CHECK_EQ(container.removeElement(40), false);
    CHECK_EQ(container.size(), 2);
}

TEST_CASE("MagicalContainer - AscendingIterator")
{
    MagicalContainer container;

    MagicalContainer::AscendingIterator it(container);
    CHECK(it == it.end());

    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    int expectedValue = 2;

    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValue++);
        ++it;
    }
}

TEST_CASE("MagicalContainer - SideCrossIterator")
{
    MagicalContainer container;

    MagicalContainer::SideCrossIterator it(container);
    CHECK(it == it.end());

    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    std::vector<int> expectedValues = {5, 8, 2};

    size_t i = 0;

    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}

TEST_CASE("MagicalContainer - PrimeIterator")
{
    MagicalContainer container;

    MagicalContainer::PrimeIterator it(container);
    CHECK(it == it.end());

    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    std::vector<int> expectedValues = {2, 5};

    size_t i = 0;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}

TEST_CASE("MagicalContainer - Mixed Iterators")
{
    MagicalContainer container;

    container.addElement(5);
    container.addElement(2);
    container.addElement(8);
    container.addElement(7);

    std::vector<int> expectedAscending = {2, 5, 7, 8};
    std::vector<int> expectedSideCross = {5, 8, 2, 7};
    std::vector<int> expectedPrime = {2, 5, 7};

    // AscendingIterator
    size_t i = 0;
    MagicalContainer::AscendingIterator it1(container);
    while (it1 != it1.end())
    {
        CHECK_EQ(*it1, expectedAscending[i++]);
        ++it1;
    }

    // SideCrossIterator
    i = 0;
    MagicalContainer::SideCrossIterator it2(container);
    while (it2 != it2.end())
    {
        CHECK_EQ(*it2, expectedSideCross[i++]);
        ++it2;
    }

    // PrimeIterator
    i = 0;
    MagicalContainer::PrimeIterator it3(container);
    while (it3 != it3.end())
    {
        CHECK_EQ(*it3, expectedPrime[i++]);
        ++it3;
    }
}


TEST_CASE("MagicalContainer - AscendingIterator - Single Element")
{
    MagicalContainer container;
    container.addElement(10);

    MagicalContainer::AscendingIterator it(container);

    CHECK_EQ(*it, 10);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("MagicalContainer - SideCrossIterator - Single Element")
{
    MagicalContainer container;
    container.addElement(10);

    MagicalContainer::SideCrossIterator it(container);

    CHECK_EQ(*it, 10);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("MagicalContainer - PrimeIterator - Single Element")
{
    MagicalContainer container;
    container.addElement(10);

    MagicalContainer::PrimeIterator it(container);

    CHECK_EQ(*it, 10);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("MagicalContainer - AscendingIterator - Repeated Elements")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(10);
    container.addElement(10);

    MagicalContainer::AscendingIterator it(container);

    CHECK_EQ(*it, 10);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("MagicalContainer - SideCrossIterator - Repeated Elements")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(10);
    container.addElement(10);

    MagicalContainer::SideCrossIterator it(container);

    CHECK_EQ(*it, 10);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("MagicalContainer - PrimeIterator - Repeated Elements")
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(10);
    container.addElement(10);

    MagicalContainer::PrimeIterator it(container);

    CHECK_EQ(*it, 10);
    ++it;
    CHECK(it == it.end());
}

TEST_CASE("MagicalContainer - AscendingIterator - Add After Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    MagicalContainer::AscendingIterator it(container);

    container.addElement(10);

    int expectedValue = 2;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValue++);
        ++it;
    }
}


TEST_CASE("MagicalContainer - PrimeIterator - Add After Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    MagicalContainer::PrimeIterator it(container);

    container.addElement(10);

    std::vector<int> expectedValues = {2, 5};

    size_t i = 0;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}

TEST_CASE("MagicalContainer - AscendingIterator - Remove Before Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    container.removeElement(2);

    MagicalContainer::AscendingIterator it(container);

    int expectedValue = 5;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValue++);
        ++it;
    }
}

TEST_CASE("MagicalContainer - SideCrossIterator - Remove Before Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    container.removeElement(2);

    MagicalContainer::SideCrossIterator it(container);

    std::vector<int> expectedValues = {5, 8};

    size_t i = 0;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}

TEST_CASE("MagicalContainer - PrimeIterator - Remove Before Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    container.removeElement(2);

    MagicalContainer::PrimeIterator it(container);

    std::vector<int> expectedValues = {5};

    size_t i = 0;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}


TEST_CASE("MagicalContainer - SideCrossIterator - Remove After Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    MagicalContainer::SideCrossIterator it(container);

    container.removeElement(2);

    std::vector<int> expectedValues = {5, 8};

    size_t i = 0;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}

TEST_CASE("MagicalContainer - PrimeIterator - Remove After Iterator Creation")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    MagicalContainer::PrimeIterator it(container);

    container.removeElement(2);

    std::vector<int> expectedValues = {5};

    size_t i = 0;
    while (it != it.end())
    {
        CHECK_EQ(*it, expectedValues[i++]);
        ++it;
    }
}

TEST_CASE("MagicalContainer - AscendingIterator - Multiple Iterators")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    MagicalContainer::AscendingIterator it1(container);
    MagicalContainer::AscendingIterator it2(container);

    CHECK_EQ(*it1, 2);
    CHECK_EQ(*it2, 2);

    ++it1;

    CHECK_EQ(*it1, 5);
    CHECK_EQ(*it2, 5);

    ++it2;

    CHECK_EQ(*it1, 8);
    CHECK_EQ(*it2, 8);

    ++it1;
    ++it2;

    CHECK(it1 == it1.end());
    CHECK(it2 == it2.end());
}
