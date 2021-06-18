// =================================================================================================
//   CComMessageFilter class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace IM
{

// Some declarations needed to map to the underlying COM concept of a message filter.
// See MSDN for more information.
[ ComImport(),
    Guid( "00000016-0000-0000-C000-000000000046" ),
    InterfaceTypeAttribute( ComInterfaceType.InterfaceIsIUnknown ) ]
interface IMessageFilter
{
    [PreserveSig]
    int HandleInComingCall( int dwCallType, IntPtr hTaskCaller, int dwTickCount, IntPtr lpInterfaceInfo );

    [PreserveSig]
    int RetryRejectedCall( IntPtr hTaskCallee, int dwTickCount, int dwRejectType );

    [PreserveSig]
    int MessagePending( IntPtr hTaskCallee, int dwTickCount, int dwPendingType );
}

enum SERVERCALL
{
    SERVERCALL_ISHANDLED  = 0,
    SERVERCALL_REJECTED   = 1,
    SERVERCALL_RETRYLATER = 2
}

enum PENDINGMSG
{
    PENDINGMSG_CANCELCALL     = 0,
    PENDINGMSG_WAITNOPROCESS  = 1,
    PENDINGMSG_WAITDEFPROCESS = 2
}

// =================================================================================================
//   Class implementing a COM message filter. This is needed so that COM calls from a worker thread
// do not throw an exception and instead retry if the main thread is busy.
//
// This is a simplified implementation that does not handle all possible cases but is usually
// sufficient for the needs of a PolyWorks plug-in.
//
// IMPORTANT : This class should always be used in a "using" scope so that it deterministically
//             registers and unregisters its filter.
// -------------------------------------------------------------------------------------------------
class CComMessageFilter : IMessageFilter, IDisposable
{
    private const int RETRY_TIME_IN_MS = 200;

    [DllImport("Ole32.dll")]
    private static extern int CoRegisterMessageFilter( IMessageFilter newFilter, out IMessageFilter oldFilter );

    private IMessageFilter m_previousFilter;

    // =================================================================================================
    //   Private Constructor. Immediately register the filter.
    // -------------------------------------------------------------------------------------------------
    private CComMessageFilter()
    {
        CoRegisterMessageFilter(this, out m_previousFilter);
    }

    // =================================================================================================
    //   Creates a CComMessageFilter or null if creation failed.
    // Should be used like this: using ( CComMessageFilter.Create() ) {}
    // -------------------------------------------------------------------------------------------------
    public static CComMessageFilter Create()
    {
        if ( Thread.CurrentThread.GetApartmentState() == ApartmentState.STA )
        {
            return new CComMessageFilter();
        }
        return null;
    }

    // =================================================================================================
    //   Implementation of the IDisposable interface. Unregister the filter.
    // -------------------------------------------------------------------------------------------------
    public void Dispose()
    {
        IMessageFilter oldFilter = null;
        CoRegisterMessageFilter( m_previousFilter, out oldFilter );
    }

    // =================================================================================================
    //   Implementation of IMessageFilter. See Microsoft documentation.
    // In our case we accept all calls.
    // -------------------------------------------------------------------------------------------------
    int IMessageFilter.HandleInComingCall( int dwCallType, IntPtr hTaskCaller, int dwTickCount, IntPtr lpInterfaceInfo )
    {
        return (int) SERVERCALL.SERVERCALL_ISHANDLED;
    }

    // =================================================================================================
    //   Implementation of IMessageFilter. See Microsoft documentation.
    // In our case we always ask for a retry when it is possible.
    // -------------------------------------------------------------------------------------------------
    int IMessageFilter.RetryRejectedCall( IntPtr hTaskCallee, int dwTickCount, int dwRejectType )
    {
        if ( dwRejectType == (int) SERVERCALL.SERVERCALL_RETRYLATER )
        {
            return RETRY_TIME_IN_MS;
        }

        return -1;
    }

    // =================================================================================================
    //   Implementation of IMessageFilter. See Microsoft documentation.
    // -------------------------------------------------------------------------------------------------
    int IMessageFilter.MessagePending( IntPtr hTaskCallee, int dwTickCount, int dwPendingType )
    {
        return (int) PENDINGMSG.PENDINGMSG_WAITDEFPROCESS;
    }
}

}
