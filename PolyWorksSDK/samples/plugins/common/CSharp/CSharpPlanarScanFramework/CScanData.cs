// =================================================================================================
//   CScanData class
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------
using System.Collections.Generic;
using System.Drawing;

namespace CompanyNameCsPlanarScanner
{

// =================================================================================================
//   Simple class representing a grid scan
// -------------------------------------------------------------------------------------------------

class CScanData
{
    public short m_height = 0;
    public short m_width = 0;
    public float[] m_normal = { 0.0f, 0.0f, 0.0f };
    public Dictionary< Point, System.Tuple< float, float, float > > m_points;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : i_ : X coordinate of normal vector
    // Parameter : j_ : Y coordinate of normal vector
    // Parameter : k_ : Z coordinate of normal vector
    // Parameter : width_ : horizontal dimension of 2D grid
    // Parameter: height_ : vertical dimension of 2D grid 
    // -------------------------------------------------------------------------------------------------
    public CScanData( short width_, short height_, float i_, float j_, float k_ )
    {
        m_normal = new float[]{ i_, j_, k_ };
        m_width = width_;
        m_height = height_;
        m_points = new Dictionary< Point, System.Tuple<float, float, float> >();
    }

    public CScanData() : this( 0, 0, 0.0f, 0.0f, 0.0f )
    {
    }
}
}