/**
 * @file deque.cpp
 * @description Implementations for PA2, Deque class
 * @author (your CWLs)
**/

template <class T>
Deque<T>::Deque() {
    this->n1 = 0;
    this->n2 = 0;
    /* YOUR CODE HERE! */

}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
**/
template <class T>
void Deque<T>::PushR(T newItem) {
    this->data.push_back(newItem);
    n2++; 
    /* YOUR CODE HERE! */

}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The item that used to be at the left of the Deque.
**/
template <class T>
T Deque<T>::PopL() {
    /* YOUR CODE HERE! */
    T removed;
    removed = data[n1];
    n1++; 
    n2--;
    //smart way of halving it 
    if (n2 <= n1) {
        vector<T> newData;
        newData.reserve(n2);
        for (int i = 0; i < n2; i++){
            newData.push_back(data[n1+i]);
        }
        data = newData; 
        n1 = 0; 

    }

    return removed;
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The item that used to be at the right of the Deque.
**/
template <class T>
T Deque<T>::PopR() {

    T removed = data[n1 + n2 - 1];
    n2--;

    if (n2 <= n1) {
        vector<T> newData;
        newData.reserve(n2);
        for (int i = 0; i < n2; i++) {
            newData.push_back(data[n1 + i]);
        }
        data = newData;
        n1 = 0;
    }

    return removed;
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike PopL(), this operation does not alter the deque.
 *
 * @return The item at the front of the deque.
**/
template <class T>
T Deque<T>::PeekL() {
    /* YOUR CODE HERE! */
    return data[n1];
}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike PopR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
**/
template <class T>
T Deque<T>::PeekR() {
    /* YOUR CODE HERE! */
    return data[n1 + n2 -1];
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
**/


template <class T>
bool Deque<T>::IsEmpty() const {
    /* REPLACE THE LINE BELOW WITH YOUR CODE */
    return n2 == 0;
}
