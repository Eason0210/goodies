// =================================================================================================
//   Some utility functions that do not belong in a specific class.
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.ComponentModel;

namespace IM
{

class Utils
{
    private static readonly string[] ON_OFF_CHOICE_STRINGS = { "On", "Off" };
    private const int                E_ON                  = 0;
    private const int                E_OFF                 = 1;

    // =================================================================================================
    //   Force the release of a COM object without waiting for the garbage collector and clears the
    // reference.
    //
    // Parameter : object_ : The object to release (can be null in which case nothing is done); on exit
    //                       this value is nulled.
    // -------------------------------------------------------------------------------------------------
    public static void COMObjectRelease< T >( ref T object_ ) where T : class
    {
        if ( object_ != null )
        {
            System.Runtime.InteropServices.Marshal.ReleaseComObject( object_ );
            object_ = null;
        }
    }

    // =================================================================================================
    //   Add double quotes around a string.
    //
    // Parameter : value_ : The value to quote.
    //
    // Return : The quoted string.
    // -------------------------------------------------------------------------------------------------
    public static string Quote( string value_ )
    {
        return "\"" + value_.ToString() + "\"";
    }

    // =================================================================================================
    //   Convert a boolean value to its "On"/"Off" representation for an MSCL command.
    //
    // Parameter : value_ : The value to convert.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    public static string BoolToMSCL( bool value_ )
    {
        return ON_OFF_CHOICE_STRINGS[ value_ ? E_ON : E_OFF ];
    }

    // =================================================================================================
    //   Convert an MSCL string containing "On" or "Off" to its bool equivalent.
    //
    // Parameter : str_ : The value to convert.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    public static Nullable<bool> MSCLToBool( string str_ )
    {
        if ( str_ == ON_OFF_CHOICE_STRINGS[ E_ON ] )
        {
            return true;
        }
        else if ( str_ == ON_OFF_CHOICE_STRINGS[ E_OFF ] )
        {
            return false;
        }
        return null;
    }

    // =================================================================================================
    //   Convert an MSCL string representing a "choice" argument to 
    // its corresponding enum value.
    //
    // Parameter : str_ : The value to convert.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    public static Nullable<T> MSCLToEnum< T >( string str_ ) where T : struct
    {
        string[] names = Enum.GetNames( typeof( T ) );

        foreach( string name in names )
        {
            System.Reflection.FieldInfo info = typeof( T ).GetField( name );

            var attribute = (DescriptionAttribute) Attribute.GetCustomAttribute( info, 
                                                                                 typeof( DescriptionAttribute ) );

            if ( ( attribute != null ) && ( str_ == attribute.Description ) )
            {
                return (T) Enum.Parse( typeof( T ), name );
            }
        }
        return null;
    }

    // =================================================================================================
    //   Convert an enum value to its string representation for an MSCL command. If the enum
    // value has a Description attribute, its value is used. Otherwise ToString is applied to the value.
    //
    // Parameter : value_ : The value to convert.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    public static string EnumToMSCL< T >( T value_ ) where T : struct
    {
        System.Reflection.FieldInfo info = typeof( T ).GetField( Enum.GetName( typeof( T ), value_ ) );

        var attribute = (DescriptionAttribute) Attribute.GetCustomAttribute( info, 
                                                                             typeof( DescriptionAttribute ) );
        if ( attribute != null )
        {
            return attribute.Description;
        }
        else
        {
            return value_.ToString();
        }
    }

    // =================================================================================================
    //   This is a special version of EnumToMSCL for CommandBuild where the enum is boxed in an object
    // reference.
    //
    // Parameter : value_ : The value to convert.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    private static string EnumToMSCL( object value_ )
    {
        Type type = value_.GetType();

        System.Reflection.FieldInfo info = type.GetField( Enum.GetName( type, value_ ) );

        if ( info == null )
        {
            return value_.ToString();
        }

        var attribute = (DescriptionAttribute) Attribute.GetCustomAttribute( info, 
                                                                             typeof( DescriptionAttribute ) );
        if ( attribute != null )
        {
            return attribute.Description;
        }
        else
        {
            return value_.ToString();
        }
    }

