#include <fstream>
#include <iostream>

#include "config.hpp"
#include "dataItem.hpp"

ZeroMBQConfig::ZeroMBQConfig( )
{

}

bool ZeroMBQConfig::parseConfig( string filePath )
{
    Json::Value root;
    Json::Reader reader;

    ifstream file( filePath );
    file >> root;

    parseSlaveConfig( root[ "slaves" ] );

    return true;
}

void ZeroMBQConfig::parseSlaveConfig( const Json::Value slaves )
{
    for ( unsigned int slaveIndex = 0; slaveIndex < slaves.size(); slaveIndex++ )
    {
        ZeroMBQSlave currSlave( slaves[ slaveIndex ][ "deviceID" ].asUInt( ) );
        Json::Value currSlaveData = slaves[ slaveIndex ];
        for ( unsigned int dataIndex = 0; dataIndex < currSlaveData[ "data" ].size(); dataIndex++ )
        {
            Json::Value currData = currSlaveData[ "data" ][ dataIndex ];

            currSlave.AddDataItem( currData[ "tag" ].asString( ), 
                new ZeroMBQDataItem( currData[ "address" ].asUInt( ), currData[ "order" ].asString( ), currData[ "tag" ].asString( ), currData[ "type" ].asString( ) ) );
        }

        m_slaveList[ currSlave.GetDeviceID( ) ] = currSlave;
    }
}

ZeroMBQSlave* ZeroMBQConfig::getSlave( uint16_t deviceID )
{
    if( m_slaveList.find( deviceID ) != m_slaveList.end( ) )
    {
        return nullptr;
    }
    else
    {
        return &( m_slaveList[ deviceID ] );
    }
    
}