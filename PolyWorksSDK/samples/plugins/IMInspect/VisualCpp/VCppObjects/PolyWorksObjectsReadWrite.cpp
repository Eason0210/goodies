// =================================================================================================
//   Example functions showing how to interact with IPWObject classes.
//
// Copyright © InnovMetric Software Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "PolyWorksObjectsReadWrite.h"

#include <windows.h>

#include <fstream>
#include <string>

#pragma warning( push )
#pragma warning( disable : 4251 )
#pragma warning( disable : 4275 )

#include "PolyWorksSDK/Geom/IBBox.h"
#include "PolyWorksSDK/Geom/IPointWithNormalArray.h"
#include "PolyWorksSDK/Object/CPWODelayer.h"
#include "PolyWorksSDK/Object/CPWOElements.h"
#include "PolyWorksSDK/Object/CPWOPredicatePWOPropertyValue.h"
#include "PolyWorksSDK/Object/CPWOPredicatePWOType.h"
#include "PolyWorksSDK/Object/FnCPWOPredicatePWOPropertyValue.h"
#include "PolyWorksSDK/Object/ILineScan.h"
#include "PolyWorksSDK/Object/IPWOElementsProperties.h"
#include "PolyWorksSDK/Object/IPWObjects.h"
#include "PolyWorksSDK/Object/IPointCloud.h"
#include "PolyWorksSDK/Object/IPolygonalModel.h"
#include <PolyWorksSDK\Object\CLineScanLineConstIterator.h>
#include <PolyWorksSDK\Object\ILineScanPass.h>
#include <PolyWorksSDK\Object\ILineScanLine.h>
#include "PolyWorksSDK/Base/IArray.h"
#include "PolyWorksSDK/Geom/ITriangleArray.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================


// =================================================================================================
// Displays a text to a dialog box or writes it to a log file.
//
// Parameter: stringToLog_   : Text to display via a message box or to write to a log file.
// Parameter: logDirNameExt_ : Complete path representing a file to log information to.
//                             If empty, no log will be written an a dialog box will display the
//                             information.
// -------------------------------------------------------------------------------------------------
static void DisplayOrLog(
    const std::wstring& stringToLog_,
    const std::wstring& logDirNameExt_ )
{
    if ( logDirNameExt_.empty() )
    {
        MessageBox( nullptr, stringToLog_.c_str(), L"VCppObjects", MB_OK );
    }
    else
    {
        std::wofstream logStream( logDirNameExt_.c_str(), std::ios_base::app );
        if ( !logStream.bad() )
        {
            logStream << stringToLog_;
        }
    }
}


// =================================================================================================
// Returns the name of the input PolyWorks Object by querying it's name property.
//
// Parameter: pPWObject_ : Pointer to the PolyWorks Object.
//
// Return: Name of the PolyWorks Object. L"" if an error occurred;
// -------------------------------------------------------------------------------------------------
static IM::CWString PWObjectNameGet( IM::IPWObject* pPWObject_ )
{
    if ( pPWObject_ == nullptr )
    {
        return IM::CWString( L"" );
    }

    IM::CWString      name( L"" );
    IM::IPWOProperty* pPropertyName = pPWObject_->PropertyGet( IM::PWOPropertyNameTypeGet() );
    if ( pPropertyName != nullptr )
    {
        pPropertyName->ValueGet( name );
    }

    return name;
}


