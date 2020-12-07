#pragma once

#include "../graph/graph.h"

template<typename K>
class GraphTraversal {

public:
    class Iterator : std::iterator<std::forward_iterator_tag, K> {
        public:
        
            /**
            * Default constructor for Iterator class
            * Sets the traversal pointer to NULL
            */
            Iterator() : traversal(NULL) 
            {
                /*Nothing*/
            }

            /**
            * Two parameters constructor for Iterator class
            *
            * @param traversal The traversal reference passed in
            * @param startingPoint the starting point to traversal
            */
            Iterator(GraphTraversal* traversal, K startingPoint)
                :traversal(traversal), current(startingPoint)
            {
                    //nothing
            }

            /**
            * operator++ for Iterator class
            * @return the current Iterator in the traversal
            */
            Iterator & operator++() 
            {
                if (!traversal->empty()) {
                    current = traversal->pop();			
                    traversal->add(current);
                    current = traversal->peek();
                }	
                return *this;
            }

            /**
            * Iterator access opreator.
            * @return the current Vertex in the GraphTraversal.
            */	
            K operator*() 
            {
                return current;
            }

            /**
            * Iterator inequality operator.
            * 
            * @return if two iterators are not equal.
            */
            bool operator!=(const Iterator& other) 
            {   
                return current != other.current;
            }

        private:
            GraphTraversal<K>* traversal;
            K current;
    };


     /**
     * Public pure virtual begin() function
     * @return an Iterator points to the first element in the Traversal
     */
    virtual Iterator begin() = 0; 

    /**
    * Public pure virtual end() function 
    * @return an Iterator one after the last element in the Traversal
    */
    virtual Iterator end() = 0;

    /**
    * Public pure virtual add() function
    * @param K current vertex to be processed
    */
    virtual void add(K currentVertex) = 0;

    /**
    * Public pure virtual pop() function
    * remove the current vertex to be processed
    * @return the vertex removed
    */
    virtual K pop() = 0;

    /**
    * Public pure virtual peek() function
    * @return a vertex with highest priority to access
    */
    virtual K peek() const = 0;

     /**
    * Public pure virtual empty() function
    * @return if there's more vertex to access
    */
    virtual bool empty() const = 0;

};
