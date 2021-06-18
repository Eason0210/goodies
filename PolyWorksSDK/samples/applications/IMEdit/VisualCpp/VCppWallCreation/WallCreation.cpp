/* *****************************************************************************
 *
 * File: WallCreation.cpp
 *
 * Description :
 *
 *      Defines the entry point for the console application.
 *      Reads a Pol model and performs a wall creation.
 * -----------------------------------------------------------------------------
 * InnovMetric Inc. Copyright ( C ) 2003
 *                            All rights reserved
 * ************************************************************************** */
#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMCommandCenter_i.c>
#include <PolyWorksSDK/COM/IIMEdit.h>
#include <PolyWorksSDK/COM/IIMEdit_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <PolyWorksSDK/COM/IMEdit_i.c>
#include <atlbase.h>
#include <comdef.h>
#include <fstream>
#include <iostream>
#include <tchar.h>
#include <time.h>
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

    int hr =  0;

    //--------------
    //IIMEdit server
    CComPtr< IIMEdit > pIMEdit;

    MULTI_QI mqiEdit = { &IID_IIMEdit, 0, 0 };

    CLSID progID = CLSID_IMEdit;
    // With the line above, your program will attempt to connect exclusively with the version of PolyWorks|Modeler
    // you're currently working with. If the user upgrades to a more recent version of PolyWorks|Modeler, your program
    // will not attempt to connect to it.
    // Instead, to let your program attempt to work with the latest version of PolyWorks|Modeler installed on the
    // user's computer, uncomment the following line and make sure hr is not an error code before continuing.
    //hr = CLSIDFromProgID( L"InnovMetric.PolyWorks.IMEdit", &progID );

    hr = CoCreateInstanceEx(
        progID,
        nullptr,
        CLSCTX_SERVER,
        nullptr,
        1,
        &mqiEdit );


    if ( !SUCCEEDED( hr ) )
    {
        return 1;
    }

    pIMEdit = reinterpret_cast< IIMEdit* >( mqiEdit.pItf );


    //----------------
    // Current project
    CComPtr< IIMEditProject > pCurrentProject;
    hr = pIMEdit->ProjectGetCurrent( &pCurrentProject );
    if ( !SUCCEEDED( hr ) || pCurrentProject == nullptr )
    {
        return 1;
    }

    //--------------
    // CommandCenter
    CComPtr< IIMCommandCenter > pEditCommandCenter;
    hr = pCurrentProject->CommandCenterCreate( &pEditCommandCenter );

    if ( !SUCCEEDED( hr ) || ( pEditCommandCenter == nullptr ) )
    {
        return 1;
    }


    // Introduction
    std::cout << std::endl <<  "Wall_Creation sample." << std::endl << std::endl << std::endl;

    char    imagePath[ 1024 ];
    wchar_t imgPathBuf[ 1024 ];
    wchar_t imgPathBufClean[ 1024 ];
    wchar_t cmdString[ 1024 ];
    long    isSuccess = 0;


    while ( Prompt( imagePath ) )
    {
        if ( ( CharToWChar( imagePath, imgPathBuf, 1024 ) == nullptr ) || ( wcslen( imgPathBuf ) == 0 ) )
        {
            continue;
        }

        long res = 0;

        pEditCommandCenter->CommandExecute( L"FILE NEW_PROJECT", &res );

        pEditCommandCenter->CommandExecute( L"TREEVIEW MODEL VIEW DEFAULT_STATIC FLAT", &res );

        // image loading...
        ( imgPathBuf[ 0 ] == L'\"' ) ? _tcscpy( imgPathBufClean, &imgPathBuf[ 1 ] ) : _tcscpy( imgPathBufClean, &imgPathBuf[ 0 ] );

        if ( imgPathBufClean[ wcslen( imgPathBufClean ) - 1 ] == L'\"' )
        {
            imgPathBufClean[ wcslen( imgPathBufClean ) - 1 ] = L'\0';
        }

        _stprintf( cmdString, L"FILE IMPORT_MODEL POLYGONAL_FILE ( \"%s\" )", imgPathBufClean );

        pEditCommandCenter->CommandExecute( cmdString, &res );

        pEditCommandCenter->ReturnValueIsSuccess( res, &isSuccess );

        if ( isSuccess != 0 )
        {
            pEditCommandCenter->CommandExecute( L"EDIT PLANE CREATE XY_PLANE",                                    &res );
            pEditCommandCenter->CommandExecute( L"EDIT OBJECT INVERT_ORIENTATION",                                &res );
            pEditCommandCenter->CommandExecute( L"SELECT TRIANGLES ALL",                                          &res );
            pEditCommandCenter->CommandExecute( L"EDIT TRIANGLES OFFSET NORMAL ( -1.0, \"On\", \"Off\", 180.0 )", &res );


            pEditCommandCenter->CommandExecute( L"SELECT TRIANGLES ALL",                                  &res );
            pEditCommandCenter->CommandExecute( L"EDIT TRIANGLES SLICE_WITH_A_PLANE INSERT_INTERSECTION", &res );
            pEditCommandCenter->CommandExecute( L"SELECT TRIANGLES USING_PLANES BELOW",                   &res );

            pEditCommandCenter->CommandExecute( L"EDIT DELETE LAST",                    &res );
            pEditCommandCenter->CommandExecute( L"TREEVIEW OBJECT VIEW HIDE",           &res );
            pEditCommandCenter->CommandExecute( L"VIEW POSE CENTER",                    &res );
            pEditCommandCenter->CommandExecute( L"EDIT TRIANGLES CREATE_WALLS ( 3.0 )", &res );

            std::cout << std::endl << "Wall creation done..." << std::endl;
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

    std::cout << std::endl << "Enter a POL model file path, or type EXIT to quit." << std::endl;
    std::cout << "File path: " << std::endl;

    std::cin.getline( buffer, 1024, '\n' );

    // if the stream is not valide or EXIT, we leave
    if ( !std::cin || !_strnicmp( buffer, "EXIT\0", 5 ) )
    {
        return 0;
    }

    return 1;
}