    // =================================================================================================
    //   Concatenate a series of arguments separated by commas for passing to an MSCL command.
    // This function will take care of adding the necessary decorations (commas, quotes).
    //
    // Parameter : preArgs_ : Arguments built elsewhere, allowing chaining of argument building.
    // Parameter : args_    : Any number of arguments.
    //
    // Return : A string formatted to pass as argument to an MSCL command.
    // -------------------------------------------------------------------------------------------------
    public static string ArgumentsBuild( string preArgs_, params object[] args_ )
    {
        string result = preArgs_;

        bool first = preArgs_.Length == 0;

        foreach( object arg in args_ )
        {
            if ( !first )
            {
                result += ",";
            }

            if ( arg is bool )
            {
                result += Quote( BoolToMSCL( (bool) arg ) );
            }
            else if ( arg is Enum )
            {
                result += Quote( EnumToMSCL( arg ) );
            }
            else
            {
                result += arg.ToString();
            }

            first = false;
        }

        return result;
    }

    // =================================================================================================
    //   Utility function to build a command from its name and a series of arguments.
    // This function will take care of adding the necessary decorations (parentheses, commas, quotes).
    //
    // Parameter : command_ : The command name
    // Parameter : preArgs_ : Arguments built elsewhere, allowing chaining of argument building.
    // Parameter : args_    : Any number of arguments.
    //
    // Return : The complete command invocation that can be passed to CIMHost.ExecuteCommand.
    // -------------------------------------------------------------------------------------------------
    public static string CommandBuild( string command_, string preArgs_, params object[] args_ )
    {
        string result = command_;

        if ( ( args_.Length > 0 ) || ( preArgs_.Length > 0 ) )
        {
            result += "(";
            result += ArgumentsBuild( preArgs_, args_ );
            result += ")";
        }

        return result;
    }

    // =================================================================================================
    //   Overload of CommandBuild for the most common case.
    //
    // Parameter : command_ : The command name
    // Parameter : args_    : Any number of arguments.
    //
    // Return : The complete command invocation that can be passed to CIMHost.ExecuteCommand.
    // -------------------------------------------------------------------------------------------------
    public static string CommandBuild( string command_, params object[] args_ )
    {
        return CommandBuild( command_, "", args_ );
    }

    // =================================================================================================
    //   Updates the changed items of the combobox list to avoid triggering 
	// a selection changed event and an infinite loop of event/reaction.
    //
    // Parameter : combo_          : The combobox to synchronize with the list.
    // Parameter : items_          : The list of strings to sync to.
    // Parameter : currentChoice_  : The current choice that should be selected. If this value is not
    //                               in items_, the behavior will depend on the next parameter.
    // Parameter : defaultChoice_  : If currentChoice_ is not in items_, this is the value that will
    //                               used as SelectedIndex.
    // -------------------------------------------------------------------------------------------------
    public static void ComboAndListSynchronize( System.Windows.Forms.ComboBox             combo_,
                                                System.Collections.Generic.List< string > items_,
                                                string                                    currentChoice_,
                                                int                                       defaultChoice_ )
    {
        int min = System.Math.Min( combo_.Items.Count, items_.Count );

        int selection = defaultChoice_;

        // First update items that are already in the combo and still in the list.
        int i = 0;
        for( ; i < min; ++i )
        {
            // If we update the selected item, it will change the selection
            // so only update if it has changed.
            if ( items_[ i ] != combo_.Items[ i ].ToString() )
            {
                combo_.Items[ i ] = items_[ i ];
            }

            // Verify if we are on the selection
            if ( items_[ i ] == currentChoice_ )
            {
                selection = i;
            }
        }

        // Then add new items in the list...
        for( ; i < items_.Count; ++i )
        {
            combo_.Items.Add( items_[ i ] );

            // Verify if we are on the selection
            if ( items_[ i ] == currentChoice_ )
            {
                selection = i;
            }
        }

        // ... or remove extra items in the combo.
        for( ; i < combo_.Items.Count; ++i )
        {
            combo_.Items.RemoveAt( i );
        }

        // Finally update the selection.
        combo_.SelectedIndex = selection;
    }

    // =================================================================================================
    //   Converts an angle from degrees to radian.
    //
    // Parameter : angle_ : The value to convert.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    public static double DegToRad( double angle_ )
    {
        return angle_ * Math.PI / 180.0f;
    }

    // =================================================================================================
    //   Squares a value
    //
    // Parameter : value_ : The value to square.
    //
    // Return : value_ multiplied by itself.
    // -------------------------------------------------------------------------------------------------
    public static double Square( double value_ )
    {
        return value_ * value_;
    }
}

}
