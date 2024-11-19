#ifndef BTREE_HPP
#define BTREE_HPP

namespace btree{
    template<typename T>
        void shiftRight(T* arr, int i, int & size){
            for(int idx = size - 1; idx >= i; idx--){
                arr[idx + 1] = arr[idx];
            }
            size++;
        }
    
    template<typename T>
        void shiftLeft(T* arr, int i, int & size){
            for(; i < size-1; i++){
                arr[i + 1] = arr[i+1];
            }
            size--;
        }

    template <typename T>
        class node{
        public:
            node<T>** children; // array of child pointers
            T** data;           // array of data (has key)

            int m;              // tree degree
            int divisor;        // index of divisor when split
            int n;              // current number of keys
            int min;            // min n of keys = ceil(m / 2) - 1

            bool leaf;          // true if no children
            node(int m, bool leaf = true);
            
            node<T>* split(T*& upshiftElement);
            
            node<T>* insert(T* element, T*& upshiftElement);

            T*& search(int key);

            void traverse(void(itemViewer)(T data));

            void clear();

        };

   template <typename T>
       class BTree{
            public:
                int m;          // degree of tree

                node<T>* root;  // root node of tree

                BTree(int m);

                void traverse(void(itemViewer)(T data));
                void insert(std::vector<T*> elements);
                void insert(T* element);
                
                T* & operator[](int key);
       };
}

#endif
