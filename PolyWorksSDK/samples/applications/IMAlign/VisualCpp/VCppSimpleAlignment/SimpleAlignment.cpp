/* *****************************************************************************
 *
 * File: SimpleAlignment.cpp
 *
 *
 * Description :
 *
 *      Defines the entry point for the console application.
 *      Reads a directory of pif files, performs an alignment,
 *      and saves the images as a IMAlign project.
 *
 * -----------------------------------------------------------------------------
 * InnovMetric Inc. Copyright ( C )
 *                            2003 All rights reserved
 * ************************************************************************** */
#include <PolyWorksSDK/COM/IIMAlign.h>
#include <PolyWorksSDK/COM/IIMAlign_i.c>
#include <PolyWorksSDK/COM/IIMAlignProject.h>
#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMCommandCenter_i.c>
#include <PolyWorksSDK/COM/IMAlign_i.c>
#include <atlbase.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
#include <windows.h>

//-----------------------------------------------------------------------------------
// FORWARD DECLARATION
//-----------------------------------------------------------------------------------
wchar_t* CharToWChar( const char* pSrc_, wchar_t* pDest_, size_t size_ );
int      Prompt( char* buffer );

//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------





/* *****************************************************************************
 *   Main routine
 *
 * Parameter: argc   : nb of arguments
 * Parameter: argv[] : array of arguments
 * -------------------------------------------------------------------------- */
int main( int argc, char* argv[] )
{
    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );

    // This line is added to release resources once the main exits
    std::atexit( [ ] { CoUninitialize(); } );

    int hr = 0;

    //---------------
    //IIMAlign server
    CComPtr< IIMAlign > pIMAlign;

    MULTI_QI mqiAlign = { &IID_IIMAlign, 0, 0 };

    CLSID progID = CLSID_IMAlign;
    // With the line above, your program will attempt to connect exclusively with the version of IMAlign
    // you're currently working with. If the user upgrades to a more recent version of IMAlign, your program
    // will not attempt to connect to it.
    // Instead, to let your program attempt to work with the latest version of IMAlign installed on the
    // user's computer, uncomment the following line and make sure hr is not an error code before continuing.
    //hr = CLSIDFromProgID( L"InnovMetric.PolyWorks.IMAlign", &progID );

    hr = CoCreateInstanceEx(
        progID,
        nullptr,
        CLSCTX_SERVER,
        nullptr,
        1,
        &mqiAlign );


    if ( !SUCCEEDED( hr ) )
    {
        return 1;
    }

    pIMAlign = reinterpret_cast< IIMAlign* >( mqiAlign.pItf );


    //----------------
    // Current project
    CComPtr< IIMAlignProject > pCurrentProject;
    hr = pIMAlign->ProjectGetCurrent( &pCurrentProject );
    if ( !SUCCEEDED( hr ) || ( pCurrentProject == nullptr ) )
    {
        return 1;
    }


    //--------------
    // CommandCenter
    CComPtr< IIMCommandCenter > pCommandCenter;
    hr = pCurrentProject->CommandCenterCreate( &pCommandCenter );
    if ( !SUCCEEDED( hr ) || ( pCommandCenter == nullptr ) )
    {
        return 1;
    }


    // Introduction
    std::cout << std::endl << "IMAlign Simple Alignment sample." << std::endl << std::endl;

    char    entryBuffer[ 1024 ];
    wchar_t repPathPif[ 1024 ];
    wchar_t repPathPifClean[ 1024 ];
    wchar_t cmdString[ 1024 ];

    long isSuccess = 0;

    while ( Prompt( entryBuffer ) )
    {
        if ( ( CharToWChar( entryBuffer, repPathPif, 1024 ) == nullptr ) || ( wcslen( repPathPif ) == 0 ) )
        {
            continue;
        }

        long res = 0;

        pCommandCenter->CommandExecute( L"FILE NEW_PROJECT",                                         &res );
        pCommandCenter->CommandExecute( L"CONFIG DIGITIZERS NAME (\"Generic Close Range (in mm)\")", &res );

        // Imports Pif files
        ( repPathPif[ 0 ] == L'\"' ) ? _tcscpy( repPathPifClean, &repPathPif[ 1 ] ) : _tcscpy( repPathPifClean, &repPathPif[ 0 ] );

        if ( repPathPifClean[ wcslen( repPathPifClean ) - 1 ] == L'\"' )
        {
            repPathPifClean[ wcslen( repPathPifClean ) - 1 ] = L'\0';
        }

        _stprintf( cmdString, L"FILE IMPORT_IMAGE 3D_DIGITIZED_DATASET PLANAR_GRID FOLDER ( \"%s\", , \"PIF\" )", repPathPifClean );

        pCommandCenter->CommandExecute( cmdString, &res );

        pCommandCenter->ReturnValueIsSuccess( res, &isSuccess );

        if ( isSuccess != 0 )
        {
            // Alignment
            pCommandCenter->CommandExecute( L"ALIGN START ( 0.000001, 10 )", &res );

            pCommandCenter->ReturnValueIsSuccess( res, &isSuccess );

            if ( isSuccess != 0 )
            {
                std::cout << std::endl << "Alignment succeeded..." << std::endl;
            }
            else
            {
                std::cout << std::endl << "Alignment failed..." << std::endl;
            }
        }
    }

    return 0;
}



/* *****************************************************************************
 *   Converts a char string into a wchar_t string
 *
 * Parameter: pSrc_  : string to convert
 * Parameter: pDest_ : result buffer
 * Parameter: size_  : buffer size
 *
 * Returns: wchar_t* : pointer to result buffer; nullptr if one of the
 *                     pointer arguments is nullptr
 * -------------------------------------------------------------------------- */
wchar_t* CharToWChar( const char* pSrc_, wchar_t* pDest_, size_t size_ )
{
    size_t charNo;
    size_t stringSize;

    if ( pSrc_ == nullptr )
    {
        return nullptr;
    }

    if ( pDest_ == nullptr )
    {
        return nullptr;
    }

    stringSize = strlen( pSrc_ );

    if ( stringSize > size_ - 1 )
    {
        std::cout << "Buffer is too small " << size_ << "for converting:\n" << pSrc_ << std::endl;
        pDest_[ 0 ] = L'\0';
        return pDest_;
    }

    for ( charNo = 0; charNo < stringSize; charNo++ )
    {
        pDest_[ charNo ] = ( unsigned char )pSrc_[ charNo ];
    }

    pDest_[ stringSize ] = L'\0';

    return pDest_;
}


/* *****************************************************************************
 *   Prompts the user for a line of text and saves the input in a buffer
 *
 * Parameter: buffer : text buffer
 *
 * Return: false, if leaving,
 *         true,  otherwise
 * -------------------------------------------------------------------------- */
int Prompt( char* buffer )
{
    if ( buffer == nullptr )
    {
        return 0;
    }

    std::cout << std::endl << "Enter a PIF files directory path, or type EXIT to quit." << std::endl;
    std::cout << "Directory path:\n";

    std::cin.getline( buffer, 1024, '\n' );

    // if the stream is not valide or EXIT, we leave
    if ( !std::cin || !_strnicmp( buffer, "EXIT\0", 5 ) )
    {
        return 0;
    }

    return 1;
}
