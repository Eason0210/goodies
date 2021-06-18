// =================================================================================================
//   CCompanyNameCSharpPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =================================================================================================
    //   Plug-in C# interface used to connect to a PolyWorks module.
    // -------------------------------------------------------------------------------------------------
    public class CCompanyNameCSharpPlugin : IMM.IPlugin
    {
        public bool Load()
        {
            return IMM.FnIDrawNodes.DrawNodesGet() != null;
        }

        public bool Unload()
        {
            return true;
        }

        public void Dispose()
        {}
    }

    // =================================================================================================
    //   Plug-in C# methods used to connect to a PolyWorks module.
    // -------------------------------------------------------------------------------------------------
    public static class Connection
    {
        public static void SDKVersionGet(ref ushort major_, ref ushort minor_, ref ushort dot_)
        {
            major_ = IMM.Version.SDK_VERSION_MAJOR;
            minor_ = IMM.Version.SDK_VERSION_MINOR;
            dot_ = IMM.Version.SDK_VERSION_DOT;
        }

        public static IMM.IPlugin PluginInterfaceGet()
        {
            if (PluginContainer.g_thePlugin == null)
            {
                PluginContainer.g_thePlugin = new CCompanyNameCSharpPlugin();
            }
            return PluginContainer.g_thePlugin;
        }
    }

    // =================================================================================================
    //   Contains an instance of the C# plug-in.
    // -------------------------------------------------------------------------------------------------
    public static class PluginContainer
    {
        public static CCompanyNameCSharpPlugin g_thePlugin;
    }
}
