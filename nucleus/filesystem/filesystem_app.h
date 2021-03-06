/**
 * (c) 2014-2016 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#pragma once

#include "nucleus/common.h"
#include "nucleus/filesystem/device.h"
#include "nucleus/filesystem/directory.h"
#include "nucleus/filesystem/file.h"
#include "nucleus/filesystem/path.h"

#include <memory>
#include <vector>

namespace fs {

enum AppFileSystemLocation {
    APP_LOCATION_LOCAL,    // Application data on the current device
    APP_LOCATION_ROAMING,  // Application data synchronized across multiple devices
    APP_LOCATION_TEMP,     // Temporary location
};

/**
 * Application File System
 * =======================
 * Allows access to the application locations potentially managed by
 * the underlying host operating system
 */
class AppFileSystem {
    using Location = AppFileSystemLocation;

public:
    /**
     * Return absolute path of the specified application location
     * @param[in]  location  Application folder
     */
    static Path getPath(Location location);

    static std::unique_ptr<File> openFile(Location location, const Path& path, OpenMode mode);
    static bool createFile(Location location, const Path& path);
    static bool existsFile(Location location, const Path& path);
    static bool removeFile(Location location, const Path& path);

    static std::vector<DirectoryEntry> listDirectory(Location location, const Path& path);
};

}  // namespace fs
