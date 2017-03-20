// ***********************************************************************
// Assembly         :
// Author           : Christos Gkantsidis
// Created          : 03-18-2017
//
// Last Modified By : Christos Gkantsidis
// Last Modified On : 03-18-2017
// ***********************************************************************
// <copyright file="FileUtilities.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary>Utilities for accessing files</summary>
// ***********************************************************************
#pragma once

#include <filesystem>
#include <string>
#include "LoaderException.h"

/// <summary>
/// The Loader namespace.
/// </summary>
namespace Loader
{

class InvalidFileException
    : LoaderException
{
public:
    InvalidFileException(const std::string& filename)
        : LoaderException()
        , _filename{ filename }
    {}

    InvalidFileException(const LPCWCHAR filename)
        : LoaderException()
        , _filename{ filename }
    {}

private:
    const std::string& _filename;
};

/// <summary>
/// Utility methods for dealing with the filesystem.
/// </summary>
class FileUtilities sealed
{
public:
    using Path = std::experimental::filesystem::path;

    static bool IsValidFile(const std::string& filename);
    static Path GetFullName(const std::string& filename);
    static PTCHAR GetFullNameAsTChar(const std::string& filename);
    static Path GetParentDirectory(const std::string& filename);
    static Path GetDirectory(const std::string& filename);

private:
    /// <summary>
    /// Initializes a new instance of the <see cref="FileUtilities"/> class.
    /// </summary>
    FileUtilities() = delete;
};

}
