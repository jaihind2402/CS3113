/**
 * @file ListNode.h
 * @author Steve Gilland (steven.gilland@gmail.com)
 * @brief Implementation of a ListNode object
 * @version 0.1
 * @date 2022-01-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <iostream>

template <typename T>
class ListNode {
 public:
  /**
   * @brief Construct a new List Node object
   * 
   * @param payload 
   */
  ListNode(T payload) : payload{payload}, next{nullptr} {}
  
  /**
   * @brief Remove default constructor
   * 
   */
  ListNode() = delete;

  /**
   * @brief Set the Next object
   * 
   * @param newNext 
   */
  void setNext(ListNode *newNext) { next = newNext; }
  
  /**
   * @brief Get the Next object
   * 
   * @return ListNode* 
   */
  ListNode *getNext() { return next; }
  
  /**
   * @brief Print payload of Node object.
   * 
   * @param strm 
   * @return std::ostream& 
   */
  std::ostream &print(std::ostream &strm) const { return strm << payload; }
  
  /**
   * @brief Get the Payload object
   * 
   * @return const T& 
   */
  const T &getPayload() { return payload; }

 private:
  const T payload;
  ListNode *next;
};

/**
 * @brief 
 * 
 * @tparam T 
 * @param strm 
 * @param node 
 * @return std::ostream& 
 */
template <typename T>
std::ostream &operator<<(std::ostream &strm, const ListNode<T> &node) {
  return node.print(strm);
}

#endif