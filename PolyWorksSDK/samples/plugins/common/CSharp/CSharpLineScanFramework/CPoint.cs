// =================================================================================================
//   CPoint class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Simple class representing a 3D point.
// -------------------------------------------------------------------------------------------------
class CPoint
{
    public float X;
    public float Y;
    public float Z;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : x_ : X coordinate
    // Parameter : y_ : Y coordinate
    // Parameter : z_ : Z coordinate
    // -------------------------------------------------------------------------------------------------
    public CPoint( float x_, float y_, float z_ )
    {
        X = x_;
        Y = y_;
        Z = z_;
    }

    // =================================================================================================
    //   Compute the squared euclidian distance between 2 points.
    //
    // Parameter : other_ : the other point. The distance is computed between "this" and "other_".
    //
    // Return : The squared distance
    // -------------------------------------------------------------------------------------------------
    public float SqrDistance( CPoint other_ )
    {
        float diffX = other_.X - X;
        float diffY = other_.Y - Y;
        float diffZ = other_.Z - Z;

        return diffX * diffX + diffY * diffY + diffZ * diffZ;
    }

    // =================================================================================================
    //   Compute the squared modulus of a vector from the origin to the coordinates of the point.
    //
    // Return : The squared modulus
    // -------------------------------------------------------------------------------------------------
    public float SqrModulus()
    {
        return X * X + Y * Y + Z * Z;
    }

    // =================================================================================================
    //   Return a point whose coordinates are equivalent to a vector going from other_ to this.
    //
    // Parameter : other_ : the other point.
    //
    // Return : The squared modulus
    // -------------------------------------------------------------------------------------------------
    public CPoint Diff( CPoint other_ )
    {
        return new CPoint( X - other_.X, Y - other_.Y, Z - other_.Z );
    }

    // =================================================================================================
    //   Return the dot product between 2 points interpreted as vector.
    //
    // Parameter : other_ : the other "vector".
    //
    // Return : The dot product
    // -------------------------------------------------------------------------------------------------
    public float DotProduct( CPoint other_ )
    {
        return X * other_.X + Y * other_.Y + Z * other_.Z;
    }
}

}
