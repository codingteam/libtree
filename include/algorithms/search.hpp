#include <type_traits>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>

#include "../interfaces/iterator.hpp"
#include "../interfaces/basictree.hpp"

namespace treecxx {

/**
 * @brief Finds 
 * 
 * @param first Initial position in tree sequence.
 * @param last Final position in tree sequence.
 * @param val Value to search for in the tree.
 * @tparam Itr Iterator type.
 * @tparam T Data value type.
 * @return 
 */
template< typename Itr, typename T >
inline Itr search_dfs( Itr first, Itr last, const T& val )
{
    return {};
}

} // treecxx
