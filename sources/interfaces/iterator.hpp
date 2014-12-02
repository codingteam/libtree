#include <type_traits>
#include <iterator>
#include <stdexcept>
#include <utility>

/**
 * @brief Interface for every iterator types.
 * 
 */
template< typename T >
class basic_tree_iterator : public std::iterator< std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T& > {
    typedef T data_type;
public:

    basic_tree_iterator( data_type* ptr = nullptr )
    {
        m_ptr = ptr;
    }

    basic_tree_iterator( const basic_tree_iterator< data_type >& iter ) = default;

    ~basic_tree_iterator()
    {

    }

    basic_tree_iterator< data_type >& operator = ( const basic_tree_iterator< data_type >& iter ) = default;

    basic_tree_iterator< data_type >& operator = (       data_type*                  ptr )
    {
        m_ptr = ptr;
        return ( *this );
    }

    operator bool() const noexcept
    {
        return m_ptr;
    }

    bool operator == ( const basic_tree_iterator< data_type >& iter ) const noexcept
    {
        return ( m_ptr == iter.get_const_ptr() );
    }

    bool operator != ( const basic_tree_iterator< data_type >& iter ) const noexcept
    {
        return ( m_ptr != iter.get_const_ptr() );
    }


    virtual basic_tree_iterator< data_type >& operator += ( const std::ptrdiff_t& movement ) = 0;

    virtual basic_tree_iterator< data_type >& operator -= ( const std::ptrdiff_t& movement ) = 0;

    virtual basic_tree_iterator< data_type >& operator ++ () = 0;

    virtual basic_tree_iterator< data_type >& operator -- () = 0;

    virtual basic_tree_iterator< data_type > operator ++ ( std::ptrdiff_t ) = 0;

    virtual basic_tree_iterator< data_type > operator -- ( std::ptrdiff_t ) = 0;

    virtual basic_tree_iterator< data_type > operator + ( const std::ptrdiff_t& movement ) = 0;

    virtual basic_tree_iterator< data_type > operator - ( const std::ptrdiff_t& movement ) = 0;


    virtual std::ptrdiff_t    operator - ( const basic_tree_iterator< data_type >& iter ) = 0;
    // {
    //     return std::distance( iter.get_ptr(), this->get_ptr() );
    // }

    data_type& operator * ()
    {
        return *m_ptr;
    }

    const data_type& operator * () const
    {
        return *m_ptr;
    }

    data_type* operator -> ()
    {
        return m_ptr;
    }

    data_type*       get_ptr() const noexcept
    {
        return m_ptr;
    }

    const data_type* get_const_ptr() const noexcept
    {
        return m_ptr;
    }

protected:

    data_type* m_ptr;
};