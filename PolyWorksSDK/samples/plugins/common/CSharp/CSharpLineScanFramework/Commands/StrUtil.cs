// =================================================================================================
// String utilities.
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{
    public static class StrUtil
    {
        public static string StrNonNull(string str_)
        {
            if(str_ == null)
            {
                return str_ = string.Empty;
            }
            return str_;
        }
    }
}
