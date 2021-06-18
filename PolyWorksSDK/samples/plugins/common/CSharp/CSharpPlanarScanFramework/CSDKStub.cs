// =================================================================================================
//   CSDKStub class
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Linq;
using System.Drawing;
using System.Threading.Tasks;
using System.Threading;

namespace CompanyNameCsPlanarScanner
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
    private const int MAX_GRID_POINTS = 32400;
    private bool m_connected = false;
    private CancellationTokenSource m_cancelSource = new CancellationTokenSource();
    private CReceiver m_receiver;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : host_     : Acces to host application functionalities (must not be null).
    // Parameter : settings_ : Access to the plug-in settings (must not be null).
    // -------------------------------------------------------------------------------------------------
    public CSDKStub(CReceiver receiver_)
    {
        m_receiver = receiver_;
    }
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
        m_cancelSource.Dispose();
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
        System.Diagnostics.Debug.Assert( m_connected );
        CancellationToken ct = m_cancelSource.Token;
        Task task = new Task(
                () =>
                {
                    CScanData data = null;
                    while (data == null)
                    {
                        if ( ct.IsCancellationRequested )
                        {
                            return;
                        }
                        data = AcquiredDataGet();
                    }
                    m_receiver.OnDataAcquired( data );
                }
        );
        task.Start();
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
        m_cancelSource.Cancel();
        m_cancelSource.Dispose();
        m_cancelSource = new CancellationTokenSource();
        return true;
    }

    // =================================================================================================
    //   Get the grid data. This function is called asynchronously by scan start.
    //
    //   TODO : Replace the code with what is needed for your device. This example returns only one
    //          line at a time but you may chose to return many.
    //
    // Return : Grid data, or null if no data is currently available.
    // -------------------------------------------------------------------------------------------------
    public CScanData AcquiredDataGet()
    {
        System.Diagnostics.Debug.Assert( m_connected );

        // Size of the planar grid
        const short width = 200;
        const short height = 200;

        // Initialize with the digitizing vector and the size
        // For this example the normal vector is hard-coded to -Z.
        // TODO: Replace with data from the device.'
        CScanData result = new CScanData( width, height, 0.0f, 0.0f, -1.0f  );

        // TODO: Remove. Used for the simulator
        // SIMULATION CODE BEGIN
        // Create simulation data, format : x,y,z,row,col with grid row, col as key and 3d point as value
        Random random = new Random();
        foreach ( short x in Enumerable.Range( 10, width - 10 ).ToArray() )
        {
            foreach (short y in Enumerable.Range( 10, height - 10 ).ToArray() )
            {
                result.m_points.Add( new Point( x, y ), Tuple.Create( ( float ) x, ( float ) y, ( float ) random.NextDouble() ) );
            }
        }
        // SIMULATION CODE END
        return result;
    }
}
}
