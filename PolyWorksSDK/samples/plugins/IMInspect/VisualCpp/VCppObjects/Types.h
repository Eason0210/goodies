#pragma once

// =================================================================================================
//   Types declaration
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <vector>
#include <string>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

struct PointF
{
    float m_values[ 3 ];

    PointF::PointF()
    {
        m_values[ 0 ] = 0; m_values[ 1 ] = 0; m_values[ 2 ] = 0;
    }
    PointF::PointF( float x_, float y_, float z_ )
    {
        m_values[ 0 ] = x_; m_values[ 1 ] = y_; m_values[ 2 ] = z_;
    }
    float& PointF::operator[]( int index_ )
    {
        return m_values[ index_ ];
    }
    const float& PointF::operator[]( int index_ ) const
    {
        return m_values[ index_ ];
    }
};

struct PointD
{
    double m_values[ 3 ];

    PointD::PointD()
    {
        m_values[ 0 ] = 0; m_values[ 1 ] = 0; m_values[ 2 ] = 0;
    }
    PointD::PointD( double x_, double y_, double z_ )
    {
        m_values[ 0 ] = x_; m_values[ 1 ] = y_; m_values[ 2 ] = z_;
    }
    double& PointD::operator[]( int index_ )
    {
        return m_values[ index_ ];
    }
    const double& PointD::operator[]( int index_ ) const
    {
        return m_values[ index_ ];
    }
};

struct TriangleIndexes
{
    size_t m_values[ 3 ];

    TriangleIndexes::TriangleIndexes()
    {
        m_values[ 0 ] = 0; m_values[ 1 ] = 0; m_values[ 2 ] = 0;
    }
    TriangleIndexes::TriangleIndexes( size_t i1_, size_t i2_, size_t i3_ )
    {
        m_values[ 0 ] = i1_; m_values[ 1 ] = i2_; m_values[ 2 ] = i3_;
    }
    size_t& TriangleIndexes::operator[]( int index_ )
    {
        return m_values[ index_ ];
    }
    const size_t& TriangleIndexes::operator[]( int index_ ) const
    {
        return m_values[ index_ ];
    }
};

template< int N_ELE >
class MatrixD
{
public:
    MatrixD()
    {
        Identity();
    }
    void Identity()
    {
        for ( int i = 0; i < N_ELE; ++i )
        {
            for ( int j = 0; j < N_ELE; ++j )
            {
                m_mat[ i ][ j ] = ( ( i == j ) ? 1.0 : 0.0 );
            }
        }
    }
    double& operator()( int row_, int col_ )
    {
        if ( ( row_ >= 0 && row_ < N_ELE ) &&
             ( col_ >= 0 && col_ < N_ELE ) )
        {
            return m_mat[ row_ ][ col_ ];
        }
        else
        {
            static double zero = 0.0;
            return zero;
        }
    }
    const double& operator()( int row_, int col_ ) const
    {
        if ( ( row_ >= 0 && row_ < N_ELE ) &&
             ( col_ >= 0 && col_ < N_ELE ) )
        {
            return m_mat[ row_ ][ col_ ];
        }
        else
        {
            static double zero = 0.0;
            return zero;
        }
    }

private:
    double m_mat[ N_ELE ][ N_ELE ];
};

using Matrix4D = MatrixD< 4 >;

using TStrings  = std::vector< std::string >;
using TWStrings = std::vector< std::wstring >;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
