#pragma once
#include "Node.h"
#include "Queue.h"

class BTBFS
{
public:
    template<typename T>
    static bool bfs(const BinaryNode<T>* head, const T& needle)
    {
        Queue<BinaryNode<T>> queue = Queue<BinaryNode<T>>();
        queue.enqueue(*head);

        while (queue.length())
        {
            const BinaryNode<T>& curr = queue.dequeue();

            if(curr.value == needle)
            {
                return true;
            }

            if(curr.left)
            {
                queue.enqueue(*curr.left);
            }

            if(curr.right)
            {
                queue.enqueue(*curr.right);
            }
        }

        return false;
    }
};
