#ifndef DATAITEM_HPP__
#define DATAITEM_HPP__

using namespace std;

#include <string>

#include "data.hpp"

class ZeroMBQDataItem
{
    public:
        ZeroMBQDataItem( int, string, string, string );

        uint16_t getAddress( ) const;
        string getTag( ) const;
        DATA_TYPE getType( ) const;
        ConvertFromZMQFunc getConvertFunc( ) const;

    private:
        uint16_t m_address;
        string m_tag;
        DATA_TYPE m_type;
        ConvertFromZMQFunc m_convertFunc;
};

#endif