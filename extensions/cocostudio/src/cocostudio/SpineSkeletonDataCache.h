#ifndef _SPINESKELETONDATACACHE_H_
#define _SPINESKELETONDATACACHE_H_

#if defined(AX_ENABLE_EXT_SPINE)
#include <cocos2d.h>
#include "spine/spine.h"
#include "spine/spine-cocos2dx.h"
#include "CocosStudioExport.h"
#include <functional>

#if !defined(AX_SPINE_VERSION) || AX_SPINE_VERSION >= 0x030700
class CCS_DLL SpineSkeletonDataCache
{
public:
    class SkeletonData : public ax::Object
    {
    public:
        SkeletonData(spine::SkeletonData* d, spine::AttachmentLoader* loader) : data(d), attachmentLoader(loader) {}
        ~SkeletonData()
        {
            if (data != nullptr)
                delete (data);
            if (attachmentLoader != nullptr)
                delete (attachmentLoader);
        }
        spine::AttachmentLoader* attachmentLoader;
        spine::SkeletonData* data;
    };

    static SpineSkeletonDataCache* getInstance();

    SpineSkeletonDataCache();

    SkeletonData* addData(const char* dataFile, const char* atlasFile, float scale);

    void removeData(const char* dataFile);

    void removeAllData(void);
    void removeAllUnusedData(void);

public:
    hlookup::string_map<SkeletonData*> _cacheTable;
};

#else
class SpineSkeletonDataCache
{
public:
    class SkeletonData : public ax::Object
    {
    public:
        SkeletonData(spSkeletonData* d, spAttachmentLoader* loader) : data(d), attachmentLoader(loader) {}
        ~SkeletonData()
        {
            if (data != nullptr)
                spSkeletonData_dispose(data);
            if (attachmentLoader != nullptr)
                spAttachmentLoader_dispose(attachmentLoader);
        }
        spAttachmentLoader* attachmentLoader;
        spSkeletonData* data;
    };

    SpineSkeletonDataCache();

    static SpineSkeletonDataCache* getInstance();

    SkeletonData* addData(const char* dataFile, const char* atlasFile, float scale);

    void removeData(const char* dataFile);

    void removeAllData(void);
    void removeAllUnusedData(void);

public:
    hlookup::string_map<SkeletonData*> _cacheTable;
};

#endif

#endif // defined(AX_ENABLE_EXT_SPINE)

#endif
