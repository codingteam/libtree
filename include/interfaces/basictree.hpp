#include <type_traits>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>

#include "iterator.hpp"

namespace treecxx {

/**
 * @brief 
 * 
 * @tparam  T [description]
 * @tparam Allocator = std::T >  [description]
 */
template< typename T, typename Allocator = std::allocator< T > >
class tree_node {

    typedef T                                        data_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;

    using node_pointer = std::weak_ptr< tree_node< data_type, allocator_type > >;

public:
    tree_node()
        : m_parent( nullptr )
    {

    }

    tree_node( const tree_node< data_type >& other )
        : m_data  ( other )
        , m_parent( other.m_parent )
    {

    }

    tree_node( tree_node< data_type >&& other )
        : m_data ( std::move( other ) )
        , m_paret(  )
    {
        
    }

    virtual ~tree_node() 
    {

    }

    /**
     * @brief Clears all child nodes.
     * 
     */
    virtual void clear() = 0;

    /**
     * @brief Returns a reference to the data.
     * 
     * @return Data reference.
     */
    reference data() noexcept
    {
        return m_data;
    }

    /**
     * @brief Returns a constant reference to the data.
     * 
     * @return Data constant reference.
     */
    const_reference data() const noexcept
    {
        return m_data;
    }


protected:

    data_type    m_data;
    node_pointer m_parent;

};

/**
 * @brief Base tree collection class.
 * 
 * @tparam  T Data type.
 * @tparam Allocator Allocator type
 */
template< typename T, typename Allocator = std::allocator< T > >
class basic_tree {

    typedef T                                        data_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef basic_tree_iterator< data_type >         iterator;
    typedef basic_tree_iterator< data_type >         const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef std::reverse_iterator< iterator >        reverse_iterator;
    typedef std::reverse_iterator< const_iterator >  const_reverse_iterator;

public:

    basic_tree() noexcept ( std::is_nothrow_default_constructible< allocator_type >::value )
    { 
        // empty
    }    

    explicit basic_tree( const allocator_type& )
    {

    }

    virtual ~basic_tree() 
    {
        // empty 
    }

    /**
     * @brief Adds a new element at the end of the tree, after its current last element. 
     *  The content of val is copied (or moved) to the new element.
     * 
     * @param[in] data Value to be copied (or moved) to the new element.
     */
    virtual void push( const data_type& data ) = 0;

    /**
     * @brief Adds a new element at the end of the tree, after its current last element. 
     *  The content of val is copied (or moved) to the new element.
     * 
     * @param[in] data Value to be copied (or moved) to the new element.
     */
    virtual void push( data_type&& data ) = 0;

    /**
     * @brief Removes from the tree either a single element (itr).
     * 
     * @param[it] itr Iterator pointing to a single element to be removed from the tree. 
     */
    virtual void erase( iterator itr ) = 0;


    /**
     * @brief Removes from the tree either a single element (itr).
     * 
     * @param[it] itr Iterator pointing to a single element to be removed from the tree. 
     */
    virtual void erase( const_iterator itr ) = 0;

    /**
     * @brief Clears the tree.
     * 
     */
    void clear()
    {
        m_root->clear();
    }

    /**
     * @brief Alocates the memory.
     * 
     * @param[in] e Number of elements.
     */
    virtual void reserve( size_type  ) = 0;

    /**
     * @brief Calculates the height of the tree.
     * 
     * @return The height of the tree.
     */
    const size_type height() const
    {
        return {}; // dummy
    }

    /**
     * @brief Checks if the tree is empty.
     * 
     *  The tree is not empty if even the root is not null.
     * 
     * @return
     */
    const bool empty() const
    {
        return !m_root;
    }

    /**
     * @brief Returns a reference to the data.
     * 
     * @return Data reference.
     */
    reference data()
    {
        return m_root->data();
    }

    /**
     * @brief Returns a constant reference to the data.
     * 
     * @return Data constant reference.
     */
    const_reference data() const
    {
        return m_root->data();
    }

protected:

    std::unique_ptr< tree_node< data_type, allocator_type > > m_root;

};

} // treecxx