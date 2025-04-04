{**************************************************************************************************}
{                                                                                                  }
{ Project JEDI Code Library (JCL)                                                                  }
{                                                                                                  }
{ The contents of this file are subject to the Mozilla Public License Version 1.1 (the "License"); }
{ you may not use this file except in compliance with the License. You may obtain a copy of the    }
{ License at http://www.mozilla.org/MPL/                                                           }
{                                                                                                  }
{ Software distributed under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF   }
{ ANY KIND, either express or implied. See the License for the specific language governing rights  }
{ and limitations under the License.                                                               }
{                                                                                                  }
{ The Original Code is jcl.inc                                                                     }
{                                                                                                  }
{ The Initial Developer of the Original Code is Marcel van Brakel.                                 }
{ Portions created by Marcel van Brakel are Copyright (C) Marcel van Brakel.                       }
{                                                                                                  }
{ Contributors:                                                                                    }
{   Marcel van Brakel                                                                              }
{   Matthias Thoma (mthoma)                                                                        }
{   Petr Vones                                                                                     }
{   Robert Marquardt (marquardt)                                                                   }
{   Robert Rossmair (rrossmair)                                                                    }
{   Florent Ouchet (outchy)                                                                        }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ This include file defines various JCL specific defines.                                          }
{ The more generic JCL defines are defined in jcl.inc and the generic defines in the jedi.inc file }
{ which is shared with the JEDI VCL.                                                               }
{                                                                                                  }
{**************************************************************************************************}
{                                                                                                  }
{ This file is filled by the JCL installer, all the changes made in its content will be lost the   }
{ next time the JCL is installed.                                                                  }
{                                                                                                  }
{**************************************************************************************************}

// $Id$

// Math precision selection, mutually exclusive
// FPC does not support EXTENDED when targetting x86_64, MATH_DOUBLE_PRECISION is the default in this situation
{$DEFINE MATH_EXTENDED_PRECISION} // default
{.$DEFINE MATH_DOUBLE_PRECISION}
{.$DEFINE MATH_SINGLE_PRECISION}


// Math functions takes care of infinites and NaN
{$DEFINE MATH_EXT_EXTREMEVALUES}


// JclHookExcept support for hooking exceptions from DLLs
{.$DEFINE HOOK_DLL_EXCEPTIONS}


//Threadsafe directive
{$DEFINE THREADSAFE}


// To exclude obsolete code from compilation, remove the point from the line below
{$DEFINE DROP_OBSOLETE_CODE}


//Support for JclUnitVersioning.pas, not supported by Delphi 2005 (automatically disabled afterward)
{$DEFINE UNITVERSIONING}


// debug sources
// defining these symbols will the debug source to be automatically registered
{.$DEFINE DEBUG_NO_BINARY}
{.$DEFINE DEBUG_NO_TD32}     // automatically defined for FPC
{.$DEFINE DEBUG_NO_MAP}
{.$DEFINE DEBUG_NO_EXPORTS}
{.$DEFINE DEBUG_NO_SYMBOLS}


// PCRE options, mutually exclusive
// IMPORTANT: The static link works only for Delphi 2005 and newer
//            (an internal error is raised on other compilers)
// Only one of the following defines can be defined at a time
//   static link: PCRE_STATICLINK
//   static dll import: PCRE_LINKDLL
//   dynamic dll import: PCRE_LINKONREQUEST
//   RTL's RegularExpressionsAPI: PCRE_RTL

{$DEFINE PCRE_STATICLINK}
{.$DEFINE PCRE_LINKDLL}
{.$DEFINE PCRE_LINKONREQUEST} // default
{.$DEFINE PCRE_RTL} // DXE and newer

// ANSI/UTF8 PCRE
{$DEFINE PCRE_8}
// UCS2/UTF16 enabled PCRE
{$DEFINE PCRE_16} // only valid when PCRE_STATICLINK is enabled, the RTL does not support it and the DLL found over the internet are completly outdated.

// use PCRE16 when available rather than good old PCRE8
{$DEFINE PCRE_PREFER_16}

// BZIP2 options, mutually exclusive

{$DEFINE BZIP2_STATICLINK} // default
{.$DEFINE BZIP2_LINKDLL}
{.$DEFINE BZIP2_LINKONREQUEST}


// ZLIB options, mutually exclusive

{$DEFINE ZLIB_STATICLINK} // default
{.$DEFINE ZLIB_LINKDLL}
{.$DEFINE ZLIB_LINKONREQUEST}
{.$DEFINE ZLIB_RTL} // DXE2 and newer only


// Unicode options
// use RTL Character Database rather than JCL one, less accurate but reduce executable size
{.$DEFINE UNICODE_RTL_DATABASE}

// insert a replacement character if sequence is corrupted rather than raising an exception
{$DEFINE UNICODE_SILENT_FAILURE}

// defines resource compression (uncompressed, compressed with ZLib, compressed with BZip2), mutually exclusive
{$DEFINE UNICODE_RAW_DATA} // default
{.$DEFINE UNICODE_ZLIB_DATA}
{.$DEFINE UNICODE_BZIP2_DATA}


// container options
// define mapping of TJclStr* containers to TJclAnsiStr* or TJclWideStr* (mutually exclusive)
{.$DEFINE CONTAINER_ANSISTR} // default for D2007 and older
{.$DEFINE CONTAINER_WIDESTR}
{$DEFINE CONTAINER_UNICODESTR} // default for D2009 and newer, not supported for Delphi 2007 and older
{.$DEFINE CONTAINER_NOSTR}


// 7Zip options, mutually exclusive
// IMPORTANT: The static link is not supported yet

{.$DEFINE 7ZIP_STATICLINK} // not supported yet
{.$DEFINE 7ZIP_LINKDLL}
{$DEFINE 7ZIP_LINKONREQUEST} // default
