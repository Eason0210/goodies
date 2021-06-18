// =================================================================================================
//   Utility classes to support the property grid in the Options dialog.
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Base class that defines the interface common to all properties.
// -------------------------------------------------------------------------------------------------
abstract class CPropertyBase
{
    protected string m_command;

    // =================================================================================================
    //   Constructor. Protected because this class must be derived.
    //
    // Parameter : command_                : The command to use to get/set the property's value.
    // Parameter : group_                  : The property group that owns this property. The constructed
    //                                       property will automatically be added to this group.
    // -------------------------------------------------------------------------------------------------
    protected CPropertyBase( string command_, List< CPropertyBase > group_ )
    {
        m_command = command_;
        group_.Add( this );
    }

    // =================================================================================================
    //   Interface definition for a function indicating if the property was modified since its
    // initialization.
    //
    // Return : true if the property was modified, false if it still has its original value.
    // -------------------------------------------------------------------------------------------------
    protected abstract bool IsModified();

    // =================================================================================================
    //   Interface definition for a function converting the property's current value to a string
    // representation appropriate to use as an MSCL argument.
    //
    // Return : The converted value.
    // -------------------------------------------------------------------------------------------------
    protected abstract string ValueToMSCLArg();

    // =================================================================================================
    //   Interface definition for a function converting a string to the property's value type and
    // storing the converted value in the property.
    //
    // Parameter : valueStr_ : The string to convert.
    // -------------------------------------------------------------------------------------------------
    protected virtual void StringToValue( string valueStr_ )
    {
        // If a class can call this function, it must overload it!.
        System.Diagnostics.Debug.Assert( false );
    }

    // =================================================================================================
    //   Use the configured command to retrieve the current value and store it internally.
    //
    // Parameter : host_ : Host object used to retrieve the value.
    // -------------------------------------------------------------------------------------------------
    public virtual void GetFromCommand( IM.CIMHost host_ )
    {
        string valueStr = host_.ValueStrGet( m_command + Consts.CMD_GET_SUFFIX, "", false );

        StringToValue( valueStr );
    }

    // =================================================================================================
    //   Use the configured command to write the current value (only if value has changed).
    //
    // Parameter : host_ : Host object used to write the value.
    //
    // Return : true if the value was successfully updated, false in case of failure.
    // -------------------------------------------------------------------------------------------------
    public bool SetToCommand( IM.CIMHost host_ )
    {
        if ( IsModified() )
        {
            return host_.ValueSet( m_command, ValueToMSCLArg(), true, true );
        }

        return true;
    }
}

// =================================================================================================
//   Generic base class that implements some behavior common to all types.
// -------------------------------------------------------------------------------------------------
class CProperty< T > : CPropertyBase
{
    protected T m_originalValue;
    public    T m_value;

    // =================================================================================================
    //   Forwarding constructor to base class.
    //
    // Parameter : command_ : See base class.
    // Parameter : group_   : See base class.
    // -------------------------------------------------------------------------------------------------
    public CProperty( string command_, List< CPropertyBase > group_ ) :
        base( command_, group_ )
    {
    }

    // =================================================================================================
    //   Indicates if the current value is different than the original value.
    //
    // Return : true if the property was modified, false if it still has its original value.
    // -------------------------------------------------------------------------------------------------
    protected override bool IsModified()
    {
        return !m_value.Equals( m_originalValue );
    }

    // =================================================================================================
    //   Convert the current value to its representation for calling the command.
    //
    // Return : A string containing the current value as appropriate for an MSCL argument.
    // -------------------------------------------------------------------------------------------------
    protected override string ValueToMSCLArg()
    {
        return m_value.ToString();
    }

    // =================================================================================================
    //   Convert an MSCL string to its T equivalent and store it in the internal values.
    //
    // Parameter : valueStr_ : The string to convert.
    // -------------------------------------------------------------------------------------------------
    protected override void StringToValue( string valueStr_ )
    {
        m_value = (T) Convert.ChangeType( valueStr_, typeof( T ) );
        m_originalValue = m_value;
    }
}

// =================================================================================================
//   Specialization for type bool that must be converted to "On" and "Off" for MSCL.
// -------------------------------------------------------------------------------------------------
class CPropertyBool : CProperty< bool >
{
    // =================================================================================================
    //   Forwarding constructor to base class.
    //
    // Parameter : command_ : See base class.
    // Parameter : group_   : See base class.
    // -------------------------------------------------------------------------------------------------
    public CPropertyBool( string command_, List< CPropertyBase > group_ ) :
        base( command_, group_ )
    {
    }

    // =================================================================================================
    //   Convert the current value to its representation for calling the command.
    //
    // Return : A string containing the current value as appropriate for an MSCL argument.
    // -------------------------------------------------------------------------------------------------
    protected override string ValueToMSCLArg()
    {
        return IM.Utils.Quote( IM.Utils.BoolToMSCL( m_value ) );
    }

