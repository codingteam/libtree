#include <type_traits>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>

#include "interfaces/iterator.hpp"
#include "interfaces/basictree.hpp"


namespace treecxx {

/**
 * @brief 
 * 
 * @tparam T Data type.
 * @tparam Allocator Custom allocator.
 */
template< typename T, typename Allocator = std::allocator< T > >
class binary_node : public tree_node< T, Allocator > {
public:
    binary_node()
    {
        // empty
    }

    ~binary_node()
    {

    }

private:

    node_pointer m_left;
    node_pointer m_right;

};

/**
 * @brief Simple binary treee implementation.
 * 
 * @tparam T Data type.
 * @tparam Allocator Custom allocator.
 */
template< typename T, typename Allocator = std::allocator< T > >
class binary_tree : public basic_tree< T, Allocator > {
public:
    binary_tree()
    {
        // empty
    }

    ~binary_tree()
    {

    }

};

} // treecxx