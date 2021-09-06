/*** 
 * @Author: liwei
 * @Date: 2021-09-06 10:36:27
 * @LastEditTime: 2021-09-06 11:30:58
 * @LastEditors: liwei
 * @Description: 
 * @FilePath: \demo\src\common\list.hpp
 */

#ifndef _LIST_H_
#define _LIST_H_

template <typename T>
struct ListNode
{   
    T value;
    ListNode* next;
    ListNode()
    {
        next = NULL;
    }

    ListNode(T val):value(val)
    {
        
    }
};

template <typename T>
class List
{
private:
    ListNode<T>* m_pHead;
    ListNode<T>* m_pTail;
    int m_length;
public:
    List()
    {
        m_pHead = 0;
        m_pTail = 0;
        m_length = 0;
    }

    void push_back(T value)
    {
        if(m_pHead == 0)
        {
            m_pHead = new ListNode<T>(value);
            m_pTail = m_pHead;
        }
        else
        {
            m_pTail->next = new ListNode<T>(value);
            m_pTail = m_pTail->next;
        }
    }

    void print()
    {
        for(ListNode<T> *ptr = m_pHead; ptr != m_pTail->next; ptr = ptr->next)
        {
            std::cout << ptr->value << std::end;
        }
    }


    class iterator
    {
        private:
            ListNode<T> *m_ptr;
        public:
            iterator(ListNode<T> *p = NULL):m_ptr(p)
            {
                
            }

            T operator*() const
            {
                return m_ptr->value;
            }
            
            ListNode<T> *operator->() const 
            {
                return m_ptr;
            }

            iterator& operator++()
            {
                m_ptr = m_ptr->next;
                return *this;
            }

            iterator operator++(int)
            {
                ListNode<T>* tmp = m_ptr;
                m_ptr = m_ptr->next;
                return iterator(tmp);
            }

            bool operator==(const iterator& arg) const 
            {
                return arg.m_ptr == this->m_ptr;
            }

            bool operator!=(const iterator& arg) const 
            {
                return arg.m_ptr != this->m_ptr;
            }

    };

    iterator begin() const 
    {
        return iterator(m_pHead);
    }

    iterator end() const 
    {
        return iterator(m_pTail->next);
    }
};

#endif