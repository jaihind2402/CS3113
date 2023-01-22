/**
 * @file LinkedList.h
 * @author JaihindReddy Vangala
 * @student id : 50717440
 * @brief Implementation of a Linked List Container
 *
 * @date Jan 15th 2023
 *
 *
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "ListNode.h"

template <typename T>
class LinkedList
{
public:
  /**
   * @brief Destroy the Linked List object
   *
   */
  ~LinkedList() { clearList(); }

  /**
   * @brief Get the Head object
   *
   * @return ListNode<T>
   */
  ListNode<T> getHead() { return head; }
  void add(T payload);
  void remove(T target);

  std::ostream &print(std::ostream &strm) const;

private:
  void clearList();
  ListNode<T> *head = nullptr;
  ListNode<T> *tail = nullptr;
};

/**
 * @brief This function adds a new node to the list at the head
 *
 * @tparam T
 * @param payload
 */
// TODO - FILL IN FUNCTION
template <typename T>
/**
 * Intital add method just to add the numbers from the home work 1 continuation
 void LinkedList<T>::add(T payload)
{
  ListNode<T> *new_node = new ListNode<T>(payload);

  if (head == nullptr)
    tail = new_node;
  new_node->setNext(head);
  head = new_node;
}
*/

void LinkedList<T>::add(T payload) {
    ListNode<T> *new_node = new ListNode<T>(payload);
    ListNode<T> *current = head;
    ListNode<T> *prev = nullptr;

    while (current != nullptr && current->getPayload() < payload) {
        prev = current;
        current = current->getNext();
    }

    if (prev == nullptr) {
        new_node->setNext(head);
        head = new_node;
    } else {
        prev->setNext(new_node);
        new_node->setNext(current);
    }

    if (current == nullptr) {
        tail = new_node;
    }
}



/**
 * @brief This function searches and removes a value from the list
 *
 * @tparam T
 * @param target
 */
// TODO - FILL IN FUNCTION
template <typename T>
void LinkedList<T>::remove(T target)
{
  if (head == nullptr)
    throw std::length_error{"unable to delete"};
  elsez
  {
    ListNode<T> *temp = head;
    while (temp != nullptr && temp->getNext()->getPayload() != target)
    {
      temp = temp->getNext();
    }
    // std::cout << "ele found" << temp->getNext()->getPayload() << std::endl;
    if (temp == nullptr)
      std::cout << "element not found";
    else
    {
      ListNode<T> *deleteEle = temp->getNext();
      temp->setNext(deleteEle->getNext());
      delete deleteEle;
    }
  }
}

/**
 * @brief Deletes all elements in the list
 *
 * @tparam T
 */
template <typename T>
void LinkedList<T>::clearList()
{
  ListNode<T> *current = head;
  while (current != nullptr)
  {
    head = current->getNext();
    delete current;
    current = head;
  }
}

/**
 * @brief Print the entire list as well as the structure
 *
 * @tparam T
 * @param strm
 * @return std::ostream&
 */
template <typename T>
std::ostream &LinkedList<T>::print(std::ostream &strm) const
{
  ListNode<T> *current = head;
  while (current != nullptr)
  {
    strm << *current << " -> ( ";
    current = current->getNext();

    if (current == nullptr)
      strm << "/ )" << std::endl;
    else
      strm << *current << " )" << std::endl;
  }
  return strm;
}

/**
 * @brief Overloaded stream insertion operator
 *
 * @tparam T
 * @param strm
 * @param list
 * @return std::ostream&
 */
template <typename T>
std::ostream &operator<<(std::ostream &strm, const LinkedList<T> &list)
{
  return list.print(strm);
}

#endif