    // =================================================================================================
    //   Convert an MSCL string to its bool equivalent and store it in the internal values.
    //
    // Parameter : valueStr_ : The string to convert to its boolean equivalent.
    // -------------------------------------------------------------------------------------------------
    protected override void StringToValue( string valueStr_ )
    {
        bool? value = IM.Utils.MSCLToBool(valueStr_);
        if ( value.HasValue )
        {
            m_value = value.Value;
            m_originalValue = m_value;
        }
    }
}

// =================================================================================================
//   Specialization for enums that must tranform from a numerical value to a string representation
// for the property grid and MSCL.
// -------------------------------------------------------------------------------------------------
class CPropertyEnum< T > : CProperty< T > where T : struct
{
    // =================================================================================================
    //   Forwarding constructor to base class.
    //
    // Parameter : command_ : See base class.
    // Parameter : group_   : See base class.
    // -------------------------------------------------------------------------------------------------
    public CPropertyEnum( string command_, List< CPropertyBase > group_ ) :
        base( command_, group_ )
    {
    }

    // =================================================================================================
    //   Convert the current value to its representation for calling the command.
    //
    // Return : A string containing the enum value as appropriate for an MSCL argument.
    // -------------------------------------------------------------------------------------------------
    protected override string ValueToMSCLArg()
    {
        return IM.Utils.Quote( IM.Utils.EnumToMSCL( m_value ) );
    }

    // =================================================================================================
    //   Find the enum value corresponding to valueStr_ and store it in the internal values.
    //
    // Parameter : valueStr_ : The string to convert to its enum value.
    // -------------------------------------------------------------------------------------------------
    protected override void StringToValue( string valueStr_ )
    {
        T? value = IM.Utils.MSCLToEnum<T>(valueStr_);
        if ( value.HasValue )
        {
            m_value = value.Value;
            m_originalValue = m_value;
        }
    }
}

// =================================================================================================
//   Specialization for Color to use the proper format for MSCL.
// -------------------------------------------------------------------------------------------------
class CPropertyColor : CProperty< System.Drawing.Color >
{
    // =================================================================================================
    //   Forwarding constructor to base class.
    //
    // Parameter : command_ : See base class.
    // Parameter : group_   : See base class.
    // -------------------------------------------------------------------------------------------------
    public CPropertyColor( string command_, List< CPropertyBase > group_ ) :
        base( command_, group_ )
    {
    }

    // =================================================================================================
    //   Converts the property value to its format as an MSCL argument. For this type it is actually
    // three arguments.
    //
    // Return : A string that can be used in the arguments part of a command invocation.
    // -------------------------------------------------------------------------------------------------
    protected override string ValueToMSCLArg()
    {
        return IM.Utils.ArgumentsBuild( "", m_value.R, m_value.G, m_value.B );
    }

    // =================================================================================================
    //   This is an override for this type as the format is different from other property types.
    //
    // Parameter : host_ : Host object to be able to retrieve the value.
    // -------------------------------------------------------------------------------------------------
    public override void GetFromCommand( IM.CIMHost host_ )
    {
        int[] values = host_.ValuesIntGet( m_command + Consts.CMD_GET_SUFFIX, 3, false );
        if ( values != null ) 
        {
            m_value = System.Drawing.Color.FromArgb( values[ 0 ], values[ 1 ], values[ 2 ] );
            m_originalValue = m_value;
        }
    }
}

// =================================================================================================
//   Simple class to group properties so that we can read when opening the dialog and write them
// when the user confirms.
// -------------------------------------------------------------------------------------------------
class CPropertyGroup
{
    private   IM.CIMHost            m_host;
    protected List< CPropertyBase > m_properties = new List< CPropertyBase >();

    // =================================================================================================
    //   Constructor
    //
    // Parameter : host_ : Access to the host object (to call commands).
    // -------------------------------------------------------------------------------------------------
    protected CPropertyGroup( IM.CIMHost host_ )
    {
        m_host = host_;
    }

    // =================================================================================================
    //   Ask all properties to read their value (via their assigned command).
    // -------------------------------------------------------------------------------------------------
    protected void ReadProperties()
    {
        foreach( CPropertyBase property in m_properties )
        {
            property.GetFromCommand( m_host );
        }
    }

    // =================================================================================================
    //   Ask all properties to write their value (via their assigned command).
    //
    // Return : true if all properties were successfully updated, false otherwise. The process is
    //          aborted as soon as one property fails.
    // -------------------------------------------------------------------------------------------------
    public bool WriteProperties()
    {
        foreach( CPropertyBase property in m_properties )
        {
            if ( !property.SetToCommand( m_host ) )
            {
                return false;
            }
        }

        return true;
    }
}

// =================================================================================================
//   By default when converting an enum to a string .NET will use the C# label directly.
// Here we derive a custom type converter to use the Description attribute to be able to provide
// the exact string required for MSCL.
// -------------------------------------------------------------------------------------------------
class CCustomEnumConverter : EnumConverter
{
    private Type enumType;

    // =================================================================================================
    //   Constructor to note the enum type supported.
    //
    // Parameter : type_ : The enum type this EnumConverter works for.
    // -------------------------------------------------------------------------------------------------
    public CCustomEnumConverter( Type type_ ) : base( type_ )
    {
        enumType = type_;
    }

