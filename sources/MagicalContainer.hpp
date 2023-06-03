#include <vector>
#include <cmath>
const int DEF_CAPACITY = 100;
using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    public:
        MagicalContainer() {}
        MagicalContainer(MagicalContainer &) {}

        class AscendingIterator
        {
        private:
        public:
            AscendingIterator(MagicalContainer &) {}

            int size = 100;
            int &operator*()
            {
                return size;
            }

            bool operator==(const AscendingIterator &otherIter) const
            {
                return false;
            }

            bool operator!=(const AscendingIterator &otherIter) const
            {
                return false;
            }

            bool operator>(const AscendingIterator &otherIter) const
            {
                return false;
            }

            bool operator<(const AscendingIterator &otherIter) const
            {
                return false;
            }

            AscendingIterator &operator++()
            {
                MagicalContainer cont;
                AscendingIterator *oper = new AscendingIterator(cont);
                return *oper;
            }

            AscendingIterator begin()
            {
                MagicalContainer cont;
                return AscendingIterator(cont);
            }

            AscendingIterator end()
            {
                MagicalContainer cont;
                return AscendingIterator(cont);
            }
        };

        class PrimeIterator
        {
        private:
            // std::vector<int> &container;
            // size_t currentIndex;

            // bool isPrime(int number) const
            // {
            //     if (number < 2)
            //         return false;
            //     for (int i = 2; i <= std::sqrt(number); ++i)
            //     {
            //         if (number % i == 0)
            //             return false;
            //     }
            //     return true;
            // }

        public:
            PrimeIterator(MagicalContainer &) {}

            int size = 100;
            int &operator*()
            {
                return size;
            }

            bool operator==(const PrimeIterator &otherIter) const
            {
                return false;
            }

            bool operator!=(const PrimeIterator &otherIter) const
            {
                return false;
            }

            bool operator>(const PrimeIterator &otherIter) const
            {
                return false;
            }

            bool operator<(const PrimeIterator &otherIter) const
            {
                return false;
            }

            PrimeIterator &operator++()
            {
                MagicalContainer cont;
                PrimeIterator *oper = new PrimeIterator(cont);
                return *oper;
            }

            PrimeIterator begin()
            {
                MagicalContainer cont;
                return PrimeIterator(cont);
            }

            PrimeIterator end()
            {
                MagicalContainer cont;
                return PrimeIterator(cont);
            }
        };

        class SideCrossIterator
        {
            // private:
            //     std::vector<int> &container;
            //     size_t forwardIndex;
            //     size_t backwardIndex;

        public:
            SideCrossIterator(MagicalContainer &) {}

            int size = 100;
            int &operator*()
            {
                return size;
            }

            bool operator==(const SideCrossIterator &otherIter) const
            {
                return false;
            }

            bool operator!=(const SideCrossIterator &otherIter) const
            {
                return false;
            }

            bool operator>(const SideCrossIterator &otherIter) const
            {
                return false;
            }

            bool operator<(const SideCrossIterator &otherIter) const
            {
                return false;
            }

            SideCrossIterator &operator++()
            {
                MagicalContainer cont;
                SideCrossIterator *oper = new SideCrossIterator(cont);
                return *oper;
            }

            SideCrossIterator begin()
            {
                MagicalContainer cont;
                return SideCrossIterator(cont);
            }

            SideCrossIterator end()
            {
                MagicalContainer cont;
                return SideCrossIterator(cont);
            }
        };

        int size() const { return DEF_CAPACITY; }

        bool removeElement(int value)
        {
          return true;
        }

        void addElement(int value) { }

        ~MagicalContainer() {}

    private:
        vector<int> container;
    };
}
