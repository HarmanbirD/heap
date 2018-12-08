//
// Created by Harmanbir Dhillon on 2018-11-30.
//

#pragma once

#include <ostream>
#include <vector>

template<class T>
class heap
{
    public:

        explicit heap(std::vector<T> sequence)
        {
            heap_vec = {};

            for (int i = 0; i < static_cast<int>(sequence.size()); ++i)
            {
                heap_vec.push_back(sequence[i]);
            }

            heapify();
        }

        // push heap
        void push(T element)
        {
            heap_vec.push_back(element);
            heapify();
        }

        // pop heap
        T pop()
        {
            T temp = heap_vec[0];

            heap_vec.erase(heap_vec.begin());

            heapify();

            return temp;
        }

        // returns size of heap
        int size()
        {
            return static_cast<int>(heap_vec.size());
        }

        // returns true if heap empty
        bool is_empty()
        {
            return heap_vec.empty();
        }

        // deletes heap elements
        void clear()
        {
            heap_vec.clear();
        }

        friend std::ostream & operator<<(std::ostream & os, const heap & h)
        {
            for (int i = 0; i < static_cast<int>(h.heap_vec.size()); ++i)
            {
                os << i << ": " << h.heap_vec[i] << std::endl;
            }
            return os;
        }

    private:

        std::vector<T>  heap_vec;

        // used to heapify
        void heapify_down(int i)
        {
            int largest = i;
            int l       = left(i);
            int r       = right(i);

            if (l < size() && heap_vec[l] > heap_vec[i])
            {
                largest = l;
            }

            if (r < size() && heap_vec[r] > heap_vec[largest])
            {
                largest = r;
            }

            if (largest != i)
            {
                std::swap(heap_vec[i], heap_vec[largest]);
                heapify_down(largest);
            }
        }

        // heapify algo
        void heapify()
        {
            for (int i = (size() - 1) / 2; i >= 0; --i)
            {
                heapify_down(i);
            }
        }

//        void heapify_up(int i)
//        {
//            if (i && heap_vec[parent(i)] < heap_vec[i])
//            {
//                std::swap(heap_vec[i], heap_vec[parent(i)]);
//                heapify_up(parent(i));
//            }
//        }
//
//        int parent(int i)
//        {
//            return (i - 1) / 2;
//        }

        // returns left node
        int left(int i)
        {
            return (2 * i + 1);
        }

        // returns right node
        int right(int i)
        {
            return(2 * i + 2);
        }
};