    // =================================================================================================
    //   Indicates if we can convert to a specific type.
    //
    // Parameter : context_  : See .NET documentation
    // Parameter : destType_ : See .NET documentation
    //
    // Return : bool if the conversion is possible (i.e. the destination type is string), false otherwise.
    // -------------------------------------------------------------------------------------------------
    public override bool CanConvertTo( ITypeDescriptorContext context_, Type destType_ )
    {
        return destType_ == typeof( string );
    }

    // =================================================================================================
    //   Converts a string value to its enum equivalent (if possible).
    //
    // Parameter : context_  : See .NET documentation
    // Parameter : culture_  : See .NET documentation
    // Parameter : value_    : See .NET documentation
    // Parameter : destType_ : See .NET documentation
    //
    // Return : The converted value, in our case an enum value.
    // -------------------------------------------------------------------------------------------------
    public override object ConvertTo( ITypeDescriptorContext           context_,
                                      System.Globalization.CultureInfo culture_,
                                      object value_,
                                      Type   destType_ )
    {
        // We use the Description attribute if present, otherwise let the standard conversion go.
        System.Reflection.FieldInfo info = enumType.GetField( Enum.GetName( enumType, value_ ) );

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
    //   Indicates if we can convert from a specific type.
    //
    // Parameter : context_ : See .NET documentation
    // Parameter : srcType_ : See .NET documentation
    //
    // Return : bool if the conversion is possible (i.e. the source type is string), false otherwise.
    // -------------------------------------------------------------------------------------------------
    public override bool CanConvertFrom( ITypeDescriptorContext context_, Type srcType_ )
    {
        return srcType_ == typeof( string );
    } 

    // =================================================================================================
    //   Convert a value_ from a source type back to the enum.
    //
    // Parameter : context_ : See .NET documentation
    // Parameter : culture_ : See .NET documentation
    // Parameter : value_   : See .NET documentation
    //
    // Return : The converted object (in our case a string).
    // -------------------------------------------------------------------------------------------------
    public override object ConvertFrom( ITypeDescriptorContext           context_,
                                        System.Globalization.CultureInfo culture_,
                                        object value_ )
    {
        // Loop to find value_ in the possible values of the enumeration.
        foreach( System.Reflection.FieldInfo info in enumType.GetFields() )
        {
            var attribute = (DescriptionAttribute) Attribute.GetCustomAttribute( info, 
                                                                                 typeof( DescriptionAttribute ) ); 
            if ( ( attribute != null ) && ( (string)value_ == attribute.Description ) )
            {
                return Enum.Parse( enumType, info.Name );
            }
        }

        // Fallback, it may work if some member of the enumeration doesn't have the Description attribute.
        return Enum.Parse( enumType, (string) value_ );
    }
}

// =================================================================================================
//   When using a compound property, by default .NET will display the class name in the grid.
// This derived class overrides ConvertTo so that the cell is left empty instead.
// -------------------------------------------------------------------------------------------------
class IMExpandableObjectConverter : ExpandableObjectConverter
{
    // =================================================================================================
    //   This override prevents the PropertyGrid from displaying the full type name in the value cell.
    //
    // Parameter : context_         : See .NET documentation
    // Parameter : culture_         : See .NET documentation
    // Parameter : value_           : See .NET documentation
    // Parameter : destinationType_ : See .NET documentation
    //
    // Return : The conversion to the requested type.
    // -------------------------------------------------------------------------------------------------
    public override object ConvertTo( ITypeDescriptorContext           context_,
                                      System.Globalization.CultureInfo culture_,
                                      object value_,
                                      Type   destinationType_ )
    {
        if ( destinationType_ == typeof( string ) )
        {
            return "";
        }

        return base.ConvertTo( context_, culture_, value_, destinationType_ );
    }
}

// =================================================================================================
//   By default .NET will only display needed decimal digits which make floating-point properties
// with an whole number value look like an integer. Here we force to always have 3 decimal digits
// for double properties.
// -------------------------------------------------------------------------------------------------
class FloatNumberTypeConverter : DoubleConverter
{
    // =================================================================================================
    //   This override forces 3 decimal digits for double numbers.
    //
    // Parameter : context_         : See .NET documentation
    // Parameter : culture_         : See .NET documentation
    // Parameter : value_           : See .NET documentation
    // Parameter : destinationType_ : See .NET documentation
    //
    // Return : The conversion to the requested type.
    // -------------------------------------------------------------------------------------------------
    public override object ConvertTo( ITypeDescriptorContext           context_,
                                      System.Globalization.CultureInfo culture_,
                                      object                           value_,
                                      Type                             destinationType_ )
    {
        if ( ( destinationType_ == typeof( string ) ) && ( value_ is double ) )
        {
            double value = (double) value_;

            return value.ToString( "F3" );
        }

        return base.ConvertTo( context_, culture_, value_, destinationType_ );
    }
}

}
