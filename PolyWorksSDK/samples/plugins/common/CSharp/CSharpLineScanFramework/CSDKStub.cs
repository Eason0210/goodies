// =================================================================================================
//   CSDKStub class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   This is an example of a class that wraps interactions with the device. There are wildly
// varying SDK architectures, data types and data rates from device to device. So there cannot
// be one implementation that covers all possible cases. This class gives a simple example of a
// possible architecture of relationship between the stub and the receiver.
//
// TODO : Replace the content of this class to fit with your SDK.
// TODO : If your stub does not contain any unmanaged resources, you can remove the IDisposable interface.
// -------------------------------------------------------------------------------------------------
class CSDKStub : IDisposable
{
    // Constants for the generation of simulation data.
    private const int COLUMN_SIZE = 250;

    // This variable simulates the device connection status.
    private bool m_connected = false;
    // This variable manages relationship with the PassStart/End button in the dialog vs
    // the information sent to the receiver.
    private bool m_passIsStarted = false;
    // This is just an internal variable to manage the generation of fake data.
    private int  m_lineCount = 0;
    // Helper to display the cursor scanning around in front of already sent lines.
    private int  m_cursorOffset = 0;

    // This is a dialog used to simulate buttons on a real device. See the class for more details.
    private CDlgScanControl m_dialog;

    // =================================================================================================
    //   Destructor
    //
    // Frees unmanaged resources.
    // -------------------------------------------------------------------------------------------------
    ~CSDKStub()
    {
        Dispose( false );
    }

    // =================================================================================================
    //   Internal code for freeing unmanaged resources common to destructor and Dispose.
    //
    // Parameter : disposing_ : true if calling from Dispose, false if calling from destructor.
    // -------------------------------------------------------------------------------------------------
    private void Dispose( bool disposing_ )
    {
        if ( disposing_ )
        {
            // We have freed the resources, tell the GC it does not need to Finalize this object.
            GC.SuppressFinalize( this );
        }
    }

    // =================================================================================================
    //   Implementation of IDisposable interface.
    // -------------------------------------------------------------------------------------------------
    public void Dispose()
    {
        Dispose( true );
    }

    // =================================================================================================
    //   Property access.
    // -------------------------------------------------------------------------------------------------
    public bool IsConnected
    {
        get { return m_connected; }
    }

    // =================================================================================================
    //   Connects to the device.
    //   TODO : Replace the code with what is needed for your device.
    //
    // Return : true if connection was successful, false in case of failure.
    // -------------------------------------------------------------------------------------------------
    public bool Connect()
    {
        // If already connected, do nothing and return success.
        if ( IsConnected )
        {
            return true;
        }

        m_dialog = new CDlgScanControl();
        m_connected = true;

        return m_connected;
    }

    // =================================================================================================
    //   Disconnects from the device.
    //   TODO : Replace the code with what is needed for your device.
    //
    // Return : true if disconnection was successful, false in case of failure.
    // -------------------------------------------------------------------------------------------------
    public bool Disconnect()
    {
        m_connected = false;

        if ( m_dialog != null )
        {
            m_dialog.Close();
            m_dialog = null;
        }

        return !m_connected;
    }

    // =================================================================================================
    //   Put the device in scan mode.
    //   TODO : Replace the code with what is needed for your device.
    //
    // Return : true if scanning was successfully started, false in case of failure.
    // -------------------------------------------------------------------------------------------------
    public bool ScanStart()
    {
        System.Diagnostics.Debug.Assert( m_connected && ( m_dialog != null ) );

        // Using the overload of Show that takes a parameter will use the "main window" when we
        // pass null. This way the window cannot end up hidden behind the main window.
        System.Windows.Forms.IWin32Window owner = null;
        m_dialog.Show( owner );

        return true;
    }

    // =================================================================================================
    //   Exit scanning mode.
    //   TODO : Replace the code with what is needed for your device.
    //
    // Return : true if successful, false in case of failure.
    // -------------------------------------------------------------------------------------------------
    public bool ScanEnd()
    {
        System.Diagnostics.Debug.Assert( m_connected && ( m_dialog != null ) );
        m_dialog.Hide();
        return true;
    }

    // =================================================================================================
    //   Return the next scan line. This function is repeatedly called by the reader thread in the
    //   receiver. This function should not be blocking so that the reader thread can be stopped at
    //   anytime; if no data is available is should simply return.
    //
    //   TODO : Replace the code with what is needed for your device. This example returns only one
    //          line at a time but you may chose to return many.
    //
    // Return : A scan line, or null if no data is currently available.
    // -------------------------------------------------------------------------------------------------
    public CScanLine NextLineGet()
    {
        System.Diagnostics.Debug.Assert( m_connected && ( m_dialog != null ) );

        // Sleep to simulate a device that cannot provide lines at infinite speed.
        if ( m_passIsStarted )
        {
            System.Threading.Thread.Sleep( 10 );
        }
        else
        {
            // We generate data slower in "cursor" mode.
            System.Threading.Thread.Sleep( 75 );
        }

        // If scan end was requested, just return an empty line of type "ScanEnd".
        if ( m_dialog.EndScanRequested )
        {
            return new CScanLine( EScanLineType.ScanEnd );
        }

        EScanLineType lineType = EScanLineType.Normal;

        if ( !m_dialog.Visible || !m_dialog.PassIsStarted )
        {
            // If in a previous call we signaled a pass start, then now we must signal a pass end.
            if ( m_passIsStarted )
            {
                m_passIsStarted = false;
                return new CScanLine( EScanLineType.PassEnd );
            }
        }
        else if ( !m_passIsStarted )
        {
            lineType = EScanLineType.PassStart;
            m_passIsStarted = true;
        }

        // Prepare a new line.
        CScanLine result = new CScanLine( lineType );

        // For this example the normal vector is hard-coded to +Z.
        // TODO: Replace with data from the device.
        result.m_x = 0;
        result.m_y = 0;
        result.m_z = 1;

        // We simulate a line of data.
        // TODO: Replace with data from the device.

        int count = m_lineCount;
        if ( !m_passIsStarted )
        {
            ++m_cursorOffset;
            count += m_cursorOffset;
        }

        const int nPoints = 40;
        result.m_data = new CPoint[ nPoints ];

        // We go in the opposite way for odd and even columns to better simulate
        // real data. Otherwise processing on the application side will not be able
        // to properly mesh and will eliminate lines.
        int  column = count / COLUMN_SIZE;
        int  row    = ( count % COLUMN_SIZE );
        if ( ( column & 1 ) != 0 )
        {
            row = COLUMN_SIZE - 1 - row;
        }

        for( int j = 0; j < nPoints; ++j )
        {
            // Generate "step" lines in a regular array.
            result.m_data[ j ] = new CPoint( column * 50 + j*1.0f,
                                             row * 1.0f,
                                             j < nPoints/2 ? 0 : 2 );
        }

        if ( m_passIsStarted )
        {
            ++m_lineCount;
        }
        else if ( m_cursorOffset > 25 )
        {
            m_cursorOffset = 0;
        }

        return result;
    }
}

}
