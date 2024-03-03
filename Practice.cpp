#include <iostream>

#include "BFSGraphMatrix.h"
#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include "BTBFS.h"
#include "BTInOrder.h"
#include "BTPostOrder.h"
#include "BTPreOrder.h"
#include "BubbleSort.h"
#include "CompareBinaryTree.h"
#include "DijkstraList.h"
#include "LinkedList.h"
#include "LRU.h"
#include "MazeSolver.h"
#include "MergeSort.h"
#include "MinHeap.h"
#include "Queue.h"
#include "QuickSort.h"
#include "Stack.h"
#include "TwoCrystalBalls.h"
#include "Vector.h"

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* m_MemoryBlock = nullptr;

    Vector3() { m_MemoryBlock = new int[5]; }

    Vector3(float scalar)
        : x(scalar), y(scalar), z(scalar)
    {
        m_MemoryBlock = new int[5];
    }

    Vector3(float x, float y, float z)
        : x(x), y(y), z(z)
    {
        m_MemoryBlock = new int[5];
    }

    Vector3(const Vector3& other) = delete;

    Vector3(Vector3&& other) noexcept
        : x(other.x), y(other.y), z(other.z)
    {
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        std::cout << "MOVE CONSTRUCTOR\n";
    }

    ~Vector3()
    {
        std::cout << "DESTROY\n";
        delete[] m_MemoryBlock;
    }

    Vector3& operator=(const Vector3& other) = delete;

    Vector3& operator=(Vector3&& other) noexcept
    {
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        std::cout << "MOVE\n";
        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }
};

template <typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }

    std::cout << "---------------------------------\n";
}

template <typename T>
void PrintVector(const std::vector<T>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }

    std::cout << "\n---------------------------------\n";
}

template <>
void PrintVector(const Vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    }

    std::cout << "---------------------------------\n";
}

