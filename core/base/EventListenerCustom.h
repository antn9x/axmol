/****************************************************************************
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axmol.dev/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef _AX_CUSTOMEVENTLISTENER_H_
#define _AX_CUSTOMEVENTLISTENER_H_

#include "base/EventListener.h"

/**
 * @addtogroup base
 * @{
 */

namespace ax
{

class EventCustom;

/** @class EventListenerCustom
 * @brief Custom event listener.
 * @code Usage:
 *        auto dispatcher = Director::getInstance()->getEventDispatcher();
 *     Adds a listener:
 *
 *        auto callback = [](EventCustom* event){ do_some_thing(); };
 *        auto listener = EventListenerCustom::create(callback);
 *        dispatcher->addEventListenerWithSceneGraphPriority(listener, one_node);
 *
 *     Dispatches a custom event:
 *
 *        EventCustom event("your_event_type");
 *        dispatcher->dispatchEvent(&event);
 *
 *     Removes a listener
 *
 *        dispatcher->removeEventListener(listener);
 * \endcode
 * @js cc._EventListenerCustom
 */
class AX_DLL EventListenerCustom : public EventListener
{
public:
    /** Creates an event listener with type and callback.
     * @param eventName The type of the event.
     * @param callback The callback function when the specified event was emitted.
     * @return An autoreleased EventListenerCustom object.
     */
    static EventListenerCustom* create(std::string_view eventName, const std::function<void(EventCustom*)>& callback);

    /// Overrides
    virtual bool checkAvailable() override;
    virtual EventListenerCustom* clone() override;

    /** Constructor */
    EventListenerCustom();

    /** Initializes event with type and callback function */
    bool init(std::string_view listenerId, const std::function<void(EventCustom*)>& callback);

protected:
    std::function<void(EventCustom*)> _onCustomEvent;

    friend class LuaEventListenerCustom;
};

}

// end of base group
/// @}

#endif /* defined(_AX_CUSTOMEVENTLISTENER_H_) */