// =================================================================================================
// Example showing how to add new lines to an existing line scan object. The new lines are
// duplicated and translated from the first pass of the line scan.
// -------------------------------------------------------------------------------------------------
void ILineScanAddLines()
{
    // Request all selected ILineScan objects
    IM::CPWObjectIterator pwObjectIt = IM::PWObjectsGet()->Begin(
        IM::CPWOPredicatePWOType( IM::ILineScanTypeGet() ) &&
        IM::MakePWOPredicatePWOPropertyValue( IM::PWOPropertySelectedTypeGet(), true ) );
    IM::CPWObjectIterator pwObjectEnd = IM::PWObjectsGet()->End();

    for ( ; pwObjectIt != pwObjectEnd; ++pwObjectIt )
    {
        IM::ILineScan* pLineScan = dynamic_cast< IM::ILineScan* >( &*pwObjectIt );
        if ( pLineScan == nullptr )
        {
            continue;
        }

        // Check if there is at least one pass in the ILineScan Object.
        IM::CLineScanPassConstIterator passIt  = pLineScan->LineScanPassBegin();
        IM::CLineScanPassConstIterator passEnd = pLineScan->LineScanPassEnd();
        if ( passIt == passEnd )
        {
            continue;
        }

        // Calculate a translation value based on the objects bounding box
        double     firstPassTranslation = 0.0;
        IM::IBBox* pBBox                = dynamic_cast< IM::IBBox* >( pLineScan->GeometryGet( IM::IBBoxTypeGet() ) );
        if ( pBBox != nullptr )
        {
            IM::CPoint diff     = pBBox->MaxGet() - pBBox->MinGet();
            double     bboxDiag = sqrt( diff[ 0 ] * diff[ 0 ] + diff[ 1 ] * diff[ 1 ] + diff[ 2 ] * diff[ 2 ] );
            firstPassTranslation = bboxDiag / 2.0;
        }

        // The instanciation of the CPWODelayer will make the ILineScan::LineAdd call to delay
        // the line addition until CPWODelayer destructor call. When de delay is expired, all added
        // lines will be regrouped in a single pass.
        IM::CPWODelayer delayer( pLineScan );

        // Copy each line of the first pass into a new pass.
        const IM::ILineScanPass&       firstPass = *passIt;
        IM::CLineScanLineConstIterator lineIt    = firstPass.LineScanLineBegin();
        IM::CLineScanLineConstIterator lineEnd   = firstPass.LineScanLineEnd();
        for ( ; lineIt != lineEnd; ++lineIt )
        {
            const IM::ILineScanLine&         line                      = *lineIt;
            const IM::IPointWithNormalArray* pLinePointWithNormalArray = line.PointWithNormalArrayGet();
            if ( pLinePointWithNormalArray == nullptr )
            {
                continue;
            }

            IM::IPointArray* pLinePointWithNormalArrayTranslated = nullptr;
            IM::Create( pLinePointWithNormalArrayTranslated );

            IM::TSize pointWithNormalNb = pLinePointWithNormalArray->Size();
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                IM::CPoint point = pLinePointWithNormalArray->PointGetAt( iPoint );
                point[ 0 ] += firstPassTranslation;
                point[ 1 ] += firstPassTranslation;
                point[ 2 ] += firstPassTranslation;
                pLinePointWithNormalArrayTranslated->Add( point );
            }

            pLineScan->LineAdd( pLinePointWithNormalArrayTranslated, line.DigitizingVectorGet() );

            IM::Destroy( pLinePointWithNormalArrayTranslated );
        }
    }
}


