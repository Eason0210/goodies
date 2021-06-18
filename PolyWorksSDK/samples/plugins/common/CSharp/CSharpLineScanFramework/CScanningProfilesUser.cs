// =================================================================================================
//   CScanningProfilesUser class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System.Collections.Generic;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Class used to manage scanning profiles.
// -------------------------------------------------------------------------------------------------
abstract class CScanningProfilesUser
{
    protected List< string > m_profileCmdArgNames;
    protected List< string > m_profileDisplayNames;
    protected List< string > m_profileAdditionalInfos;
    protected string         m_currentProfile;

    // =================================================================================================
    //   Sets available scanning profiles.
    //
    // Parameter : profileCmdArgNames_    : Profile names used for command arguments
    // Parameter : profileDisplayNames_   : Profile display names
    // Parameter : profileAddtionalInfos_ : Profile additional information
    // Parameter : currentProfile_        : Current profile
    // -------------------------------------------------------------------------------------------------
    public void ScanningProfilesSet( System.Array profileCmdArgNames,
                                     System.Array profileDisplayNames_,
                                     System.Array profileAdditionalInfos_,
                                     string       currentProfile_ )
    {
        m_profileCmdArgNames     = new List<string>();
        m_profileDisplayNames    = new List<string>();
        m_profileAdditionalInfos = new List<string>();
        m_currentProfile         = currentProfile_;

        foreach( string name in profileCmdArgNames )
        { 
            m_profileCmdArgNames.Add( name );
        }
        foreach( string name in profileDisplayNames_ )
        { 
            m_profileDisplayNames.Add( name );
        }
        foreach( string name in profileAdditionalInfos_ )
        { 
            m_profileAdditionalInfos.Add( name );
        }

        UpdateProfiles();
    }

    // =================================================================================================
    //   Gets available scanning profiles.
    //
    // Parameter : profileCmdArgNames_    : Profile names used for command arguments
    // Parameter : profileDisplayNames_   : Profile display names
    // Parameter : profileAddtionalInfos_ : Profile additional information
    // Parameter : currentProfile_        : Current profile
    // -------------------------------------------------------------------------------------------------
    public void ScanningProfilesGet( out List< string > profileCmdArgNames_,
                                     out List< string > profileDisplayNames_,
                                     out List< string > profileAdditionalInfos_,
                                     out string         currentProfiles_ )
    {
        profileCmdArgNames_     = m_profileCmdArgNames;
        profileDisplayNames_    = m_profileDisplayNames;
        profileAdditionalInfos_ = m_profileAdditionalInfos;
        currentProfiles_        = m_currentProfile;
    }

    public abstract void UpdateProfiles();
}

}