int main(int argc, char* argv[])
{
    // {
    //     Vector<Vector3> vector;
    //     vector.EmplaceBack(1.0f);
    //     vector.EmplaceBack(2, 3, 4);
    //     vector.EmplaceBack(2, 3, 4);
    //     PrintVector(vector);
    //     vector.Clear();
    //     PrintVector(vector);
    // }

    // std::vector<int> array = {5, 4, 3, 2, 1, 0};
    // PrintVector(array);
    // BubbleSort::BubbleSortList(array);
    // PrintVector(array);

    // LinkedList<int> list = LinkedList<int>(0);
    // list.prepend(1);
    // LinkedList<int> other = LinkedList<int>(2);
    // other.prepend(3);

    // list = other;
    // list.inserAt(0, 1);
    // list.append(2);
    // list.prepend(3);
    // list.prepend(4);
    // list.prepend(5);
    // list.remove(5);
    // list.removeAt(4);

    // Queue<int> queue = Queue<int>();
    // queue.enqueue(2);
    // queue.enqueue(3);
    // queue.enqueue(4);
    // std::cout << queue.dequeue() << std::endl;
    // std::cout << queue.peek() << std::endl;

    // Stack<int> stack = Stack<int>();
    // stack.push(1);
    // stack.push(2);
    // stack.push(3);
    // stack.push(4);
    // stack.push(5);
    //
    // while(stack.peek())
    // {
    //     std::cout << stack.pop() << std::endl;
    // }
    //
    // stack.pop();

    // const std::vector<std::string> maze = {
    //     "xxxxxxxxxx x",
    //     "x        x x",
    //     "x        x x",
    //     "x xxxxxxxx x",
    //     "x          x",
    //     "x xxxxxxxxxx",
    // };
    //
    // auto path = MazeSolver::solve(maze, 'x', { 10, 0 }, { 1, 5 });

    // int arr[7] = {9, 3, 7, 4, 69, 420, 42};
    // std::vector<int> array{9, 3, 7, 4, 69, 420, 42};
    // QuickSort::sort<int>(arr, 7);
    // MergeSort::sort(array);

    // BinaryNode<int> A(20);
    // BinaryNode<int> B(10);
    // BinaryNode<int> C(5);
    // BinaryNode<int> D(7);
    // BinaryNode<int> E(15);
    // BinaryNode<int> F(50);
    // BinaryNode<int> G(30);
    // BinaryNode<int> H(29);
    // BinaryNode<int> I(45);
    // BinaryNode<int> J(100);

    // A.left = &B;
    // B.left = &C;
    // C.right = &D;
    //
    // B.right = &E;
    // A.right = &F;
    //
    // F.left = &G;
    // G.left = &H;
    //
    // G.right = &I;
    // F.right = &J;


    // const auto path = BTPostOrder::order(&A);
    //
    // for(const int num: path)
    // {
    //     std::cout << num << " ";
    // }

    // std::cout << (BTBFS::bfs(&A, 45) ? "true" : "false") << std::endl;
    // std::cout << (BTBFS::bfs(&A, 7) ? "true" : "false") << std::endl;
    // std::cout << (BTBFS::bfs(&A, 69) ? "true" : "false") << std::endl;


    // A.left = &B;
    // B.left = &C;
    // C.right = &D;
    //
    // F.value = 20;
    // G.value = 10;
    // H.value = 5;
    // I.value = 7;
    //
    // F.left = &G;
    // G.left = &H;
    // H.right = &I;
    // I.left = &A;
    // A.right = &F;

    // std::cout << ( CompareBinaryTree::compare(&A, &F) ? "true" : "false") << std::endl;

    // BinaryNode<int> root = BinaryNode<int>(15);
    //
    // BinarySearchTree<int> BST;
    // BST.insert(&root, 51);
    // BST.insert(&root, 7);
    // BST.insert(&root, 4);
    // BST.insert(&root, 25);
    // BST.insert(&root, 60);
    // BST.insert(&root, 37);
    // BST.insert(&root, 32);
    //
    // std::cout << ( BST.find(&root, 51) ? "true" : "false") << std::endl;
    //
    // BST.del(&root, 51);
    //
    // std::cout << ( BST.find(&root, 51) ? "true" : "false") << std::endl;

    // MinHeap<int> heap = MinHeap<int>();
    //
    // heap.insert(5);
    // heap.insert(3);
    // heap.insert(69);
    // heap.insert(420);
    // heap.insert(4);
    // heap.insert(1);
    // heap.insert(8);
    // heap.insert(7);
    //
    //
    // std::cout << (heap.length() == 8) << '\n';
    // std::cout << (heap.del() == 1) << '\n';
    // std::cout << (heap.del() == 3) << '\n';
    // std::cout << (heap.del() == 4) << '\n';
    // std::cout << (heap.del() == 5) << '\n';
    // std::cout << (heap.length() == 4) << '\n';
    // std::cout << (heap.del() == 7) << '\n';
    // std::cout << (heap.del() == 8) << '\n';
    // std::cout << (heap.del() == 69) << '\n';
    // std::cout << (heap.del() == 420) << '\n';
    // std::cout << (heap.length() == 0) << '\n';

    // std::vector<std::vector<int>> graph = {
    //     {0, 3, 1, 0, 0, 0, 0}, // 0
    //     {0, 0, 0, 0, 1, 0, 0},
    //     {0, 0, 7, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0},
    //     {0, 1, 0, 5, 0, 2, 0},
    //     {0, 0, 18, 0, 0, 0, 1},
    //     {0, 0, 0, 1, 0, 0, 1},
    // };
    //
    // auto path = BFSGraphMatrix::bfs(graph, 0, 6);
    // std::cout << (path == std::vector<int>{0, 1, 4, 5, 6}) << '\n';
    // path = BFSGraphMatrix::bfs(graph, 6, 0);
    // std::cout << !path.empty() << '\n';

    //      (1) --- (4) ---- (5)
    //    /  |       |       /|
    // (0)   | ------|------- |
    //    \  |/      |        |
    //      (2) --- (3) ---- (6)

    // WeightedAdjacencyList array = {
    //     {
    //         {1, 3},
    //         {2, 1}
    //     },
    //     {
    //         {0, 3},
    //         {2, 4},
    //         {4, 1},
    //     },
    //     {
    //         {1, 4},
    //         {3, 7},
    //         {0, 1},
    //     },
    //     {
    //         {2, 7},
    //         {4, 5},
    //         {6, 1},
    //     },
    //     {
    //         {1, 1},
    //         {3, 5},
    //         {5, 2},
    //     },
    //     {
    //         {6, 1},
    //         {4, 2},
    //         {2, 18},
    //     },
    //     {
    //         {3, 1},
    //         {5, 1},
    //     }
    // };
    //
    // auto path = DijkstraList::shortestPath(0, 6, array);

    auto lru = LRU<std::string, int>(3);

    std::cout << (lru.get("foo") == NULL) << '\n';

    lru.update("foo", 69);

    std::cout << (lru.get("foo") == 69) << '\n';

    lru.update("bar", 420);

    std::cout << (lru.get("bar") == 420) << '\n';

    lru.update("baz", 1337);

    std::cout << (lru.get("baz") == 1337) << '\n';

    lru.update("ball", 69420);

    std::cout << (lru.get("ball") == 69420) << '\n';
    std::cout << (lru.get("foo") == NULL) << '\n';
    std::cout << (lru.get("bar") == 420) << '\n';

    lru.update("foo", 69);

    std::cout << (lru.get("bar") == 420) << '\n';
    std::cout << (lru.get("foo") == 69) << '\n';

    // shouldn't of been deleted, but since bar was get'd, bar was added to the
    // front of the list, so baz became the end
    std::cout << (lru.get("baz") == NULL) << '\n';

    std::cin.get();
    return 0;
}