// =================================================================================================
// Pops up a message box displaying information about the selected ILineScan objects
//
// Parameter: logDirNameExt_ : Complete path representing a file to log information to.
//                             If empty, no log will be written an a dialog box will display the
//                             information.
// -------------------------------------------------------------------------------------------------
void ILineScanRead( std::wstring logDirNameExt_ )
{
    // Request all selected ILineScan objects
    IM::CPWObjectIterator pwObjectIt = IM::PWObjectsGet()->Begin(
        IM::CPWOPredicatePWOType( IM::ILineScanTypeGet() ) &&
        IM::MakePWOPredicatePWOPropertyValue( IM::PWOPropertySelectedTypeGet(), true ) );
    IM::CPWObjectIterator pwObjectEnd = IM::PWObjectsGet()->End();

    std::wstring messageString;
    messageString += L"Information about ILineScan objects:\n";
    wchar_t   printfBuffer[ 1024 ];
    IM::TSize nbObjects = 0;
    for ( ; pwObjectIt != pwObjectEnd; ++pwObjectIt )
    {
        IM::ILineScan* pLineScan = dynamic_cast< IM::ILineScan* >( &*pwObjectIt );
        if ( pLineScan == nullptr )
        {
            continue;
        }

        // Name of the object
        IM::CWString name = PWObjectNameGet( pLineScan );
        swprintf_s( printfBuffer, L"\tName of the ILineScan: %s\n", static_cast< const __wchar_t* >( name ) );
        messageString += printfBuffer;

        const IM::IPointWithNormalArray* pPointWithNormalArray = pLineScan->PointWithNormalArrayGet();
        if ( pPointWithNormalArray != nullptr )
        {
            IM::TSize pointWithNormalNb = pPointWithNormalArray->Size();
            swprintf_s( printfBuffer, L"\t\tNumber of points: %d\n", pointWithNormalNb );
            messageString += printfBuffer;

            int numberOfNormals = 0;
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                if ( pPointWithNormalArray->HasNormalAt( iPoint ) )
                {
                    ++numberOfNormals;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of normals: %d\n", numberOfNormals );
            messageString += printfBuffer;

            int numberOfVisiblePoints = 0;
            IM::CPWOElements elementsVisible( pLineScan, pPointWithNormalArray, IM::PWOElementsVisible() );
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                if ( elementsVisible.StateGet( iPoint ) )
                {
                    ++numberOfVisiblePoints;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of visible points: %d\n", numberOfVisiblePoints );
            messageString += printfBuffer;
        }

        IM::TSize totalNbPass                  = 0;
        IM::TSize totalNbLines                 = 0;
        IM::CLineScanPassConstIterator passIt  = pLineScan->LineScanPassBegin();
        IM::CLineScanPassConstIterator passEnd = pLineScan->LineScanPassEnd();
        for ( ; passIt != passEnd; ++passIt )
        {
            const IM::ILineScanPass& pass = *passIt;

            IM::CLineScanLineConstIterator lineIt  = pass.LineScanLineBegin();
            IM::CLineScanLineConstIterator lineEnd = pass.LineScanLineEnd();
            for ( ; lineIt != lineEnd; ++lineIt )
            {
                const IM::ILineScanLine&         line                      = *lineIt;
                const IM::IPointWithNormalArray* pLinePointWithNormalArray = line.PointWithNormalArrayGet();
                if ( pLinePointWithNormalArray == nullptr )
                {
                    continue;
                }

                ++totalNbLines;
            }
            ++totalNbPass;
        }

        swprintf_s( printfBuffer, L"\t\tNumber of passes: %d\n", totalNbPass );
        messageString += printfBuffer;
        swprintf_s( printfBuffer, L"\t\tNumber of lines: %d\n", totalNbLines );
        messageString += printfBuffer;

        ++nbObjects;
    }

    swprintf_s( printfBuffer, L"\tNumber of ILineScan: %d\n", nbObjects );
    messageString += printfBuffer;
    DisplayOrLog( messageString, logDirNameExt_ );
}


// =================================================================================================
// Pops up a message box displaying information about the selected IPointCloud objects. Note that
// an ILineScan object is considered as being an IPointCloud object.
//
// Parameter: logDirNameExt_ : Complete path representing a file to log information to.
//                             If empty, no log will be written an a dialog box will display the
//                             information.
// -------------------------------------------------------------------------------------------------
void IPointCloudRead( std::wstring logDirNameExt_ )
{
    // Request all selected IPointCloud objects
    IM::CPWObjectIterator pwObjectIt = IM::PWObjectsGet()->Begin(
        IM::CPWOPredicatePWOType( IM::IPointCloudTypeGet() ) &&
        IM::MakePWOPredicatePWOPropertyValue( IM::PWOPropertySelectedTypeGet(), true ) );
    IM::CPWObjectIterator pwObjectEnd = IM::PWObjectsGet()->End();

    std::wstring messageString;
    messageString += L"Information about IPointCloud objects:\n";
    wchar_t   printfBuffer[ 1024 ];
    IM::TSize nbObjects = 0;
    for ( ; pwObjectIt != pwObjectEnd; ++pwObjectIt )
    {
        IM::IPointCloud* pPointCloud = dynamic_cast< IM::IPointCloud* >( &*pwObjectIt );
        if ( pPointCloud == nullptr )
        {
            continue;
        }

        // Name of the object
        IM::CWString name = PWObjectNameGet( pPointCloud );
        swprintf_s( printfBuffer, L"\tName of the IPointCloud: %s\n", static_cast< const __wchar_t* >( name ) );
        messageString += printfBuffer;

        const IM::IPointWithNormalArray* pPointWithNormalArray = pPointCloud->PointWithNormalArrayGet();
        if ( pPointWithNormalArray != nullptr )
        {
            IM::TSize pointWithNormalNb = pPointWithNormalArray->Size();
            swprintf_s( printfBuffer, L"\t\tNumber of points: %d\n", pointWithNormalNb );
            messageString += printfBuffer;

            int numberOfNormals = 0;
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                if ( pPointWithNormalArray->HasNormalAt( iPoint ) )
                {
                    ++numberOfNormals;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of normals: %d\n", numberOfNormals );
            messageString += printfBuffer;

            int numberOfVisiblePoints = 0;
            IM::CPWOElements elementsVisible( pPointCloud, pPointWithNormalArray, IM::PWOElementsVisible() );
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                if ( elementsVisible.StateGet( iPoint ) )
                {
                    ++numberOfVisiblePoints;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of visible points: %d\n", numberOfVisiblePoints );
            messageString += printfBuffer;
        }

        ++nbObjects;
    }

    swprintf_s( printfBuffer, L"\tNumber of IPointCloud: %d\n", nbObjects );
    messageString += printfBuffer;
    DisplayOrLog( messageString.c_str(), logDirNameExt_ );
}


// =================================================================================================
// Apply a 1:2 subsampling to the selected IPointCloud objects.
// -------------------------------------------------------------------------------------------------
void IPointCloudSubsample()
{
    // Request all selected IPointCloud objects
    IM::CPWObjectIterator pwObjectIt = IM::PWObjectsGet()->Begin(
        IM::CPWOPredicatePWOType( IM::IPointCloudTypeGet() ) &&
        IM::MakePWOPredicatePWOPropertyValue( IM::PWOPropertySelectedTypeGet(), true ) );
    IM::CPWObjectIterator pwObjectEnd = IM::PWObjectsGet()->End();

    for ( ; pwObjectIt != pwObjectEnd; ++pwObjectIt )
    {
        IM::IPointCloud* pPointCloud = dynamic_cast< IM::IPointCloud* >( &*pwObjectIt );
        if ( pPointCloud == nullptr )
        {
            continue;
        }

        IM::IPointArray* pPointArray = pPointCloud->PointArrayGet();
        if ( pPointArray == nullptr )
        {
            continue;
        }

        IM::IPWOElementsProperties* pPWOElementsProperties;
        IM::IPWOProperty*           pPWOPropertyElements = pPointCloud->PropertyGet( IM::PWOPropertyElementPropertiesTypeGet() );
        if ( pPWOPropertyElements == nullptr || !pPWOPropertyElements->ValueGet( pPWOElementsProperties ) )
        {
            continue;
        }

        // Using thte CPWOElements tool will give a fast read-only access to the properties of a
        // PolyWorks Object's elements.
        IM::CPWOElements elements( pPointCloud, pPointArray, IM::PWOElementsVisible() );

        // Instanciating the CPWODelayer will delay all calls to VisibleSet until the CPWODelayer object
        // is destroyed. This optimization is very important to avoid expensive reaction to each individual
        // element property modification (feature recalculation, re-fits, etc...).
        IM::CPWODelayer delayer( pPointCloud );

        IM::TSize iSubsample = 0;
        IM::TSize pointNb    = pPointArray->Size();
        for ( IM::TSize iPoint = 0; iPoint < pointNb; ++iPoint )
        {
            if ( elements.StateGet( iPoint ) )
            {
                if ( ( iSubsample % 2 ) != 0 )
                {
                    pPWOElementsProperties->DeletedSet( pPointArray, iPoint, true );
                }

                ++iSubsample;
            }
        }
    }
}


// =================================================================================================
// Add a small noise value to each coordinates of each point of selected IPointCloud object.
// -------------------------------------------------------------------------------------------------
void IPointCloudWrite()
{
    // Request all selected IPointCloud objects
    IM::CPWObjectIterator pwObjectIt = IM::PWObjectsGet()->Begin(
        IM::CPWOPredicatePWOType( IM::IPointCloudTypeGet() ) &&
        IM::MakePWOPredicatePWOPropertyValue( IM::PWOPropertySelectedTypeGet(), true ) );
    IM::CPWObjectIterator pwObjectEnd = IM::PWObjectsGet()->End();

    srand( 1 );
    for ( ; pwObjectIt != pwObjectEnd; ++pwObjectIt )
    {
        IM::IPointCloud* pPointCloud = dynamic_cast< IM::IPointCloud* >( &*pwObjectIt );
        if ( pPointCloud == nullptr )
        {
            continue;
        }

        // Calculate the noise value to be added to each points based on the bounding box diagonal length
        double     noiseValue = 0.0;
        IM::IBBox* pBBox      = dynamic_cast< IM::IBBox* >( pPointCloud->GeometryGet( IM::IBBoxTypeGet() ) );
        if ( pBBox != nullptr )
        {
            IM::CPoint diff     = pBBox->MaxGet() - pBBox->MinGet();
            double     bboxDiag = sqrt( diff[ 0 ] * diff[ 0 ] + diff[ 1 ] * diff[ 1 ] + diff[ 2 ] * diff[ 2 ] );
            noiseValue = bboxDiag / 1000.0;
        }

        IM::IPointWithNormalArray* pPointWithNormalArray = pPointCloud->PointWithNormalArrayGet();
        if ( pPointWithNormalArray == nullptr )
        {
            continue;
        }

        // Instanciating the CPWODelayer will delay all calls to PointSetAt until the CPWODelayer object
        // is destroyed. This optimization is very important to avoid expensive reaction to each individual
        // point modification (feature recalculation, re-fits, etc...).
        IM::CPWODelayer delayer( pPointCloud );

        IM::TSize pointWithNormalNb = pPointWithNormalArray->Size();
        for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
        {
            IM::CPoint point = pPointWithNormalArray->PointGetAt( iPoint );
            point[ 0 ] += rand() > 16382 ? noiseValue : -noiseValue;
            point[ 1 ] += rand() > 16382 ? noiseValue : -noiseValue;
            point[ 2 ] += rand() > 16382 ? noiseValue : -noiseValue;
            pPointWithNormalArray->PointSetAt( iPoint, point );
        }
    }
}


// =================================================================================================
// Pops up a message box displaying information about the selected IPolygonalModel objects.
//
// Parameter: dataOrRef_     : true if the caller wants information about data polygonal models,
//                             false if the caller wants information about reference polygonal models
// Parameter: logDirNameExt_ : Complete path representing a file to log information to.
//                             If empty, no log will be written an a dialog box will display the
//                             information.
// -------------------------------------------------------------------------------------------------
void IPolygonalModelRead( bool dataOrRef_, std::wstring logDirNameExt_ )
{
    // Request all selected data or reference IPolygonalModel objects
    IM::CPWOPropertyType  dataOrRefPropertyType = dataOrRef_ ? IM::PWOPropertyDataTypeGet() : IM::PWOPropertyReferenceTypeGet();
    IM::CPWObjectIterator pwObjectIt            = IM::PWObjectsGet()->Begin(
        IM::CPWOPredicatePWOType( IM::IPolygonalModelTypeGet() ) &&
        IM::MakePWOPredicatePWOPropertyValue( dataOrRefPropertyType,            true ) &&
        IM::MakePWOPredicatePWOPropertyValue( IM::PWOPropertySelectedTypeGet(), true ) );
    IM::CPWObjectIterator pwObjectEnd = IM::PWObjectsGet()->End();

    std::wstring messageString;
    messageString += L"Information about IPolygonalModel objects:\n";
    wchar_t   printfBuffer[ 1024 ];
    IM::TSize nbObjects = 0;
    for ( ; pwObjectIt != pwObjectEnd; ++pwObjectIt )
    {
        IM::IPolygonalModel* pPolygonalModel = dynamic_cast< IM::IPolygonalModel* >( &*pwObjectIt );
        if ( pPolygonalModel == nullptr )
        {
            continue;
        }

        // Name of the object
        IM::CWString name = PWObjectNameGet( pPolygonalModel );
        swprintf_s( printfBuffer, L"\tName of the IPolygonalModel: %s\n", static_cast< const __wchar_t* >( name ) );
        messageString += printfBuffer;

        const IM::IPointWithNormalArray* pPointWithNormalArray = pPolygonalModel->PointWithNormalArrayGet();
        if ( pPointWithNormalArray != nullptr )
        {
            IM::TSize pointWithNormalNb = pPointWithNormalArray->Size();
            swprintf_s( printfBuffer, L"\t\tNumber of points: %d\n", pointWithNormalNb );
            messageString += printfBuffer;

            int numberOfNormals = 0;
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                if ( pPointWithNormalArray->HasNormalAt( iPoint ) )
                {
                    ++numberOfNormals;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of normals: %d\n", numberOfNormals );
            messageString += printfBuffer;

            int numberOfVisiblePoints = 0;
            IM::CPWOElements elementsVisible( pPolygonalModel, pPointWithNormalArray, IM::PWOElementsVisible() );
            for ( IM::TSize iPoint = 0; iPoint < pointWithNormalNb; ++iPoint )
            {
                if ( elementsVisible.StateGet( iPoint ) )
                {
                    ++numberOfVisiblePoints;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of visible points: %d\n", numberOfVisiblePoints );
            messageString += printfBuffer;
        }

        const IM::ITriangleArray* pTriangleArray = pPolygonalModel->TriangleArrayGet();
        if ( pTriangleArray != nullptr )
        {
            IM::TSize triangleNb = pTriangleArray->Size();
            swprintf_s( printfBuffer, L"\t\tNumber of triangles: %d\n", triangleNb );
            messageString += printfBuffer;

            int numberOfVisibleTriangles = 0;
            IM::CPWOElements elementsVisible( pPolygonalModel, pTriangleArray, IM::PWOElementsVisible() );
            for ( IM::TSize iTriangle = 0; iTriangle < triangleNb; ++iTriangle )
            {
                if ( elementsVisible.StateGet( iTriangle ) )
                {
                    ++numberOfVisibleTriangles;
                }
            }
            swprintf_s( printfBuffer, L"\t\tNumber of visible triangles: %d\n", numberOfVisibleTriangles );
            messageString += printfBuffer;
        }


        ++nbObjects;
    }

    dataOrRef_ ? swprintf_s( printfBuffer, L"\tNumber of IPolygonalModel datas: %d\n", nbObjects ) :
    swprintf_s( printfBuffer, L"\tNumber of IPolygonalModel references: %d\n", nbObjects );
    messageString += printfBuffer;
    DisplayOrLog( messageString.c_str(), logDirNameExt_ );
}

#pragma warning( pop )
